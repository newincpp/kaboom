#include "VideoPlayer.hh"

VideoPlayer::VideoPlayer(const std::string &name) : _name(name), _app(sf::VideoMode(920, 480, 32), "Gentoo rocks")
{
    av_register_all(); // libav initialization
    _format = avformat_alloc_context(); // context allocation
    validation(); // checking file validity
    retrieveStream(); // search for stream
    checkVideoStream(); // checks if there is a _video_ stream
    decodeVideo(); // decode video
    video_decode_example("test%02d.pgm", _name.c_str());
}

VideoPlayer::~VideoPlayer()
{
    avformat_free_context(_format);
}

void VideoPlayer::validation()
{
    // opening file and searching its infos in the stream
    if (avformat_open_input(&_format, _name.c_str(), NULL, NULL) < 0) {
        throw std::invalid_argument("invalid file format");
    }
    if (avformat_find_stream_info(_format, NULL) < 0) {
        throw std::runtime_error("cannot find video stream");
    }
}

void VideoPlayer::retrieveStream()
{
    // searching the format structure for infos about the stream
    for (size_t i = 0; i < _format->nb_streams; ++i) {
        _stream = _format->streams[i]; // stream pointer
        _codecType = _stream->codec->codec_type;
        _codecID = _stream->codec->codec_id;
    }
}

void VideoPlayer::checkVideoStream()
{
    for (size_t i = 0; i < _format->nb_streams; ++i) {
        if (_format->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO) {
            _video = _format->streams[i]; // there is an existing video stream \o/
            break;
        }
    }
    if (!_video) {
        throw std::runtime_error("no video stream found");
    }
}

void VideoPlayer::decodeVideo()
{
    _codec = avcodec_find_decoder(_video->codec->codec_id);
    if (_codec == NULL)
        throw std::runtime_error("codec required not available");
    std::cout << _codec->name << std::endl;

    dump_format(_format, 0, _name.c_str(), 0);
}


static void pgm_save(unsigned char *buf, int wrap, int xsize, int ysize, char *filename)
{
    FILE *f;
    int i;
    f=fopen(filename,"w");
    fprintf(f,"P5\n%d %d\n%d\n",xsize,ysize,255);
    for(i=0;i<ysize;i++) {
        fwrite(buf + i * wrap,1,xsize,f);
    }
    fclose(f);
}
int VideoPlayer::decode_write_frame(const char *outfilename, AVCodecContext *avctx, AVFrame *frame, int *frame_count, AVPacket *pkt, int last)
{
    int len, got_frame;
    char buf[1024];
    len = avcodec_decode_video2(avctx, frame, &got_frame, pkt);
    if (len < 0) {
        fprintf(stderr, "Error while decoding frame %d\n", *frame_count);
        return len;
    }

    sf::Image img;

    if (got_frame) {
        printf("Saving %sframe %3d\n", last ? "last " : "", *frame_count);
        fflush(stdout);
        /* the picture is allocated by the decoder, no need to free it */
        snprintf(buf, sizeof(buf), outfilename, *frame_count);
        /*if (!img.LoadFromPixels(920, 480, buf))
            std::cerr << "cannot load image" << std::endl;*/
        sf::Sprite sprite;
        sprite.SetImage(img);
        _app.Draw(sprite);
        _app.Display();
        pgm_save(frame->data[0], frame->linesize[0],
                avctx->width, avctx->height, buf);
        (*frame_count)++;
        exit(0);
    }
    if (pkt->data) {
        pkt->size -= len;
        pkt->data += len;
    }
    return 0;
}

void VideoPlayer::video_decode_example(const char *outfilename, const char *filename)
{
    AVCodec *codec;
    AVCodecContext *c= NULL;
    int frame_count;
    FILE *f;
    AVFrame *frame;
    uint8_t inbuf[INBUF_SIZE + FF_INPUT_BUFFER_PADDING_SIZE];
    AVPacket avpkt;
    av_init_packet(&avpkt);
    /* set end of buffer to 0 (this ensures that no overreading happens for damaged mpeg streams) */
    memset(inbuf + INBUF_SIZE, 0, FF_INPUT_BUFFER_PADDING_SIZE);
    printf("Decode video file %s to %s\n", filename, outfilename);
    /* find the mpeg1 video decoder */
    codec = _codec;//avcodec_find_decoder(AV_CODEC_ID_MPEG1VIDEO);
    if (!codec) {
        fprintf(stderr, "Codec not found\n");
        exit(1);
    }
    c = avcodec_alloc_context3(codec);
    if (!c) {
        fprintf(stderr, "Could not allocate video codec context\n");
        exit(1);
    }
    if(codec->capabilities&CODEC_CAP_TRUNCATED)
        c->flags|= CODEC_FLAG_TRUNCATED; /* we do not send complete frames */
    /* For some codecs, such as msmpeg4 and mpeg4, width and height
     *        MUST be initialized there because this information is not
     *               available in the bitstream. */
    /* open it */
    if (avcodec_open2(c, codec, NULL) < 0) {
        fprintf(stderr, "Could not open codec\n");
        exit(1);
    }
    f = fopen(filename, "rb");
    if (!f) {
        fprintf(stderr, "Could not open %s\n", filename);
        exit(1);
    }
    frame = avcodec_alloc_frame();
    if (!frame) {
        fprintf(stderr, "Could not allocate video frame\n");
        exit(1);
    }
    frame_count = 0;
    for(;;) {




        avpkt.size = fread(inbuf, 1, INBUF_SIZE, f);
        if (avpkt.size == 0)
            break;
        /* NOTE1: some codecs are stream based (mpegvideo, mpegaudio)
         * and this is the only method to use them because you cannot
         * know the compressed data size before analysing it.
         * BUT some other codecs (msmpeg4, mpeg4) are inherently frame
         * based, so you must call them with all the data for one
         * frame exactly. You must also initialize 'width' and
         * 'height' before initializing them. */
        /* NOTE2: some codecs allow the raw parameters (frame size,
         * sample rate) to be changed at any frame. We handle this, so
         * you should also take care of it */
        /* here, we use a stream based decoder (mpeg1video), so we
         * feed decoder and see if it could decode a frame */
        avpkt.data = inbuf;
        while (avpkt.size > 0)
            if (decode_write_frame(outfilename, c, frame, &frame_count, &avpkt, 0) < 0)
                exit(1);
    }
    /* some codecs, such as MPEG, transmit the I and P frame with a
     *        latency of one frame. You must do the following to have a
     *               chance to get the last frame of the video */
    avpkt.data = NULL;
    avpkt.size = 0;
    decode_write_frame(outfilename, c, frame, &frame_count, &avpkt, 1);
    fclose(f);
    avcodec_close(c);
    av_free(c);
    //avcodec_free_frame(&frame);
    printf("\n");
}

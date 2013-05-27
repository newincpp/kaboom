#ifndef __VIDEO__
#define __VIDEO__

# ifndef INT64_C
#  define INT64_C(c) (c ## LL)
#  define UINT64_C(c) (c ## ULL)
# endif

extern "C" {
# include <avformat.h>
# include <avcodec.h>
}

# include <iostream>
# include <stdexcept>
# include <vector>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


#define INBUF_SIZE 4096
#define AUDIO_INBUF_SIZE 20480
#define AUDIO_REFILL_THRESH 4096

class VideoPlayer {

    public:
        // ctors, dtors
        VideoPlayer(const std::string&);
        virtual ~VideoPlayer();

    private:
        // funcs
        void validation();
        void retrieveStream();
        void checkVideoStream();
        void decodeVideo();
        void video_decode_example(const char*, const char*);
        int decode_write_frame(const char*, AVCodecContext*, AVFrame*, int*, AVPacket*, int);

        // generic vars
        std::string _name;

        // libav vars
        AVFormatContext *_format;
        AVStream *_stream;
        AVStream *_video;
        AVPacket _pack;
        AVCodec *_codec;
        AVCodecContext *_context;
        int _codecType;
        int _codecID;
        sf::RenderWindow _app;

};

#endif

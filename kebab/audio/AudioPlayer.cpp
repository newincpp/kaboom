#include "AudioPlayer.hh"

/********************************************\
 *
 *          Public members functions
 *
\*********************************************/

// default constructor
AudioPlayer::AudioPlayer()
{
    initContext(); // initialization of device and context
}

// file loading constructor
AudioPlayer::AudioPlayer(const std::string& name) : _name(name)
{
    initContext(); // initialization of device and context
    loadFile(); // loading file with sndfile lib
    createSource(); // creating source to play song
}

// destructor, clean context and source
AudioPlayer::~AudioPlayer()
{
    destroySource();
    cleanContext();
}

// public function member to load files
void AudioPlayer::loadFile(const std::string& name)
{
    _name = name;
    loadFile();
    createSource();
}

// play loaded song
void AudioPlayer::play()
{
    ALint status;

    alSourcePlay(_source);
    status = AL_PLAYING;
    while (status == AL_PLAYING) {
        alGetSourcei(_source, AL_SOURCE_STATE, &status);
    }
}

// pause loaded song
void AudioPlayer::pause()
{
    alSourcePause(_source);
}



/********************************************\
 *
 *          Private members functions
 *
\*********************************************/


// open OpenAL context
void AudioPlayer::initContext()
{
    _device = alcOpenDevice(NULL);
    _context = alcCreateContext(_device, NULL);
    alcMakeContextCurrent(_context);
}

// clean OpenAL context
void AudioPlayer::cleanContext()
{
    alcMakeContextCurrent(NULL);
    alcDestroyContext(_context);
    alcCloseDevice(_device);
}

void AudioPlayer::loadFile()
{
    SF_INFO info;
    SNDFILE *file;

    if ((file = sf_open(_name.c_str(), SFM_READ, &info)) == NULL)
        throw Exception("cannot load file " + _name);
    _nbsample = static_cast<ALsizei>(info.channels * info.frames);
    _samplerate = static_cast<ALsizei>(info.samplerate);

    std::vector<ALshort> sample(_nbsample);
    _sample = sample;
    if (sf_read_short(file, &_sample[0], _nbsample) < _nbsample)
        throw Exception("cannot read " + _name +  " sample");
    sf_close(file);

    if (info.channels == 1)
        _format = AL_FORMAT_MONO16;
    else if (info.channels == 2)
        _format = AL_FORMAT_STEREO16;

    alGenBuffers(1, &_buff);
    alBufferData(_buff, _format, &_sample[0], _nbsample * sizeof(ALushort), _samplerate);
    if (alGetError() != AL_NO_ERROR)
        throw Exception("cannot generate audio buffer for " + _name);
}

// create corresponding source from buffer
void AudioPlayer::createSource()
{
    alGenSources(1, &_source);
    alSourcei(_source, AL_BUFFER, _buff);
}

// destroy source
void AudioPlayer::destroySource()
{
    alDeleteBuffers(1, &_buff);
    alSourcei(_source, AL_BUFFER, 0);
    alDeleteSources(1, &_source);
}

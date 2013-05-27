#include "AudioPlayer.hh"

AudioPlayer::AudioPlayer(const std::string& name) : _name(name)
{
    initContext(); // initialization of device and context
    loadFile(); // loading file with sndfile lib
    createSource(); // creating source to play song
}

AudioPlayer::~AudioPlayer()
{
    cleanContext();
}

void AudioPlayer::initContext()
{
    _device = alcOpenDevice(NULL);
    _context = alcCreateContext(_device, NULL);
    alcMakeContextCurrent(_context);
}

void AudioPlayer::cleanContext()
{
    alcMakeContextCurrent(NULL);
    alcDestroyContext(_context);
    alcCloseDevice(_device);
}

void AudioPlayer::loadFile()
{
    std::cout << "Loading song..." << std::endl;
    SF_INFO info;
    SNDFILE *file;
    if ((file = sf_open(_name.c_str(), SFM_READ, &info)) == NULL)
        std::cout << "! ! ! ! ! ! cannot open song ! ! ! ! ! !" << std::endl;
    _nbsample = static_cast<ALsizei>(info.channels * info.frames);
    _samplerate = static_cast<ALsizei>(info.samplerate);

    std::vector<ALshort> sample(_nbsample);
    _sample = sample;
    if (sf_read_short(file, &_sample[0], _nbsample) < _nbsample)
        std::cout << "DO NOT WORK" << std::endl;
    sf_close(file);

    if (info.channels == 1)
        _format = AL_FORMAT_MONO16;
    else if (info.channels == 2)
        _format = AL_FORMAT_STEREO16;

    alGenBuffers(1, &_buff);
    alBufferData(_buff, _format, &_sample[0], _nbsample * sizeof(ALushort), _samplerate);
    if (alGetError() != AL_NO_ERROR)
        std::cout << "error" << std::endl;
}

void AudioPlayer::createSource()
{
    alGenSources(1, &_source);
    if (alGetError() != AL_NO_ERROR)
        std::cout << "error" << std::endl;
    alSourcei(_source, AL_BUFFER, _buff);
    if (alGetError() != AL_NO_ERROR)
        std::cout << "error" << std::endl;
}

void AudioPlayer::destroySource()
{
    alDeleteBuffers(1, &_buff);
    alSourcei(_source, AL_BUFFER, 0);
    alDeleteSources(1, &_source);
}

void AudioPlayer::play()
{
    ALint status;
    float result;
    std::cout << "Playing song..." << std::endl;
    alSourcePlay(_source);
    if (alGetError() == AL_INVALID_NAME)
        std::cout << "pas bon nom" << std::endl;
    if (alGetError() == AL_INVALID_OPERATION)
        std::cout << "pas bonne operation" << std::endl;
    if (alGetError() != AL_NO_ERROR)
        std::cout << "error" << std::endl;
    status = AL_PLAYING;
    while (status == AL_PLAYING) {
        alGetSourcei(_source, AL_SOURCE_STATE, &status);
    }
}

void AudioPlayer::pause()
{
    std::cout << "Pausing song" << std::endl;
    alSourcePause(_source);
}

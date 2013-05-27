#ifndef __AUDIOPLAYER__
# define __AUDIOPLAYER__

# include <iostream>
# include <vector>

# include <al.h>
# include <alc.h>
# include <sndfile.h>

class AudioPlayer {

    public:
        AudioPlayer(const std::string&);
        virtual ~AudioPlayer();

        void initContext();
        void cleanContext();
        void createSource();
        void destroySource();
        void loadFile();
        void play();
        void pause();

    private:
        std::string _name;
        ALCdevice *_device;
        ALCcontext *_context;

        // load song
        ALsizei _nbsample;
        ALsizei _samplerate;
        ALenum _format;
        ALuint _buff;
        std::vector<ALshort> _sample;

        //play song
        ALuint _source;

};

#endif

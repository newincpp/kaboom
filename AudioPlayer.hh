#ifndef __AUDIOPLAYER__
# define __AUDIOPLAYER__

# include <iostream>
# include <vector>
# include <exception>

# include <al.h>
# include <alc.h>
# include <sndfile.h>
# include <string.h>

class AudioPlayer {

    public:
        // ctors, dtors
        AudioPlayer();
        AudioPlayer(const std::string&);
        virtual ~AudioPlayer();

        // controllers
        void cleanUp();
        void loadFile(const std::string&);
        void play();
        void pause();
        void destroySource();

        // exception
        class Exception : public std::exception {

            public:
                Exception(const std::string& msg) : _msg(msg) {}
                virtual ~Exception() throw() {}
                virtual const char *what() const throw() { return (_msg.c_str()); }

            private:
                std::string _msg;

        };

    private:
        // file name
        std::string _name;

        // initializer members
        void loadFile();
        void initContext();
        void cleanContext();
        void createSource();

        // initializer variables
        ALCdevice *_device;
        ALCcontext *_context;

        // load song
        ALsizei _nbsample;
        ALsizei _samplerate;
        ALenum _format;
        ALuint _buff;
        std::vector<ALshort> _sample;

        // song source
        ALuint _source;

};

#endif

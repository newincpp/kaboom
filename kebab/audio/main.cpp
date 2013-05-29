#include "AudioPlayer.hh"

int main(int ac, char **av)
{
    if (ac == 3) {
        AudioPlayer p;
        try {
            std::cout << "Playing " << av[1] << "..." << std::endl;
            p.loadFile(av[1]);
            p.play();
            std::cout << "Playing " << av[1] << "..." << std::endl;
            p.play();
            std::cout << "Playing " << av[2] << "..." << std::endl;
            p.loadFile(av[2]);
            p.play();
            p.destroySource();
        }
        catch (const AudioPlayer::Exception& e) {
            std::cout << "AudioPlayer error: " << e.what() << std::endl; 
            p.cleanUp();
        }
    }
    else
        std::cout << "./audio FILE FILE" << std::endl;
}

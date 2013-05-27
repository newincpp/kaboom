#include "AudioPlayer.hh"

int main(int ac, char **av)
{
    if (ac == 2) {
        try {
            std::cout << "Lecture de " << av[1] << std::endl;
            AudioPlayer p(av[1]);
            p.play();
        }
        catch (const AudioPlayer::Exception& e) {
            std::cout << "AudioPlayer error: " << e.what() << std::endl; 
        }
    }
    else
        std::cout << "./audio FILE" << std::endl;
}

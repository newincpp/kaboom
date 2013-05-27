#include "AudioPlayer.hh"

int main(int ac, char **av)
{
    if (ac == 2) {
        std::cout << "Lecture de " << av[1] << std::endl;
        AudioPlayer p(av[1]);
        p.play();
    }
    else
        std::cout << "./audio FILE" << std::endl;
}

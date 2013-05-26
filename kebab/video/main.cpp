#include "VideoPlayer.hh"

int main(int ac, char **av)
{
    if (ac == 2) {
        try {
            VideoPlayer video(av[1]);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Invalid argument: " << e.what() << std::endl;
        }
        catch (const std::runtime_error& e) {
            std::cout << "Runtime error: " << e.what() << std::endl;
        }
    }
    else {
        std::cout << "Please enter video filename!" << std::endl;
    }
}

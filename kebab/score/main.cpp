#include "Score.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 2) {
        Score score;
        std::vector<int> rank;

        try {
            rank = score.getRanking();
        }
        catch (const std::runtime_error& e) {
            std::cout << "No scores..." << std::endl;
        }

        score.add(atoi(av[1]));

        rank = score.getRanking();
        for (size_t i = 0; i < rank.size(); ++i) {
            std::cout << (i + 1) << "° " << rank[i] << std::endl;
        }
    }
    else
        std::cout << "./a.out score" << std::endl;
}

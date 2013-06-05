#include "Score.h"

bool sorting(int i, int j)
{
    return (i > j);
}

void Score::add(int score)
{
    std::ofstream file;
    std::vector<int> rank;

    try {
        rank = getRanking();
    }
    catch (const std::runtime_error& e) {
       createFile(score);
       return;
    }
    for (size_t i = 0; i < rank.size(); ++i) {
        if (score > rank[i] || rank.size() < 10) {
            std::cout << "Adding score of value " << score << std::endl;
            rank.push_back(score);
            std::sort (rank.begin(), rank.begin() + rank.size(), sorting);
            if (rank.size() > 10)
                rank.pop_back();
            file.open("./.score", std::ios::trunc);
            file.clear();
            if (file.is_open()) {
                for (size_t j = 0; j < rank.size(); ++j) {
                    std::ostringstream oss;
                    oss << rank[j];
                    file << oss.str() << std::endl;
                }
            }
            file.close();
            return;
        }
    }
}

void Score::createFile(int score)
{
    std::ofstream file;
    std::ostringstream oss;

    file.open("./.score");
    oss << score;
    file << oss.str() << std::endl;
 
}

std::vector<int> Score::getRanking()
{
    int score;
    std::string in;
    std::ifstream file;
    std::vector<int> ret;

    file.open("./.score");
    if (file.is_open()) {
        while (file.good()) {
            if (getline (file, in)) {
                std::istringstream(in) >> score;
                ret.push_back(score);
            }
        }
        file.close();
    }
    else
        throw std::runtime_error("cannot open score file");
    return (ret);
}

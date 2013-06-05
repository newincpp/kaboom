#ifndef __SCORE__
# define __SCORE__

# include <vector>
# include <fstream>
# include <sstream>
# include <iostream>
# include <stdexcept>
# include <algorithm>

class Score {

    public:
        Score() {}
        virtual ~Score() {}

        void add(int);
        std::vector<int> getRanking();
        
    private:
        void createFile(int);

};

#endif /*__SCORE__*/

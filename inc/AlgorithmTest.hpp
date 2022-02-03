#ifndef ALGORITHMTEST_H
#define ALGORITHMTEST_H


#include<Algorithm.hpp>

class AlgorithmTest {
    public:
        static void testAlgorithm(std::tuple<bool, std::string, std::string, std::string> config, const Algorithm& algorithm, const std::string& algorithm_name);
};


#endif //ALGORITHMTEST_H

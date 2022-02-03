#ifndef DIAL_H
#define DIAL_H


#include<Algorithm.hpp>

class Dial : public Algorithm {
    public:
        int findPath(std::shared_ptr<Graph> graph, int source, int destination) const;
};


#endif //DIAL_H

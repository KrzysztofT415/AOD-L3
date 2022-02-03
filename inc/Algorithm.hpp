#ifndef ALGORITHM_H
#define ALGORITHM_H


#include <limits>
#include <Graph.hpp>

class Algorithm {
    public:
        virtual int findPath(std::shared_ptr<Graph> graph, int source, int destination = -1) const = 0;
};


#endif //ALGORITHM_H
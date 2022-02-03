#ifndef DIJKSTRA_H
#define DIJKSTRA_H


#include<Algorithm.hpp>

class Dijkstra : public Algorithm {
    public:
        int findPath(std::shared_ptr<Graph> graph, int source, int destination) const;
};


#endif //DIJKSTRA_H

#ifndef RADIXHEAP_H
#define RADIXHEAP_H


#include<Algorithm.hpp>

class RadixHeap : public Algorithm {
    public:
        int findPath(std::shared_ptr<Graph> graph, int source, int destination) const;
};


#endif //RADIXHEAP_H

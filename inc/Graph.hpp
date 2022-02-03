#ifndef GRAPH_H
#define GRAPH_H


#include <vector>
#include <fstream>
#include <memory>
#include <stack>
#include <Edge.hpp>

class Graph {
private:
    std::vector<std::shared_ptr<std::vector<std::shared_ptr<Edge>>>> _adjacency;
    int _edges = 0;
    int _min = std::numeric_limits<int>::max();
    int _max = 0;

public:
    explicit Graph() {};

    std::tuple<int, int, int, int> loadData(const std::string &fileName);
    std::stack<int> loadSources(const std::string &fileName);
    std::stack<std::pair<int, int>> loadRoutes(const std::string &fileName);
    
    void loadClique(int vertices);
    void addEdge(int source, int destination, int wage);

    std::shared_ptr<std::vector<std::shared_ptr<std::vector<std::shared_ptr<Edge>>>>> getAdjacency() const {
        return std::make_shared<std::vector<std::shared_ptr<std::vector<std::shared_ptr<Edge>>>>>(_adjacency);
    }
    int getVerticesNum() const { return _adjacency.size(); }
    int getEdgesNum() const { return _edges; }
    int getMin() const { return _min; }
    int getMax() const { return _max; }
};


#endif //GRAPH_H

#ifndef SOLVER_H
#define SOLVER_H


#include <Algorithm.hpp>
#include <Graph.hpp>

class Solver {
    private:
        const Algorithm& _algorithm;
        std::shared_ptr<Graph> _graph;
    public:
        Solver(std::shared_ptr<Graph> graph, const Algorithm& algorithm);
        double establishRoutes(std::stack<int>& sources) const;
        std::stack<std::tuple<int, int, int>> findPaths(std::stack<std::pair<int, int>>& routes) const;
};


#endif //SOLVER_H
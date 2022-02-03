#include<Solver.hpp>
#include<chrono>

Solver::Solver(std::shared_ptr<Graph> graph, const Algorithm& algorithm) : _graph(graph), _algorithm(algorithm) {}

double Solver::establishRoutes(std::stack<int>& sources) const {
    unsigned long long int duration = 0;
    int size = sources.size();
    
    while (!sources.empty()) {
        auto t1 = std::chrono::high_resolution_clock::now();
        _algorithm.findPath(_graph, sources.top() - 1);
        auto t2 = std::chrono::high_resolution_clock::now();

        duration += std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        sources.pop();
    }
    double result = (double)(duration) / size;
    return result;
}

std::stack<std::tuple<int, int, int>> Solver::findPaths(std::stack<std::pair<int, int>>& routes) const {
    std::stack<std::tuple<int, int, int>> results;
    while (!routes.empty()) {
        int length = _algorithm.findPath(_graph, routes.top().first - 1, routes.top().second - 1);
        results.push(std::make_tuple(routes.top().first, routes.top().second, length));
        routes.pop();
    }
    return results;
}
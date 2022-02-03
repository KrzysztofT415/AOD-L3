#include<Graph.hpp>

std::tuple<int, int, int, int> Graph::loadData(const std::string &fileName) {
    std::ifstream file;
    file.open(fileName);

    char lineSign;
    std::string comment;
    int vertices, edges, source, destination, wage;

    while (file.get(lineSign)) {
        switch (lineSign) {
            case 'p':
                file >> comment >> vertices >> edges;
                _adjacency.reserve(vertices);
                for (int i = 0; i < vertices; ++i)
                    _adjacency.emplace_back(std::make_shared<std::vector<std::shared_ptr<Edge>>>());
                getline(file, comment);
                break;
            case 'a':
                file >> source >> destination >> wage;
                addEdge(source, destination, wage);
                getline(file, comment);
                break;
            case 'c':
                getline(file, comment);
                break;
            default:
                break;
        }
    }
    file.close();
    return std::make_tuple(vertices, edges, getMin(), getMax());
}

std::stack<int> Graph::loadSources(const std::string &fileName) {
    std::ifstream file(fileName);
    std::stack<int> sources;

    char lineSign;
    std::string comment;
    int sources_len, source;

    while (file.get(lineSign)) {
        switch (lineSign) {
            case 'p':
                file >> comment >> comment >> comment >> sources_len;
                getline(file, comment);
                break;
            case 's':
                file >> source;
                sources.push(source);
                getline(file, comment);
                break;
            case 'c':
                getline(file, comment);
                break;
            default:
                break;
        }
    }
    file.close();
    return sources;
}

std::stack<std::pair<int, int>> Graph::loadRoutes(const std::string &fileName) {
    std::ifstream file(fileName);
    std::stack<std::pair<int, int>> routes;

    char lineSign;
    std::string comment;
    int routes_len, source, destination;

    while (file.get(lineSign)) {
        switch (lineSign) {
            case 'p':
                file >> comment >> comment >> comment >> routes_len;
                getline(file, comment);
                break;
            case 'q':
                file >> source >> destination;
                routes.push(std::make_pair(source, destination));
                getline(file, comment);
                break;
            case 'c':
                getline(file, comment);
                break;
            default:
                break;
        }
    }
    file.close();
    return routes;
}

void Graph::addEdge(int source, int destination, int wage) {
    std::shared_ptr<Edge> newEdge = std::make_shared<Edge>(source - 1, destination - 1, wage);
    int cap = std::max(source, destination);
    if (_adjacency.size() < cap) {
        int j = cap - (int)_adjacency.size();
        _adjacency.reserve(cap);
        for (int i = 0; i < j; ++i)
            _adjacency.push_back(std::make_shared<std::vector<std::shared_ptr<Edge>>>());
    }
    if (wage > _max) _max = wage;
    if (wage < _min) _min = wage;
    _edges += 1;
    _adjacency[source - 1]->push_back(newEdge);
}
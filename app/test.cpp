#include <AlgorithmTest.hpp>
#include <Dijkstra.hpp>
#include <Dial.hpp>
#include <RadixHeap.hpp>
#include <Solver.hpp>
#include <iostream>

int main(int argc, char** argv) {
    std::cout << "Starting test\n";
    auto graph = std::make_shared<Graph>();
    auto params = graph->loadData("/home/krzysiek/files/sem5/aod/lista_3/test.gr");
    std::cout << "loaded data\n";
    {
        auto algorithm = Dijkstra();
        std::cout << "Dijkstra\n";

        auto solver = std::make_unique<Solver>(graph, algorithm);
        auto sources = graph->loadSources("/home/krzysiek/files/sem5/aod/lista_3/test.ss");
        auto time = solver->establishRoutes(sources);
        std::cout << "t " << time << '\n';

        auto routes = graph->loadRoutes("/home/krzysiek/files/sem5/aod/lista_3/test.p2p");
        auto paths = solver->findPaths(routes);
        while (!paths.empty()) {
            std::cout << "d " << std::get<0>(paths.top()) << ' ' << std::get<1>(paths.top()) << ' ' << std::get<2>(paths.top()) << '\n';
            paths.pop();
        }
    }
    {
        auto algorithm = Dial();
        std::cout << "Dial\n";

        auto solver = std::make_unique<Solver>(graph, algorithm);
        auto sources = graph->loadSources("/home/krzysiek/files/sem5/aod/lista_3/test.ss");
        auto time = solver->establishRoutes(sources);
        std::cout << "t " << time << '\n';

        auto routes = graph->loadRoutes("/home/krzysiek/files/sem5/aod/lista_3/test.p2p");
        auto paths = solver->findPaths(routes);
        while (!paths.empty()) {
            std::cout << "d " << std::get<0>(paths.top()) << ' ' << std::get<1>(paths.top()) << ' ' << std::get<2>(paths.top()) << '\n';
            paths.pop();
        }
    }
    {
        auto algorithm = RadixHeap();
        std::cout << "RadixHeap\n";

        auto solver = std::make_unique<Solver>(graph, algorithm);
        auto sources = graph->loadSources("/home/krzysiek/files/sem5/aod/lista_3/test.ss");
        auto time = solver->establishRoutes(sources);
        std::cout << "t " << time << '\n';

        auto routes = graph->loadRoutes("/home/krzysiek/files/sem5/aod/lista_3/test.p2p");
        auto paths = solver->findPaths(routes);
        while (!paths.empty()) {
            std::cout << "d " << std::get<0>(paths.top()) << ' ' << std::get<1>(paths.top()) << ' ' << std::get<2>(paths.top()) << '\n';
            paths.pop();
        }
    }
    return 0;
}
#include <Solver.hpp>
#include <AlgorithmTest.hpp>

void AlgorithmTest::testAlgorithm(std::tuple<bool, std::string, std::string, std::string> config, const Algorithm& algorithm, const std::string& algorithm_name) {
    auto graph = std::make_shared<Graph>();
    auto params = graph->loadData(std::get<1>(config));
    auto solver = std::make_unique<Solver>(graph, algorithm);
    std::ofstream file(std::get<3>(config));

    if (std::get<0>(config)) {
        auto sources = graph->loadSources(std::get<2>(config));
        auto time = solver->establishRoutes(sources);
        file << "p res sp ss " << algorithm_name << '\n';
        file << "f " << std::get<1>(config) << ' ' << std::get<2>(config) << '\n';
        file << "g " << std::get<0>(params) << ' ' << std::get<1>(params) << ' ' << std::get<2>(params) << ' ' << std::get<3>(params) << '\n';
        file << "t " << time << '\n';
    } else {
        auto routes = graph->loadRoutes(std::get<2>(config));
        auto paths = solver->findPaths(routes);
        file << "f " << std::get<1>(config) << ' ' << std::get<2>(config) << '\n';
        file << "g " << std::get<0>(params) << ' ' << std::get<1>(params) << ' ' << std::get<2>(params) << ' ' << std::get<3>(params) << '\n';
        while (!paths.empty()) {
            file << "d " << std::get<0>(paths.top()) << ' ' << std::get<1>(paths.top()) << ' ' << std::get<2>(paths.top()) << '\n';
            paths.pop();
        }
    }

    file.close();
}
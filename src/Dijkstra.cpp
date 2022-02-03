#include<Dijkstra.hpp>
#include<PriorityQueue.hpp>

int Dijkstra::findPath(std::shared_ptr<Graph> graph, int source, int destination = -1) const {
    auto adjacency = graph->getAdjacency();
    int inf = std::numeric_limits<int>::max();

    std::vector<int> distances(graph->getVerticesNum(), inf);
    std::vector<int> parent(graph->getVerticesNum(), -1);

    PriorityQueue<int> queue;
    distances[source] = 0.0;
    queue.insert(source, 0.0);

    int nodesToFind = graph->getVerticesNum();
    while (nodesToFind && !queue.empty()) {
        auto node = queue.pop();
        nodesToFind--;
        if (destination != -1 && node->getValue() == destination)
            return distances[node->getValue()];
        for (const std::shared_ptr<Edge>& edge : *(*adjacency)[node->getValue()]) {
            int newDistance = distances[node->getValue()] + edge->getWeight();
            if (distances[edge->getDestination()] > newDistance) {
                if (distances[edge->getDestination()] == inf)
                    queue.insert(edge->getDestination(), newDistance);
                else queue.priority(edge->getDestination(), newDistance);
                distances[edge->getDestination()] = newDistance;
                parent[edge->getDestination()] = node->getValue();
            }
        }
    }
    return -1;
}
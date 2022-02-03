#include<RadixHeap.hpp>
#include<CirDblList.hpp>
#include<PriorityQueue.hpp>
#include<math.h>

int RadixHeap::findPath(std::shared_ptr<Graph> graph, int source, int destination) const {
    auto adjacency = graph->getAdjacency();
    int inf = std::numeric_limits<int>::max();

    std::vector<int> distances(graph->getVerticesNum(), inf);
    distances[source] = 0;
    std::vector<bool> visited(graph->getVerticesNum(), false);
    std::vector<int> parent(graph->getVerticesNum(), -1);

    int size = std::ceil(std::log2(graph->getMax() * graph->getVerticesNum())) + 1;
    std::vector<std::shared_ptr<PriorityQueue<int>>> sets{ std::make_shared<PriorityQueue<int>>(), std::make_shared<PriorityQueue<int>>() };
    for (int i = 2; i < size; i++)
        sets.push_back(std::make_shared<PriorityQueue<int>>());

    auto currentSetId = -1;
    auto currentSet = sets[0];
    currentSet->insert(source, 0);
    int nodesToFind = graph->getVerticesNum();
    while (nodesToFind > 0 && ++currentSetId < size) {
        currentSet = sets[currentSetId];

        if (currentSet->empty()) continue;
        if (currentSetId > 1) {
            auto first = currentSet->get(1);
            int minDistance = first->getPriority();
            sets[0]->insert(first->getValue(), first->getPriority());

            for (int i = 2; i <= currentSet->size(); ++i) {
                auto node = currentSet->get(i);
                if (visited[node->getValue()]) continue;

                int newSetId = std::ceil(std::log2(node->getPriority() - minDistance + 1));
                sets[newSetId]->insert(node->getValue(), node->getPriority());
            }
            currentSet->clear();

        } else {
            while (!currentSet->empty()) {
                auto node = currentSet->pop();
                if (destination != -1 && node->getValue() == destination) return distances[node->getValue()];

                if (visited[node->getValue()]) continue;
                visited[node->getValue()] = true;
                nodesToFind--;

                for (const std::shared_ptr<Edge>& edge : *(*adjacency)[node->getValue()]) {
                    int newDistance = distances[node->getValue()] + edge->getWeight();

                    if (distances[edge->getDestination()] > newDistance) {
                        int newSetId = std::ceil(std::log2(newDistance + 1));
                        sets[newSetId]->insert(edge->getDestination(), newDistance);
                        distances[edge->getDestination()] = newDistance;
                        parent[edge->getDestination()] = node->getValue();
                    }
                }
            }
        }
        currentSetId = -1;
    }
    return -1;
}
#include<Dial.hpp>
#include<CirDblList.hpp>

int Dial::findPath(std::shared_ptr<Graph> graph, int source, int destination) const {
    auto adjacency = graph->getAdjacency();
    int inf = std::numeric_limits<int>::max();

    std::vector<int> distances(graph->getVerticesNum(), inf);
    distances[source] = 0;
    std::vector<bool> visited(graph->getVerticesNum(), false);
    std::vector<int> parent(graph->getVerticesNum(), -1);

    int size = graph->getMax() + 1;
    CirDblList<std::shared_ptr<std::vector<int>>> sets;
    for (int i = 0; i < size; i++)
        sets.push(std::make_shared<std::vector<int>>());

    auto currentSet = sets.getNode(0);
    currentSet->getValue()->push_back(source);
    int nodesToFind = graph->getVerticesNum();
    int emptySetsChecked = 0;
    auto currentSetId = 0;
    while (nodesToFind > 0 && emptySetsChecked < size) {

        auto currentSetStack = currentSet->getValue();
        while (!currentSetStack->empty()) {
            auto node = currentSetStack->back();
            currentSetStack->pop_back();

            if (destination != -1 && node == destination) return distances[node];
            if (visited[node]) continue;
            nodesToFind--;
            visited[node] = true;
            emptySetsChecked = 0;

            for (const std::shared_ptr<Edge>& edge : *(*adjacency)[node]) {
                int newDistance = distances[node] + edge->getWeight();

                if (distances[edge->getDestination()] > newDistance) {
                    int newSetId = (currentSetId + edge->getWeight()) % size;
                    sets.getNode(newSetId + 1)->getValue()->push_back(edge->getDestination());
                    distances[edge->getDestination()] = newDistance;
                    parent[edge->getDestination()] = node;
                }
            }
        }
        currentSet = currentSet->next;
        currentSetId = (currentSetId + 1) % size;
        emptySetsChecked++;
    }
    return -1;
}
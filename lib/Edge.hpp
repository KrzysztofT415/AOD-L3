#ifndef EDGE_H
#define EDGE_H


class Edge {
private:
    int _source;
    int _destination;
    int _weight;
public:
    Edge(const int &source, const int &destination, const int &wage)
            : _source(source), _destination(destination), _weight(wage) {}
    int getSource() const { return _source; }
    void setSource(int source) { _source = source; }
    int getDestination() const { return _destination; }
    void setDestination(int destination) { _destination = destination; }
    int getWeight() const { return _weight; }
    void setWeight(int weight) { _weight = weight; }
};


#endif //EDGE_H

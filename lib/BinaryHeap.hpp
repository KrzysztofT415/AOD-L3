#ifndef BINARYHEAP_H
#define BINARYHEAP_H


#include <vector>
#include <HeapNode.hpp>

template<typename T>
class BinaryHeap {
private:
    std::vector<std::shared_ptr<HeapNode<T>>> _table;
public:
    static int parent(int i) { return i >> 1; }
    static int left(int i) { return i << 1; }
    static int right(int i) { return (i << 1) | 1; }

    void setNode(int id, const std::shared_ptr<HeapNode<T>>& node) {
        if (id > _table.size()) {
            _table.push_back(node);
            return;
        }
        _table[id - 1] = node;
    }
    std::shared_ptr<HeapNode<T>> getNode(int id) {
        return _table[id - 1];
    }
    void swapNodes(int idx, int idy) {
        _table[idx - 1].swap(_table[idy - 1]);
    }

    void heapify(int i) {
        auto _this = _table[i - 1];
        auto _left = left(i) <= _table.size() ? _table[left(i) - 1] : nullptr;
        auto _right = right(i) <= _table.size() ? _table[right(i) - 1] : nullptr;

        if (_left && _left->getPriority() < _this->getPriority()) {
            if (_right && _right->getPriority() < _left->getPriority()) {
                _table[i - 1].swap(_table[right(i) - 1]);
                heapify(right(i));
                return;
            }
            _table[i - 1].swap(_table[left(i) - 1]);
            heapify(left(i));
            return;
        }
        if (_right && _right->getPriority() < _this->getPriority()) {
            _table[i - 1].swap(_table[right(i) - 1]);
            heapify(right(i));
        }
    }

    int getSize() const { return _table.size(); }
    void decSize() { _table.pop_back(); }
    void clear() { _table.clear(); }
};


#endif //BINARYHEAP_H

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


#include <BinaryHeap.hpp>

template<typename T>
class PriorityQueue {
private:
    std::shared_ptr<BinaryHeap<T>> _heap;

public:
    PriorityQueue() { _heap = std::make_shared<BinaryHeap<T>>(); }

    void insert(T value, int priority) {
        int i = _heap->getSize() + 1;
        std::shared_ptr<HeapNode<T>> newNode = std::make_shared<HeapNode<T>>(value, priority);
        _heap->setNode(i, newNode);
        while (i > 1 && _heap->getNode(_heap->parent(i))->getPriority() > priority) {
            _heap->swapNodes(i, _heap->parent(i));
            i = _heap->parent(i);
        }
    }
    bool empty() {
        return _heap->getSize() == 0;
    }
    std::shared_ptr<HeapNode<T>> top() {
        if (_heap->getSize() == 0) return nullptr;
        return _heap->getNode(1);
    }
    std::shared_ptr<HeapNode<T>> pop() {
        if (_heap->getSize() == 0) return nullptr;
        if (_heap->getSize() == 1) {
            auto _first = _heap->getNode(1);
            _heap->decSize();
            return _first;
        }
        auto _pop = _heap->getNode(1);
        _heap->swapNodes(1, _heap->getSize());
        _heap->decSize();
        _heap->heapify(1);
        return _pop;
    }
    void remove(int position) {
        if (position <= _heap->getSize()) {
            if (position == 1) {
                _heap->decSize();
                return;
            }
            _heap->swapNodes(position, _heap->getSize());
            _heap->decSize();
            _heap->heapify(position);
        }
    }
    std::shared_ptr<HeapNode<T>> get(int position) {
        return _heap->getNode(position);
    }
    void priority(T value, int newPriority, bool all = false) {
        bool found = false;
        for (int i = 1; i <= _heap->getSize(); ++i) {
            auto _node = _heap->getNode(i);
            if (_node->getValue() == value && _node->getPriority() > newPriority) {
                _node->setPriority(newPriority);
                _heap->heapify(i);
                if (!all) return;
                found = true;
            }
        }
        if (!found) insert(value, newPriority);
    }
    void print(std::ostream& stream) {
        for (int i = 1; i <= _heap->getSize(); ++i) {
            auto _node = _heap->getNode(i);
            stream << "(" << _node->getValue() << ";" << _node->getPriority() << ") ";
        }
    }
    void clear() { _heap->clear(); }
    int size() { return _heap->getSize(); }
};


#endif //PRIORITYQUEUE_H

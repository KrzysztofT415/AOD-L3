#ifndef CIRDBLLIST_H
#define CIRDBLLIST_H


#include <ListNode.hpp>

template<typename T>
class CirDblList {
private:
    std::shared_ptr<ListNode<T>> _head = nullptr;
public:
    void push(T value) {
        std::shared_ptr<ListNode<T>> newNode = std::make_shared<ListNode<T>>(value);
        if (!_head) _head = newNode;
        else {
            _head->prev->next = nullptr;
            _head->prev->appendChild(newNode);
        }
        _head->prev = newNode;
        newNode->next = _head;
    }

    std::shared_ptr<ListNode<T>> getNode(int position) {
        std::shared_ptr<ListNode<T>> current = _head;
        while (position > 1 && current) {
            current = current->next;
            position--;
        }
        return current;
    }

    void remove(int position) {
        std::shared_ptr<ListNode<T>> current = _head;
        while (position > 2 && current) {
            current = current->next;
            position--;
        }
        if (!current || !current->next) return;
        current->next = current->next->next;
        current->next->prev = current;
    }
};


#endif //CIRDBLLIST_H
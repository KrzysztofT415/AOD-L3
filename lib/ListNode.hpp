#ifndef LISTNODE_H
#define LISTNODE_H


template<typename T>
class ListNode {
private:
    T _value;
public:
    std::shared_ptr<ListNode<T>> next = nullptr;
    std::shared_ptr<ListNode<T>> prev = nullptr;
    
    ListNode(const T& value) : _value(value) {}

    void appendChild(std::shared_ptr<ListNode<T>> newNode) {
        if (!next) {
            next = newNode;
            newNode->prev = newNode;
            return;
        }
        next->appendChild(newNode);
    }
    T getValue() const { return _value; }
};


#endif //LISTNODE_H

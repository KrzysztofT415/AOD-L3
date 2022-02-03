#ifndef HEAPNODE_H
#define HEAPNODE_H


template<typename T>
class HeapNode {
private:
    T _value;
    int _priority;
public:
    HeapNode(const T& value, const int& priority) : _value(value), _priority(priority) {}
    
    T getValue() const { return _value; }
    void setValue(T value) { _value = value; }
    int getPriority() const { return _priority; }
    void setPriority(int priority) { _priority = priority; }
};


#endif //HEAPNODE_H

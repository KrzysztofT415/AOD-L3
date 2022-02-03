// #ifndef LIST_H
// #define LIST_H


// #include <ListNode.hpp>

// template<typename T>
// class List {
// private:
//     std::shared_ptr<ListNode<T>> _head = nullptr;
// public:
//     void push(T value) {
//         if (!_head) {
//             _head = std::make_shared<Listode<T>>(value);
//             return;
//         }
//         _head->appendChild(value);
//     }

//     std::shared_ptr<ListNode<T>> at(int position) {
//         std::shared_ptr<ListNode> current_node = head;
//         while (position > 1 && current_node) {
//             current_node = current_node->next;
//             position--;
//         }
//         if (!current_node) {
//             printf("   WARNING : Index out of list size");
//             return nullptr;
//         }
//         return current_node;
//     }

//     void delete(int position) {
//         std::shared_ptr<ListNode> current_node = head;
//         while (position > 2 && current_node) {
//             current_node = current_node->next;
//             position--;
//         }
//         if (!current_node || !current_node->next) {
//             printf("   WARNING : Index out of list size");
//             return;
//         }
//         current_node->next = current_node->next->next;
//     }

//     void merge(List list1, List list2) {
//         std::shared_ptr<ListNode> current_node = list1->head;
//         while (current_node->next) {
//             current_node = current_node->next;
//         }
//         current_node->next = list2->head;
//         free(list2);
//     }
// };


// #endif //LIST_H
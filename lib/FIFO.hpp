// #include <stdio.h> //printf
// #include <stdlib.h> //malloc

// // DATA TYPE

// typedef struct Data Data;
// struct Data {
//     double value;
// };

// // QUEUE DEFINITION

// typedef struct Queue Queue;
// Queue* newQueue(int MAX_SIZE);
// void queue_push(Queue* queue, Data data);
// Data* queue_next(Queue* queue);

// struct Queue {
//     int MAX_SIZE;
//     int size;
//     int front;
//     Data* data;

//     void (*push)(Queue* queue, Data data);
//     Data* (*next)(Queue* queue);
// };

// Queue* newQueue(int MAX_SIZE) {
//     Queue* queue_instance;
//     if ((queue_instance = malloc(sizeof *queue_instance))
//         && (queue_instance->data = malloc(MAX_SIZE * sizeof(Data)))) {

//         queue_instance->MAX_SIZE = MAX_SIZE;
//         queue_instance->size = 0;
//         queue_instance->front = 0;
//         queue_instance->next = queue_next;
//         queue_instance->push = queue_push;

//         return queue_instance;
//     }
//     printf("   WARNING : Lack of memory to create new Queue");
//     return NULL;
// }

// void queue_push(Queue* queue, Data data) {
//     if (queue->size + 1 > queue->MAX_SIZE) {
//         printf("   WARNING : Queue overflow, data lost ");
//         return;
//     }
//     queue->data[(queue->size + queue->front) % queue->MAX_SIZE] = data;
//     queue->size++;
// }

// Data* queue_next(Queue* queue) {
//     if (queue->size != 0) {
//         queue->size--;
//         Data* next = &queue->data[queue->front];
//         queue->front++;
//         if (queue->front >= queue->MAX_SIZE) {
//             queue->front = 0;
//         }
//         return next;
//     }
//     printf("   WARNING : Tried to get next data from empty Queue\n");
//     return NULL;
// }
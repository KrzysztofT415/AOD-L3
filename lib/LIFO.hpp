// #include <stdio.h> //printf
// #include <stdlib.h> //malloc

// // DATA TYPE

// typedef struct Data Data;
// struct Data {
//     int value;
// };

// // STACK DEFINITION

// typedef struct Stack Stack;
// Stack* newStack(int MAX_SIZE);
// void stack_push(Stack* stack, Data data);
// Data* stack_pop(Stack* stack);

// struct Stack {
//     int MAX_SIZE;
//     int size;
//     Data* data;

//     void (*push)(Stack* stack, Data data);
//     Data* (*pop)(Stack* stack);
// };

// Stack* newStack(int MAX_SIZE) {
//     Stack* stack_instance;
//     if ((stack_instance = malloc(sizeof *stack_instance))
//         && (stack_instance->data = malloc(MAX_SIZE * sizeof(Data)))) {

//         stack_instance->MAX_SIZE = MAX_SIZE;
//         stack_instance->size = 0;
//         stack_instance->pop = stack_pop;
//         stack_instance->push = stack_push;

//         return stack_instance;
//     }
//     printf("   WARNING : Lack of memory to create new Stack");
//     return NULL;
// }

// void stack_push(Stack* stack, Data data) {
//     if (stack->size + 1 > stack->MAX_SIZE) {
//         printf("   WARNING : Stack overflow, data lost ");
//         return;
//     }
//     stack->data[stack->size] = data;
//     stack->size++;
// }

// Data* stack_pop(Stack* stack) {
//     if (stack->size != 0) {
//         stack->size--;
//         return &stack->data[stack->size];
//     }
//     printf("   WARNING : Tried to pop empty Stack\n");
//     return NULL;
// }

// // TESTING STACK

// void testLIFO();

// int main() {
//     {
//         Stack *myLIFO = newStack(100);

//         printf("\nInserting data:\n");
//         for (int i = 1; i <= 100; ++i) {
//             Data data = {i};
//             myLIFO->push(myLIFO, data);
//             printf("%d\n", data.value);
//         }

//         printf("\nPrinting data:\n");
//         for (int i = 1; i <= 100; ++i) {
//             Data *data = myLIFO->pop(myLIFO);
//             if (data) { printf("%d\n", data->value); }
//         }
//     }

// //    testLIFO(); // uncomment this line to see how memory works
//     return 0;
// }

// // MY TEST OF MEMORY MANAGEMENT (EXTRA)

// void manageLIFO(Stack* myLIFO, int insertions, int deletions);
// void printLIFO(Stack* myLIFO);

// void testLIFO() {
//     printf("\n\nCreating new Stack");
//     Stack* myLIFO = newStack(16);
//     printLIFO(myLIFO);
//     printf("Inserting 222\n");
//     Data data = {222};
//     myLIFO->push(myLIFO, data);
//     manageLIFO(myLIFO, 1, 4);
//     printLIFO(myLIFO);
//     manageLIFO(myLIFO, 18, 5);
//     printLIFO(myLIFO);
//     printf("Inserting 111\n");
//     Data data2 = {111};
//     myLIFO->push(myLIFO, data2);
//     printLIFO(myLIFO);
//     manageLIFO(myLIFO, 5, 15);
//     printLIFO(myLIFO);
//     printf("Elements left : %d\n", myLIFO->size);
//     printf("It is : %d\n--------------------\n", myLIFO->pop(myLIFO)->value);
// }

// void manageLIFO(Stack* myLIFO, int insertions, int deletions) {
//     printf("\nInserting data:\n");
//     for (int i = 1; i <= insertions; ++i) {
//         Data data = {i * 2};
//         printf("%d : %d - insertion started ", i, data.value);
//         myLIFO->push(myLIFO, data);
//         printf("; ended\n");
//     }

//     printf("\nPrinting data:\n");
//     for (int i = 1; i <= deletions; ++i) {
//         Data* a = myLIFO->pop(myLIFO);
//         if (a) { printf("%d\n", a->value); }
//     }
// }

// void printLIFO(struct Stack* myLIFO) {
//     printf("\n--------------------------\nMemory :-");
//     for (int i = 0; i < myLIFO->MAX_SIZE; ++i) {
//         printf(": %d ", myLIFO->data[i].value);
//     }
//     printf("\n--------------------------\n");
// }
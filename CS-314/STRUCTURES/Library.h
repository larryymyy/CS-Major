#include <stdlib.h>

typedef struct {
	long value;
	struct Node * next;
} Node;

typedef struct {
	Node * tail;
} Queue;

typedef struct {
	Node * top;
} Stack;

/* Node Methods */
Node * mallocNode(long value, Node * parent);
void freeNodeChain(Node * root);
void freeNode(Node * node);

/* Stack Methods */
Stack * mallocStack();
void freeStack(Stack * stack);
void push(Stack * stack, long val);
long pop(Stack * stack);
int isEmpty_STACK(Stack * stack);

/* Queue Methods */
Queue * mallocQueue();
void freeQueue(Queue * queue);
void enqueue(Queue * queue, long value);
long dequeue(Queue * queue);
int isEmpty_QUEUE(Queue * queue);

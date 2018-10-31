#include "Library.h"

Queue * mallocQueue() {
	Queue * queue = malloc(1 * sizeof(Queue));
	return queue;
}

// frees the memory used in a queue
void freeQueue(Queue * queue) {
	freeNodeChain(queue->tail);
	free(queue);
}

// Enqueue a value
void enqueue(Queue * queue, long value) {
	if(queue->tail == NULL) {
		queue->tail = mallocNode(value, NULL);
		return;
	}
	Node * current = queue->tail;
	while(current->next != NULL) {
		current = current->next;
	}
	current->next = mallocNode(value, current);
	return;
}

// Dequeue a value
long dequeue(Queue * queue) {
	if(queue->tail == NULL) {
		return 0;
	}
	Node * current = queue->tail;
	Node * parent = queue->tail;
	while(current->next != NULL) {
		parent = current;
		current = current->next;
	}
	parent->next = NULL;
	long value = current->value;
	freeNode(current);
	return value;
}

int isEmpty_QUEUE(Queue * queue) {
	return queue->tail == NULL;
}

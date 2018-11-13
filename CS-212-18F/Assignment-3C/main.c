#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 10

typedef struct {
	int front, back;  // Indeces of the start and end of the queue
	int size;         // Number of items in the queue
	char ** array;    // Array of strings
} Queue;

// Queue constructor
void InitializeQueue(Queue * queue) {
	queue->array = malloc(sizeof(char *) * QUEUE_SIZE);
	queue->front = 0;
	queue->back = 0;
	queue->size = 0;
}

// Determines if a queue is at capacity
int isFull(Queue * queue) { return queue->size == QUEUE_SIZE; }

// Determines if a queue is empty
int isEmpty(Queue * queue) { return queue->size == 0; }

// Enqueues a string into a queue (assuming there is enough space for it)
void Enqueue(Queue * queue, char * str) {
	if(isFull(queue))
		return;
	int len = strlen(str);
	queue->array[queue->back] = malloc(len);
	strcpy(queue->array[queue->back], str);
	queue->back++;
	queue->size++;
}

// Dequeus a string from a queue (assuming it is not empty)
char * Dequeue(Queue * queue) {
	int len = strlen(queue->array[queue->front]);
	char * str = malloc(len);
	strcpy(str, queue->array[queue->front]);
	free(queue->array[queue->front]);
	queue->front++;
	queue->size--;
	if(isEmpty(queue))
		queue->front = queue->size = queue->back = 0;
	return str;
}

// Prints the queue
void PrintQueue(Queue * queue) {
	int i;
	printf("Printing queue %p\n", queue);
	printf("\tThe index for the front of the queue is %d\n", queue->front);
	printf("\tThe index for the back of the queue is %d\n", queue->back);
	if(queue->front == queue->back) {
		printf("\tThe queue is empty.\n");
		return;
	}
	int back = queue->back;
	if(queue->back < queue->front) {
		// wrapped around, so modify indexing
		back += QUEUE_SIZE;
	}

	for(i = queue->front; i < back; i++) {
		printf("\t\tEntry[%d] = \"%s\"\n", i % QUEUE_SIZE, queue->array[i % QUEUE_SIZE]);
	}
}

char * NewString(char * s) {
	int len = strlen(s);
	char * rv = malloc(len);
	strcpy(rv, s);
	rv[len - 1] ='\0';
	return rv;
}


int main(int argc, char * argv[]) {
	Queue q;
	InitializeQueue(&q);
	PrintQueue(&q);
	Enqueue(&q, "hello");
	PrintQueue(&q);
	Enqueue(&q, "world");
	PrintQueue(&q);
	printf("Dequeue: %s\n", Dequeue(&q));
	PrintQueue(&q);
	return 0;
}

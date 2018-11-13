#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 10

typedef struct {
	char ** data;
	int head, tail, count;
} Queue;

void InitializeQueue(Queue * queue) {
	queue = malloc(sizeof(Queue));
	queue->data = malloc(sizeof(char *) * QUEUE_SIZE);
	queue->head = 0;
	queue->tail = -1;
	queue->count = 0;
}



int main() {
	Queue q;
	InitializeQueue(&q);
	return 0;
}

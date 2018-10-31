#include <stdio.h>
#include "Library.h"

int main() {
	Queue * queue = mallocQueue();
	enqueue(queue, 100);
	enqueue(queue, 90);
	enqueue(queue, 80);
	enqueue(queue, 70);
	enqueue(queue, 60);
	enqueue(queue, 50);
	enqueue(queue, 40);
	enqueue(queue, 30);
	enqueue(queue, 20);
	enqueue(queue, 10);
	
	Node * current = queue->tail;
	while(current->next != NULL && current != NULL) {
		printf("%ld -> ", current->value);
		current = current->next;
	}
	printf("%ld\n", current->value);
}

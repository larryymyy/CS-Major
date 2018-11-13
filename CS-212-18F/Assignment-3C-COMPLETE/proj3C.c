#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 16
#define MAX_STRING_SIZE 32

typedef struct {
	int front, back; // Indeces of the start and end of the queue
	int size;        // Number of items in the queue
	char array[MAX_QUEUE_SIZE][MAX_STRING_SIZE]; // Array to hold data members
} Queue;

// Queue constructor
void InitializeQueue(Queue * queue) {
	// Initially empty queue
	memset(queue->array, '\0', MAX_QUEUE_SIZE * MAX_STRING_SIZE);
	queue->front = -1;
	queue->back = -1;
	queue->size = MAX_QUEUE_SIZE;
}

// Determines whether the queue is empty
int isEmpty(Queue * queue) {
	return queue->front == -1;
}

// Enqueues a string into a queue (assuming there is enough space for it)
void Enqueue(Queue * queue, char * str) {
	// Queue is full
	if((queue->front == 0 && queue->back == MAX_QUEUE_SIZE - 1) ||
	   (queue->back == (queue->front - 1) % (MAX_QUEUE_SIZE - 1))) {
		return;
	}

	// Inserting the first element
	else if(queue->front == -1) { queue->front = queue->back = 0; }

	// Wrap around
	else if(queue->back == MAX_QUEUE_SIZE - 1 && queue->front != 0) { queue->back = 0; }

	// Normal Enqueue
	else { queue->back++; }
	strcpy(queue->array[queue->back], str);
}

// Dequeus a string from a queue (assuming it is not empty)
void Dequeue(Queue * queue, char * dest) {
	// Queue is empty
	if(queue->front == -1) { memset(dest, 0, MAX_STRING_SIZE); }

	strcpy(dest, queue->array[queue->front]);
	memset(queue->array, 0, MAX_STRING_SIZE);

	// Queue is now empty
	if(queue->front == queue->back) { queue->front = queue->back = -1; }

	// Wrap around
	else if(queue->front == MAX_QUEUE_SIZE - 1) { queue->front = 0; }

	// Normal Dequeue
	else { queue->front++; }
}

void PrettyPrintQueue(Queue * queue, char * type) {
	if(strcmp(queue->array[queue->front], "") == 0) {
		printf("No unmatched entries for %s\n", type);
	} else {
		printf("Unmatched %s:\n", type);
		char * s = malloc(MAX_STRING_SIZE);
		Dequeue(queue, s);
		while(strlen(s) > 0) {
			printf("\t%s\n", s);
			Dequeue(queue, s);
		}
	}
}

int main(int argc, char * argv[]) {

	if(argc != 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	FILE * file = fopen(argv[1], "r");
	if(file == NULL) {
		fprintf(stderr, "ERROR: could not open file \"%s\" for reading.\n", argv[1]);
	}

	// Various Queues needed for the applications
	Queue f_donors,
		  f_recipients,
		  m_donors,
		  m_recipients,
		  hospitals;

	InitializeQueue(&f_donors);
	InitializeQueue(&f_recipients);
	InitializeQueue(&m_donors);
	InitializeQueue(&m_recipients);
	InitializeQueue(&hospitals);

	char * line = malloc(MAX_STRING_SIZE);
	char * donor = malloc(MAX_STRING_SIZE);
	char * recipient = malloc(MAX_STRING_SIZE);
	char * hospital = malloc(MAX_STRING_SIZE);
	while(fgets(line, MAX_STRING_SIZE, file) != NULL) {
		line[strlen(line) - 1] = '\0';
		switch(line[0]) {
			case 'D':
				switch(line[2]) {
					case 'F':
						Enqueue(&f_donors, line + 4);
						break;
					default:
						Enqueue(&m_donors, line + 4);
						break;
				}
				break;
			case 'R':
				switch(line[2]) {
					case 'F':
						Enqueue(&f_recipients, line + 4);
						break;
					default:
						Enqueue(&m_recipients, line + 4);
						break;
				}
				break;
			case 'H':
				Enqueue(&hospitals, line + 2);
				break;
		}
		if(!isEmpty(&hospitals)) {
			if(!isEmpty(&f_donors) && !isEmpty(&f_recipients)) {
				Dequeue(&f_donors, donor);
				Dequeue(&f_recipients, recipient);
				Dequeue(&hospitals, hospital);
				printf("MATCH: %s donates to %s at hospital %s\n", donor, recipient, hospital);
			} else if(!isEmpty(&m_donors) && !isEmpty(&m_recipients)) {
				Dequeue(&m_donors, donor);
				Dequeue(&m_recipients, recipient);
				Dequeue(&hospitals, hospital);
				printf("MATCH: %s donates to %s at hospital %s\n", donor, recipient, hospital);
			}
		}

	}


	PrettyPrintQueue(&f_donors, "female donors");
	PrettyPrintQueue(&f_recipients, "female recipients");
	PrettyPrintQueue(&m_donors, "male donors");
	PrettyPrintQueue(&m_recipients, "male recipients");
	PrettyPrintQueue(&hospitals, "hospitals");

	// Free the strings used
	free(line);
	free(donor);
	free(recipient);
	free(hospital);

	fclose(file);
	return 0;
}

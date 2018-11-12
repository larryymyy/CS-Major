#include <stdio.h>
#include <stdlib.h>

/* ==== START STRUCTS ==== */
typedef struct Node Node;
struct Node {
	void * data;
	Node * next;
};

typedef struct {
	Node * top;
} Stack;
/* ====  END STRUCTS  ==== */



/* ==== START PROTOTYPES ==== */
Node * init_node(void * data);                 /* Creates a new node */
void free_node(Node * node);                   /* Frees the memory used by a Node */

/* Our stack will not be limited by the software */
/* It is effectively an infinite stack, bounded by memory restrictions */
Stack * init_stack();                          /* Create a new stack */
void push(Stack * stack, void * data);         /* Pushes a value onto the top of a stack */
void * pop(Stack * stack);                     /* Pops a value off of a stack */
int is_empty(Stack * stack);                   /* Determines if a stack is empty */
void free_stack(Stack * stack);                /* Frees the memory used by a stack (frees ALL nodes contained in stack) */

void parse_int(char * str, int * dest);        /* Parses an integer from a character string (Error checks) */
void parse_operation(char * str, char * dest); /* Parses an arithmetic operation from a character string (Error checks) */
/* ====  END PROTOTYPES  ==== */



/* ==== START MAIN ==== */
int main(int argc, char * argv[]) {

	/* If the user does not provide an expression, it is impossible to evaluate anything */
	/* Alert the user and exit with failure code */
	if(argc < 2) {
		fprintf(stderr, "Usage: %s [RPN Expression]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	Stack * stack = init_stack();
	push(stack, (void *)(10));

	/* If execution reaches this point, all is well and we can exit with a success code */
	return EXIT_SUCCESS;
}
/* ====  END MAIN  ==== */



/* ==== START METHOD DEFINITIONS ==== */
Node * init_node(void * data) {

}

Stack * init_stack() {
	Stack * stack = malloc(sizeof(Stack));
	stack->top = NULL;
	return stack;
}

void push(Stack * stack, void * data) {
	if(stack->top == NULL) {
		stack->top = init_node(data);
		return;
	}
	Node * temp = stack->top;
	stack->top = init_node(data);
	stack->top->next = temp;
	return;
}

/* ====  END METHOD DEFINITIONS  ==== */

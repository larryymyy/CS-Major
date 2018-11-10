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
Node * init_node(void * data);
void free_node(Node * node);

Stack * init_stack();
void push(Stack * stack, void * data);
void * pop(Stack * stack);
void * peek(Stack * stack);
int is_empty(Stack * stack);
void free_stack(Stack * stack);

void parse_int(char * str, int * dest);
void parse_operation(char * str, char * dest);
/* ====  END PROTOTYPES  ==== */



/* ==== START MAIN ==== */
int main(int argc, char * argv[]) {

	return EXIT_SUCCESS;
}
/* ====  END MAIN  ==== */



/* ==== START METHOD DEFINITIONS ==== */
void parse_int(char * str, int * dest) {

}

void parse_operation(char * str, char * dest) {

}
/* ====  END METHOD DEFINITIONS  ==== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	void * data;
	int top;
	int max_size;
	size_t member_size;
} Stack;

/* Create a new stack, given a member size and maximum number of elements */
Stack * create_stack(size_t member_size, int max_size) {
	Stack * stack = malloc(sizeof(Stack));
	stack->top = -1;
	stack->member_size = member_size;
	stack->max_size = max_size;
	stack->data = malloc(max_size * member_size);
	memset((char *)stack->data, 0, max_size * member_size);
	return stack;
}

/* Push a value onto a stack, assuming there is space for it */
int push(Stack * stack, void * value) {
	if(stack->top == stack->max_size) {
		return 0;
	}
	stack->top++;
	void * target = (char *)stack->data + (stack->top * stack->member_size);
	memcpy(target, value, stack->member_size);
	return 1;
}

/* Pop a value of the top of a stack, assuming stack is not empty */
int pop(Stack * stack, void * dest) {
	if(stack->top == -1) {
		memset((char * )dest, 0, stack->member_size);
		return 0;
	}
	void * src = (char *)stack->data + (stack->top * stack->member_size);
	stack->top--;
	memcpy(dest, src, stack->member_size);
	return 1;
}


/* Free the memory used by the stack */
int free_stack(Stack * stack) {
	free(stack->data);
	free(stack);
	return 1;
}


/* Operate on the next two values in the stack, given an operation, and put the result on the top of the stack */
void operate(Stack * stack, char operation) {
	if(stack->top < 1) {
		fprintf(stderr, "Invalid Expression!\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	int val1, val2, result;
	pop(stack, (void *)&val2);
	pop(stack, (void *)&val1);

	switch(operation) {
		case '+':
			result = val1 + val2;
			push(stack, (void *)&result);
			break;
		case '-':
			result = val1 - val2;
			push(stack, (void *)&result);
			break;
		case 'x':
			result = val1 * val2;
			push(stack, (void *)&result);
			break;
		default:
			fprintf(stderr, "Invalid Operator: %c\n", operation);
			exit(EXIT_FAILURE);
	}
}

void parse(char * src, int * dest) {
	int i = 0;
	*dest = 0;
	if(src[0] == '-')
		i++;
	char current = src[i++];
	while(1) {
		if(current == '\0')
			break;
		else if(current - '0' > 9 || current - '0' < 0) {
			fprintf(stderr, "ERROR: number %s has character that is outside 0-9\n", src);
			exit(EXIT_FAILURE);
		} else if((src[0] == '-' && i > 10) ||
				  (src[0] != '-' && i > 9)) {
			fprintf(stderr, "ERROR: number %s has 10 or more digits\n", src);
			exit(EXIT_FAILURE);
		}
		*dest *= 10;
		*dest += (current - '0');
		current = src[i++];
	}
	if(src[0] == '-')
		*dest *= -1;
}

char is_valid_operator(char test) {
	return test == '-' || test == '+' || test == 'x';
}

int main(int argc, char * argv[]) {

	/* If the user does not provide an expression, it is impossible to evaluate anything */
	/* Alert the user and exit with failure code */
	if(argc < 2) {
		fprintf(stderr, "Usage: %s [RPN Expression]\n", argv[0]);
		exit(EXIT_FAILURE);
	}


	/* Create a stack to hold the results of the expression */
	Stack * stack = create_stack(sizeof(int), 10);

	for(int i = 1; i < argc; i++) {
		char * to_parse = argv[i];
		if(to_parse[1] == '\0' && is_valid_operator(to_parse[0]))
			operate(stack, to_parse[0]);
		else {
			int val;
			parse(to_parse, &val);
			push(stack, (void *)&val);
		}
	}

	int result;
	if(stack->top == 0) {
		pop(stack, (void *)&result);
		printf("The total is %d\n", result);
	} else {
		fprintf(stderr, "ERROR: Not enough operations provided!\n");
		exit(EXIT_FAILURE);
	}

	free_stack(stack);

	/* If execution reaches this point, all is well and we can exit with a success code */
	return EXIT_SUCCESS;
}

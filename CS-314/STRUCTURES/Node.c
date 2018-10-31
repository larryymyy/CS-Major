# include "Library.h"

Node * mallocNode(long value, Node * parent) {
	Node * newNode = malloc(sizeof(Node));
	if(parent != NULL) {
		parent->next = newNode;
	}
	newNode->value = value;
	return newNode;
}

void freeNode(Node * node) {
	free(node);
}

void freeNodeChain(Node * root) {
	if(root == NULL)
		return;
	Node * next = root->next;
	root->next = NULL;
	freeNode(root);
	freeNodeChain(next);
}

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *new(int num) {
	struct node *n = malloc(size(struct node));
	if (n== NULL)
		return NULL;

	n->data = num;
	n->next = NULL;

	return n;
}

void main(){
	struct node *first, *second, *third;
	first=new(10);
	second=new(20);
	third=new(30);

	first->next = second;
	second->next = third;
	third->next = NULL;

	
}



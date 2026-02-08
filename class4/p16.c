#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

int main(){
	struct node *node1;
	node1->data = 1;

	struct node *node2;
	node2->data = 2;

	struct node *node3;
	node3->data = 3;

	return 0;
}

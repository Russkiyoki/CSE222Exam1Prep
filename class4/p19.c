#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

int main(){
	struct node *node1;
	node1=malloc(sizeof(struct node));
	node1->data = 1;

	struct node *node2;
	node2=malloc(sizeof(struct node));
	node2->data = 2;

	struct node *node3;
	node3=malloc(sizeof(struct node));
	node3->data = 3;

	node1->next=node2;
	node2->next=node3;
	node3->next=node1;

	struct node *temp;
	temp=node1;

	printf("%d \n", temp->data);
	printf("%d \n", temp->next->data);
	printf("%d \n", temp->next->next->data);
	printf("%d \n", temp->next->next->next->data);

	free(node1);
	free(node2);
	free(node3);

	return 0;
}

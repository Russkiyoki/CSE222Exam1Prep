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
	node3->next=NULL;

	struct node *temp;
	temp=node1;

	while(temp!= NULL){
		printf("data=%d\n", temp->data);
		temp=temp->next;
	}

	free(node1);
	free(node2);
	free(node3);

	return 0;
}

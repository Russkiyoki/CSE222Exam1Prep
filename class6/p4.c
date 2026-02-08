#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
	int data;
	struct node *next;
};

void print(struct node*);

struct node *new(int num) {
	struct node *n = malloc(sizeof(struct node));
	if (n== NULL)
		return NULL;

	n->data = num;
	n->next = NULL;

	return n;
}

int main(){
	struct node *first, *second, *third;
	first=new(10);
	second=new(20);
	third=new(30);
	

	first->next = second;
	second->next = third;
	third->next = NULL;


	print(first);

	free(first);
	free(second);
	free(third);
	
	return 0;	
}
void print(struct node *first){
	struct node *temp=first;
	while(temp!=NULL){
                printf("data=%d\n", temp->data);
		temp=temp->next;
        }
}


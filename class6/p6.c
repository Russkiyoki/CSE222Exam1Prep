#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct node{
	int data;
	struct node *next;
};

void print(struct node*);
void add(struct node *firstnode, int num);
struct node *init();

struct node *new(int num) {
	struct node *n = malloc(sizeof(struct node));
	if (n== NULL)
		return NULL;

	n->data = num;
	n->next = NULL;

	return n;
}

struct node *init(){
	struct node *n = malloc(sizeof(struct node));
	n->data = 0;
	n->next = NULL;

	return n;
}

int main(){
	struct node *first=init();
	add(first,10);
	add(first,30);
	add(first,50);
	add(first,40);
	add(first,20);
	print(first);	
	
	free(first);
	
	return 0;	
}
void print(struct node *first){
	struct node *temp=first;
	while(temp!=NULL){
                printf("data=%d\n", temp->data);
		temp=temp->next;
        }
}

void add(struct node *firstnode, int num){
	struct node *temp=new(num);
	temp->next = firstnode->next;
	firstnode->next=temp;
}




#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *next;
};
struct node *top = NULL;

void insert(int num){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->value = num;
	if(top==NULL){
		top = newNode;
		top->next = NULL;
	}
	else{
		newNode->next = top;
		top = newNode;
	}
}
void delete(){
	struct node *temp = top;
	if(top==NULL){
		printf("Cannot delete");
	}
	else{
		top = top->next;
		free(temp);
		
	}
}
void display(){
	struct node *curr = top;
	if(top==NULL){
		printf("Stack empty");
	}
	else{
		while(curr!=NULL){
			printf("%d ", curr->value);
			curr = curr->next;
		}
		printf("\n");
	}
}
int main(){
	insert(1);
	insert(2);
	insert(3);
	insert(10);
	display();
	delete();
	display();
	printf("%d",top->value);
	return 0;
}

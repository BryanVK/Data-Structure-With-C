#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *next;
	struct node *prev;
};
struct node *insert(struct node *head, int val){
	struct node *ptr = (struct node*)malloc(sizeof(struct node));
	if(head==NULL){
		head->val = val;
		head->next = NULL;
	}
	else{
		ptr->val = val;
		head->prev = ptr;
		head = ptr;
		}
	return head;
};
int main(){
	struct node *head = NULL;
	head = insert(head,1);
	return 0;
}

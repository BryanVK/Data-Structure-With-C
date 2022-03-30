#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};

struct node *tail = NULL;

void insertTail(int num){
	struct node *newNode = (struct  node*)malloc(sizeof(struct node));
	newNode->val = num;
	if(tail==NULL){
		tail=newNode;
		tail->next = tail;
	}
	else{
		newNode->next = tail->next;
		tail->next = newNode;
		tail = newNode;
	}
}
void insertHead(int num){
	struct node *newNode = (struct  node*)malloc(sizeof(struct node));
	newNode->val = num;
	if(tail == NULL){
		tail=newNode;
		tail->next = tail;
	}
	else{
		newNode->next = tail->next;
		tail->next = newNode;
	}
}
void display(){
	struct node *curr;
	curr = tail->next;
	if(tail==NULL){
		printf("Empty\n");
	}
	else{
		while(curr!=tail){
			printf("%d ",curr->val);
			curr = curr->next;
		}
		printf("%d ",curr->val);
		printf("\n");
	}
}
//delete
void delete(int num){
	struct node *curr = tail->next;
	if(tail!=NULL){
		if(curr->val==num){
			tail->next = curr->next;
			free(curr);
		}
		else if(tail->val == num){
			while(curr->next!=tail){
				curr = curr->next;
			}
			curr->next = tail->next;
			tail = curr;
		}
		else{
			while(curr->next->val!=num){
				curr = curr->next;
			}
			struct node *temp = curr->next;
			curr->next = temp->next;
			free(temp);
		}
	}
}

int main(){
	insertTail(11);
	display();
	insertHead(5);
	display();
	insertTail(19);
	display();
	delete(11);
	display();
	
	return 0;
}

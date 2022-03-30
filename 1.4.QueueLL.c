#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node *next;
};

struct node *front=NULL, *rear=NULL;

void push(int num){
	struct node *newNode=(struct node*)malloc(sizeof(struct node));
	newNode->val = num;
	newNode->next = NULL;
	if(rear==NULL&&front==NULL){
		rear = newNode;
		front = newNode;
	}
	else{
		rear->next = newNode;
		rear = newNode;
	}
}

void pop(){
	struct node *curr = front;
	if(front==NULL&&rear==NULL){
		puts("stack is overflow");
	}
	else{
		front = curr->next;
		free(curr);
	}
}

void display(){
	struct node *curr = front;
	if(front==NULL&&rear==NULL){
		printf("Empty\n");
	}
	else{
		while(curr!=NULL){
			printf("%d -",curr->val);
			curr=curr->next;
		}
		printf("\n");
		printf("Depan: %d\n",front->val);
		printf("Belakang: %d\n\n",rear->val);
	}
}

int main(){
	int pil,num;
	while(1){
		puts("1.push");
		puts("2.pop");
		puts("3.display");
		scanf("%d",&pil);
		if(pil==1){
			scanf("%d",&num);
			push(num);
		}
		else if(pil==2){
			pop();
		}
		else if(pil==3){
			printf("\n");
			display();
			
		}
	}

	
	return 0;
}

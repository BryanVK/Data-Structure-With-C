#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 5

int queue[MAX];
int rear=-1, front=-1; //dalam array untuk nandain kosong pake -1 bkn NULL

bool isfull(){
	if(rear == MAX-1){       //cek apakah queue full?
		return true;
	}
	else{
		return false;
	}
}
bool isempty(){
	if(front ==-1 || front>rear){
		return true;
	}
	return false;
}

void enqueue(int num){
	
	if(isfull()){
		printf("FULL\n");
	}
	else{
		if(front==-1 && rear ==-1){ //enqueue data pertama
			front++;
			rear++;
		}
		else{  //enqueu data beikutnya 
			rear++;
		}
		queue[rear]=num;
	}
}

//delete / dequeue
void dequeue(){
	
}

void display(){
	if(isempty()){
		printf("Empty\n");
	}
	else{
		int i;
		for(i=front;i<=rear;i++){
			printf("%d -",queue[i]);
		}
		printf("\n");
	}
}

int main(){
	display();
	enqueue(1);
	enqueue(2);
	display();
	return 0;
}

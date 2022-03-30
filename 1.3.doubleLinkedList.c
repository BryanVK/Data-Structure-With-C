#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
	int age;
	char name[20];
	struct node *next; //simpan alamat data seletah
	struct node *prev; //simpan alamat data sebelumnya
};

struct node *head = NULL; // assign tail n head null karna masih kosong
struct node *tail = NULL;

struct node *createNewNode(int age, char name[]){ //fungsi untuk buat node baru 
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->age = age;
	strcpy(newNode->name, name);
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void insertHead(int age, char name[]){
	struct node *newNode = createNewNode(age, name);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}
//make your own insertTail
void insertTail(int age, char name[]){
	struct node *newNode = createNewNode(age, name);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		newNode->next = NULL;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
		
	}
}
void insertMid(int age, char name[]){
	struct node *newNode = createNewNode(age, name);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else if(age< head->age){
		insertHead(age, name);
	}
	else if(age > tail->age){
		insertTail(age,name);
	}
	else{
		struct node *curr = head;
		while(curr->next != NULL && curr->next->age <= age){
			curr = curr->next;
		}
		newNode->next = curr->next;
		curr->next->prev = newNode;
		curr->next = newNode;
		newNode->prev = curr;
	}
}
//delete head
void deleteHead(){
	struct node *curr = head;
	if(head!=NULL){
		curr->next->prev = NULL;
		head = curr->next;
		free(curr);
	}
}
//delete tail
void deleteTail(){
	struct node *curr = tail;
	if(head!=NULL){
		curr->prev->next = NULL;
		tail = curr->prev;
		free(curr);
	}
}
//delete mid
void deleteMid(char name[]){
	struct node *curr = head;
	if(head!=NULL){
		if(strcmp(head->name, name)==0){
			deleteHead();
		}
		else if(strcmp(tail->name, name)==0){
			deleteTail();
		}
		else{
			while(strcmp(name, curr->name)!=0){
				curr = curr->next;
			}
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
		    free(curr);

		}
	}
}
void printAll(){
	struct node *curr = head;
	while(curr != NULL){
		printf("[%d %s] -> ", curr->age, curr->name);
		curr = curr->next;
	}
	printf("NULL\n");
}
int main(){
	insertMid(15, "fudi");
	insertMid(11, "audi");
	insertMid(13, "budi");
	printAll();
	insertHead(19, "fuda");
	printAll();
	insertTail(10, "dufan");
	printAll();
	deleteMid("budi");
	printAll();
	deleteHead();
	printAll();
	deleteTail();
	printAll();
	return 0;
}

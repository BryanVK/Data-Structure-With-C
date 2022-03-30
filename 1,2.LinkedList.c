#include<stdio.h>
#include<stdlib.h> // wajib untuk data struktur karena kita pakai malloc 
#include<string.h>

struct node{
	int age;
	char name[20];
	struct node *next; // karena kita akan nunjuk ke node  selanjutnya yg bertipe struct node
};

struct node *head = NULL;
struct node *tail = NULL;

struct node *createNewnode(char name[], int age){
	struct node *newNode = (struct node *) malloc(sizeof(struct node)); // (struct node *) untuk typecast
	newNode->age = age;
	strcpy(newNode->name, name);
	newNode->next = NULL;
	return newNode;
}

void insertHead(char *name, int age){
	struct node *newNode = createNewnode(name, age);
	
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		newNode->next = head;
		head = newNode;
	}
}

//make insert tail function
void insertTail(char *name, int age){
	struct node *newNode = createNewnode(name, age);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		tail->next = newNode;
		tail = newNode;
	}
}

void insertMid(char *name, int age){
	struct node *newNode = createNewnode(name, age);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		struct node *curr; // curr adalah pointer penelusur 
		curr = head;
		while(curr->next != NULL && curr->next->age <= age ){ // untuk looping sealama mencari
			curr = curr->next;
		}
		//meyambungukan dengan node baru 
		newNode->next = curr->next;
		curr->next = newNode;
		// jika data lebih besar dari tail update tailnya
		if(curr == tail ){
			tail = newNode;
		}
	}
}
//make your delete head function hapus dr pertama , hapus berdasarkan  name nya 
void deleteHead(){
	struct node *curr = head;
	if(head!=NULL){
		head = curr->next;
		free(curr);
	}
}
//make delete Tail function
void deleteTail(){
	if(head != NULL){
		struct node *curr = head;
		if(head == tail){
			head = NULL;
			tail = NULL;
			free(curr);
		}
		else{
			while(curr->next != tail){
				curr = curr->next;
			}
			struct node *temp = tail;
			tail = curr;
			curr->next = NULL;
			free(temp);
		}
	}
}

/*make your own deleteMid function*/
//hint: curr punya next adalah data yang akan dihapus. bukan curr-nya
void deleteMid(char *name){
	if(head != NULL){
		
		if(strcmp(head->name, name)==0){
			deleteHead();
		}
		else if(strcmp(tail->name, name)==0){
			deleteTail();
		}
		else{
			/*bikin curr nya mulai dari head*/
			struct node *curr = head;
			while(curr->next != NULL && strcmp(curr->next->name, name) != 0){
				curr = curr->next;
			}
			
			if(curr->next != NULL){
				/*buat variable pointer temp utk menampung node yg mau di delete*/
				struct node *temp = curr->next;
				/*sambungkan curr ke data setelah temp*/
				curr->next = temp->next;
				/*bebaskan temp nya*/
				free(temp);
			}
			
		}
		
	}
}

void printAll(){
	struct node *curr = head;
	while(curr!= NULL){
		printf("[%d %s] -> ", curr->age, curr->name);
		curr = curr->next;
	}
	printf("NULL\n");
}

int main(){
	insertMid("Budi", 5);
	printAll();
	insertMid("Sisi", 7);
	printAll();
	insertMid("Desi", 6);
	printAll();
	insertMid("Cika", 10);
	printAll();
	puts("");
	insertMid("Ciko", 9);   // test insert in middle
	printAll();
	puts("");
	insertHead("Bryan", 1); // test insert in head
	printAll();
	puts("");
	insertTail("Zoro", 11); // test insert in tail
	printAll();
	puts("");
	deleteHead();// test delete in head
	printAll();
	puts("");
	deleteTail();// test delete in tail
	printAll();
	puts("");
	deleteMid("Desi");  // test insert in middle
	printAll();
	return 0;
}

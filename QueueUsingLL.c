#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int y){
	struct node *newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode->data = y;
	newnode->next = NULL;
	
	if(front==NULL && rear==NULL){
		front=rear=newnode;
	}
	else{
		rear->next = newnode;
		rear=newnode;
	}
}

void display(){
	struct node *temp;
	if(front==NULL && rear==NULL){
		printf("\n Underflow !!!");
	}
	else{
		printf("\n");
		temp = front;
		while(temp!=NULL){
			printf(" %d ",temp->data);
			temp = temp->next;
		}
	}
	
}

void dequeue(){
	struct node *temp;
	temp = front;
	if(front==NULL && rear == NULL){
		printf("\n Unnderflow!!! \n");
	}
	else{
		front = front->next;
		free(temp);
	}
}

void peek(){
	if(front==NULL && rear==NULL){
		printf("\n Underflow \n");
	}
	else{
		printf("\n %d ",front->data);
	}
}


int main()
{
	enqueue(5);
	enqueue(0);
	enqueue(-3);
	display();
	dequeue();
	peek();	
	display();
	
	return 0;
}

#include<stdio.h>
#define N 5

int queue[N];
int front= -1;
int rear = -1;

void enqueue(int z){
	int i ;
	if(rear==-1){
		front=rear=0;
		queue[rear]=z;
	}
	else if(((rear+1)%N)==front){
		printf("\n Queue is Full !!!");
	}
	else{
		rear = (rear+1)%N;
		queue[rear]=z;
		//printf("\n\t %d",rear);
	}
}

void dequeue(){
	if(front==-1 && rear ==-1){
		printf("\n Queue is empty !!!");
	}
	else if(front==rear){
		front = rear =-1;
	}
	else{
		front = (front+1)%N;
	}
}

void display(){
	int i;
	if(front==-1 && rear ==-1){
		printf("\n Queue is empty !!");
	}
	else{
		 i = front;
		printf("\n");
		do{
			printf(" %d ",queue[i]);
			i = (i+1)%N;
		}while(i!=rear);
		printf(" %d ",queue[rear]);
		}
	}

void peek(){
	if(front==rear){
		printf("\n Queue is empty !!!");
	}
	else{
		printf("\n %d",queue[front]);
	}
}

int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	display();
	dequeue();
	enqueue(6);
	peek();
	display();
	enqueue(7);
	dequeue();
	dequeue();
	enqueue(2);
	display();
	peek();
	return 0;
}

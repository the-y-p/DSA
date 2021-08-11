#include<stdio.h>

#define N 5
int i =0;
int queue[N];
int front,rear = -1;

void enqueue(int x){
	if (rear==N-1){
		printf("\n Overflow !!!\n");
	}
	else if(front==-1 && rear==-1){
		front=rear=0;
		queue[rear]=x;
	}
	else{
		rear++;
		queue[rear]=x;
	}
}

void dequeue(){
	if(front==-1 && rear==-1){
		printf("\n Underflow !!!\n");
	}
	else if(front==rear){
		front=rear=-1;
	}
	else{
		front++; 
	}
}

void display(){
	if(front==-1 && rear==-1){
		printf("\n Underflow!!!\n");
	}
	else{
		printf("\n");
		for(i=front;i<rear+1;i++){
			printf(" %d ",queue[i]);
		}
	}
}
void peek(){
	if (front==-1 &&rear==-1){
		printf("\n Underflow !!!\n");
	}
	else{
		printf("\n %d ",queue[front]);
	}
}

int main()
{
	enqueue(2);
	enqueue(5);
	enqueue(-1);
	display();
	peek();
	dequeue();
	peek();
	display();
	
	return 0;
}

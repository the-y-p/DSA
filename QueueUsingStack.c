#include<stdio.h>
#define N 5
int s1[N],s2[N];
int top1=-1, top2=-1,count=0;

void push1(int data){
	if(top1==N-1){
		printf("\n Overflow!!!");
	}
	else{
		top1++;
		s1[top1]=data;
	}
}

void push2(int data){
	if(top2==N-1){
		printf("\n Overflow!!!");
	}
	else{
		top2++;
		s2[top2]=data;
	}
}

int pop1(){
	return s1[top1--];
}

int pop2(){
	return s2[top2--];
}


void enqueue(int x){
	push1(x);
	count++;
}

void dequeue(){
	int i,a,b;
	if(top1==-1&&top2==-1){
		printf("\n Underflow!!!");
	}
	for(i=0;i<count;i++){
		a = pop1();
		push2(a);
	}
	b = pop2();
	count--;
	for(i=0;i<count;i++){
		a = pop2();
		push1(a);
	}
}

void display(){
	int i =0;
	printf("\n");
	if(top1==-1&&top2==-1){
		printf("\n Underflow!!!");
	}
	else if(top1==N){
		printf("\n Overflow!!!");
	}
	else{
		for(i=0;i<=top1;i++){
			printf(" %d ",s1[i]);
		}
		
	}
}

int main(){
	enqueue(5);
	enqueue(4);
	enqueue(3);
	enqueue(2);
	display();
	dequeue();
	display();
	enqueue(1);
	enqueue(7);
	display();
	enqueue(8);	
	return 0;
}




//stack implementation using array 
#define N 5
int stack[N];
int top = -1;
#include<stdio.h>



void push(){
	int x;
	printf("\n Enter the data : ");
	scanf("%d",&x);
	if(top==N-1){
		printf("\n Overflow !!!");
	}
	else{
		top++;
		stack[top]=x;
	}
}

void pop(){
	int item;
	if(top==-1){
		printf("\n Underflow !!!");
	}
	else{
		item = stack[top];
		top--;
	}
	
}

void peek(){
	if(top==-1){
		printf("\n Stack is empty !!!");
	}
	else{
		printf("\n %d ",stack[top]);
	}
}

void display(){
	int i;
	for (i = top ;i>=0;i--){
		printf(" %d ",stack[i]);
	}
}

int main(){
	int ch=1,c;
	while(ch){
	printf("\n 1. Push \n 2. Pop \n 3. Peek \n 4. Display \n Enter choice : ");
	scanf("%d",&c);
	switch(c){
		case 1 : push();break;
		case 2 : pop();break;
		case 3 : peek();break;
		case 4 : display();break;
	}	
	printf("\n Do you want to continue operations on stack (1/0): ");
	scanf("%d",&ch);
	}	
}














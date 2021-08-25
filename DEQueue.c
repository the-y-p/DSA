#include<stdio.h>
#define N 5
int deque[N];
int f=-1, r=-1;

void enqueuefront(int x){
	if((f==0 && r == N-1)||(f==r+1)){
		printf("\n Queue is full !!");
	}
	else if(f==-1 && r ==-1){
		//printf("\n Queue is Empty !!");
		f=r=0;
		deque[f]=x;
	}
	else if(f==0){
		f=N-1;
		deque[f]=x;
	}
	else{
		f--;
		deque[f]=x;
	}
}

void enqueuerear(int x){
	if((f==0 && r == N-1)||(f==r+1)){
		printf("\n Queue is full !!");
	}
	else if(f==-1 && r ==-1){
		printf("\n Queue is Empty !!!");
		f=r=0;
		deque[r]=x;
	}
	else if(r==N-1){
		r = 0;
		deque[r]=x;
	}
	else{
		r++;
		deque[r]=x;
	}
}
void display(){
	int i = f;
	printf("\n");
	while(i!=r){
		printf(" %d ",deque[i]);
		i = (i+1)%N;
	}
	printf(" %d ",deque[i]);
}

void getfront(){
	printf("\n F :  %d ",deque[f]);
}

void getrear(){
	printf("\n R :  %d ",deque[r]);
}

void dequeuefront(){
	if(f==-1 && r==-1){
		printf("\n Queue is empty !!!");
	}
	else if(f==r){
		f=r=-1;
	}
	else if(f==N-1){
		f = 0;
	}
	else{
		f++;
	}
}

void dequeuerear(){
	if(f==-1 && r==-1){
		printf("\n Queue is empty !!!");
	}
	else if(f==r){
		f=r=-1;
	}
	else if(r==0){
		r = N-1;
	}
	else{
		r--;
	}
}


int main(){
	enqueuefront(1);
	enqueuefront(2);
	enqueuerear(5);
	enqueuerear(4);
	dequeuerear();
	enqueuefront(0);
	display();
	enqueuerear(6);
	getfront();
	getrear();
	display();
}

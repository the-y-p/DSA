#include<stdio.h>
int a[10],size,i=0,num,pos,ch;
void insert(int,int);
void del(int);
void print();
int main()
{
	int index,temp;
	printf("\nEnter the size of array  : ");
	scanf("%d",&size);
	printf("\nEnter the elements of array : ");
	for (i =0 ;i<size;i++)
	{
		scanf("%d",&a[i]);
	} 
	
	printf("\n1.Print elements \n2.Insertion \n3.Deletion \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1 : print(); break;
		
		case 2 : //Inserting at specific position
				printf("\nEnter the Number : ");
				scanf("%d",&num);
				printf("\nEnter the position : ");
				scanf("%d",&pos); 
				insert(num,pos);
				break;
		case 3 : //Deletion of number by index
				printf("\n Enter the index Number you want to delete: ");
				scanf("%d",&index);
				if (index<=0 || index >=size){
					printf("Invalid index!!!!");
				}
				else{
					del(index);
				}
				break;
	}
	
	return 0;
	
}
void print(){
	printf("Elements of array are :\n");
	for (i =0 ;i<size;i++)
	{
		printf("%d \t",a[i]);
	}
	}

void insert(num,pos){
		if (pos<=0 || pos>size+1){
		printf("Invalid Position !!!!");	
	}
	else{
			for (i=size-1;i>=pos-1;i--){
			a[i+1] = a[i];
			}
			a[pos-1] = num;
			size++;
			print();
		}
	
	}
	
void del(index){
		for(i = index-1;i<=size-1;i++){
			a[i]=a[i+1];
		}
		size--;
		print();
	}


#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *prev;
	struct node *next;
}*head,*tail,*temp,*newnode;

void create(){
	int ch=1;
	head = tail = NULL;
	while(ch){
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\n Enter the data : ");
	scanf("%d",&newnode->data);
	if(head==NULL){
		head=tail=newnode;
		tail->next = head->prev = newnode;
	}
	else{
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
		newnode->next = head;
		head->prev = tail;
	}
	
	printf("\n Do you want to insert again ? (0/1) : ");
	scanf("%d",&ch);
	}
}

void display(){
	int l;
	temp = head;
	if(head==NULL){
		printf("\n DCLL is empty !!!");
	}
	else{
	do{
		printf(" %d ",temp->data);
		temp = temp->next;
	}while(temp!=tail);
	printf(" %d ",temp->data);
	}
	l = getlen();
	printf("\n %d ",l);
}

void insertatbeg(){
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\n Enter the Data : ");
	scanf("%d",&newnode->data);
	if(head==NULL){
		head = tail = newnode;
		head->prev = tail->next = newnode;
	}
	else{
		newnode->next = head;
		head->prev = newnode;
		newnode->prev = tail;
		tail->next = newnode;
		head = newnode;
	}
}

void insertatend(){
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\n Enter the Data : ");
	scanf("%d",&newnode->data);
	if(head == NULL){
		head = tail = newnode;
		head->prev = tail->next = newnode;
	}
	else{
		newnode->prev = tail;
		tail->next = newnode;
		newnode->next = head;
		tail = newnode;
		head->prev = tail;
	}
}

void insertatpos(){
	int i=1,pos,len;
	printf("\n Enter the position : ");
	scanf("%d",&pos);
	len = getlen();
	if(pos == len+1){
		insertatend();
	}
	else if(pos == 1){
		insertatbeg();
	}
	else if(pos<1 || pos>len){
		printf("\n Invalid Position !!!");
	}
	else{
		temp = head;
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("\n Enter the data : ");
		scanf("%d",&newnode->data);
		while(i<pos-1){
			temp = temp->next;
			i++;
		}
		newnode->prev = temp;
		newnode->next = temp->next;
		temp->next->prev = newnode;
		temp->next = newnode;
	}
}

void delfrombeg(){
	temp = head;
	if(head==NULL){
		printf("\n DCLL is empty !!!");
	}
	else if(head->next = tail){
		head = tail = NULL;
		free(temp);
	}
	else{
		head = head->next;
		head->prev = tail;
		tail->next = head;
		free(temp);
	}
}

void delfromend(){
	temp = tail;
	if(head==NULL){
		printf("\n DCLL is empty !!!");
	}
	else if(head->next = tail){
		head = tail = NULL;
		free(temp);
	}
	else{
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
		free(temp); 
	}
}

void delfrompos(){
	int i=1,pos,len;
	printf("\n Enter the position : ");
	scanf("%d",&pos);
	len = getlen();
	if(pos == len){
		delfromend();
	}
	else if(pos == 1){
		delfrombeg();
	}
	else if(pos<1 || pos>len){
		printf("\n Invalid Position !!!");
	}
	else{
		while(i<pos){
			temp = temp->next;
			i++;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp); 
	}
}


int getlen(){
	int len=0;
	temp = head;
	if (head==NULL){
		return len;
	}
	else{
		while(temp!=tail){
			temp = temp->next;
			++len;
		}
	return (len+1);
	}
}


int main()
{
	int choice = 1,cho;
	while(choice){
		printf("\n Enter the Choice : ");
		printf("\n 1. Create \n 2. Display \n 3. Insert at beginning \n 4. Insert at end \n 5. Insert at position");
		printf("\n 6. Delete form beginning \n 7. Delete from end \n 8. Delete from position");
		printf("\n \t : ");
		scanf("%d",&cho);
		switch(cho){
			case 1 :
					create();
					break;
			case 2 :
					display();
					break;
			case 3 :
					insertatbeg();
					break;
			case 4 :
					insertatend();
					break;
			case 5 :
					insertatpos();
					break;
			case 6 :
					delfrombeg();
					break;
			case 7 :
					delfromend();
					break;
			case 8 :
					delfrompos();
					break;
			default :
				printf("\n Enter valid choice : ");
		}
		printf("\n Do you want to continue operations on Doubly Circular Linked List (0/1) : ");
		scanf("%d",&choice);
	}
	return 0;
}

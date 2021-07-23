#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head,*tail,*temp,*newnode;

int create(){
	int r = 1;
	tail = NULL;
	while(r){
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("\n Enter the Data : ");
	scanf("%d",&newnode->data);
	newnode->next =NULL;
	if (tail==NULL){
		tail = newnode;
		tail->next = newnode;
	}
	else{
			newnode->next = tail->next;
			tail->next = newnode;
			tail = newnode;
	}
	printf("\n Do you want to insert (0/1) : ");
	scanf("%d",&r);
	}
	
	
}

void display(){
	printf("\n");
	if (tail==NULL){
		printf("\n CLL is empty !!!");
	}
	else{
		temp = tail->next;
		while(temp!=tail){
			printf(" %d ",temp->data);
			temp = temp->next;
		}
		printf(" %d ",temp->data);
	}
	//printf("\t %d \t %d ",tail,tail->next->data);
}

void delfrombeg(){
	if (tail==NULL){
		printf("\n CLL is empty !!!");
	}
	else if (tail->next == tail){
		tail=NULL;
		free(tail);
	}
	else{
	temp = tail->next;
	tail->next = temp->next;
	free(temp);
	}
}

void delfromend(){
	struct node *current,*prev;
	current = tail->next;
	if (tail==NULL){
		printf("\n CLL is empty !!!");
	}
	else if (current->next == current){
		tail=NULL;
		free(current);
	}
	else{
		while(current->next != tail->next){
			prev = current;
			current = current->next;
		}
		prev->next = tail->next;
		tail = prev;
		free(current);
	}
}

void delfrompos(){
	struct node *cur,*nextnode;
	int pos,i=1,len;
	len = getlength();
	printf("\n Enter the position : ");
	scanf("%d",&pos);
	if (pos<1 || pos > len){
		printf("\n Invalid Position !!!");
	}
	else if(pos==1){
		delfrombeg();
	}
	else{
		while(i<pos-1){
			cur = cur->next;
			i++;
		}
		nextnode = cur->next;
		cur->next = nextnode->next;
		free(nextnode);
	}
	
}

int getlength(){
	int len=0;
	temp = tail->next;
	if (tail==NULL){
		len = 0;
	}
	while(temp!=tail){
		temp = temp->next;
		++len;
	}
	return (len+1);
}

void insertatbeg(){
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("\n Enter the Data : ");
	scanf("%d",&newnode->data);
	if(tail==NULL){
		tail = newnode;
		tail->next = newnode;
	}
	else{
	newnode->next = tail->next;
	tail->next = newnode;
	}
}

void insertatend(){
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("\n Enter the Data : ");
	scanf("%d",&newnode->data);
	if(tail==NULL){
		tail = newnode;
		tail->next = newnode;
	}
	else{
	newnode->next = tail->next;
	tail->next = newnode;
	tail = newnode;
	}
}

void insertatpos(){
	int pos,i=1,len;
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("\n Enter the Position : ");
	scanf("%d",&pos);
	len = getlength();
	 if (pos==len+1){
		insertatend();
	}
	else if (pos==1){
		insertatbeg();
	}
	else if(pos<1||pos>len){
		printf("\n Position is invalid !!!");
	}
	else{
		printf("\n Enter the data : ");
		scanf("%d",&newnode->data);
		temp = tail->next;
		while(i<pos-1){
			temp = temp->next;
			i++;
		}
		newnode->next = temp->next;
		temp->next = newnode;
	}
	
}


void reverse(){
	struct node *prev,*current,*nextnode;
	current = tail->next;
	nextnode = current->next;
	if(tail==0){
		printf("\n CLL is empty !!!");
	}
	else{
		while(current!=tail){
			prev = current;
			current = nextnode;
			nextnode = current->next;
			current->next = prev;
		}
		nextnode->next = tail;
		tail = nextnode;
	}
}

int main(){
	int choice = 1,cho;
	while(choice){
		printf("\n Enter the Choice : ");
		printf("\n 1.Create \n 2.Display \n 3.Insert at beginning \n 4. Insert at end \n 5. Insert at position");
		printf("\n 6. Delete form beginning \n 7. Delete from end \n 8. Delete from position");
		printf("\n 9. Reverse the Circular LinkedList \n \t : ");
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
			case 9 :
					reverse();
					break;
			default :
				printf("\n Enter valid choice : ");
		}
		printf("\n Do you want to continue operations on Doubly Linked List (0/1) : ");
		scanf("%d",&choice);
	}
	return 0;
}

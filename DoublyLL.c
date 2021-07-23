#include<stdio.h>
struct node{
	int data;
	struct node *prev;
	struct node *next;
}*newnode,*temp,*tail,*nextnode,*prevnode,*head;
int len =0;

int create(){
	int ch=1;
	head = NULL;
	while(ch){
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("Enter the Data : ");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	if (head==NULL){
		
		
		head = tail = newnode;
		newnode->prev = NULL;
		
	}
	else{
		tail->next = newnode;
		newnode->prev = tail;
		tail = newnode;
	}
	len++;
	printf("\n Do you want to insert (0/1): ");
	scanf("%d",&ch);
	}
}


int display(){
	temp = head;
	printf("\n");
	while(temp!=NULL){
		printf("\t%d  ",temp->data);
		temp = temp->next;
	}
}

int insert_at_beg(){
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\n Enter Data to insert : ");
	scanf("%d",&newnode->data);
	newnode->next = newnode->prev = NULL;
	if (head==NULL){
		head = newnode;
	}
	else{
		head->prev = newnode;
		newnode->next = head;
		head = newnode;
	}
	len++;
}

int insert_at_end(){
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\n Enter Data to insert : ");
	scanf("%d",&newnode->data);
	newnode->next = newnode->prev = NULL;
	if(tail==NULL){
		tail=newnode;
	}
	else{
		tail->next = newnode;
		newnode->next = tail;
		tail = newnode;
		tail->next = NULL;
	}
	len++;
}

int insert_at_pos(){
	int pos,i;
	temp = head;
	printf("\n Enter the Position : ");
	scanf("%d",&pos);
	if(pos<0 || pos > len){
		printf("\n Invalid Position !!!");
	}
	else if(pos==1){
		insert_at_beg();
	}
	else if(pos==len){
		insert_at_end();
	}
	else{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("\n Enter Data to insert : ");
		scanf("%d",&newnode->data);
		newnode->next = newnode->prev = NULL;
		while(i<pos-1){
			temp = temp->next;
			i++;
		}
		newnode->prev = temp;
		newnode->next = temp->next;
		temp->next = newnode;
		newnode->next->prev = newnode;
		len++;
	}
}

int insert_after_pos(){
	int pos,i;
	temp = head;
	printf("\n Enter the Position : ");
	scanf("%d",&pos);
	if(pos<0 || pos > len){
		printf("\n Invalid Position !!!");
	}
	else{
		newnode = (struct node *)malloc(sizeof(struct node));
		printf("\n Enter Data to insert : ");
		scanf("%d",&newnode->data);
		newnode->next = newnode->prev = NULL;
		while(i<pos){
			temp = temp->next;
			i++;
		}
		newnode->prev = temp;
		newnode->next = temp->next;
		temp->next = newnode;
		newnode->next->prev = newnode;
		len++;
	}
}


int del_from_beg(){
	if(head==NULL){
		printf("\n DLL is empty !!!");
	}
	else{
		temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
		len--;
	}
}

int del_from_end(){
	if(tail==NULL){
		printf("\n DLL is empty !!!");
	}
	else{
		temp = tail;
		tail = temp->prev;
		tail->next = NULL;
		free(temp);
		len--;
	}
}

int del_from_pos(){
	int pos,i=0;
	printf("\n Enter the position : ");
	scanf("%d",&pos);
	if (pos==1){
		del_from_beg();
	}
	else if(pos==len){
		del_from_end();
	}
	else{
		temp = head;
		while(i<pos){
			temp = temp->next;
			i++;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
		len--;
		
	}
}

int reverse(){
	if (head==NULL){
		printf("\n DLL is empty !!!");
	}
	else{
		temp = head;
		while(temp!= NULL){
			nextnode = temp->next;
			temp->next = temp->prev;
			temp->prev = nextnode;
			temp = nextnode;
		}
		temp = head;
		head = tail;
		tail = temp;
	}
}



int main()
{
	int choice = 1,cho;
	while(choice){
		printf("\n Enter the Choice : ");
		printf("\n 1.Create \n 2.Display \n 3.Insert at beginning \n 4. Insert at end \n 5. Insert at position");
		printf("\n 6. Insert after position \n 7. Delete form beginning \n 8. Delete from end \n 9. Delete from position");
		printf("\n 10. Reverse the Doubly LinkedList \n \t : ");
		scanf("%d",&cho);
		switch(cho){
			case 1 :
					create();
					break;
			case 2 :
					display();
					break;
			case 3 :
					insert_at_beg();
					break;
			case 4 :
					insert_at_end();
					break;
			case 5 :
					insert_at_pos();
					break;
			case 6 :
					insert_after_pos();
					break;
			case 7 :
					del_from_beg();
					break;
			case 8 :
					del_from_end();
					break;
			case 9 :
					del_from_pos();
					break;
			case 10 :
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

#include<stdio.h>
struct node{
	int data;
	struct node *next; 
};

int main()
{
	struct node *head,*newnode,*temp,*prev;
	int ch=1,n=1,choice,count=0,pos,i=0;
	
	while(n){
	printf("\n 1. Create \n 2. Insert \n 3.Print LL \n 4. Delete : \n");
	scanf("%d",&choice);
	switch(choice){
		
		case 1 ://creation of Linked List 
						
						head = 0;
			while(ch){
							
						newnode = (struct node *)malloc(sizeof(struct node));
						
						printf("\n Enter data : ");
						
						scanf("%d",&newnode->data);
						
						if (head == 0){
							head = temp = newnode;	
						}
						else{
							temp->next = newnode;
							printf(" %d ",temp->data);
							temp = newnode;
							}
						newnode->next = 0;
						printf("\n Do you want to continue 0 /1 : ");
						scanf("%d",&ch);
						count++;
				}
						
						break;
		case 2 :
				printf("\n Where to insert :\n");
				printf("1.at Beginning \n2.at End \n3.after given location \n");
				scanf("%d",&ch);
				switch(ch){
							case 1 ://at beginning
									newnode = (struct node *)malloc(sizeof(struct node));
									printf("Enter the Data : ");
									scanf("%d",&newnode->data);
									newnode->next = head;
									head = newnode;
									count++;
									break;
							case 2 ://at end
									newnode = (struct node *)malloc(sizeof(struct node));
									printf("Enter the Data : ");
									scanf("%d",&newnode->data);
									newnode->next=0;
									temp = head;
									while(temp->next!=0){
										temp = temp->next;
									}
									temp->next = newnode;
									count++;
									break;
							case 3 ://after position
									pos = 0;
									newnode = (struct node *)malloc(sizeof(struct node));
									printf("Enter the Data : ");
									scanf("%d",&newnode->data);
									newnode->next=0;
									printf("\n Enter the Position : ");
									scanf("%d",&pos);
									if (pos > count){
										printf("\n Invalid Position !!!");
									}
									else{
										temp = head;
										while(i<pos-1){
											temp = temp->next;
											i++;
										}
										newnode->next = temp->next;
										temp->next = newnode;
										count++;
									}
									break;
						}
				break;
		
		
		case 3 : 
				temp = head;
				while(temp != 0){
						printf(" %d ",temp->data);
						temp = temp->next;
					}
				break;
				
		case 4 : //Deleting the Node
				printf("\n Enter the choice : ");
				printf("\n 1. Delete at Begineeing \n 2. Delete at end \n 3. Delete at Specified position \n : ");
				scanf("%d",&ch);
				
				switch(ch){
					case 1 : //1.del at beg
							if (head==0){
								printf("LinkedList is empty !!");
								
							}
							else {
							
							temp = head;
							head = head->next;
							free(temp);
							}	
							break;
					
					case 2 : //2. Del at end
								if (head==0){
								printf("LinkedList is empty !!");
								
								}
								else{
								
								temp = head;
								while(temp->next->next!=0){
									temp = temp->next;
								}
								free(temp->next);
								temp->next = 0;
								
								}
								break;
								
					case 3 : //3.Delete at specific position
								printf("\n Enter the position : ");
								scanf("%d",&pos); i =1;
								temp = prev = head;
								while(i<pos-1){
									prev = prev->next;
									i++;
								}
								temp = prev->next;
								prev->next = temp->next;
								free(temp);
								break;
					
				}
				break;
				
	}
	printf("\n Do you want to continue to Operations on LinkedList 0 /1 : ");
	scanf("%d",&n);
	
	}
	return 0;	 	
}

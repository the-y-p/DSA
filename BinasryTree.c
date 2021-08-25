#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left,*right;
};

struct node * create(){
	int x;
	struct node * newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("\n Enter data : ");
	scanf("%d",&x);
	if(x==-1){
		return 0;
	}
	newnode->data = x;
	printf("\n Enter left child of %d : ",x);
	newnode->left = create();
	printf("\n Enter right child of %d : ",x);
	newnode->right = create();
	return newnode;
}

void preorder(struct node *root){
	if(root==0){
		return;
	}
	printf(" %d ",root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(struct node *root){
	if(root==0){
		return;
	}
	inorder(root->left);
	printf(" %d ",root->data);
	inorder(root->right);
}

void postorder(struct node *root){
	if(root==0){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf(" %d ",root->data);
}

void main(){
	int ch,y=1;
	struct node *root;
	while(y){
	printf("\n 1. Create Binary tree \n 2. Preorder \n 3. Inorder \n 4. Postorder \n \t : ");
	scanf("%d",&ch);
	switch(ch){
		case 1 : 	root = create();
					printf("\n");
					break;
		case 2 : 	printf("\n Preorder is : ");
					preorder(root);
					printf("\n");
					break;
		case 3 : 	printf("\n Inorder is : ");
					inorder(root);
					printf("\n");
					break;
		case 4 : 	printf("\n Postorder is : ");
					postorder(root);
					printf("\n");
					break;
		default : printf("\n Enter valid choice !!!");break;
	}
	printf("\n Do you want to continue ?? (1/0) : ");
	scanf("%d",&y);
	}
	
}

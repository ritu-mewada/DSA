// Inorder, Postorder and Preorder traversal in binary tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *lptr;
	struct node *rptr;
};

struct node *tree; // Head pointer
struct node *new;

// Creating the tree
struct node* insert_node(struct node *tree, int value)
{
    struct node *ptr, *parentptr;
    new=(struct node*)malloc(sizeof(struct node*));
    new->info=value;
    new->lptr=NULL;
    new->rptr=NULL;
    // If the tree is empty, inserted node will be the root node.
    if(tree==NULL)
    	tree=new;
    else
    {
		ptr=tree;
		// Comparing the values, info(current node) and value to be inserted to find proper position of insertion
    	while(ptr!=NULL)
    	{
    		parentptr=ptr;
			if(value<ptr->info)
			   ptr=ptr->lptr;
			else
			   ptr=ptr->rptr;
		}
		// Inserting new node
		if(value<parentptr->info)
		   parentptr->lptr=new;
		else
		   parentptr->rptr=new;
	}
	return tree;
} 

// Function to print Inorder traversal sequence
void inorder(struct node*tree)
{
	if(tree!=NULL)
	{
		inorder(tree->lptr);
	    printf("%d\t",tree->info);
	    inorder(tree->rptr);
	}	
}

// Function to print Preorder traversal sequence
void preorder(struct node*tree)
{
	if(tree!=NULL)
	{
		printf("%d\t",tree->info);
	    preorder(tree->lptr);
	    preorder(tree->rptr);
	}
}

// Function to print Postorder traversal sequence
void postorder(struct node*tree)
{
	if(tree!=NULL)
	{
		postorder(tree->lptr);
	    postorder(tree->rptr);
	    printf("%d\t",tree->info);
	}
}

int main()
{
	int value,choice;
	tree=NULL;
	printf(" Create tree:\n\n");
	printf(" NOTE: Enter (-9999) when you done with inserting elements.\n");
	while(1)
	{
		printf(" Insert element:");
		scanf("%d",&value);
		if(value==-9999)
		   break;
		else
		   tree=insert_node(tree,value); // Inserting the new node in tree
	}
	// Printing inorder sequence of traversal
	printf(" Sequence of elements of the tree in Inorder traversal:\n ");
	inorder(tree);
	// Printing preorder sequence of traversal
	printf("\n Sequence of elements of the tree in Preorder traversal:\n ");
	preorder(tree);
	// Printing postorder sequence of traversal
	printf("\n Sequence of elements of the tree in Postorder traversal:\n ");
	postorder(tree);
	return 0;
}

// Implementation of stake using linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};

struct node *head,*top;

void push()
{
	int val;
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element to be pused:");
	scanf("%d",&val);
	new->info=val;
	new->link=NULL; // As element is to be inserted at the end of stack
	// inserting new node
	// Stack is empty
    if(head==NULL)
        head=new;
    // Stack isn't empty
    else
        top->link=new;
    // setting top pointer of stack to new node
    top=new;
}

void pop()
{
	struct node *temp;
	// Case-1: Stack is empty
	if(head==NULL)
	{
		printf("Stack is Underflow.\n");
	}
	// Stack isn't empty
	else
	{
		temp=head;
		// Case-2: Stack with one element 
		if(head==top)
			head=top=NULL;
		// Case-3: Stack with more than one elements
		else
		{
			// traverse till next node != top
			while(temp->link != top)
				temp=temp->link;
			/* Setting top pointer to 2nd last element of the stack 
			as in stack, element is to be popped from top */ 
		    top=temp; 
		    // setting temp pointer to the last node of the stack
		    temp=temp->link; 
		    // setting link of the 2nd last node to null
		    top->link=NULL;
		}
		printf("Popped Element: %d\n",temp->info); 
		// Deleting last element of the stack
		free(temp);
	}
}

void peep()
{
	struct node *temp;
	// stack is empty
	if(head==NULL)
	{
		printf("Stack is empty.\n");
	}
	// stack isn't empty
	else
	{
		printf("Elements of stack:");
		temp=head;
		// Printing all elements of the stack
		while(temp != top->link)
		{
			printf("%d\t",temp->info);
			temp=temp->link;
		}
	}
}

int main()
{
	int choice;
	do
	{
		printf("\n\nEnter your choice:\n");
    	printf("1.  Push\n");
    	printf("2.  Pop\n");
	    printf("3.  Peep\n");
	    printf("4.  Exit\n");
	    scanf("%d",&choice);
	    switch(choice)
	    {
		    case 1:
			    push();
			    break;
		    case 2:
			    pop();
			    break;
		    case 3:
			    peep();
			    break;
		    case 4:
			    break;
		    default:
			    printf("Please, enter valid choice(1-4).\n");
			    break;
	    }
	}while(choice!=4);
	return 0;
}

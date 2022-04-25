// basic oprerations on doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *lptr;
	struct node *rptr;
};

struct node *first=NULL; // head pointer
// function prototypes
struct node *createdll(struct node*);
struct node *displaydll(struct node*);
struct node *insbeg(struct node*);
struct node *insend(struct node*);
struct node *delend(struct node*);
struct node *delbefore(struct node*);

int main()
{
	int choice;
	do
	{
	    printf("\n\n");
	    printf(" 1.  Create a doubly linked list\n");
	    printf(" 2.  Display a doubly linked list\n");
	    printf(" 3.  Insert a node at begining of doubly linked list\n");
	    printf(" 4.  Insert a node at the end of doubly linked list\n");
	    printf(" 5.  Delete a node from the end of doubly linked list\n");
	    printf(" 6.  Delete a node before specified node of doubly linked list\n");
	    printf(" 7.  Exit\n");
	    printf(" Enter your choice:");
	    scanf("%d",&choice); 
	
		switch(choice)
	    {
		    case 1:
			    first=createdll(first);
			    printf(" Doubly linked list is created successfully.\n");
			    break;
		    case 2:
			    first=displaydll(first);
			    break;
		    case 3:
			    first=insbeg(first);
			    printf(" A node has been successfully inserted at the begining of the doubly linked list.\n");
			    break;
		    case 4:
			    first=insend(first);
			    printf(" A node has been successfully inserted at the end of the doubly linked list.\n");
			    break;
		    case 5:
			    first=delend(first);
			    break;
		    case 6:
			    first=delbefore(first);
			    break;
			case 7:
				break;
			default:
				printf(" Please, Enter valid choice(1-7).\n");
				break;
	    } // End of switch statement
	}while(choice!=7); // End of do...while loop
	return 0;
}

// Create doubly linked list
struct node *createdll(struct node *first)
{
	int value;
	struct node *new,*temp;
	
	printf(" NOTE: Enter -1 to end list.\n");
	printf(" Enter data:");
	scanf("%d",&value);
	
	while(value!=-1)
	{
		new=(struct node*)malloc(sizeof(struct node*));
		if(new==NULL)
		{
			printf("Free memory is not available.");
			exit(0);
		}
		
		new->info=value;
		new->rptr=NULL;
		// Case-1: linked list is empty
		if(first==NULL)
		{
			new->lptr=NULL;
			first=new;
		}
		// Case-1: linked list is not empty
		else
		{
			temp=first;
			while(temp->rptr!=NULL) // traverse till last node 
			 temp=temp->rptr;
			temp->rptr=new;
			new->lptr=temp;
		} // End of if statement
		
		printf(" Enter data:"); // data for info part of next node
	    scanf("%d",&value);
	}  // End of while loop
	return first;
}

// Display doubly linked list
struct node *displaydll(struct node *first)
{
	struct node *temp;
	if(first==NULL)
	  printf(" Doubly linked list is empty.\n");
	else
	{
		printf(" Linked list:");
		temp=first;
		while(temp!=NULL)
		{
			printf("%d\t",temp->info);
			temp=temp->rptr;
		}
		printf("\n");
	}
	return first;
}

// Insert node at begining
struct node *insbeg(struct node *first)
{
	int value;
	struct node *new,*temp;
	
	printf(" Enter data:");
	scanf("%d",&value);
	new=(struct node*)malloc(sizeof(struct node*));
	if(new==NULL)
	{
	    printf("Free memory is not available.");
		exit(0);
	}
	
	new->info=value;
	new->lptr=NULL; // as the new node is to be inserted at the begining of linked list
	new->rptr=first; 
	if(first!=NULL) // if the linked list is not empty
	   first->lptr=new;
	first=new;
	return first;
}

// Insert node at end
struct node *insend(struct node *first)
{
	int value;
	struct node *new,*temp;
	
	printf(" Enter data:");
	scanf("%d",&value);
	new=(struct node*)malloc(sizeof(struct node*));
	if(new==NULL)
	{
	    printf("Free memory is not available.");
		exit(0);
	}
	
	new->info=value;
	new->rptr=NULL; // as the new node is to be inserted at the end of linked list
	// Case-1: linked list is empty
	if(first==NULL)
	{
		new->lptr=NULL;
		first=new;
	}
	// Case-2: linked list is not empty
	else
	{
		temp=first;
		// traverse till last node
		while(temp->rptr!=NULL)
		  temp=temp->rptr;
		// Setting right pointer of last node to new node
		temp->rptr=new;
		// Setting left pointer of new node to last node
		new->lptr=temp;
	}
	return first;
}

// Delete node from end
struct node *delend(struct node *first)
{
	struct node *temp;
	// Case-1: linked list is empty
	if(first==NULL)
	  printf(" Linked list is empty.\n");
	else
	{
		temp=first;
		// Case-2: linked list with one element
		if(first->rptr==NULL)
			first=NULL; 
		// Case-3: linked list with more then one element
		else
		{
		    while(temp->rptr!=NULL)
		        temp=temp->rptr;
		    // Setting right pointer of 2nd last node as null
		    temp->lptr->rptr=NULL;
	    }
	    // Deleting last node of the linked list
		free(temp);
		printf(" A node has been deleted successfully from the end of the doubly linked list.\n");
	}
	return first;
}

// Delete predecessor node of entered node
struct node *delbefore(struct node *first)
{
	int value;
	struct node *temp;
	// Case-1: Linked list is empty
	if(first==NULL)  //If statement-1
	  printf(" Linked list is empty.\n");
	else
	{
		printf(" Enter the node before which you want to delete node:");
	    scanf("%d",&value);
	    //Case-2: Entered value is stored in 1st node 
		if(first->info==value) // If statement-2
	        printf(" No predecessor node avilable to delete.\n");
	    else
	    {
		    temp=first;
		    // traverese till right pointer of the node is not null and info(next node) != value entered
		    while(temp->rptr!=NULL && temp->rptr->info!=value)
		        temp=temp->rptr;
		    // Case-3: Entered value is not available in the linked list
			if(temp->rptr==NULL)
		        printf(" Entered node is not found in linked list.\n");
		    //Case-4: Entered value is stored in 2nd node 
		    else if(temp==first)
		    {
			    // Setting 2nd node of the linked list as first
				first=temp->rptr;
				// Setting pointer of the 2nd node of the linked list null
			    first->lptr=NULL;
			    // Deleting first node
			    free(temp);
			    printf(" A predecessor node of the entered node has been deleted successfully.\n");
		    }
		    else
		    {
			    // Setting right pointer of the previous to previous node  to entered node
				temp->lptr->rptr=temp->rptr;
				// Setting left pointer of the entered node to previous to previous node of the entered node
			    temp->rptr->lptr=temp->lptr;
			    // Deleting the node 
		        free(temp);
		        printf(" A predecessor node of the entered node has been deleted successfully.\n");
		    } // End of ladder if statements
    	} // End of if statement-2
	}  // End of if statement-1
	return first;
}

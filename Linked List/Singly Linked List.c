// Operations on singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
// head pointer
struct node *first=NULL;
 
// prototype of functions
struct node *createsll(struct node *);
struct node *displaysll(struct node *);
struct node *insbeg(struct node *);
struct node *insend(struct node *);
struct node *insord(struct node *);
struct node *delbeg(struct node *);
struct node *delbefore(struct node *);
struct node *delafter(struct node *);

int main()
{
	int choice;
	do
	{
		printf("\n\n");
	    printf(" 1. Create a singly linked list\n");
	    printf(" 2. Display a singly linked list\n");
	    printf(" 3. Insert node at begining\n");
	    printf(" 4. Insert node at end\n");
	    printf(" 5. Insert a node in ordered linked list.\n");
	    printf(" 6. Delete first node\n");
	    printf(" 7. Delete a node before specified node\n");
	    printf(" 8. Delete a node after specified node\n");
	    printf(" 9. Exit\n");
	    printf(" Enter your choice:");
	    scanf("%d",&choice);
	    switch(choice)
	    {
		    case 1:
			    first=createsll(first);
			    printf("\n Linked list has been created sucessfully.\n");
			    break;
		    case 2:
			    first=displaysll(first);
			    break;
		    case 3:
			    first=insbeg(first);
			    printf("\n A node has been sucessfully inserted at begining.\n");
			    break;
		    case 4:
			    first=insend(first);
			    printf("\n A node has been sucessfully inserted at end.\n");
			    break;
		    case 5:
			    first=insord(first);
			    break;
		    case 6:
			    first=delbeg(first);
			    break;
		    case 7:
			    first=delbefore(first);
			    break;
		    case 8:
			    first=delafter(first);
			    break; 
			case 9:
				break;
		    default:
		    	printf(" Please, enter valid choice.(0-9)\n");
			    break;
	    }
	    // End of switch statement
	}while(choice!=9);
	// End of do...while loop
	return 0;
} 
// Create new linked list or adds more nodes in created linked list
struct node *createsll(struct node *first)
{
	struct node *new,*ptr;
	int value;
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
		if(first==NULL) 
		{
			new->link=NULL;
			first=new;
		}
		else
		{
			ptr=first;
			while(ptr->link!=NULL)
			{
				ptr=ptr->link;	
			}
			//End of while loop
			ptr->link=new;
			new->link=NULL;
		}
		//End of if...else
		printf(" Enter data:"); // data for info part of next node
	    scanf("%d",&value);
	}
	// End of while loop
	return first;
}

// Display created or updated linked list
struct node *displaysll(struct node *first)
{
	struct node *temp;
	if(first==NULL) 
	{
		printf(" Linked list is empty.\n");
	}
	else
	{
		printf("\n Linked list: ");
		temp=first;
	    while(temp != NULL)
	    {
		  printf("%d\t",temp->info); 
		  temp=temp->link; 
	    }
	    //End of while loop
	    printf("\n");
	}
	// End of if...else statement
	return first;
}

// Insert node at begining
struct node *insbeg(struct node *first)
{
	struct node *new;
	int value;
	printf(" Enter data:");
	scanf("%d",&value);
	new=(struct node*)malloc(sizeof(struct node*));
	if(new==NULL)
	{
		printf("Failed to allocate memory.\n");
		exit(0);
	}
	new->info=value; 
	new->link=first; 
	first=new;  
	return first;
}

// Insert node at end
struct node *insend(struct node *first)
{
	struct node *new,*temp; 
	int value;
	printf(" Enter data:");
	scanf("%d",&value);
	new=(struct node*)malloc(sizeof(struct node*));
	if(new==NULL)
	{
		printf("Failed to allocate memory.\n");
		exit(0);
	}
	new->info=value;
	new->link=NULL; // As link part of last node=null
	//Case-1: linked list is empty
	if(first==NULL)   
	{
		first=new;
	}
	// Case-2: linked list is not empty
	else
	{
		temp=first;
	    while(temp->link!= NULL)  // traverse till last node
	    {
		   temp=temp->link;
	    }
	    // End of while loop
	    temp->link=new;
	}
	// End of if statment
	return first;
}

// Insert element in an ordered list
struct node *insord(struct node *first)
{
	struct node *new,*temp;
	int value;
	// Case-1: linked list is empty
	if(first==NULL)
	{
		goto Y; // jumps to statements for inserting node
	}
	// Case-1: linked list is not empty
	else
	{
	    temp=first;
	    while(temp->link!=NULL) // to check linked list is in ascending order or not
	    {
		    
		    if((temp->info)>(temp->link->info)) // i.e, checks for info(node(i)) > info(node(i+1)) 
		    {
			    printf(" Please, create linked list in ascending order.\n");
			    goto X;  // jumps to return statement
		    }
		    else
		      temp=temp->link;
	    }
	    // End of while loop
    }
	//End of else statment
	Y:printf(" Enter data:");
	scanf("%d",&value);
	new=(struct node*)malloc(sizeof(struct node*));
	if(new==NULL)
	{
		printf("Failed to allocate memory.\n");
		exit(0);
	}
	new->info=value;
	// case-1:liked list is empty
	// if statement-1
	if(first==NULL) 
	{
		first=new;
		first->link=NULL;
	}
	else
	{
		// case-2:linked list with one element
		if(first->link==NULL) 
		{
			// If statement-2
			if(new->info<=first->info)
			{
				new->link=first;
				first=new;
			}
			else
			{
				first->link=new;
			    new->link=NULL;
			}
			//End of if statement-2
		}
		// case-2:linked list with more than one element
		else
		{
		    temp=first;
		    //if statement
			if(new->info<temp->info) // Info part of new having value less than 1st node
			{
				new->link=first;
				first=new;
			}
			else 
			{
		        // traversing till info(next node) >= info(new node) and next node is not last node 
				while(new->info>=temp->link->info && temp->link->link!=NULL) 
		        {
		    	   temp=temp->link;
			    }
			    // End of while loop
			    // If statement-3
			    if(temp->link->info<=new->info && temp->link->link==NULL) // info(last node) <= info(new node) 
			    {
				   // Setting link(last node) = new node
				   temp->link->link=new; 
				   // new is to be inserted at the end of linked list
				   new->link=NULL; 
			    }
			    else
			    {
				   // setting link(new) to next node
				   new->link=temp->link; 
				   // setting link(current node) to new node
				   temp->link=new;  
			    }
			    // End of if statement-3
		    }
		    // End of ladder if statements
		}
		// End of if statement-2
	}
	// End of if statement-1
	printf("\n A node has been sucessfully inserted in ordered linked list.\n");
	X:return first;
}

// Delete first element of linked list
struct node *delbeg(struct node *first)
{
	struct node *temp;
	if(first==NULL)
	   printf(" Linked list is empty.\n");
	else
	{
		temp=first;
	    first=first->link;
	    free(temp);
	    printf("\n The first node of linked list has been deleted sucessfully.\n");
	} 
	return first;
}

// Delete predecessor node of specified node
struct node *delbefore(struct node *first)
{
	int value;
	struct node *pred,*temp;
	// ladder if statement
	//Case-1: linked list is empty
	if(first==NULL) 
	{
		printf(" Linked list is empty.\n");
	}
	// Case-2: linked list with one element.
	else if (first->link==NULL) 
	{
		// predecessor node is not available to delete as only one node is there in the list.
		printf(" Only 1 element in linked list.\n"); 
	}
	else
	{
		printf(" Enter the node before which you want to delete node:");
		scanf("%d",&value);
		// if statement-1
		// Case-3: entered node is first node.
		if(first->info==value)
		{
			// no predecessor node is not available to delete.
			printf(" No predecessor node avilable to delete.\n");
		}
		else
		{
		    temp=first;
		    // traversing till info(next node) != entered value and next node != last node
		    while(temp->link->info!=value && temp->link->link!=NULL)
		    {
			    pred=temp;
			    temp=temp->link;
		    }
		    // Case-4: Entered value is not available in linked list
		    if(temp->link->info!=value && temp->link->link==NULL) // info(last node)!=value  
		      printf(" Entered node has not been found in linked list.");
		    // Case-5: Entered value is stored in 2nd node
		    else if(temp==first) // i.e, predecessor=first
		    {
		    	// setting first pointer to 2nd node
				first=first->link; 
				// Deleting the first node of linked list i.e, predecessor node of entered node 
			    free(temp); 
			    printf(" The predecessor node of entered node has been deleted sucessfully from linked list.\n");
		    }
		    else
		    {
			    // setting link(previous node) to next node
				pred->link=temp->link; 
			    // Deleting the node having entered value
				free(temp); 
			    printf(" The predecessor node of entered node has been deleted sucessfully from linked list.\n");
		    } // End of ladder if statements
		}
		// End of if statement-1
	}
	// End of ladder if statements
	return first;
}

// Delete successor node of specified node
struct node *delafter(struct node *first)
{
	struct node *pred,*temp;
	int value;
	// ladder if statements -1
	// Case-1: linked list is empty
	if(first==NULL)
	{
		printf(" Linked list is empty.\n");
	}
	// Case-2: linked list with one element
	else if (first->link==NULL)
	{
		// successor node is not available to delete as only one node is there in the list.
		printf(" Only 1 element in linked list.\n");
	}
	else
	{
		printf(" Enter the node after which you want to delete node:");
	    scanf("%d",&value);
	    pred=temp=first;
	    temp=temp->link;
	    // traverse till info(prevoius node)!= entered value and node != last node
		while(pred->info!=value && temp->link!=NULL) 
		{
			pred=temp;
			temp=temp->link;
		}
		// End of while loop
		// ladder if statements-2
		// Case-3: Entered value is stored in last node
		if(temp->info==value) 
		{
			printf(" No successor node avilable to delete.\n");
		}
		// Case-4: Entered value is not available in liked list
		// Checks if entered value is stored in last two nodes or not
		else if(pred->info!=value && temp->info!=value && temp->link==NULL) 
		{
			printf(" Entered node isn't part of linked list.\n");
		}
		else
		{
		    // setting link(previous node) to next node
			pred->link=temp->link; 
	        temp->link=NULL;
			// free memory of the node having info part = entered value 
		    free(temp); 
		    printf(" The successor node of entered node has been deleted sucessfully from linked list.\n");
	    }
	    // End of ledder if statements-2
	}
	//  End of ladder if statements-1
	return first;
}

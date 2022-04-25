// Insertion and deletion operation on circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *link;
};
struct node *first=NULL,*last=NULL;

struct node *createcll(struct node*);
struct node *displaycll(struct node*);
struct node *insbeg(struct node*);
struct node *insend(struct node*);
struct node *insbefore(struct node*);
struct node *insafter(struct node*);
struct node *delbeg(struct node*);
struct node *delend(struct node*);
struct node *delbefore(struct node*);
struct node *delafter(struct node*);

int value,data;
struct node *new,*temp;

int main()
{
	int choice;
	do
	{
		printf("\n\n");
	    printf(" 1. Create a circular linked list\n");
	    printf(" 2. Display a circular linked list\n");
	    printf(" 3. Insert node at begining\n");
	    printf(" 4. Insert node at end\n");
	    printf(" 5. Insert a node before specified node\n");
	    printf(" 6. Insert a node after specified node\n");
	    printf(" 7. Delete first node\n");
	    printf(" 8. Delete last node\n");
	    printf(" 9. Delete a node before specified node\n");
	    printf(" 10. Delete a node after specified node\n");
		printf(" 11. Exit\n");
		printf(" Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
	    {
		    case 1:
			    first=createcll(first);
			    printf("\n Linked list has been created sucessfully.\n");
			    break;
		    case 2:
			    first=displaycll(first);
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
			    first=insbefore(first);
			    break;
			case 6:
			    first=insafter(first);
			    break;
		    case 7:
			    first=delbeg(first);
			    break;
			case 8:
			    first=delend(first);
			    break;
		    case 9:
			    first=delbefore(first);
			    break;
		    case 10:
			    first=delafter(first);
			    break; 
			case 11:
				break;
		    default:
		    	printf(" Please, enter valid choice.\n");
			    break;
	    }
	}while(choice!=11);
    return 0;
}
// Create linked list
struct node *createcll(struct node *first)
{
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
		// Assigning value to info of new node
		new->info=value;
		// linked list is empty
		if(first==NULL)
		{
			new->link=new; // In circular linked list, link(last node) points to first element 
			first=last=new;  // inserting 1st element in linked list
		}
		// linked list isn't empty
		else
		{
			// inserting new node at the end
			last->link=new; 
			last=new;
			// Setting link of last node to first
			last->link=first;
		}
		// Taking input from user for next node
		printf(" Enter data:");
	    scanf("%d",&value);
	}
	return first;
}
// Display contents of linked list
struct node *displaycll(struct node *first)
{
	// linked list is empty
	if(first==NULL)
	  printf(" Linked list is empty.\n");
	// linked list isn't empty
	else
	{
		printf("\n Linked list:");
		temp=first;
		// Printing elements of the circular linked list
		do
		{
			printf("%d\t",temp->info);
			temp=temp->link;
		}while(temp!=first);		
	}
	return first;
}
// Insert a node at begining
struct node *insbeg(struct node *first)
{
	int value;
	struct node *new;
	printf(" Enter data:");
	scanf("%d",&value);
	new=(struct node*)malloc(sizeof(struct node*));
	if(new==NULL)
	{
		printf("Free memory is not available.");
		exit(0);
	}
	new->info=value;
	// linked list is empty
	if(first==NULL)
	{
		new->link=new;
		first=last=new;
	}
	// linked list isn't empty
	else
	{
		last->link=new; 
		// As new node is to be inserted at the begining and link(last) points to first node 
		// Setting link of new node to first
		new->link=first; 
		// Setting first pointer to new node
		first=new;
	}
	return first;
}
// Insert node at end
struct node *insend(struct node *first)
{
	printf(" Enter data:");
	scanf("%d",&value);
	new=(struct node*)malloc(sizeof(struct node*));
	if(new==NULL)
	{
		printf("Free memory is not available.");
		exit(0);
	}
	new->info=value;
	// linked list is empty
	if(first==NULL)
	{
		new->link=new;
		first=last=new;
	}
	// linked list isn't empty
	else
	{
		// As new node is to be inserted at the end so link(last) = new node
		last->link=new;
		// Setting link of new node to first
		new->link=first;
		// Setting last pointer to new node
		last=new;
	}
	return first;
}
// Insert a node before specified node
struct node *insbefore(struct node *first)
{
	printf(" Enter data:");
	scanf("%d",&value);
	printf(" Before which node you wanted to insert new node:"); // Consider as entered node
	scanf("%d",&data);
	new=(struct node*)malloc(sizeof(struct node*));
	if(new==NULL)
	{
		printf("Free memory is not available.");
		exit(0);
	}
	new->info=value;
	// Case-1: linked list is empty
	if(first==NULL)
	{
		new->link=new;
		first=last=new;
		printf(" A new node has been inserted successfully before entered node.\n");
	}
	// Case-2: Entered node is first node
	else if(first->info==data)
	{
		last->link=new;
		new->link=first;
		first=new;
		printf(" New node has been inserted successfully before entered node.\n");
	}
	else
	{
		temp=first;
		// traverse till info(next node) != info(entered node) and next node is not last node 
		while(temp->link->info!=data && temp->link!=last)
		   temp=temp->link;
		// Case-3: Entered node is not available in linked list
		if(temp->link->info!=data && temp->link==last)
		  printf(" Entered node has not been found in linked list.");
		else
		{
			// Setting link(new) to entered node
			new->link=temp->link;
			// Setting link of previous node of entered node to new node
			temp->link=new;
			printf(" New node has been inserted successfully before entered node.\n");
		}
	}
	return first;
}
// Insert after specified node
struct node *insafter(struct node *first)
{
	printf(" Enter data:");
	scanf("%d",&value);
	printf(" After which node you wanted to insert new node:"); // Consider as entered node
	scanf("%d",&data);
	new=(struct node*)malloc(sizeof(struct node*));
	if(new==NULL)
	{
		printf("Free memory is not available.");
		exit(0);
	}
	new->info=value;
	// Case-1: linked list is empty
	if(first==NULL)
	{
		new->link=new;
		first=last=new;
		printf(" A new node has been inserted successfully before entered node.\n");
	}
	else
	{
		temp=first;
		// traverse till info(current node) != info(entered node) and current node is not last node 
		while(temp->info!=data && temp->link!=first)
		   temp=temp->link;
		// Case-2: entered node is not available in the liked list
		if(temp->info!=data && temp->link==first)
		  printf(" Entered node has not been found in linked list.");
		else 
		{
			// setting link of new node to next node
			new->link=temp->link;
			// setting link of entered node to new node as it is to be inserted after entered node
			temp->link=new;
			// Case-3: entered node is last node of the linked list
			if(temp==last)
			  last=new;
			printf(" A new node has been inserted successfully before entered node.\n");
		}
	}
	return first;
}
// Delete first node
struct node *delbeg(struct node *first)
{
	// Case-1: linked list is empty
	if(first==NULL)
	  printf(" Linked list is empty.\n");
	// Case-2: linked list with one element
	else if(first==last)
	{
		temp=first;
		first=last=NULL; 
		free(temp);
		printf(" First node has been deleted successfully.\n");
	}
	else
	{
		temp=first;
		first=first->link;
		last->link=first;
		free(temp);
		printf(" First node has been deleted successfully.\n");
	}
	return first;
}
// Delete last node
struct node *delend(struct node *first)
{
	// Case-1: linked list is empty
	if(first==NULL)
	  printf(" Linked list is empty.\n");
	// Case-2: linked list with one element
	else if(first==last)
	{
		temp=first;
		first=last=NULL;
		free(temp);
		printf(" Last node has been deleted successfully.\n");
	}
	else
	{
		temp=first;
		// traverse till 2nd last node
		while(temp->link!=last)
		  temp=temp->link;
	    // Setting last pointer to 2nd last node
		last=temp;
		temp=temp->link;
		// Setting link of the 2nd last node of linked list to first node
		last->link=first;
		// Deleting last node of the linked list
		free(temp);
		printf(" Last node has been deleted successfully.\n");
	}
	return first;
}
// Delete predecessor node of specified node
struct node *delbefore(struct node *first)
{
	struct node *pred;
	// Case-1: linked list is empty
	if(first==NULL)
	  printf(" Linked list is empty.\n");
	// Case-2: linked list with one element
	else if(first==last)
	  printf(" No predecessor node available to delete.\n");
	else
	{
		printf(" Before which node you wanted to delete node:"); // Consider as entered node
	    scanf("%d",&data);
	    // Case-3: Entered node is the 1st node of the linked list
	    if(first->info==data)
	      printf(" No predecessor node available to delete.\n");
		else
		{
			temp=first;
			// traverse till info(next node) != entered value and next node != last node
		    while(temp->link->info!=data && temp->link!=last)
		    {
			    pred=temp;
			    temp=temp->link;
		    }
		    // Case-4: Entered node is not available in linked list
		    if(temp->link->info!=data && temp->link==first)
		      printf(" Entered node has not been found in linked list.");
		    // Case-5: Entered node is 2nd node
		    else if(temp==first)
		    {
			    // Setting first pointer to 2nd node of linked list
				first=first->link;
				// Setting link(last node) to 2nd node
			    last->link=first;
			    // Deleting first node of linked list
			    free(temp);
			    printf(" The predecessor node of entered node has been deleted sucessfully from linked list.\n");
		    }
		    else
		    {
			    // Setting link(previous to previous node) to entered node
				pred->link=temp->link;
				// Deleting predecessor node of the entered node
			    free(temp);
			    printf(" The predecessor node of entered node has been deleted sucessfully from linked list.\n");
		    } // End of ladder if statements
		}	// End of if statement-2	
	}  // End of if statement-1
	return first;
}
// Delete the successor node of specified node
struct node *delafter(struct node *first)
{
	struct node *suc;
	// Case-1: linked list is empty
	if(first==NULL)
	  printf(" Linked list is empty.\n");
	// Case-2: linked list with one element
	else if(first==last)
	  printf(" No successor node available to delete.\n");
	else
	{
		printf(" After which node you wanted to delete node:"); // Consider as entered node
	    scanf("%d",&data);
	    // Case-3: Entered node is the last node of the linked list
	    if(last->info==data)
	      printf(" No successor node available to delete.\n");
		else
		{
			temp=first;
			// traverese till entered node is not found and link of the node is not null
		    while(temp->info!=data && temp->link!=first)
		       temp=temp->link;
		    // Case-4: Entered node is not available in linked list
		    if(temp->info!=data && temp->link==first)
		       printf(" Entered node has not been found in linked list.");
		    else
		    {
		        // setting pointer suc to next node i.e, successor node of the entered node
				suc=temp->link;
				// Case-5: successor node of the entered node is last node i.e, last node is to be deleted
		        if(suc==last)
		          // Setting last pointer to 2nd last node of the linked list
		          last=temp;
		        // Setting link(entered node) to link(next node)
				temp->link=suc->link;
			    // Deleting successor node of the entered node
				free(suc);
				printf(" The successor node of entered node has been deleted sucessfully from linked list.\n");	    	
			}
		}
	}
	return first;
}

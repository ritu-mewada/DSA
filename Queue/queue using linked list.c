// Implementation of queue using linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

struct node *f,*r; // f = front  &  r = rear

void push()
{
	int val;
	struct node *new;
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element to be pused:");
	scanf("%d",&val);
	new->info=val;
	new->link=NULL; // As element is to be inserted at the end of queue 
    // inserting new node
	// Queue is empty
	if(f==NULL) 
      f=new;
    // Queue isn't empty
    else  
    	r->link=new; 
    // setting rear pointer of queue to new node
    r=new;  
}

void pop()
{
	struct node *temp;
	// Queue is empty
	if(f==NULL) 
	{
		printf("Queue is Underflow.\n");
	}
	// Queue isn't empty
	else  
	{
		temp=f; 
		// setting first pointer to 2nd node as in queue, element is to be popped from front
		f=f->link; 
		printf("Popped Element: %d\n",temp->info);
		// Deleting the first element from the queue
		free(temp);  
	}
}

void peep()
{
	struct node *temp;
	// Queue is empty
	if(f==NULL)
		printf("Queue is empty.\n");
	// Queue isn't empty
	else
	{
		printf("Elements of queue:");
		temp=f;
		// Printing all elements of the queue
		while(temp != r->link)
		{
			printf("%d\t",temp->info);
			temp=temp->link;
		}
	}
}

int main()
{
	int option;
	do
	{
		printf("\n\nEnter your choice:\n");
		printf("1.  Push\n");
		printf("2.  Pop\n");
		printf("3.  Peep\n");
		printf("4.  Exit\n");
		scanf("%d",&option);
		switch(option)
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
	}while(option!=4);
	return 0;
}

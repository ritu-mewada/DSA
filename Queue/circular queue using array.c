// Insertion and deletion operstions on circular queue
#include<stdio.h>
#define max 5

int queue[max];
int front=-1,rear=-1;

void insert();
void delete();
void display();

int main()
{
	int choice;
	do
	{
		printf("\n\n");
		printf("Enter your choice:\n");
		printf("1. Insert an element\n");
		printf("2. Delete an element\n");
		printf("3. Display all elements of queue\n");
		printf("4. Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("Please, enter valid choice(1-4)\n");
				break;
		}
	}while(choice!=4);
	return 0;
}

void insert()
{
	if((rear>=max-1 && front==0) || rear==front-1)
	  printf("Circular queue is overflow.\n");
	else
	{
		//Case-1: Queue is empty
		if(front==-1)
		  front++;
		// Case-2: rear is at the last position of an array and front is at any position except 1st position
		if(rear==max-1 && front>0)
			rear=0;
		else
			rear++;
		printf("Enter the value you wanted to insert in queue:");
		scanf("%d",&queue[rear]);
	}
}

void delete()
{
	// Case-1: Queue is empty
	if(front==-1)
	  printf("Circular queue is underflow.\n");
	else
	{
		// Case-2: Only one element is in queue
		if(front==rear)
           front=rear=-1;
        // Case-3: Front pointer is points to last element of an array
        else if(front==max-1)
           front=0;
        else
           front++;
	}
}

void display()
{
	int i;
	if(front==-1)
	    printf("Circular queue is empty.\n");
	else if(rear>=front)
	{
		printf("Circular Queue:\n\t");
		// printing elements of a circular queue
		for(i=front;i<=rear;i++)
		   printf("%d\t",queue[i]);
	}
	else
	{
		printf("Circular Queue:\n\t");
		// printing elements of queue till last position of an array 
		for(i=front;i<max;i++)
		  printf("%d\t",queue[i]);
		// printing elements of queue from 1st position 
		for(i=0;i<=rear;i++)
		  printf("%d\t",queue[i]);
	}
}

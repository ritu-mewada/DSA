// Basic operations on queue
#include<stdio.h>
#define max 5

int queue[max];
int value,front=-1,rear=-1;

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
	if(rear>=max-1)
	  printf("Queue is overflow.\n");
	else
	{
		if(front==-1)
		  front++;
		rear++;
		printf("Enter the value you wanted to insert in queue:");
		scanf("%d",&queue[rear]);
	}
	
}

void delete()
{
	if(front<=-1 || front>rear)
	  printf("Queue is underflow.\n");
	else
	{
		front++;
		printf("Deleted element from queue:%d\n",queue[front-1]);
	}
}

void display()
{
	if((front<=-1 && rear<=-1) || front>rear)
	  printf("The queue is empty.\n");
	else
	{
		int i;
		printf("Queue:\n\t");
		for(i=front;i<=rear;i++)
		  printf("%d\t",queue[i]);
	}
}

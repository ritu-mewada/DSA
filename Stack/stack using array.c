// Basic stake operations
#include<stdio.h>
# define max 10

void push();
void pop();
void peep();
int top=-1;
int stack[max];

int main()
{
	int choice;
	do
	{
		printf("\n\n");
		printf("Enter your choice here:\n");
		printf("1. Insert an element\n");
		printf("2. Delete an element\n");
		printf("3. Display all elements\n");
		printf("4. Exit\n");
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
				printf("Please, enter valid choice(1-4)\n");
				break;
		}
	}while(choice!=4);
	return 0;
}
void push()
{
	if(top>=max-1)
		printf("Stake is overflow.\n");
	else
	{
		top++;
		printf("Enter the value of an element:");
		scanf("%d",&stack[top]);
	}
}
void pop()
{
	if(top<=-1)
		printf("Stake is underflow.\n");
	else
	{
		printf("Deleted element:%d\n",stack[top]);
		top--;
	}
}
void peep()
{
	int i;
	if(top<=-1)
	  printf("The stack is empty.");
	else
	{
	    printf("Stack:\n\t");
		for(i=0;i<=top;i++)
		  printf("%d\t",stack[i]);
	}
}

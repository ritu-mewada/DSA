#include<stdio.h>
#define MAX 10

// Function to print elements of an array
void printarray(int a[], int n)
{
	int i=0;
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
}

int main()
{
	int size, array[MAX], i, j, element;
	X: printf("Enter the size of an array: "); 
	scanf("%d", &size);
	
	if(size > MAX || size<0)
	{
		printf("Invalid array size.\n");
		goto X;
	}
	else
	{
		for(i=0; i<size; i++)
		{
			printf("Enter the value of an element-%d: ", i);
			scanf("%d", &array[i]);
		}
		
		// Printing elements of an array
		printf("\nElements of an array: ");
		printarray(array,size);
		
		// Implementing insertion sort
		for(i=1; i<size; i++)
		{
			element = array[i];
			j=i-1;
			while(array[j] > element && j>=0)
			{
				array[j+1] = array[j];
				j--;
			}
			array[j+1] = element;			
		}
		// Printing sorted array
		printf("\nElements of the sorted array: ");
		printarray(array, size);
	}
	return 0;
}

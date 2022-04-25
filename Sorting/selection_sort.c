#include<stdio.h>
#define MAX 10

// Function to print elements of an array
void printarray(int a[], int n)
{
	int i=0;
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
}

// Function to swap two elements of an array
void swap(int *a, int *b)
{
    int temp;
	temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
	int size, array[MAX], i, j, min_i, min_element;
	
	X: printf("Enter the size of an array: "); 
	scanf("%d", &size);
	
	if(size > MAX || size < 0)
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
		
		for(i=0; i<size-1; i++)
		{
			// Finding minimum element from unsorted array
			min_i = i;
			min_element = array[i];
			for(j=i+1; j<size; j++)
			{
				if(array[j]<min_element)
				{
					min_i = j;
					min_element = array[j];
				}
			}
			// Swapping minimum element of an unsorted array with first element of an array
			swap(&array[min_i], &array[i]);
		}
		// Printing sorted array
		printf("\nElements of the sorted array: ");
		printarray(array, size);	
	}
	return 0;
}

#include<stdio.h>
#define MAX 10

// Function to print elements of an array
void printarray(int a[], int n)
{
	int i=0;
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
}

// Function to perform swapping
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int arr[], int lb, int ub)
{
	int pivot, x, i;
	pivot = arr[ub];
	x = lb-1;
	for(i=lb; i<ub; i++)
	{
		if(arr[i] < pivot)
		{
			x++;
			swap(&arr[x], &arr[i]);
		}
	}
	swap(&arr[x+1], &arr[ub]);
	return(x+1);
}

void quicksort(int arr[], int lb, int ub)
{
	if(lb<ub)
	{
		int pi = partition(arr, lb, ub);
		quicksort(arr, lb, pi-1);
		quicksort(arr, pi+1, ub);
	}
}

int main()
{
	int arr[MAX], size, i;
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
			scanf("%d", &arr[i]);
		}
		
		// Printing elements of an array
		printf("\nElements of an array: ");
		printarray(arr,size);
		
		// Implementing Quick Sort
		quicksort(arr, 0, size-1);
		
		// Printing sorted array
		printf("\nElements of a sorted array: ");
		printarray(arr,size);
	}
	return 0;
}

#include<stdio.h>
#define MAX 10

// Function to merge two sorted list
void merge(int array[], int lb, int mid, int ub)
{
	int i, j , k , temp_array[ub+1];
	i = k = lb;
	j = mid+1;
	
	// Sorting elements until one of the list entirely traversed
	while(i<=mid && j<=ub)
	{
		if(array[i]<= array[j])
		{
			temp_array[k] = array[i];
			i++;
		}	
		else
		{
			temp_array[k] = array[j];
			j++;
		}
		k++;
	}
	
	// Copying remaining elements in array
	if(i > mid)
	{
		while(j <= ub)
		{
			temp_array[k] = array[j];
			j++;
			k++; 
		}
	}
	else
	{
		while(i <= mid)
		{
			temp_array[k] = array[i];
			i++;
			k++;
		}
	}
	
	// Copying all sorted elemnts to original array
	for(i = lb; i<= ub; i++)
		array[i] = temp_array[i];	
}

// Function to implement merge sort
void merge_sort(int array[], int lb, int ub)
{
	int mid;
	if(lb<ub)
	{
		mid = (lb+ub) / 2;
		merge_sort(array, lb, mid);
		merge_sort(array, mid+1, ub);
		merge(array, lb, mid, ub);
	}	
}

int main()
{
	int array[MAX], i, size;
	
	X: printf("Enter the size of an array: ");
	scanf("%d",&size);
	
	if(size > MAX || size < 0)
	{
		printf("Invalid array size!\n");
		goto X;
	}
	else
	{
		printf("Enter elements of an array:\n");
		for(i = 0; i < size; i++)
		{
			printf("Element-%d: ", i);
			scanf("%d", &array[i]);
		}
			
		// Prinnting unsorted array
		printf("Entered array:\t");
		for(i = 0; i < size; i++)	
			printf("%d ", array[i]);
			
		// Implementing merge sort
		merge_sort(array, 0, size-1);
		
		// Printing sorted array
		printf("\nSorted array:\t");
		for(i = 0; i < size; i++)	
			printf("%d ", array[i]);
	}
	return 0;
}

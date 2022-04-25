#include<stdio.h>
#define MAX 10

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int array[],int i, int n)
{
	int left, right, max, j; 
	max = i;
	left = 2*i + 1;
	right = 2*i + 2;
	if((left<n) && (array[left]>array[max]))
	{
		max=left;
	}
	if((right<n) && (array[right]>array[max]))
	{
		max=right;
	}
	if(max!=i)
	{
		swap(&array[i],&array[max]);
		max_heapify(array, max, n);
	}
}

void build_max_heap(int array[], int size)
{
	int i;
	for(i=(size/2)-1; i>=0; i--)
	{
		max_heapify(array, i, size);
	}
}

int main()
{
	int array[MAX], i, size;
	X: printf("Enter the size of an array: ");
	scanf("%d",&size);
	if(size>10 || size<0)
	{
		printf("Invalid array size!\n");
		goto X;
	}
	else
	{
		for(i=0;i<size;i++)
		{
			printf("Enter an element-%d: ",i);
			scanf("%d",&array[i]);
		}
		
		//printing element of an unsorted array
		printf("Unsorted array: ");
		for(i=0;i<size;i++)
		{
			printf("%d ",array[i]);
		}
		build_max_heap(array, size);
		for(i=size-1; i>0; i--)
		{
			swap(&array[i], &array[0]);
			max_heapify(array, 0, i);
		}
		printf("\nSorted array: ");
		for(i=0;i<size;i++)
		{
			printf("%d ",array[i]);
		}
	} 
	return 0;
}

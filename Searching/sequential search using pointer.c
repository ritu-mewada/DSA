// Sequential search
#include<stdio.h>
#include<stdlib.h>

void sequential_search(int *a,int size,int ele)
{
	int i;
	for(i=0;i<size;i++)
	{
		if(a[i]==ele) // i.e., element is found in an array
		  break;
	}
	if(i==size)
	  printf("Element is not found in an array.");
	else
	  printf("Element %d is stored at index %d.",ele,i);
	
}
int main()
{
	int *arr,i,size,ele;
	printf("Enter the size of an array:");
	scanf("%d",&size);
	arr= (int*)malloc(size * sizeof(int));
	printf("Enter the elements of an array:");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	printf("Enter the element to be searched:");
	scanf("%d",&ele);
	// Implementing sequential search
	sequential_search(arr,size,ele);
	return 0;
}

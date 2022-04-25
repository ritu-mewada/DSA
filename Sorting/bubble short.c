// Bubble shorting
#include<stdio.h>
#include<stdlib.h>

void bubble_short(int *arr,int n) 
{
	int i,j,temp,count;
	for(i=0;i<n-1;i++)
	{
		count=0;
		for(j=0;j<n-i-1;j++)
		{
			// Comparing elements of an array
			if(arr[j]>arr[j+1])
			{
				// Swapping elements
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				count+=1;
			}
		}
		if(count==0) // i.e., all elements have been shorted
		  break;
	}
}

int main()
{
	int size,i;
	int *arr;
	printf("Enter an array size:");
	scanf("%d",&size);
	arr= (int*)malloc(size*sizeof(int));
	printf("Enter the elements of an array:");
	for(i=0;i<size;i++)
	   scanf("%d",&arr[i]);
	// Implimenting bubble short for shorting
	printf("Bubble short begins...\n\n");
	bubble_short(arr,size);
	printf("Elements are successfully shorted using bubble short...\n\n");
	printf("Shorted elements of the array:\n");
	for(i=0;i<size;i++)
	   printf("%d\t",arr[i]);
	return 0;
}

// Binary search
#include<stdio.h>
#include<stdlib.h>

void short_elements(int *arr,int n) // n= last index value of an array
{
	int i,j,temp,count;
	for(i=0;i<n-1;i++)
	{
		count=0;
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				count+=1;
			}
		}
		if(count==0)
		  break;
	}
}

void binary_search(int *a,int i,int e, int ele) // i=initial index & e=last index
{
	int n; // n=middle index value
	n=(i+e)/2; 
	//Case-1: Element is not part of an array
	if(i>e)
	   printf("Element is not found in array.");
	// Case-2: Element is stored at current location i.e.,n
	else if(a[n]==ele)
	   printf("Element %d is  stored at index %d.",ele,n);
	else if(ele>a[n])
	   binary_search(a,n+1,e,ele); // Searching element in right part of an array for middle element
	else
	   binary_search(a,0,n-1,ele); // Searching element in right part of an array for middle element
}

int main()
{
	int *arr,ele,i,size;
	printf("Enter the size of an array:");
	scanf("%d",&size);
	arr= (int*)malloc(size * sizeof(int));
	printf("Enter the elements of an array:");
	for(i=0;i<size;i++)
		scanf("%d",&arr[i]);
	// Shorting elements in acsending order for searching
	short_elements(arr,size);
	printf("Enter the element to be searched:");
	scanf("%d",&ele);
	// Implementing binary search
	binary_search(arr,0,size-1,ele);
	return 0;
}

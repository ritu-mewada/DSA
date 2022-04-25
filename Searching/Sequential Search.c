#include<stdio.h>

int find_index(int A[5], int value)
{
	int i;
	for(i=0;i<5;i++)
	{
		if (A[i]==value)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	int i, index;
	int A[5] = {1, -4, 857, 0, 45};
	int x[2] = {5, 0};	
	for(i=0; i<2; i++)
	{
		index = find_index(A, x[i]);
		if (index==-1)
		{
			printf("%d is not present in array.\n",x[i]);
		}
		else
		{
			printf("%d is present at location %d in array.\n",x[i], index);
		}
	}
	return 0;
}

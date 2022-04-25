#include<stdio.h>
#define MAX 20

int min(int a, int b)
{
	if(a < b)
		return a;
	else
		return b;
}

int main()
{
	int table[MAX][MAX+1], d[MAX], i , j, n, N;
	X:printf("Enter total number of denominators:");
	scanf("%d", &n);
	printf("Enter total amount:");
	scanf("%d", &N);
	if(n>MAX || N>MAX || n<0 || N<0)
	{
		printf("Invalid Input!!\n");
		goto X;
	}
	else
	{
		// Taking value of coins as input
		for(i=0; i<n; i++)
		{
			printf("d[%d] = ", i+1);
			scanf("%d", &d[i]);
		}
		
		// Filling the table
		for(i=0; i<n; i++)
		{
			for(j=0; j<=N; j++)
			{
				if(j==0)
					table[i][0]=0;
				else if(i==0)
					table[i][j] = 1+table[0][j-d[0]];
				else if(j < d[i])
					table[i][j] = table[i-1][j];
				else
					table[i][j] = min(table[i-1][j], 1+table[i][j-d[i]]);
			}
		}
		
		// Finding which coins are needed
		printf("\n\nCoins to be selected:");
		i=n-1;
		j=N;
		int count = table[i][j];
		while(table[i][j] != 0)
		{
			if(table[i][j] != table[i-1][j])
			{
				printf(" %d", d[i]);
				count--;
				j = j - d[i];
			}
			else if(i==0 && count!=0)
			{
				while(count!=0)
				{
					printf(" %d", d[i]);
					count--;
				}
				break;
			}
			else
			{
				i -= 1;
			}
		}
	}
	return 0;
}

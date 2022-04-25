#include<stdio.h>
#define MAX 10

void PrintSolution(int k[MAX][MAX], int lb, int ub)
{
	int i,j;
	if(lb == ub)
		printf("A%d ", lb+1);
	else
	{
		printf("(");
		PrintSolution(k, lb, k[lb][ub]-1);
		PrintSolution(k, k[lb][ub], ub);
		printf(")");
	}
}

int main()
{
	int matrix[MAX][MAX], ktable[MAX][MAX], i, j, k, n, P[MAX], temp, min, kmin;
	X: printf("Enter total number of matrices to be multiplied:");
	scanf("%d", &n);
	if(n<0 || n>MAX)
	{
		printf("Invalid input size!!\n");
		goto X;
	}
	else
	{
		printf("Enter total number of rows in matrix-1:");
		scanf("%d", &P[0]);
		for(i=1; i<=n; i++)
		{
			printf("Enter total number of columns in matrix-%d:",i);
			scanf("%d", &P[i]);
		}
		
		// Filling matrix and ktable
		for(i=n-1; i>=0; i--)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
				{
					matrix[i][i] = 0;
					ktable[i][i] = 0;
				}
				else if (j == i+1)
				{
					matrix[i][j] = P[i]*P[i+1]*P[i+2];
					ktable[i][j] = i+1;
				}
				else if(i<j)
				{
					for(k=i;k<j; k++)
					{
						temp = matrix[i][k] + matrix[k+1][j] + P[i]*P[k+1]*P[j+1];
						if(k == i)
						{
							min = temp;
							kmin = i+1;
						}
						else
						{
							if(temp < min)
							{
								min = temp;
								kmin = k+1;
							}
						}
					}
					matrix[i][j] = min;
					ktable[i][j] = kmin;
				}
			}
		}
		printf("The optimal cost = %d\n", matrix[0][n-1]);
		printf("Optimal solution: ");
		PrintSolution(ktable, 0, n-1);
	}
	return 0;
}

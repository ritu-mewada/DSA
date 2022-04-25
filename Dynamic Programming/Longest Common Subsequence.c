#include<stdio.h>
#include<string.h>
#define MAX 10

char s1[MAX], s2[MAX];
int table[MAX+1][MAX+1], m, n;

int maximum(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void printsolution(int sol_len)
{
	int i, j, k=0;
	char res[sol_len];
	i=n;
	j=m;
	while(table[i][j]!=0)
	{
		if(s1[j-1]==s2[i-1])
		{
			res[k]=s1[j-1];
			k++;
			i-=1;
			j-=1;
		}
		else
		{
			if(maximum(table[i][j-1], table[i-1][j]) == table[i-1][j])
				i-=1;
			else
				j-=1;
		}
	}
	for(k=sol_len-1;k>=0;k--)
	{
		printf("%c",res[k]);
	}
}

int main()
{
	int i, j;
	X: printf("Enter string 1:");
	scanf("%s", s1);
	m=strlen(s1);
	if(m>MAX || m<0)
	{
		printf("Invalid size of string 1.\n");
		goto X;
	}
	
	Y: printf("Enter string 2:");
	scanf("%s", s2);
	n=strlen(s2);
	if(n>MAX || n<0)
	{
		printf("Invalid size of string 2.\n");
		goto Y;
	}
	else
	{
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				if(i==0 || j==0)
				{
					table[i][j] = 0;
				}
				else if(s2[i-1] == s1[j-1])
				{
					table[i][j] = table[i-1][j-1]+1;
				}
				else
				{
					table[i][j] = maximum(table[i][j-1], table[i-1][j]);
				}
			}
		}
		
		printf("\n\nLongest Common Subsequence: ");
		printsolution(table[n][m]);
	}
	return 0;
}

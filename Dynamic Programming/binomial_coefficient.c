#include<stdio.h>

int main()
{
	int i, n, r; 
	float ans;
	printf("n= ");
	scanf("%d",&n);
	printf("r= ");
	scanf("%d",&r);
	ans=1.0;
	for(i=r; i>0; i--, n--)
	{
		ans = ans*((float)n/i);
	}
	printf("Answer= %.0f", ans);
	return 0;
} 

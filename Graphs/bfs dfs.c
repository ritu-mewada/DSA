#include<stdio.h>
#define max 5

void bfs(int adj[][max],int v[],int start) 
{
    int q[max]; 
    int f,r, i; 
    f=-1;
    r=-1;
    q[++r]=start; 
    v[start]=1;
    while(r!=f)
    {
        start=q[++f];
        if(start==5)
            printf("\t");
        else
            printf("%d \t",start); // printing visited node
        // Exploring adjacent nodes 
        for(i=0;i<max;i++)
        {
        	// Checking if the explored node is visited or not
            if(adj[start][i]==1 && v[i]==0) 
            {
                q[++r]=i; // inserting explored and unvisited node in queue
                v[i]=1;  
            }
        }
    }
}

void dfs(int adj[][max],int v[],int start) 
{
    int i,s[max]; 
    int top=-1;
    printf("%d ",start); 
    v[start]=1; 
    s[++top]=start;  
    while(top!=-1)  
    {
        start=s[top];  
        for(i=0;i<max;i++)
        {
            // Checking if the explored node is visited or not 
			if(adj[start][i] && v[i]==0)
            {
                s[++top]=i;  
                printf("\t%d",i);
                v[i] = 1;
                break;
            }
        }
        if(i==max)
            top--; 
    }
}

int main()
{
	int r,c,v,adj[max][max];
	int visited1[max]={0};
	int visited2[max]={0};
	printf("Enter total no of vertices:");
	scanf("%d",&v);
	printf("Enter adjacency matrix:\n");
	for(r=0;r<v;r++)
	{
		for(c=0;c<v;c++)
		    scanf("%d",&adj[r][c]);
		printf("\n");
	}
	printf("BFS traversal sequence: ");
	// Implimanting BFS
	bfs(adj,visited1,0);
	printf("\nDFS traversal sequence: ");
	// Implimanting DFS using iterative method
	dfs(adj,visited2,0);
	return 0;
}

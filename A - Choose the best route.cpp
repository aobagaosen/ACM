#include<stdio.h>
#include<string.h>
const int INF = 100000000;
int cost[20001][20001];
int d[1001],used[1001],sum_point;
int num_station,num_path,end, num_begin, min_time;

void dijkstra(int s)
{
	int i, j, k;
	
	for( i = 0; i < 1001; i++ )
		d[i] = INF;	
	memset( used , 0 , sizeof(used) );
	
	d[s] = 0;
	while(1)
	{
		int v = -1;
		for( int u = 0; u < num_station; u++ )
		if( !used[u] && ( v == -1 || d[u] < d[v]) ) v = u;
		
		if( v == -1 ) break;
		used[v] = 1;
		
		for( int u = 0; u < num_station ; u++ )
		d[u] = d[u] < ( d[v] + cost[v][u] ) ? d[u] : ( d[v] + cost[v][u] );
					
	}			
}

int main()
{
	int i, j, k;
	int first, second, time, begin, sumbeg[1001];
	
	while( scanf("%d%d%d",&num_station,&num_path,&end) == 3 )
	{
		min_time = INF;
		for( i = 0; i < num_station; i++ )
	    for( j = 0; j < num_station; j++ )
	    	cost[i][j] = INF;
	    	
		for( i = 0; i < num_station; i++ )
		cost[i][i] = 0;

		for( i = 0; i < num_path ; i++ )
		{
			scanf("%d%d%d",&first, &second, &time);
			
	
			cost[second-1][first-1] = time;
			
		}
		
		scanf("%d",&num_begin);
		
		for( i = 0; i < num_begin ; i++ )
		{
		scanf("%d",&sumbeg[i]);
	    }	    
	    
		dijkstra( end-1 );
		
		for( i = 0; i < num_begin ; i++ )
		
		min_time = min_time > d[sumbeg[i]-1] ? d[sumbeg[i]-1] : min_time;
		if(min_time < INF )
		printf("%d\n",min_time);
		else printf("-1\n");		
	}
	
	return 0;	
}

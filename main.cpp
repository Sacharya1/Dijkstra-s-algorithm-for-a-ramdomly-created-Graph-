#include<iostream>
#include<climits>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define numOfPoints 7
int minimumDist(int dist[], bool Dset[])
{
	int min=INT_MAX,index;
	for(int v=0;v<numOfPoints;v++)
	{
		if(Dset[v]==false && dist[v]<=min)
		{
			min=dist[v];
			index=v;
		}
	}
	return index;
}
void dijkstra(int graph[numOfPoints][numOfPoints],int src)
{
	int dist[numOfPoints];
	bool Dset[numOfPoints];
	for(int i=0;i<numOfPoints;i++)
	{
		dist[i]=INT_MAX;
		Dset[i]=false;
	}
	dist[src]=0;
	for(int c=0;c<numOfPoints;c++)
	{
		int u=minimumDist(dist,Dset);
		Dset[u]=true;
		for(int v=0;v<numOfPoints;v++)
		{
			if(!Dset[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v])
			dist[v]=dist[u]+graph[u][v];
		}
	}
	cout<<"numOfPoints\tTotal cost count of the path"<<endl;
	for(int i=0;i<numOfPoints;i++)
	{
		char c=65+i;
		cout<<c<<"\t\t"<<dist[i]<<endl;
	}
}
int main()
{
     srand(time(0));
 int graph[numOfPoints][numOfPoints], i ,j;

 for( i = 0; i < numOfPoints; ++i)
  {for( j = 0;  j < numOfPoints; ++j)
     {graph[i][j] = abs((i-j)*rand()) ;
     cout<<graph[i][j]<<'\t';

}
cout<<'\n';
  }



	dijkstra(graph,0);
	return 0;
}

//http://www.cplusplus.com/doc/tutorial/preprocessor/ //

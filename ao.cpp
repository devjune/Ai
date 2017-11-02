#include<iostream>
#include <list>
#include <stdio.h>
#include <limits.h>
 #define Value 9

int d=0;
using namespace std;


class Graph
{
     int V;
    list<int> *adj;


    void printAllPathsUtil(int , int , bool [], int [], int &);

public:
    Graph(int V);
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}


void Graph::printAllPaths(int s, int d)
{

    bool *visited = new bool[V];


    int *path = new int[V];
    int path_index = 0;


    for (int i = 0; i < V; i++)
        visited[i] = false;


    printAllPathsUtil(s, d, visited, path, path_index);
}


void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index)
{

    visited[u] = true;
    path[path_index] = u;
    path_index++;


    if (u == d)
    {
        for (int i = 0; i<path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else
    {

        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }


    path_index--;
    visited[u] = false;
}
 //doosra wala

int minDistance(int dist[], bool sptSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < Value; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}


void printPath(int parent[], int j)
{

    if (parent[j]==-1)
        return;

    printPath(parent, parent[j]);

    printf("%d ", j);
}


int printSolution(int dist[], int n, int parent[])
{
    int src = 0;
    printf("Vertex\t  Distance\tPath");

        printf("\n%d -> %d \t\t %d\t\t%d ", src, d, dist[d], src);
        printPath(parent, d);

}


void Calculate(int graph[Value][Value], int src)
{
    int dist[Value];



    bool sptSet[Value];


    int parent[Value];


    for (int i = 0; i < Value; i++)
    {
        parent[0] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }


    dist[src] = 0;


    for (int count = 0; count < Value-1; count++)
    {

        int u = minDistance(dist, sptSet);


        sptSet[u] = true;


        for (int v = 0; v < Value; v++)


            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }


    printSolution(dist, Value, parent);
}

int main()
{
	int limit=0,n,m,s;
	int graph[9][9]={0};

    cout<<"Enter the no. of nodes:";
    cin>>limit;
    Graph g(limit);
    cout<<"Enter the edges:";
    while(n!=-1)
    {
    	cin>>n>>m;
    	if(n==-1)
    	break;
    	g.addEdge(n, m);
    }
    cout<<"Enter the weights of the respective nodes";
    for(int i=0;i<=limit-1;i++)
    for(int j=0;j<=limit-1;j++)
	cin>>graph[i][j];


    //int s = 2, d = 3;
    cout<<"enter the start node and the destination:";
    cin>>s>>d;
    cout << "Following are all different paths from " << s
         << " to " << d << endl;
    g.printAllPaths(s, d);
    Calculate(graph, s);
    return 0;
}

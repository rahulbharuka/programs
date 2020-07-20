#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef struct _auxiliary
{
	bool visited;
	int distance;
	int prev;
} Auxiliary;

void print_path(int dst, Auxiliary *aux)
{
	if (aux[dst].prev != -1)
		print_path(aux[dst].prev, aux);

	printf("%d ", dst+1);
}

int getMinDistVertex(Auxiliary *aux, int V)
{
	int inx = -1, min = INT_MAX;
	for (int i = 0; i < V; i++)
	{
		if (!aux[i].visited && (aux[i].distance < min))
		{
			min = aux[i].distance;
			inx = i;
		}
	}
	return inx;
}

void find_shortest_path(int V, int **Adj, int src, int dst)
{
	int u;
	Auxiliary aux[V];
	for (int inx = 0; inx < V; inx++)
	{
		aux[inx].visited = false;
		aux[inx].distance = INT_MAX;
		aux[inx].prev = -1;
	}

	aux[src].distance = 0;
	for (int it = 0; it < V-1; it++)
	{
		u = getMinDistVertex(aux, V);
		aux[u].visited = true;

		if (u == dst)
			goto path_found;

		for (int v = 0; v < V; v++)
		{
			if ((u != v) && (Adj[u][v] != INT_MAX) && !aux[v].visited && ((aux[u].distance + Adj[u][v]) < aux[v].distance))
			{
				aux[v].distance = aux[u].distance + Adj[u][v];
				aux[v].prev = u;
			}
		}

	}

	if (aux[dst].distance == INT_MAX)
		printf("No path from %d to %d\n", src+1, dst+1);
	else
	{
path_found:
		printf("Distance from %d to %d is %d\n", src+1, dst+1, aux[dst].distance);
		printf("And the corresponding path is: ");
		print_path(dst, aux);
		printf("\n");
	}
}

int main()
{
	int V, E;
	printf("Enter the number of nodes in the graph: ");
	scanf("%d", &V);
	printf("Enter the number of edges in the graph: ");
	scanf("%d", &E);
	if ((V <= 0) || (E <= 0))
		goto err;

	int u, v, d;
	int **Adj = (int **) malloc(sizeof(int *) * V);
	for (int i = 0; i < V; i++)
		Adj[i] = (int *) malloc(sizeof(int) * V);

	for (int i = 0; i < V; i++)
		for (int j = 0; j < V; j++)
			Adj[i][j] = INT_MAX;

	printf("Now enter %d edges with their weights, one on each line\n", E);
	for (int i = 0; i < E; i++)
	{
		scanf("%d %d %d", &u, &v, &d);
		if ((u <= 0) || (v <= 0))
		{
			free(Adj);
			goto err;
		}

		Adj[u-1][v-1] = d;
		Adj[v-1][u-1] = d;
	}
	
	int src, dst;
	printf("Now enter the source and destination vertex: ");
	scanf("%d %d", &src, &dst);
	find_shortest_path(V, Adj, src-1, dst-1);
	free(Adj);
	return 0;
err:
	printf("Invalid input\n");
	exit(EXIT_FAILURE);
}

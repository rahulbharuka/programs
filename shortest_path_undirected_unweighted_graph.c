#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include "queue.h"

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

void find_shortest_path(int V, bool **Adj, int src, int dst)
{
	if (src == dst)
		printf("source and destination are same.\n");
	else
	{
		int u;
		Queue *q = createQueue(V);
		Auxiliary aux[V];
		memset(&aux, 0, sizeof(aux[0]) * V);

		aux[src].prev = -1;
		enqueue(q, src);
		while(!isEmpty(q))
		{
			u = dequeue(q);
			aux[u].visited = true;

			for (int v = 0; v < V; v++)
			{
				if ((u != v) && Adj[u][v] && !aux[v].visited)
				{
					aux[v].visited = true;
					aux[v].distance = aux[u].distance + 1;
					aux[v].prev = u;

					if (v == dst)
					{
						printf("Distance from %d to %d is %d\n", src+1, dst+1, aux[dst].distance);
						printf("And the corresponding path is: ");
						print_path(dst, aux);
						printf("\n");
						goto ret;
					}
					else
						enqueue(q, v);
				}

			}
		}

		printf("No path from %d to %d\n", src+1, dst+1);
ret:
		freeQueue(q);
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

	int p, q;
	bool **Adj = (bool **) calloc(sizeof(bool *), V);
	for (int i = 0; i < V; i++)
		Adj[i] = (bool *) calloc(sizeof(bool), V);

	printf("Now enter %d edges, one on each line\n", E);
	for (int i = 0; i < E; i++)
	{
		scanf("%d %d", &p, &q);
		if ((p <= 0) || (q <= 0))
		{
			free(Adj);
			goto err;
		}

		Adj[p-1][q-1] = true;
		Adj[q-1][p-1] = true;
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

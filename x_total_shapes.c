#include <stdio.h>
#include <stdlib.h>

typedef struct _Queue
{
	int *arr;
	int front;
	int rear;
	int size;
	int capacity;
} Queue;

Queue* createQueue(int N)
{
	Queue *Q = (Queue *) malloc(sizeof(Queue));
	Q->arr = (int *) malloc(sizeof(int) * N);
	Q->front = Q->rear = Q->size = 0;
	Q->capacity = N;
	return Q;
}

int isFull(Queue *Q)
{
	return (Q->size == Q->capacity);
}

int isEmpty(Queue *Q)
{
	return !Q->size;
}

void enqueue(Queue *Q, int val)
{
	if (isFull(Q))
		return;
	
	Q->arr[Q->rear] = val;
	Q->size += 1;
	Q->rear += 1;
	if (Q->rear == Q->capacity)
		Q->rear = 0;
		
}

int dequeue(Queue *Q)
{
	if (isEmpty(Q))
		return -1; 

	int item = Q->arr[Q->front];
	Q->size -= 1;
	Q->front += 1;
	if (Q->front == Q->capacity)
		Q->front = 0;

	return item;
}

int getFront(Queue *Q)
{
	if (isEmpty(Q))
		return -1;

	return Q->arr[Q->front];
}

void bfs(Queue *Q, char **grid, int N, int M)
{
	int r, c, inx, pr, pc, nr, nc;

	while (!isEmpty(Q))
	{
		inx = dequeue(Q);
		r = inx / M;
		c = inx % M;
		//printf("[%d, %d]\n", r, c);
		pr = r - 1;
		pc = c - 1;
		nr = r + 1;
		nc = c + 1;

		if ((pr >= 0) && (grid[pr][c] == 'X'))
		{
			grid[pr][c] = 'O';
			enqueue(Q, pr * M + c);
		}

		if ((nr < N) && (grid[nr][c] == 'X'))
		{
			grid[nr][c] = 'O';
			enqueue(Q, nr * M + c);
		}
		
		if ((pc >= 0) && (grid[r][pc] == 'X'))
		{
			grid[r][pc] = 'O';
			enqueue(Q, r * M + pc);
		}

		if ((nc < M) && (grid[r][nc] == 'X'))
		{
			grid[r][nc] = 'O';
			enqueue(Q, r * M + nc);
		}
	}
}

int calcShapesCount(char **grid, int N, int M)
{
	int c = 0;
	Queue *Q = createQueue(N * M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (grid[i][j] == 'X')
			{
				c++;
				grid[i][j] = 'O';
				enqueue(Q, i * M + j);
				bfs(Q, grid, N, M);
			}
		}
	}
	return c;
}

int main()
{
	int T, N, M;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &N);
		scanf("%d", &M);
		char **grid = (char **) malloc(sizeof(char*) * N);
		getchar();
		for (int j = 0; j < N; j++)
		{
			grid[j] = (char *) malloc(sizeof(char) * M + 1);
			fgets(grid[j], M+1, stdin);
			getchar();
			//printf("[%s]\n", grid[j]);
		}

		printf("%d\n", calcShapesCount(grid, N, M));

		for (int k = 0; k < N; k++)
			free(grid[k]);

		free(grid);
	}

	return 0;
}

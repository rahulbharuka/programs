#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int computeBooleanParenthesization(char sym[], char op[])
{
    int N = strlen(sym);
    unsigned long True[N][N], False[N][N], tot_ik, tot_kj;
    
    for (int i = 0; i < N; i++)
    {
        True[i][i] = (sym[i] == 'T') ? 1 : 0;
        False[i][i] = (sym[i] == 'F') ? 1 : 0;
    }
    
    for (int gap = 1; gap < N; gap++)
    {
        for (int i = 0, j = gap; j < N; i++, j++)
        {
            True[i][j] = False[i][j] = 0;
            
            for (int g = 0; g < gap; g++)
            {
                int k = i + g;
                tot_ik = True[i][k] + False[i][k];
                tot_kj = True[k+1][j] + False[k+1][j];
                
                if (op[k] == '&')
                {
                    True[i][j] += True[i][k] * True[k+1][j];
                    False[i][j] += (tot_ik * tot_kj - True[i][k] * True[k+1][j]);
                }
                else if (op[k] == '|')
                {
                    False[i][j] += False[i][k] * False[k+1][j];
                    True[i][j] += (tot_ik * tot_kj - False[i][k] * False[k+1][j]);
                }
                else if (op[k] == '^')
                {
                    True[i][j] += True[i][k] * False[k+1][j] + False[i][k] * True[k+1][j];
                    False[i][j] += False[i][k] * False[k+1][j] + True[i][k] * True[k+1][j];
                }
            }
        }
    }
    
    return ((True[0][N-1])%1003);
}

int main()
{
	int T, N, res;
	char *sym, *op;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
	    scanf("%d", &N);
	    if (!(N%2))
	    {
	        printf("-1\n");
	        continue;
	    }
	    
	    sym = malloc(sizeof(char) * (N+3)/2);
	    op = malloc(sizeof(char) * (N+2)/2);
	    getchar();
	    for(int j = 0, s = 0, p = 0; j < N; j++)
	    {
	        if (!(j%2))
	            scanf("%c", &sym[s++]);
	        else
	            scanf("%c", &op[p++]);
	    }
	    
	    res = computeBooleanParenthesization(sym, op);
	    printf("%d\n", res);
	}
	return 0;
}

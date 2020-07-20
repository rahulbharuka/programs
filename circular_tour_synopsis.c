#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a, b) ((a >= b) ? a : b)

long long countStartingCity(long long n, long long *Fuel, long long *Dist)
{
    long long cur_fuel = 0, start = 0, inx, res;
    for (long long i = 0; (i < n) && (start < n); i++)
    {
        inx = start;
        do
        {
            cur_fuel = cur_fuel + Fuel[inx] - Dist[inx];
        
            if (cur_fuel < 0)
            {
                cur_fuel = 0;
                start = inx + 1;
                break;
            }
            
            inx++;
            if (inx == n)
                inx = 0;
            
        } while (inx != start);
        
        if (inx == start)
            break;
        
    }
    
    if ((start >= n) || (inx != start))
        res = 0;
    else
    {
        //printf("start = %lld\n", start);
        res = 1;
        long long need[n], next_inx;
        need[start] = 0;
        for (long long i = 1; i < n; i++)
        {
            inx = start - i;
            if (inx < 0)
                inx = n + inx;
         
            //printf("i=%lld inx=%lld start=%lld n=%lld\n", i, inx, start, n);
            next_inx = (inx + 1) % n;
            need[inx] = max(0, need[next_inx] + Dist[inx] - Fuel[inx]);
            if (need[inx] == 0)
                res++;
        }
        
    }
    
    return res;
}

int main()
{
    long long n;
    scanf("%lld", &n);
    long long Fuel[n], Dist[n];
    for (long long i = 0; i < n; i++)
        scanf("%lld", &Fuel[i]);
    
    for (long long i = 0; i < n; i++)
        scanf("%lld", &Dist[i]);
    
    printf("%lld", countStartingCity(n, Fuel, Dist));
    return 0;
}

/*
 There are N cities and N directed roads in Steven's world. The cities are numbered from 0 to N - 1. Steven can travel from city i to city (i + 1) % N, ( 0-> 1 -> 2 -> .... -> N - 1 -> 0).

Steven wants to travel around the world by car. The capacity of his car's fuel tank is C gallons. There are a[i] gallons he can use at the beginning of city i and the car takes b[i] gallons to travel from city i to (i + 1) % N.

How many cities can Steven start his car from so that he can travel around the world and reach the same city he started? 
Note

The fuel tank is initially empty.

Input Format

The first line contains two integers (separated by a space): city number N and capacity C.
The second line contains N space-separated integers: a[0], a[1], … , a[N - 1].
The third line contains N space-separated integers: b[0], b[1], … , b[N - 1].

Constraints

2 ≤ N ≤ 105
1 ≤ C ≤ 1018
0 ≤ a[i], b[i] ≤ 109

Output Format

The number of cities which can be chosen as the start city.

Sample Input

3 3
3 1 2
2 2 2

Sample Output

2

 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define min(a, b) ((a <= b) ? a : b)
#define max(a, b) ((a >= b) ? a : b)

long long countStartingCity(long long n, long long vol, long long *A, long long *B)
{
    long long cur_fuel = 0, start = 0, inx, res;
    for (long long i = 0; (i < n) && (start < n); i++)
    {
        inx = start;
        do
        {
            cur_fuel += A[inx];
            cur_fuel = min(cur_fuel, vol);
            cur_fuel -= B[inx];
        
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
            need[inx] = max(0, need[next_inx] + B[inx] - min(vol, A[inx]));
            if (need[inx] == 0)
                res++;
        }
        
    }
    
    return res;
}

int main() {
    long long n, vol;
    scanf("%lld %lld", &n, &vol);
    long long A[n], B[n];
    for (long long i = 0; i < n; i++)
        scanf("%lld", &A[i]);
    
    for (long long i = 0; i < n; i++)
        scanf("%lld", &B[i]);
    
    printf("%lld\n", countStartingCity(n, vol, A, B));
    return 0;
}


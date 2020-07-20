#include<stdio.h>
#include<stdlib.h>

/*
There're 3 kinds of bus ticket. 1: ticket 1 cost 2 and can be used for a day. 2: ticket 2 cost 7 and can be used for a consecutive 7 days. 3: ticket 3 cost 25 can be used for a month. Assume month here means 30 consecutive days.

Now there's a array filled with elements. Each element value is a date for a person to travel. This array has already been sorted in ascending order, like {1,3,4,5,11,12,23,24,30}. Obviously the final day is 30th and first day is 1st.

So for any given array from a person to travel, how can this person cost least ?

Assume that:
-N is an integer within the range [0…30];

-each element of array A is an integer within the range [1…30];

-array A is sorted in increasing order;

-the elements of A are all distinct.

Sample input 1:
9
1 3 4 5 11 12 23 24 30

Sample output 1:
17


Sample Input 2:
1 2 4 5 7 8 9 10 11 12 29 30

Sample Outpur 2:
18

Approach: At every array index there are only two choices- (1) buy 1 day ticket; or (2) buy 7 day ticket. And then we recursively call arr[index+1] to find the solution. For each recursive call, we pass the information (max variable below) to convey the type of last ticket bought. The min of the two recursive call plus the ticket chosen at that index, is the result.
NOTE: This is not an optimal solution since same computation is done multiple time. DP must be used here.

*/


#define MIN(a, b) (a < b ? a: b)

int solve(int *arr, int N, int inx, int max)
{
	int res;
	if (inx >= N)
		res = 0;
	else if (arr[inx] <= max)
		res = solve(arr, N, inx+1, max);
	else
		res = MIN(solve(arr, N, inx+1, arr[inx]+6)+7, solve(arr, N, inx+1, 0)+2);

	//printf("\tinx=%d max=%d res=%d\n", inx, max, res);
	return res;
}

int solve_using_dp(int *arr, int N)
{
	int Cost[N], buy_day_pass, buy_week_pass, j, min_day;
	Cost[0] = 2;
	for (int i = 1; i < N; i++)
	{
		buy_day_pass = Cost[i-1] + 2;
		min_day = arr[i] - 6;

		j = i - 1;
		while((j >= 0) && (arr[j] >= min_day))
			j--;

		buy_week_pass = 7;
		buy_week_pass += (j >= 0) ? Cost[j] : 0;
		Cost[i] = (buy_day_pass < buy_week_pass) ? buy_day_pass : buy_week_pass;
	}

	return Cost[N-1];
}

int main()
{
	int N, *arr, ans = 0, ans_dp = 0;
	scanf("%d", &N);
	arr = (int *) malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	
	if (N <= 3)
		ans = 2 * N;
	else if (N >= 23)
		ans = 25;
	else
	{
		ans = MIN(solve(arr, N, 1, arr[0]+6)+7, solve(arr, N, 1, 0)+2);
		ans = MIN(ans, 25);

		ans_dp = solve_using_dp(arr, N);
		ans_dp = (ans_dp < 25) ? ans_dp : 25;
	}
	printf("Minimum ticket cost = %d\n", ans);
	printf("Minimum ticket cost using DP = %d\n", ans_dp);
	free(arr);
}

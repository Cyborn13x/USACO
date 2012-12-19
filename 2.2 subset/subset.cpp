/*
USER: zobayer1
TASK: subset
LANG: C++
*/

#include <cstdio>
using namespace std;

int dp[80][800];

int main()
{
	int n, s, e, i, j;
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	scanf("%d", &n);
	s = n * (n+1);
	if(s & 3) printf("0\n");
	else
	{
		s >>= 2;
		dp[1][1] = 1;
		for(i=2; i<=n; i++)
		{
			e = ((i+1) * i)>>1;
			for(j=0; j<=e; j++)
				dp[i][j] = ((j>i)? dp[i-1][j-i] : 0) + dp[i-1][j];
			dp[i][e] = 1;
		}
		printf("%d\n", dp[n][s]);
	}
	return 0;
}


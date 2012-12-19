/*
USER: zobayer1
LANG: C++
TASK: money
ALGO: dp
*/

#include <cstdio>
using namespace std;

#define MAX 10001
#define COIN 26

typedef unsigned long long i64;

i64 dp[MAX], coins[COIN];

int main()
{
	int n, v, i, j, c;
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d %d", &v, &n);
	dp[0] = 1;
	for(i=0; i<v; i++)
	{
		scanf("%d", &c);
		for(j=c; j<=n; j++) dp[j] += dp[j-c];
	}
	printf("%llu\n", dp[n]);
	return 0;
}

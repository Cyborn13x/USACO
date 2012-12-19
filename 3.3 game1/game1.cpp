/*
USER: zobayer1
TASK: game1
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[201][201][2];
int a[201], s[201];

void play(int i, int j, int p) {
	if(i==j) {
		dp[i][j][p] = a[i];
		dp[i][j][p^1] = 0;
		return;
	}
	if(dp[i][j][p]!=-1) return;
	play(i+1, j, p^1);
	play(i, j-1, p^1);
	dp[i][j][p] = max(dp[i+1][j][p]+a[i], dp[i][j-1][p]+a[j]);
	dp[i][j][p^1] = s[j]-s[i-1]-dp[i][j][p];
}

int main() {
	int n, i;
	freopen("game1.in", "r", stdin);
	freopen("game1.out", "w", stdout);
	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		s[i] = s[i-1] + a[i];
	}
	memset(dp, -1, sizeof dp);
	play(1, n, 0);
	printf("%d %d\n", dp[1][n][0], dp[1][n][1]);
	return 0;
}
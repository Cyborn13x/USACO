/*
USER: zobayer1
TASK: humble
LANG: C++
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int humble[100001], primes[101], idx[101], temp[101];

int main()
{
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
	int n, k, i, j, minval;
	scanf("%d%d", &k, &n);
	for(i=0; i<k; i++) scanf("%d", &primes[i]);
	for(humble[0]=i=1; i<=n; i++)
	{
		for(j=0; j<k; j++) temp[j] = humble[idx[j]]*primes[j];
		for(minval=temp[0], j=0; j<k; j++) minval = min(minval, temp[j]);
		for(j=0; j<k; j++) if(temp[j]==minval) idx[j]++;
		humble[i] = minval;
	}
	printf("%d\n", humble[n]);
	return 0;
}

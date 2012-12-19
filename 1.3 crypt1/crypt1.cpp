/*
USER: zobayer1
TASK: crypt1
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

#define TASK "crypt1"
#define DEBUG if(0)

bool is[10];
int a[10];

bool isinset(int n, int len)
{
	int cnt = 0;
	while(n)
	{
		if(!is[n%10]) return false;
		cnt++;
		n /= 10;
	}
	if(cnt > len) return false;
	return true;
}

int main()
{
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	int n, i, j, k, n1, n2, p, q, cnt = 0;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
		is[a[i]] = 1;
	}
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			for(k=0; k<n; k++)
				for(p=0; p<n; p++)
					for(q=0; q<n; q++)
					{
						n1 = a[i]*100 + a[j]*10 + a[k];
						n2 = a[p]*10 + a[q];
						if(isinset(n1*a[q], 3) && isinset(n1*a[p], 3) && isinset(n1*n2, 4))
						{
							cnt++;
							//printf("%d %d\n", n1, n2);
						}
					}
	printf("%d\n", cnt);
	return 0;
}

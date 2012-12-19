/*
USER: zobayer1
TASK: lamps
LANG: C++
*/

#include <cstdio>
using namespace std;

#define MAX 64

int n, c, on, off;
int state[MAX];
int bits[6] = {32, 16, 8, 4, 2, 1};

void solve(int curr, int step)
{
	if(step==c)
	{
		if(!state[curr] && (curr & off) == 0 && ~(curr | ~on) == 0)
			state[curr] = 1;
		return;
	}
	solve(curr ^ 63, step + 1); // b1
	solve(curr ^ 42, step + 1); // b2
	solve(curr ^ 21, step + 1); // b3
	solve(curr ^ 36, step + 1); // b4
}

int main()
{
	int i, j, a, f;
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
	scanf("%d %d", &n, &c);
	while(scanf("%d", &a)==1 && a != -1) on |= bits[(a-1)%6];
	while(scanf("%d", &a)==1 && a != -1) off |= bits[(a-1)%6];
	c %= 12;
	f = 0;
	solve(63, 0);
	for(i=0; i<MAX; i++)
	{
		if(state[i])
		{
			f = 1;
			for(j=0; j<n; j++)
			{
				a = i & bits[j%6];
				printf("%c", (a? '1':'0'));
			}
			printf("\n");
		}
	}
	if(!f) printf("IMPOSSIBLE\n");
	return 0;
}


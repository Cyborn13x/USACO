/*
USER: zobayer1
LANG: C++
TASK: comehome
ALGO: dijkstra
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <cctype>
#include <algorithm>
using namespace std;

#define MAX 52
#define pii pair<int,int>

int d[MAX], f[MAX];
vector< pii > graph[MAX];
/*
 * a-z : 0 to 25 ; A-Z : 26 to 51
*/
int main()
{
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
	int e, i, u, v, w, sz, ew, dist;
	char su[2], sv[2], cow;
	scanf("%d", &e);
	for(i=0; i<e; i++)
	{
		scanf("%s%s%d", su, sv, &w);
		u = (isupper(su[0]))? su[0] - 'A' + 26 : su[0] - 'a';
		v = (isupper(sv[0]))? sv[0] - 'A' + 26 : sv[0] - 'a';
		graph[u].push_back(pii(w, v));
		graph[v].push_back(pii(w, u));
	}
	for(i=0; i<51; i++) d[i] = (1<<28);
	d[i] = 0;
	priority_queue< pii, vector< pii >, greater< pii > > Q;
	Q.push(pii(0, 51));
	while(!Q.empty())
	{
		u = Q.top().second;
		w = Q.top().first;
		Q.pop();
		sz = graph[u].size();
		for(i=0; i<sz; i++)
		{
			v = graph[u][i].second;
			ew = graph[u][i].first;
			if(!f[v])
			{
				if(d[u] + ew < d[v])
				{
					d[v] = d[u] + ew;
					Q.push(pii(d[v], v));
				}
			}
		}
		f[u] = 1;
	}
	cow = 'A';
	dist = 1000000000;
	for(i=26; i<51; i++)
	{
		if(d[i] < dist)
		{
			dist = d[i];
			cow = i-26+'A';
		}
	}
	printf("%c %d\n", cow, dist);
	return 0;
}

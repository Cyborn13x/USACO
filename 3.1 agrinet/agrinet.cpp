/*
USER: zobayer1
TASK: agrinet
LANG: C++
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define edge pair<int,int>
#define MAX 1001

vector< pair< int, edge > > GRAPH;
int parent[MAX], total, N;

int findset(int x)
{
    if(x != parent[x])
        parent[x] = findset(parent[x]);
    return parent[x];
}

void kruskal()
{
    int i, sz, pu, pv;
    sort(GRAPH.begin(), GRAPH.end());
    sz = GRAPH.size()-1;
    for(i=total=0; i<sz; i++)
    {
        pu = findset(GRAPH[i].second.first);
        pv = findset(GRAPH[i].second.second);
        if(pu != pv)
        {
            total += GRAPH[i].first;
            parent[pu] = parent[pv];
        }
    }
}

int main()
{
    int i, j, w;
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);
    scanf("%d", &N);
    for(i=1; i<=N; i++)
    {
		parent[i] = i;
		for(j=1; j<=N; j++)
		{
			scanf("%d", &w);
			if(j > i) GRAPH.push_back(pair< int, edge >(w, edge(i, j)));
		}
	}
    kruskal();
    printf("%d\n", total);
    return 0;
}

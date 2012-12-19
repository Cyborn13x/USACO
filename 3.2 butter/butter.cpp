/*
USER: zobayer1
TASK: butter
LANG: C++
*/

#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair< int, int > edge;

const int MAXC = 500;
const int MAXN = 800;
const int INF = 0x3f3f3f3f;

int cowpos[MAXC], ncowpos;
bool f[MAXN];
int d[MAXN];
int N, C, E;
vector< edge > edges[MAXN];

int dist(int s) {
	int i, u, v, w, ret, nedge;
	priority_queue< edge, vector< edge >, greater< edge > > Q;
	memset(f, 0, sizeof(f));
	memset(d, 0x3f, sizeof(d));
	d[s] = 0;
	Q.push(edge(0, s));
	while(!Q.empty()) {
		u = Q.top().second; Q.pop();
		nedge = edges[u].size();
		for(i=0; i<nedge; i++) {
			v = edges[u][i].second;
			w = edges[u][i].first;
			if(!f[v] && d[v] > d[u] + w) {
				d[v] = d[u] + w;
				Q.push(edge(d[v], v));
			}
		}
		f[u] = 1;
	}
	for(i=ret=0; i<ncowpos; i++) ret += d[cowpos[i]];
	return ret;
}

int main() {
	int i, u, v, w, x, res = INF;
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);
	scanf("%d%d%d", &C, &N, &E);
	for(i=ncowpos=0; i<C; i++) {
		scanf("%d", &x);
		cowpos[ncowpos++] = --x;
	}
	for(i=0; i<E; i++) {
		scanf("%d%d%d", &u, &v, &w);
		u--, v--;
		edges[u].push_back(edge(w, v));
		edges[v].push_back(edge(w, u));
	}
	for(i=0; i<N; i++) res = min(res, dist(i));
	printf("%d\n", res);
	return 0;
}


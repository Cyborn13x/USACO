/*
USER: zobayer
TASK: fence
LANG: C++
*/

//#pragma warning (disable: 4786)
//#pragma comment (linker, "/STACK:0x800000")
//#define _CRT_SECURE_NO_WARNINGS 1

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define ALL(p) p.begin(),p.end()
#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const int MAX = 512;

vector< int > G[MAX];
set< int > nodes;
int deg[MAX], flag[MAX][MAX];
int stck[MAX << 1], top;

void traverse(int u) {
	for(int i = 0; i < SZ(G[u]); i++) {
		int v = G[u][i];
		while(flag[u][v] > 0) {
			flag[u][v]--; flag[v][u]--;
			traverse(v);
		}
	}
	stck[top++] = u;
}

int main() {
	READ("fence.in");
	WRITE("fence.out");
	int e, u, v;
	scanf("%d", &e);
	for(int i = 0; i < e; i++) {
		scanf("%d %d", &u, &v);
		G[u].PB(v);
		G[v].PB(u);
		nodes.insert(u);
		nodes.insert(v);
		flag[u][v]++;
		flag[v][u]++;
		deg[u]++;
		deg[v]++;
	}
	int odd = MAX;
	for(set< int >::iterator it = nodes.begin(); it != nodes.end(); it++) {
		sort(ALL(G[*it]));
		if(deg[*it] & 1) odd = _min(odd, *it);
	}
	if(odd == MAX) traverse(*nodes.begin());
	else traverse(odd);
	while(top--) printf("%d\n", stck[top]);
	return 0;
}
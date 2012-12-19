/*
USER: zobayer1
TASK: inflate
LANG: C++
*/

#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cassert>
using namespace std;

#define BUG if(0)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define REP(i,n) for(int i=0; i<(n); i++)
#define READ(x) freopen(x, "r", stdin)
#define WRITE(x) freopen(x, "w", stdout)
#define MAX 10000

int point[MAX+10]; // max point at any time

int main() {
	int M, N, p, t, ans;
	READ("inflate.in");
	WRITE("inflate.out");
	scanf("%d %d", &M, &N);
	REP(i, N) {
		scanf("%d %d", &p, &t);
		point[t] = max(point[t], p);
		FOR(j,t,M) {
			if(point[j-t]) {
				point[j] = max(point[j], point[j-t] + p);
			}
		}
	}
	ans = 0;
	FOR(i,1,M) ans = max(ans, point[i]);
	printf("%d\n", ans);
	return 0;
}
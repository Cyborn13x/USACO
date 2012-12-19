/*
USER: zobayer1
TASK: stamps
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

#define MAX 200*10000

bool flag[MAX+10];
int cnt[MAX+10], values[100];

int main() {
	READ("stamps.in");
	WRITE("stamps.out");
	int K, N, v, maxv = 0;
	scanf("%d %d", &K, &N);
	REP(i, N) {
		scanf("%d", &values[i]);
		maxv = max(maxv, values[i]);
	}
	maxv *= K;
	REP(i, N) {
		v = values[i];
		flag[v] = true;
		cnt[v] = 1;
		FOR(j, v, maxv) {
			if(flag[j-v]) {
				if(!flag[j]) {
					if(cnt[j-v]+1 > K) continue; // crossing limit
					flag[j] = true;
					cnt[j] = cnt[j-v]+1;
				}
				else cnt[j] = min(cnt[j], cnt[j-v]+1);
			}
		}
	}
	FOR(i, 1, maxv+1){
		if(!flag[i]) {
			printf("%d\n", i-1);
			break;
		}
	}
	return 0;
}

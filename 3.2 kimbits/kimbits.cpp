/*
USER: zobayer1
TASK: kimbits
LANG: C++
*/
#include <cassert>
#include <cctype>
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

template< class T > T abs(T n) { return (n < 0 ? -n : n); }
template< class T > T max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }
template< class T > T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inside(T a, T b, T c) { return a<=b && b<=c; }
template< class T > void setmax(T &a, T b) { if(a < b) a = b; }
template< class T > void setmin(T &a, T b) { if(b < a) a = b; }

#define MP(x, y) make_pair(x, y)
#define REV(s, e) reverse(s, e)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define ALL(c) c.begin(), c.end()
#define SIZE(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const double BIG = 1e19;
const int INF = 0x7f7f7f7f;

int main() {
	READ("kimbits.in");
	WRITE("kimbits.out");
	int nCr[32][32] = {0}, i, j, n, b;
	i64 dp[32][32] = {0}, pos, tmp;
	scanf("%d%d%lld", &n, &b, &pos);

	//combination of i bits with exactly j 1 bits
	for(i = 0; i <= n; i++) {
		for(j = 0; j <= i; j++) {
			if(i == j) nCr[i][j] = 1;
			else if(j == 0) nCr[i][j] = 1;
			else if(j == 1) nCr[i][j] = i;
			else nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
		}
	}
	//combination of i bits with at most j 1 bits
	for(i = 0; i <= n; i++) {
		for(j = 0; j <= n; j++) {
			if(j == 0) dp[i][j] = nCr[i][j];
			else dp[i][j] = dp[i][j-1] + nCr[i][j];
		}
	}
	while(n > 0) {
		tmp = dp[--n][b];
		if(tmp >= pos) {
			//using 0 bit, we still will be able to reach target
			putchar('0');
		}
		else {
			//no way, must use a 1 bit, so we jump tmp items
			putchar('1');
			b--, pos -= tmp;
		}
	}
	putchar('\n');
	return 0;
}
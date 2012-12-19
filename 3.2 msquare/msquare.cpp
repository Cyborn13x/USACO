/*
USER: zobayer1
TASK: msquare
LANG: C++
*/

#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <valarray>
using namespace std;

#define DEBUG if(0)
#define PAUSE system("pause")
#define ALL(c) c.begin(), c.end()
#define PB(x) push_back(x)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define BIG(p) memset(p, 0x3f, sizeof(p))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) c.size()

typedef long long i64;
typedef unsigned long long u64;
typedef pair< int, int > pii;

template< class T > T _abs(const T &n) { return (n < 0 ? -n : n); }
template< class T > T _max(const T &a, const T &b) { return (a > b ? a : b); }
template< class T > T _min(const T &a, const T &b) { return (a < b ? a : b); }
template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }
template< class T > bool inrange(const T &a, const T &b, const T &c) { return a<=b && b<=c; }
template< class T > T sq(const T &x) { return x * x; }

const double EPS = 1e-10;
const int INF = 0x3f3f3f3f;
const int MAX = 40320;

struct trie {
	char ch;
	int idx;
	struct trie *next[9];
	trie() {
		for(int i=0; i<9; i++) next[i] = NULL;
		idx = ch = 0;
	}
} *T;

int itemID, Q[MAX+10], printed;

struct node {
	char name[9];
	bool vis;
	int prev, move, dist;
} nodes[MAX+10];

int add(char *str) {
	int i, t;
	struct trie *curr = T;
	for(i=0; i<8; i++) {
		t = str[i]-'0';
		if(curr->next[t]==NULL) {
			curr->next[t] = new trie;
			curr->next[t]->ch = str[i];
			curr = curr->next[t];
		}
		else curr = curr->next[t];
	}
	if(curr->next[0]==NULL) {
		curr->next[0] = new trie;
		i = curr->next[0]->idx = itemID++;
		nodes[i].vis = false;
		nodes[i].move = nodes[i].prev = -1;
		nodes[i].dist = 0;
		strcpy(nodes[i].name, str);
	}
	return curr->next[0]->idx;
}

void getA(char *src, char *dst) {
	dst[0] = src[7]; dst[1] = src[6]; dst[2] = src[5]; dst[3] = src[4];
	dst[7] = src[0]; dst[6] = src[1]; dst[5] = src[2]; dst[4] = src[3];
	dst[8] = 0;
}

void getB(char *src, char *dst) {
	dst[0] = src[3]; dst[1] = src[0]; dst[2] = src[1]; dst[3] = src[2];
	dst[7] = src[4]; dst[6] = src[7]; dst[5] = src[6]; dst[4] = src[5];
	dst[8] = 0;
}

void getC(char *src, char *dst) {
	dst[0] = src[0]; dst[1] = src[6]; dst[2] = src[1]; dst[3] = src[3];
	dst[7] = src[7]; dst[6] = src[5]; dst[5] = src[2]; dst[4] = src[4];
	dst[8] = 0;
}

int bfs(char *src, char *dst) {
	int u, v, st, en, i;
	char str[9];
	void (*getX[])(char*, char*) = {&getA, &getB, &getC};
	u = add(src);
	nodes[u].vis = true;
	st = en = 0;
	Q[en++] = u;
	while(st < en) {
		u = Q[st++];
		if(!strcmp(nodes[u].name, dst)) return u;
		for(i=0; i<3; i++) {
			getX[i](nodes[u].name, str);
			v = add(str);
			if(!nodes[v].vis) {
				nodes[v].vis = true;
				nodes[v].prev = u;
				nodes[v].move = i;
				nodes[v].dist = nodes[u].dist + 1;
				if(!strcmp(nodes[v].name, dst)) return v;
				Q[en++] = v;
			}
		}
	}
	return -1;
}

void printPath(int u) {
	if(nodes[u].prev==-1) return;
	printPath(nodes[u].prev);
	putchar(nodes[u].move + 'A');
	printed++;
	if(printed==60) {
		putchar('\n');
		printed = 0;
	}
}

int main() {
	int i, p;
	char target[9], initial[] = "12345678";
	T = new trie;
	itemID = printed = 0;
	READ("msquare.in"); WRITE("msquare.out");
	for(i=0; i<8; i++) scanf("%s", &target[i]);
	p = bfs(initial, target);
	printf("%d\n", nodes[p].dist);
	printPath(p); putchar('\n');
	return 0;
}

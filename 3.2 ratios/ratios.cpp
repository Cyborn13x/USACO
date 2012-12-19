/*
USER: zobayer1
TASK: ratios
LANG: C++
*/

#include <cstdio>
using namespace std;

const int MAX = 100;
const int INF = 0x1f3f3f3f;

struct triple {
	int a, b, c;
	triple() {}
	triple(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

bool operator<(const triple t1, const triple t2) {
	return (t1.a + t1.b + t1.c) < (t2.a + t2.b + t2.c);
}

int main() {
	triple x, y, z, w, t, r(INF, INF, INF);
	int i, j, k, g, gf, a, b, c;
	freopen("ratios.in", "r", stdin);
	freopen("ratios.out", "w", stdout);
	scanf("%d%d%d", &w.a, &w.b, &w.c);
	scanf("%d%d%d", &x.a, &x.b, &x.c);
	scanf("%d%d%d", &y.a, &y.b, &y.c);
	scanf("%d%d%d", &z.a, &z.b, &z.c);
	for(i=0; i<MAX; i++) {
		for(j=0; j<MAX; j++) {
			for(k=0; k<MAX; k++) {
				a = x.a * i + y.a * j + z.a * k;
				b = x.b * i + y.b * j + z.b * k;
				c = x.c * i + y.c * j + z.c * k;
				if(a % w.a == 0) {
					g = a / w.a;
					if(g && g<MAX && g*w.b==b && g*w.c==c) {
						t = triple(i, j, k);
						if(t < r) {
							r = t;
							gf = g;
						}
					}
				}
			}
		}
	}
	if(r.a==INF) printf("NONE\n");
	else printf("%d %d %d %d\n", r.a, r.b, r.c, gf);
	return 0;
}


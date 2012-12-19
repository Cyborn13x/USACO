/*
USER: zobayer1
TASK: rect1
LANG: C++
*/

#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct Rectangle {
	int x1, x2, y1, y2, c;
	Rectangle() {}
	Rectangle(int _x1, int _y1, int _x2, int _y2, int _c) {
		x1 = _x1, y1 = _y1, x2 = _x2, y2 = _y2, c = _c;
	}
	inline bool valid() {
		return x1<x2 && y1<y2;
	}
	inline int area() {
		return (x2-x1) * (y2-y1);
	}
	inline bool disjoint(const Rectangle &r) {
		return x2<=r.x1 || r.x2<=x1 || y2<=r.y1 || r.y2<=y1;
	}
	inline Rectangle common(const Rectangle &r) {
		return Rectangle(max(x1, r.x1), max(y1, r.y1), min(x2, r.x2), min(y2, r.y2), c);
	}
} RECT;

RECT myRect[2][100000], t, x;
int nRect[2], color[2505], idx, n, mxColor;

inline void process(int j) {
	if(myRect[idx][0].disjoint(myRect[idx^1][j])) myRect[idx][nRect[idx]++] = myRect[idx^1][j];
	else {
		t = myRect[idx][0].common(myRect[idx^1][j]);
		x = RECT(myRect[idx^1][j].x1, myRect[idx^1][j].y1, t.x1, myRect[idx^1][j].y2, myRect[idx^1][j].c);
		if(x.valid()) myRect[idx][nRect[idx]++] = x;
		x = RECT(t.x1, t.y2, t.x2, myRect[idx^1][j].y2, myRect[idx^1][j].c);
		if(x.valid()) myRect[idx][nRect[idx]++] = x;
		x = RECT(t.x2, myRect[idx^1][j].y1, myRect[idx^1][j].x2, myRect[idx^1][j].y2, myRect[idx^1][j].c);
		if(x.valid()) myRect[idx][nRect[idx]++] = x;
		x = RECT(t.x1, myRect[idx^1][j].y1, t.x2, t.y1, myRect[idx^1][j].c);
		if(x.valid()) myRect[idx][nRect[idx]++] = x;
	}
}

int main() {
	freopen("rect1.in", "r", stdin);
	freopen("rect1.out", "w", stdout);
	scanf("%d%d%d", &myRect[idx][nRect[idx]].x2, &myRect[idx][nRect[idx]].y2, &n);
	myRect[idx][nRect[idx]].x1 = myRect[idx][nRect[idx]].y1 = 0;
	myRect[idx][nRect[idx]].c = 1;
	nRect[idx]++;
	for(int i=0; i<n; i++) {
		idx ^= 1; nRect[idx] = 0;
		scanf("%d%d%d%d%d", &t.x1, &t.y1, &t.x2, &t.y2, &t.c);
		myRect[idx][nRect[idx]++] = t;
		for(int j=0; j<nRect[idx^1]; j++) process(j);
	}
	for(int i=0; i<nRect[idx]; i++) {
		color[myRect[idx][i].c] += myRect[idx][i].area();
		mxColor = max(mxColor, myRect[idx][i].c);
	}
	for(int i=1; i<=mxColor; i++)
		if(color[i])
			printf("%d %d\n", i, color[i]);
	return 0;
}
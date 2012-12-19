/*
USER: zobayer1
TASK: spin
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

typedef struct {
	int st, sp;
} Wedge;

typedef struct {
	int speed, nwedges;
	Wedge *wedges;
} Wheel;

Wheel wheels[5];
char flag[5][360];

void rotate(int rotate) {
	int i, j, k, s;
	for(i = 0; i < 5 && rotate; i++) {
		for(j = 0; j < wheels[i].nwedges; j++) {
			wheels[i].wedges[j].st = (wheels[i].wedges[j].st + wheels[i].speed) % 360;
		}
	}
	memset(flag, 0, sizeof flag);
	for(i = 0; i < 5; i++) {
		for(j = 0; j < wheels[i].nwedges; j++) {
			s = wheels[i].wedges[j].st + wheels[i].wedges[j].sp;
			for(k = wheels[i].wedges[j].st; k <= s; k++) {
				flag[i][k%360] = 1;
			}
		}
	}
}

bool passes() {
	int i, j;
	for(j = 0; j < 360; j++) {
		for(i = 0; i < 5; i++) if(!flag[i][j]) break;
		if(i == 5) return true;
	}
	return false;
}

int gettime() {
	for(int i = 0; i < 1024; i++) {
		rotate(i);
		if(passes()) return i;
	}
	return -1;
}

int main() {
	int i, j;
	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);
	for(i = 0; i < 5; i++) {
		scanf("%d %d", &wheels[i].speed, &wheels[i].nwedges);
		wheels[i].wedges = new Wedge[wheels[i].nwedges];
		for(j = 0; j < wheels[i].nwedges; j++) {
			scanf("%d %d", &wheels[i].wedges[j].st, &wheels[i].wedges[j].sp);
		}
	}
	i = gettime();
	if(i == -1) puts("none");
	else printf("%d\n", i);
	return 0;
}
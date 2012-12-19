/*
USER: zobayer1
PROG: packrec
LANG: C++
*/

#include <cstdio>
using namespace std;

bool flag[210][210];
int best, R[4][2];

int max2(int a, int b)
{
	return (a>b)? a : b;
}

int max3(int a, int b, int c)
{
	return max2(max2(a,b),c);
}

int max4(int a, int b, int c, int d)
{
	return max2(max3(a,b,c),d);
}

void update(int x, int y)
{
	if(x*y < best) best = x*y;
	flag[x][y] = flag[y][x] = true;
}

void assign(int ax, int ay, int bx, int by, int cx, int cy, int dx, int dy)
{
	update(max4(ax,bx,cx,dx),ay+by+cy+dy);
	update(max3(ax,bx,cx)+dx,max2(ay+by+cy,dy));
	update(max2(ax+bx,cx)+dx,max2(max2(ay,by)+cy,dy));
	update(max3(ax,bx+cx,dx),ay+max2(by,cy)+dy);
	if(ax>bx||cx<dx||by>dy) return;
	update(max2(ax+cx,bx+dx),max2(ay+by,cy+dy));
}

inline void search(long a,long b,long c,long d)
{
	assign(R[a][0],R[a][1],R[b][0],R[b][1],R[c][0],R[c][1],R[d][0],R[d][1]);
	assign(R[a][1],R[a][0],R[b][0],R[b][1],R[c][0],R[c][1],R[d][0],R[d][1]);
	assign(R[a][0],R[a][1],R[b][1],R[b][0],R[c][1],R[c][0],R[d][0],R[d][1]);
	assign(R[a][0],R[a][1],R[b][0],R[b][1],R[c][1],R[c][0],R[d][0],R[d][1]);
	assign(R[a][0],R[a][1],R[b][0],R[b][1],R[c][0],R[c][1],R[d][1],R[d][0]);
	assign(R[a][1],R[a][0],R[b][1],R[b][0],R[c][0],R[c][1],R[d][0],R[d][1]);
	assign(R[a][0],R[a][1],R[b][1],R[b][0],R[c][1],R[c][0],R[d][0],R[d][1]);
	assign(R[a][0],R[a][1],R[b][0],R[b][1],R[c][1],R[c][0],R[d][1],R[d][0]);
	assign(R[a][1],R[a][0],R[b][0],R[b][1],R[c][0],R[c][1],R[d][1],R[d][0]);
	assign(R[a][1],R[a][0],R[b][0],R[b][1],R[c][1],R[c][0],R[d][0],R[d][1]);
	assign(R[a][1],R[a][0],R[b][0],R[b][1],R[c][0],R[c][1],R[d][1],R[d][0]);
	assign(R[a][1],R[a][0],R[b][1],R[b][0],R[c][1],R[c][0],R[d][1],R[d][0]);
	assign(R[a][0],R[a][1],R[b][1],R[b][0],R[c][1],R[c][0],R[d][1],R[d][0]);
	assign(R[a][1],R[a][0],R[b][0],R[b][1],R[c][1],R[c][0],R[d][1],R[d][0]);
	assign(R[a][1],R[a][0],R[b][1],R[b][0],R[c][0],R[c][1],R[d][1],R[d][0]);
	assign(R[a][1],R[a][0],R[b][1],R[b][0],R[c][1],R[c][0],R[d][0],R[d][1]);
}

int main()
{
	int i, j;
	FILE *fi = fopen("packrec.in","r");
	FILE *fo = fopen("packrec.out","w");
	for(i=0;i<4;i++)
		fscanf(fi,"%d%d",&R[i][0], &R[i][1]);
	best = 100000000;
	search(0,1,2,3);
	search(0,1,3,2);
	search(0,2,1,3);
	search(0,2,3,1);
	search(0,3,1,2);
	search(0,3,2,1);
	search(1,0,2,3);
	search(1,0,3,2);
	search(1,2,0,3);
	search(1,2,3,0);
	search(1,3,0,2);
	search(1,3,2,0);
	search(2,0,1,3);
	search(2,0,3,1);
	search(2,1,0,3);
	search(2,1,3,0);
	search(2,3,0,1);
	search(2,3,1,0);
	search(3,0,1,2);
	search(3,0,2,1);
	search(3,1,0,2);
	search(3,1,2,0);
	search(3,2,0,1);
	search(3,2,1,0);
	fprintf(fo,"%d\n",best);
	for(i=1;;i++)
	{
		if(best%i) continue;
		j=best/i;
		if(i>j) break;
		if(flag[i][j]) fprintf(fo,"%d %d\n",i,j);
	}
	return 0;
}

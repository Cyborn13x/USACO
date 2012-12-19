/*
USER: zobayer1
PROG: milk3
LANG: C++
*/

#include <cstdio>
#include <algorithm>
using namespace std;

#define MAX 21

bool flag[MAX][MAX], take[MAX];
int a, b, c;

void dfs(int x, int y, int z)
{
	if(flag[x][y]) return;
	flag[x][y] = true;
	if(!x) take[z] = true;
	if(x>0 && y<b) dfs(max(0,x+y-b),min(b,x+y),z);
	if(x>0 && z<c) dfs(max(0,x+z-c),y,min(c,x+z));
	if(y>0 && x<a) dfs(min(a,y+x),max(0,y+x-a),z);
	if(y>0 && z<c) dfs(x,max(0,y+z-c),min(c,y+z));
	if(z>0 && x<a) dfs(min(a,z+x),y,max(0,z+x-a));
	if(z>0 && y<b) dfs(x,min(b,z+y),max(0,z+y-b));
}

int main()
{
	int i, s=0;
	FILE *fin = fopen("milk3.in","r");
	FILE *fout = fopen("milk3.out","w");
	fscanf(fin,"%d%d%d",&a,&b,&c);
	dfs(0,0,c);
	for(int i=0;i<c;i++)
		if(take[i])
			fprintf(fout,"%d ",i);
	fprintf(fout,"%d\n",c);
	return 0;
}

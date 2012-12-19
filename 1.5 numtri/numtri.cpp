/*
USER: zobayer1
PROG: numtri
LANG: C++
*/

#include <cstdio>
using namespace std;

#define MAX 1001

struct TRI{
	int val, csum;
} tri[MAX][MAX];

void settri(int i, int j)
{
	int max, tmp1, tmp2;
	tmp1 = tri[i][j].val + tri[i-1][j-1].csum;
	tmp2 = tri[i][j].val + tri[i-1][j].csum;
	max = (tmp1 > tmp2)? tmp1 : tmp2;
	tri[i][j].csum = max;
}

int main()
{
	int n, i, j, max;
	FILE *fi = fopen("numtri.in","r");
	FILE *fo = fopen("numtri.out","w");
	fscanf(fi,"%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<=i;j++)
			fscanf(fi,"%d",&tri[i][j].val);
	tri[0][0].csum = tri[0][0].val;
	for(i=1;i<n;i++)
	{
		tri[i][0].csum = tri[i-1][0].csum + tri[i][0].val;
		tri[i][i].csum = tri[i-1][i-1].csum + tri[i][i].val;
	}
	for(i=2;i<n;i++)
		for(j=1;j<i;j++)
			settri(i, j);
	max = tri[n-1][0].csum;
	for(j=1;j<n;j++)
		if(tri[n-1][j].csum > max)
			max = tri[n-1][j].csum;
	fprintf(fo,"%d\n",max);
	return 0;
}

/*
USER: zobayer1
PROG: clocks
LANG: C++
*/

#include <cstdio>
using namespace std;

int type[9];
int moves[9][9] = {
	{3,3,3,3,3,2,3,2,0},
	{2,3,2,3,2,3,1,0,1},
	{3,3,3,2,3,3,0,2,3},
	{2,3,1,3,2,0,2,3,1},
	{2,3,2,3,1,3,2,3,2},
	{1,3,2,0,2,3,1,3,2},
	{3,2,0,3,3,2,3,3,3},
	{1,0,1,3,2,3,2,3,2},
	{0,2,3,2,3,3,3,3,3}
};

int main()
{
	int i, j, k;
	FILE *fi, *fo;
	fi = fopen("clocks.in","r");
	fo = fopen("clocks.out","w");
	for(i=0;i<9;i++)
	{
		fscanf(fi,"%d",&k);
		for(j=0;j<9;j++)
			type[j] = (type[j]+(4-k/3)*moves[i][j])%4;
	}
	for(i=k=0;i<9;i++)
		for(j=0;j<type[i];j++)
			if(!k)
			{
				fprintf(fo,"%d",i+1);
				k = 1;
			}
			else fprintf(fo," %d",i+1);
	fprintf(fo,"\n");
	return 0;
}
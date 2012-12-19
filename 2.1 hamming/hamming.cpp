/*
USER: zobayer1
PROG: hamming
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

FILE *fin = fopen("hamming.in","r");
FILE *fout = fopen("hamming.out","w");
int N, B, D, max = 1, found = 0;
int dist[256][256], res[64];

int get_dist(int i, int j)
{
	int k, cnt = 0;
	for(k=1;k<=B;k++,i/=2,j/=2)
		if(i%2 != j%2)
			cnt++;
	return cnt;
}

void calc_dist()
{
	for(int i=0;i<max;i++)
		for(int j=i+1;j<max;j++)
			dist[i][j] = dist[j][i] = get_dist(i,j);
}

void dfs(int n, int t)
{
	int i, j;
	if(t==N)
	{
		found = 1;
		return;
	}
	for(i=n+1;i<max && !found;i++)
	{
		if(dist[n][i]>=D)
		{
			for(j=0;j<t;j++)
				if(dist[i][res[j]]<D)
					break;
			if(j==t)
			{
				res[t] = i;
				dfs(i,t+1);
			}
		}
	}
}

void print()
{
	fprintf(fout,"%d",res[0]);
	for(int i=1;i<N;i++)
		fprintf(fout,"%c%d",i%10==0? '\n' : ' ',res[i]);
	fprintf(fout,"\n");
}

int main()
{
	fscanf(fin,"%d%d%d",&N,&B,&D);
	max <<= B;
	calc_dist();
	for(int i=0;i<max && !found;i++)
	{
		res[0] = i;
		dfs(i,1);
	}
	print();
	return 0;
}

/*
USER: zobayer1
PROG: sprime
LANG: C++
*/

#include <cstdio>
using namespace std;

FILE *fi, *fo;

bool isprime(int n)
{
	if(n<2) return false;
	if(n==2) return true;
	if(n%2==0) return false;
	for(int i=3;i*i<=n;i+=2)
		if(n%i==0)
			return false;
	return true;
}

void dfs(int n, int d, int s)
{
	if(!isprime(n)) return;
	if(s==d)
	{
		fprintf(fo,"%d\n",n);
		return;
	}
	for(int i=1;i<=9;i+=2) dfs(n*10+i,d+1,s);
}

int main()
{
	int s, ssp[4] = {2,3,5,7};
	fi = fopen("sprime.in","r");
	fo = fopen("sprime.out","w");
	fscanf(fi,"%d",&s);
	for(int i=0;i<4;i++)
		dfs(ssp[i],1,s);
	return 0;
}
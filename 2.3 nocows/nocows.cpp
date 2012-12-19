/*
USER: zobayer1
LANG: C++
TASK: nocows
*/

#include <stdio.h>
#include <string.h>

// states: nodes, height
int exact[202][101], smaller[202][101];

int smallTrees(int n, int k)
{
	if(n<0 || k<=0) return 0;
	if(k==1) return n==1;
	if(n<=1) return 1;
	
	int &ret = smaller[n][k], l, r;
	if(ret!=-1) return ret;
	
	ret = 0;
	for(int i=1; i<n-1; i++)
	{
		l = i, r = n-1-i;
		if(l && r)
		{
			ret += smallTrees(l, k-1)*smallTrees(r, k-1);
			ret %= 9901;
		}
	}
	return ret;
}

int exactTrees(int n, int k)
{
	if(k==1) return n==1;
	if(n<=1) return 0;
	
	int &ret = exact[n][k], l, r;
	if(ret!=-1) return ret;
	ret = 0;
	for(int i=1; i<n-1; i++)
	{
		l = i, r = n-1-i;
		if(l && r)
		{
			ret += exactTrees(l, k-1)*exactTrees(r, k-1);
			ret += exactTrees(l, k-1)*smallTrees(r, k-2);
			ret += smallTrees(l, k-2)*exactTrees(r, k-1);
			ret %= 9901;
		}
	}
	return ret;
}

int main()
{
	int n, k;
	freopen("nocows.in", "r", stdin);
	freopen("nocows.out", "w", stdout);
	scanf("%d%d", &n, &k);
	memset(exact, -1, sizeof(exact));
	memset(smaller, -1, sizeof(smaller));
	printf("%d\n", exactTrees(n, k));
	return 0;
}


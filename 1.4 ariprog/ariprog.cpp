/*
USER: zobayer1
PROG: ariprog
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
using namespace std;

int num[31627];
bool flag[125001];

struct ANS{
	int x, y;
} ans[10001];

int comp1(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int comp2(const void *a, const void *b)
{
	ANS *p = (ANS *)a;
	ANS *q = (ANS *)b;
	return (p->y==q->y? p->x-q->x : p->y-q->y);
}

int main()
{
	FILE *fi, *fo;
	fi = fopen("ariprog.in","r");
	fo = fopen("ariprog.out","w");
	int n, m, n_num = 0, n_ans = 0, i, j, k, a, b;
	bool take;
	fscanf(fi,"%d%d",&n,&m);
	for(i=0;i<=m;i++)
		for(j=i;j<=m;j++)
			if(!flag[i*i+j*j])
			{
				flag[i*i+j*j] = true;
				num[++n_num] = i*i+j*j;
			}
	qsort(&num[1],n_num,sizeof(int),comp1);
	for(i=1;i<=n_num-n+1;i++)
	{
		for(j=i+1;j<=n_num-n+2;j++)
		{
			a = num[i];
			b = num[j] - num[i];
			if(!b) continue;
			if(a+(n-1)*b > m*m*2) break;
			take = true;
			for(k=2;k<n;k++)
				if(!flag[a+k*b])
				{
					take = false;
					break;
				}
			if(take)
			{
				ans[++n_ans].x = a;
				ans[n_ans].y = b;
			}
		}
	}
	qsort(&ans[1],n_ans,sizeof(ANS),comp2);
	for(i=1;i<=n_ans;i++)
		fprintf(fo,"%d %d\n",ans[i].x, ans[i].y);
	if(n_ans==0) fprintf(fo,"NONE\n");
	return 0;
}
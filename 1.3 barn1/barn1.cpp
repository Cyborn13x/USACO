/*
ID: zobayer1
PROG: barn1
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

bool stall[202];
int M, S, C;
int gaps[202];

int compF(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

void range(int &F, int &L)
{
	int i;
	for(i=1;i<=S;i++)
	{
		if(stall[i])
		{
			F = i;
			break;
		}
	}
	for(i=S;i>0;i--)
	{
		if(stall[i])
		{
			L = i;
			break;
		}
	}
}

int getGap(int F, int L)
{
	int i, k=0;
	bool flag = true;
	for(i=F;i<=L;i++)
	{
		if(!flag && stall[i])
		{
			k++;
			flag = true;
		}
		else if(!stall[i])
		{
			gaps[k]++;
			flag = false;
		}
	}
	qsort(gaps,k,sizeof(int),compF);
	return k;
}

int main()
{
	FILE *fi = fopen("barn1.in","r");
	FILE *fo = fopen("barn1.out","w");
	int i, k, indx, F, L, totalGap = 0;
	fscanf(fi,"%d%d%d",&M,&S,&C);
	for(i=0;i<C;i++)
	{
		fscanf(fi,"%d",&indx);
		stall[indx] = true;
	}
	range(F,L);
	k = getGap(F,L);
	for(i=0;i<M-1 && i<k;i++)
		totalGap += gaps[i];
	fprintf(fo,"%d\n",L-F+1-totalGap);
	return 0;
}

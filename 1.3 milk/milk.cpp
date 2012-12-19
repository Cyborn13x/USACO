/*
ID: zobayer1
PROG: milk
LANG: C++
*/

#include <stdio.h>
#include <stdlib.h>

struct MILK {
	int amount;
	int value;
} milk[5001];

int comp(const void *a, const void *b)
{
	MILK *x = (MILK *)a;
	MILK *y = (MILK *)b;
	return (x->value > y->value);
}

int main()
{
	FILE *fi = fopen("milk.in","r");
	FILE *fo = fopen("milk.out","w");
	int i, N, M;
	int totalcost = 0, totalamount = 0;
	fscanf(fi,"%d%d",&N,&M);
	for(i=0;i<M;i++)
		fscanf(fi,"%d%d",&milk[i].value,&milk[i].amount);
	qsort(milk,M,sizeof(MILK),comp);
	for(i=0;i<M;i++)
	{
		if(milk[i].amount > N - totalamount)
		{
			totalcost += milk[i].value * (N-totalamount);
			totalamount += (N - totalamount);
		}
		else
		{
			totalcost += milk[i].value * milk[i].amount;
			totalamount += milk[i].amount;
		}
		if(totalamount == N) break;
	}
	fprintf(fo,"%d\n",totalcost);
	return 0;
}

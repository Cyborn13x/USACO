/*
ID: zobayer1
PROG: milk2
LANG: C++
*/

#include <stdlib.h>
#include <stdio.h>

struct farmer{
	int s; // start
	int f; // finish
} F[5000];

int comp(const void *a, const void *b)
{
	farmer *x = (farmer *)a;
	farmer *y = (farmer *)b;
	if(x->s > y->s || (x->s == y->s && x->f > y->f)) return 1;
	return -1;
}

int main()
{
	int n, i, busy, idle, start, finish, max_busy, max_idle;
	FILE *in, *out;
	in = fopen("milk2.in","r");
	out = fopen("milk2.out","w");
	fscanf(in,"%d",&n);
	for(i=0;i<n;i++) fscanf(in,"%d%d",&F[i].s,&F[i].f);
	qsort(F,n,sizeof(farmer),comp);
	start = F[0].s; finish = F[0].f;
	max_busy = max_idle = 0;
	for(i=1;i<n;i++)
	{
		if(F[i].s <= finish && F[i].f > finish) finish = F[i].f;
		if(F[i].s > finish)
		{
			busy = finish - start;
			idle = F[i].s - finish;
			if(busy > max_busy) max_busy = busy;
			if(idle > max_idle) max_idle = idle;
			start = F[i].s; finish = F[i].f;
		}
	}
	busy = finish - start;
	if(busy > max_busy) max_busy = busy;
	fprintf(out,"%d %d\n",max_busy,max_idle);
	return 0;
}

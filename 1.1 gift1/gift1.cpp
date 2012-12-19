/*
ID: zobayer1
PROG: gift1
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

char temp[20], name[10][20];
int money[10];

int main()
{
	int i, n, k, g, j, l, m, cash;
	FILE *in = fopen("gift1.in","r");
	FILE *out = fopen("gift1.out","w");
	
	fscanf(in,"%d",&n);
	for(i=0;i<n;i++)
		fscanf(in,"%s",name[i]);
	while(fscanf(in,"%s",temp)==1)
	{
		for(i=0;i<n;i++)
			if(!strcmp(temp,name[i]))
				break;
		fscanf(in,"%d%d",&cash,&k);
		if(k)
		{
			g = cash / k;
			m = cash % k;
			money[i] += (m - cash);
		}
		else money[i] -= cash;
		for(j=0;j<k;j++)
		{
			fscanf(in,"%s",temp);
			for(l=0;l<n;l++)
				if(!strcmp(temp,name[l]))
					break;
			money[l] += g;
		}
	}
	for(i=0;i<n;i++)
		fprintf(out,"%s %d\n",name[i],money[i]);
	return 0;
}

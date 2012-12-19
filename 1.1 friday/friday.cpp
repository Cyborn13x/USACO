/*
ID: zobayer1
PROG: friday
LANG: C++
*/

#include <cstdio>
using namespace std;

int day[7]; // starts from monday
int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
// (mod 7) seq: mon, tue, wed, thr, fri, sat, sun

bool isLeap(int y)
{
	return (!(y%400) || (!(y%4) && y%100));
}

int main()
{
	FILE *in = fopen("friday.in","r");
	FILE *out = fopen("friday.out","w");
	
	int n, c13, i, j;
	fscanf(in,"%d",&n);
	n = 1900 + n -1;
	c13 = 12;
	for(i=1900;i<=n;i++)
	{
		month[1] = (isLeap(i))? 29 : 28;
		for(j=0;j<12;j++)
		{
			day[c13%7]++;
			c13 += month[j];
		}
	}
	fprintf(out,"%d %d %d %d %d %d %d\n",day[5],day[6],day[0],day[1],day[2],day[3],day[4]);
	return 0;
}

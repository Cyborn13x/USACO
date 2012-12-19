/*
USER: zobayer1
PROG: sort3
LANG: C++
*/

#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int i, n;
	int a[1001];
	int count[3] = {0}, bucket[3];
	int s12, s13, s21, s23, s31, s32, res;
	s12 = s13 = s21 = s23 = s31 = s32 = 0;
	FILE *fin = fopen("sort3.in","r");
	FILE *fout = fopen("sort3.out","w");
	fscanf(fin,"%d",&n);
	for(i=0;i<n;i++)
	{
		fscanf(fin,"%d",&a[i]);
		count[a[i]-1]++;
	}
	bucket[0] = 0;
	bucket[1] = count[0];
	bucket[2] = count[0]+count[1];
	for(i=0;i<bucket[1];i++)
	{
		if(a[i]==2) s12++;
		if(a[i]==3) s13++;
	}
	for(i=bucket[1];i<bucket[2];i++)
	{
		if(a[i]==1) s21++;
		if(a[i]==3) s23++;
	}
	for(i=bucket[2];i<n;i++)
	{
		if(a[i]==1) s31++;
		if(a[i]==2) s32++;
	}
	res = min(s12,s21)+min(s13,s31)+min(s23,s32)+2*(max(s12,s21)-min(s12,s21));
	fprintf(fout,"%d\n",res);
	fclose(fin);
	fclose(fout);
	return 0;
}
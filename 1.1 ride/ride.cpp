/*
ID: zobayer1
PROG: ride
LANG: C++
*/

#include <cstdio>
using namespace std;

int main()
{
	int i, a, b;
	char str1[10], str2[10];
	FILE *in = fopen("ride.in","r");
	FILE *out = fopen("ride.out","w");
	
	fscanf(in,"%s%s",str1,str2);
	for(i=0,a=1;str1[i];i++) a *= (str1[i]-'A' +1);
	for(i=0,b=1;str2[i];i++) b *= (str2[i]-'A' +1);
	a %= 47; b %= 47;
	
	fprintf(out,"%s\n",(a==b)? "GO" : "STAY");
	return 0;
}

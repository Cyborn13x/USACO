/*
ID: zobayer1
PROG: test
LANG: C++
*/

#include <cstdio>
using namespace std;

int main()
{
	int a, b;
	FILE *in, *out;
	in = fopen("test.in","r");
	out = fopen("test.out","w");
	fscanf(in,"%d%d",&a,&b);
	fprintf(out,"%d\n",a+b);
	return 0;
}

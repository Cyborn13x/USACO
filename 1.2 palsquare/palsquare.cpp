/*
ID: zobayer1
PROG: palsquare
LANG: C++
*/

#include <stdio.h>

char convert[21] = {"0123456789ABCDEFGHIJ"};

void d_to_n(int dec, char *res, int base, int &k)
{
	k = 0;
	while(dec)
	{
		res[k++] = convert[dec%base];
		dec /= base;
	}
	res[k] = 0;
}

bool isPalin(char *str, int len)
{
	for(int i=0,j=len-1;i<j;i++,j--)
		if(str[i]!=str[j])
			return false;
	return true;
}

void rev(char *str, int len)
{
	for(int i=0,j=len-1;i<j;i++,j--) str[i] ^= str[j] ^= str[i] ^= str[j];
}

int main()
{
	int i, base, k;
	char res[100], num[100];
	FILE *in, *out;
	in = fopen("palsquare.in","r");
	out = fopen("palsquare.out","w");
	fscanf(in,"%d",&base);
	for(i=1;i<=300;i++)
	{
		d_to_n(i*i, res, base, k);
		if(isPalin(res, k))
		{
			d_to_n(i, num, base, k);
			rev(num, k);
			fprintf(out,"%s %s\n",num,res);
		}
	}
	return 0;
}

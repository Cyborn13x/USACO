/*
ID: zobayer
PROG: dualpal
LANG: C++
*/

#include <stdio.h>
#include <string.h>

bool isPal(char *str)
{
	for(int i=0,j=strlen(str)-1;i<j;i++,j--)
		if(str[i]!=str[j])
			return false;
	return true;
}

void getNBased(int n, int b, char *str)
{
	int k=0;
	while(n)
	{
		str[k++] = n%b + '0';
		n /= b;
	}
	str[k] = 0;
}

int main()
{
	FILE *fi = fopen("dualpal.in","r");
	FILE *fo = fopen("dualpal.out","w");
	int N, S;
	int i, j, k, n;
	char temp[50];
	fscanf(fi,"%d%d",&N,&S);
	for(i=S+1,n=0;n<N;i++)
	{
		for(j=2,k=0;j<=10;j++)
		{
			getNBased(i,j,temp);
			if(isPal(temp))
				k++;
			if(k==2)
			{
				fprintf(fo,"%d\n",i);
				n++;
				break;
			}
		}
	}
	return 0;
}

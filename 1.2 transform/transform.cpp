/*
ID: zobayer1
PROG: transform
LANG: C++
*/

#include <stdio.h>
#include <string.h>

void rotate_90(char sh1[][11], char sh3[][11], int n)
{
	int i, j, p, q;
	for(i=0,p=0;i<n;i++,p++)
	{
		for(j=0,q=n-1;j<n;j++,q--)
			sh3[i][j] = sh1[q][p];
		sh3[i][j] = 0;
	}
}

void rotate_180(char sh1[][11], char sh3[][11], int n)
{
	int i, j, p, q;
	for(i=0,p=n-1;i<n;i++,p--)
	{
		for(j=0,q=n-1;j<n;j++,q--)
			sh3[i][j] = sh1[p][q];
		sh3[i][j] = 0;
	}
}

void rotate_270(char sh1[][11], char sh3[][11], int n)
{
	int i, j, p, q;
	for(i=0,p=n-1;i<n;i++,p--)
	{
		for(j=0,q=0;j<n;j++,q++)
			sh3[i][j] = sh1[q][p];
		sh3[i][j] = 0;
	}
}

void reflect(char sh1[][11], char sh3[][11], int n)
{
	int i, j, k;
	for(i=0;i<n;i++)
	{
		for(j=0,k=n-1;j<n;j++,k--)
			sh3[i][j] = sh1[i][k];
		sh3[i][j] = 0;
	}
}

bool check(char sh2[][11], char sh3[][11], int n)
{
	for(int i=0;i<n;i++)
		if(strcmp(sh2[i],sh3[i]))
			return false;
	return true;
}

int main()
{
	int i, n;
	char sh1[10][11], sh2[10][11], sh3[10][11], sh4[10][11];
	FILE *in, *out;
	in = fopen("transform.in","r");
	out = fopen("transform.out","w");
	fscanf(in,"%d",&n);
	for(i=0;i<n;i++) fscanf(in,"%s",sh1[i]);
	for(i=0;i<n;i++) fscanf(in,"%s",sh2[i]);
	rotate_90(sh1, sh3, n);
	if(check(sh2, sh3, n))
	{
		fprintf(out,"1\n");
		return 0;
	}
	rotate_180(sh1, sh3, n);
	if(check(sh2, sh3, n))
	{
		fprintf(out,"2\n");
		return 0;
	}
	rotate_270(sh1, sh3, n);
	if(check(sh2, sh3, n))
	{
		fprintf(out,"3\n");
		return 0;
	}
	reflect(sh1, sh3, n);
	if(check(sh2, sh3, n))
	{
		fprintf(out,"4\n");
		return 0;
	}
	reflect(sh1, sh4, n);
	rotate_90(sh4, sh3, n);
	if(check(sh2, sh3, n))
	{
		fprintf(out,"5\n");
		return 0;
	}rotate_180(sh4, sh3, n);
	if(check(sh2, sh3, n))
	{
		fprintf(out,"5\n");
		return 0;
	}
	rotate_270(sh4, sh3, n);
	if(check(sh2, sh3, n))
	{
		fprintf(out,"5\n");
		return 0;
	}
	if(check(sh1, sh2, n))
	{
		fprintf(out,"6\n");
		return 0;
	}
	fprintf(out,"7\n");
	return 0;
}

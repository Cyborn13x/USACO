/*
ID: zobayer1
PROG: beads
LANG: C++
*/

#include <stdio.h>

int count_frd(char *str, int len, int ptr, int &k)
{
	char pre = str[ptr];
	int i, count = 1;
	for(i=(ptr+1)%len;;i++)
	{
		if(str[i%len]!=pre && str[i%len]!='w') break;
		else
		{
			count++;
			k = i%len;
		}
	}
	return count;
}

int count_bck(char *str, char pre, int len, int ptr, int k)
{
	int i, count = 1;
	for(i=(ptr+len-1)%len;(i+len)%len!=k;i--)
	{
		if(str[(i+len)%len]!=pre && str[(i+len)%len]!='w') break;
		else count++;
	}
	return count;
}

int main()
{
	char str[1000], pre;
	int len, count, i, max, k;
	FILE *in = fopen("beads.in","r");
	FILE *out = fopen("beads.out","w");
	fscanf(in,"%d%s",&len,str);
	for(i=0;i<len;i++)
		if(str[i]!='w')
			break;
	if(i==len)
	{
		fprintf(out,"%d\n",len);
		return 0;
	}
	pre = str[i];
	for(i=(i+1)%len,max=0;i<len;i++)
	{
		count = 0;
		if(str[i]!=pre && str[i]!='w')
		{
			count += count_frd(str, len, i, k);
			count += count_bck(str, pre, len, (i+len-1)%len, k);
		}
		if(str[i]!='w') pre = str[i];
		if(count>max) max = count;
	}
	if(max==0) fprintf(out,"%d\n",len);
	else fprintf(out,"%d\n",max);
	return 0;
}

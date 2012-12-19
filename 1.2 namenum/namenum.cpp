/*
ID: zobayer1
PROG: namenum
LANG: C++
*/

#include <stdio.h>
#include <string.h>

char d[4620][40], num[15];
int alph[26];
char letter[10][4] = {"","","ABC","DEF","GHI","JKL","MNO","PRS","TUV","WXY"};
int number[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};

int main()
{
	int st, len, i=0, flag, j, k, ptr;
	FILE *in, *out, *dict;
	in = fopen("namenum.in","r");
	out = fopen("namenum.out","w");
	dict = fopen("dict.txt","r");
	while(fscanf(dict,"%s",d[i])==1)
	{
		alph[d[i][0]-'A']++;
		i++;
	}
	for(i=1;i<26;i++) alph[i] = alph[i-1] + alph[i];
	for(i=25;i>0;i--) alph[i] = alph[i-1];
	alph[0] = flag = 0;
	fscanf(in,"%s",num);
	len = strlen(num);
	st = num[0]-'0';
	for(k=0;k<3;k++)
	{
		ptr = letter[st][k]-'A';
		for(i=alph[ptr];i<alph[ptr+1];i++)
		{
			if(d[i][len]==0 && d[i][len-1]!=0)
			{
				for(j=1;j<len;j++)
					if(number[d[i][j]-'A']!=num[j]-'0') break;
				if(j==len)
				{
					fprintf(out,"%s\n",d[i]);
					flag = 1;
				}
			}
		}
	}
	if(!flag) fprintf(out,"NONE\n");
	return 0;
}

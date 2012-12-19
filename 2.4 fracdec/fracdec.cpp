/*
USER: zobayer1
TASK: fracdec
LANG: C++
*/

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int hash[100001];
char num[100001];

int main()
{
	int n, d, len, i;
	freopen("fracdec.in", "r", stdin);
	freopen("fracdec.out", "w", stdout);
	scanf("%d%d", &n, &d);
	sprintf(num, "%d.", n/d);
	len = strlen(num);
	while(1)
	{
		n %= d;
		if(!n)
		{
			//num[len++] = '0';
			num[len] = 0;
			break;
		}
		if(hash[n])
		{
			for(i=0; i<len; i++)
			{
				if((i+1) % 76 == 0) printf("\n");
				if(i==hash[n]) printf("(");
				printf("%c", num[i]);
			}
			printf(")\n");
			return 0;
		}
		hash[n] = len;
		n *= 10;
		num[len++] = n/d + '0';
		num[len] = 0;
	}
	for(i=0; i<len; i++)
	{
		printf("%c", num[i]);
	}
	if(num[i-1]=='.') printf("0");
	printf("\n");
	return 0;
}

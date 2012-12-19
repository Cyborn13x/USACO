/*
USER: zobayer1
TASK: calfflac
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
using namespace std;

#define TASK "calfflac"
#define DEBUG if(0)
#define IOF if(0)

char temp[100];
char buff[20002];

int main()
{
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	int last = 0, len, i, p, q, st, en, mst, men, maxlen;
	while(gets(temp))
	{
		len = strlen(temp);
		strcat(&buff[last], temp);
		last += len;
		buff[last++] = '\n';
		buff[last] = 0;
	}
	maxlen = 0;
	for(i=0; i<last; i++)
	{
		if(isalpha(buff[i]))
		{
			len = 1, p = i-1, q = i+1;
			while(p>=0 && q<last)
			{
				while(p >= 0 && !isalpha(buff[p])) p--;
				while(q < last && !isalpha(buff[q])) q++;
				if(p>=0 && q<last && tolower(buff[p])==tolower(buff[q]))
					len+=2, st=p--, en=q++;
				else break;
			}
			if(len > maxlen) maxlen = len, mst = st, men = en;
			else if(len == maxlen && st < mst) mst = st, men = en;
			
			p = i, q = i+1, len=0;
			while(p>=0 && q<last)
			{
				while(p >= 0 && !isalpha(buff[p])) p--;
				while(q < last && !isalpha(buff[q])) q++;
				if(p>=0 && q<last && tolower(buff[p])==tolower(buff[q]))
					len+=2, st=p--, en=q++;
				else break;
			}
			if(len > maxlen) maxlen = len, mst = st, men = en;
			else if(len == maxlen && st < mst) mst = st, men = en;
		}
	}
	printf("%d\n", maxlen);
	for(i=mst; i<=men; i++) putchar(buff[i]);
	putchar('\n');
	return 0;
}

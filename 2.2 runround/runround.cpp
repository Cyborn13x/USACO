/*
USER: zobayer1
TASK: runround
LANG: C++
*/

#include <cstdio>
#include <cstring>

int is_run_around(int n)
{
	char num[12], used[12] = {0}, touch[12] = {0};
	int len, i = 0, j, p;
	sprintf(num, "%d", n);
	len = strlen(num);
	for( ; ; )
	{
		p = num[i] - '0';
		if(!p || used[i] || touch[p]) return 0;
		used[i] = touch[p] = 1;
		i = (i+p) % len;
		if(!i)
		{
			for(j=0; j<len; j++)
				if(!used[j])
					return 0;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int m;
	freopen("runround.in", "r", stdin);
	freopen("runround.out", "w", stdout);
	scanf("%d", &m);
	do {
		m++;
	} while(!is_run_around(m));
	printf("%d\n", m);
	return 0;
}


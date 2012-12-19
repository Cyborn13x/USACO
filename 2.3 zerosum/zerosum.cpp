/*
USER: zobayer1
LANG: C++
TASK: zerosum
ALGO: brute force / dfs
*/

#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

int sum(char *str, int n)
{
	int a, b, c, cnt = 0;
	stack< int > num;
	num.push(str[0]-'0');
	for(int i=2; i<2*n-1; i+=2)
	{
		if(str[i-1]==' ')
		{
			a = num.top(); num.pop();
			c = a < 0;
			if(c) a = -a;
			a = a * 10 + str[i] - '0';
			if(c) a = -a;
			num.push(a);
		}
		else
		{
			cnt++;
			num.push(((str[i-1]=='-') ? -(str[i]-'0') : (str[i]-'0')));
		}
	}
	while(cnt--)
	{
		b = num.top(); num.pop();
		a = num.top(); num.pop();
		num.push(a + b);
	}
	return num.top();
}

void search(char *str, int i, int n)
{
	if(i==n-1)
	{
		if(sum(str, n)==0) cout << str << endl;
		return;
	}
	
	str[2*i+1] = ' ';
	search(str, i+1, n);
	
	str[2*i+1] = '+';
	search(str, i+1, n);
	
	str[2*i+1] = '-';
	search(str, i+1, n);
}

int main()
{
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
	
	char str[22];
	int i, j, n;
	cin >> n;
	for(i=1, j=0; i<=n; i++)
	{
		str[j++] = i+'0';
		str[j++] = ' ';
	}
	str[--j] = 0;
	search(str, 0, n);
	return 0;
}

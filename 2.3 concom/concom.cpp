/*
USER: zobayer1
LANG: C++
TASK: concom
ALGO: dp
*/

#include <iostream>
#include <cstdio>
using namespace std;

#define MAX 101

bool control[MAX][MAX];
int share[MAX][MAX];

void addControl(int u, int v)
{
	if(control[u][v]) return;
	control[u][v] = true;
	
	for(int i=1; i<MAX; i++)
		share[u][i] += share[v][i];
	
	for(int i=1; i<MAX; i++)
		if(control[i][u])
			addControl(i, v);
	
	for(int i=1; i<MAX; i++)
		if(share[u][i] > 50)
			addControl(u, i);
}

void addCompany(int u, int v, int w)
{
	for(int i=1; i<MAX; i++)
		if(control[i][u])
			share[i][v] += w;
	for(int i=1; i<MAX; i++)
		if(share[i][v] > 50)
			addControl(i, v);
}

int main()
{
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
	int n, u, v, w;
	cin >> n;
	for(int i=1; i<MAX; i++) control[i][i] = true;
	for(int i=0; i<n; i++)
	{
		cin >> u >> v >> w;
		addCompany(u, v, w);
	}
	for(int i=1; i<MAX; i++)
		for(int j=1; j<MAX; j++)
			if(i!=j && control[i][j])
				cout << i << ' ' << j << '\n';
	return 0;
}

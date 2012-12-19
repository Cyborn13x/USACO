/*
USER: zobayer1
LANG: C++
TASK: cowtour
*/

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MAX 150
#define pii pair<int,int>
#define sq(x) ((x)*(x))

double d[MAX][MAX], md[MAX];
char adj[MAX][MAX+1];
pii point[MAX];

double dist(pii a, pii b)
{
	double x1 = a.first, y1 = a.second, x2 = b.first, y2 = b.second;
	return sqrt(sq(x1-x2)+sq(y1-y2));
}

int main()
{
	int n, i, j, k, x, y;
	double inf = 100000000001.0, ans;
	freopen("cowtour.in", "r", stdin);
	freopen("cowtour.out", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d%d", &x, &y);
		point[i] = pii(x,y);
	}
	for(i=0; i<n; i++) scanf("%s", adj[i]);
	for(i=0; i<n-1; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(adj[i][j]=='1') d[i][j] = d[j][i] = dist(point[i], point[j]);
			else d[i][j] = d[j][i] = inf;
		}
	}
	for(k=0; k<n; k++)
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(fabs(d[i][j]-inf)<1e-10)
				d[i][j] = d[j][i] = -1.0;
	for(i=0; i<n; i++)
	{
		md[i] = 0.0;
		for(j=0; j<n; j++) md[i] = max(md[i], d[i][j]);
	}
	ans = inf;
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(d[i][j]<0.0)
				ans = min(ans, md[i] + md[j] + dist(point[i], point[j]));
	for(i=0; i<n; i++) ans = max(md[i], ans);
	printf("%.6lf\n", ans);
	return 0;
}

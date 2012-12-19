/*
USER: zobayer1
LANG: C++
TASK: maze1
ALGO: bfs
*/

#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define MAXW 38
#define MAXH 100
#define pii pair<int,int>

char maze[2*MAXH+2][2*MAXW+2];
int d[MAXH][MAXW];
int H, W;

vector< pii > getStart()
{
	vector< pii > start;
	for(int i=0; i<W; i++)
		if(maze[0][2*i+1] < 40)
			start.push_back(pii(0, i));
	for(int i=0; i<W; i++)
		if(maze[2*H][2*i+1] < 40)
			start.push_back(pii(H-1, i));
	for(int i=0; i<H; i++)
		if(maze[2*i+1][0] < 40)
			start.push_back(pii(i, 0));
	for(int i=0; i<H; i++)
		if(maze[2*i+1][2*W] < 40)
			start.push_back(pii(i, W-1));
	return start;
}

void init()
{
	for(int i=0; i<H; i++)
		for(int j=0; j<W; j++)
			d[i][j] = (1<<28);
}

bool isvalid(int i, int j)
{
	return (i>=0 && j>=0 && i<H && j<W);
}

bool adj(int r1, int c1, int r2, int c2)
{
	return (maze[r1+r2+1][c1+c2+1] < 40);
}

void bfs(pii start)
{
	d[start.first][start.second] = 1;
	int r, c;
	queue< pii > Q;
	Q.push(start);
	while(!Q.empty())
	{
		r = Q.front().first;
		c = Q.front().second;
		Q.pop();
		if(isvalid(r+1, c) && adj(r, c, r+1, c))
		{
			if(d[r+1][c] > d[r][c]+1)
			{
				d[r+1][c] = d[r][c]+1;
				Q.push(pii(r+1, c));
			}
		}
		if(isvalid(r-1, c) && adj(r, c, r-1, c))
		{
			if(d[r-1][c] > d[r][c]+1)
			{
				d[r-1][c] = d[r][c]+1;
				Q.push(pii(r-1, c));
			}
		}
		if(isvalid(r, c+1) && adj(r, c, r, c+1))
		{
			if(d[r][c+1] > d[r][c]+1)
			{
				d[r][c+1] = d[r][c]+1;
				Q.push(pii(r, c+1));
			}
		}
		if(isvalid(r, c-1) && adj(r, c, r, c-1))
		{
			if(d[r][c-1] > d[r][c]+1)
			{
				d[r][c-1] = d[r][c]+1;
				Q.push(pii(r, c-1));
			}
		}
	}
}

int main()
{
	freopen("maze1.in", "r", stdin);
	freopen("maze1.out", "w", stdout);
	vector< pii > start;
	scanf("%d%d", &W, &H);
	getchar();
	for(int i=0; i<2*H+1; i++) gets(maze[i]);
	start = getStart();
	init();
	for(int i=0; i<(int)start.size(); i++)
	{
		bfs(start[i]);
	}
	int maxval = 0;
	for(int i=0; i<H; i++)
		for(int j=0; j<W; j++)
			maxval = max(maxval, d[i][j]);
	printf("%d\n", maxval);
	return 0;
}

/*
USER: zobayer1
PROG: castle
LANG: C++
*/

#include <fstream>
#include <string>
using namespace std;

int M,N;
int s[60][60];
int room[60][60];
basic_string<int> size;

void input()
{
	ifstream cin("castle.in");
	cin >> M >> N;
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			cin >> s[i][j];
	memset(room,-1,sizeof(room));
}

inline bool has_north(int i,int j)
{
	return !(s[i][j]&2);
}

inline bool has_south(int i,int j)
{
	return !(s[i][j]&8);
}

inline bool has_west(int i,int j)
{
	return !(s[i][j]&1);
}

inline bool has_east(int i,int j)
{
	return !(s[i][j]&4);
}

void flood(int i,int j)
{
	if(room[i][j]!=-1) return;
	room[i][j]=size.length()-1;
	++(size[room[i][j]]);
	if(has_north(i,j))flood(i-1,j);
	if(has_south(i,j))flood(i+1,j);
	if(has_west(i,j))flood(i,j-1);
	if(has_east(i,j))flood(i,j+1);
}

void floodfill()
{
	for(int i=0;i<N;++i)
		for(int j=0;j<M;++j)
			if(room[i][j]==-1)
			{
				size += int(0);
				flood(i,j);
			}
}

void output()
{
	ofstream cout("castle.out");
	cout << size.length() << "\n";
	int big = -1, i, j, now, nn, mm, WorS;
	for(i=size.length()-1;i>=0;--i)
		if(size[i]>big)
			big=size[i];
	cout << big << "\n";
	big = -1;
	for(j=0;j<M;++j)
	{
		for(i=N-1;i>=0;--i)
		{
			if(j!=0&&room[i][j]!=room[i][j-1])
			{
				now = size[room[i][j]]+size[room[i][j-1]];
				if(now>big)
				{
					big = now;
					nn = i;
					mm = j;
					WorS = true;
				}
			}
			if(i!=N-1&&room[i][j]!=room[i+1][j])
			{
				now = size[room[i][j]]+size[room[i+1][j]];
				if(now>big)
				{
					big = now;
					nn = i;
					mm = j;
					WorS = false;
				}
			}
		}
	}
	cout << big << "\n";
	if(WorS) cout << nn+1 << " " << mm << " E\n";
	else cout << nn+2 << " " << mm+1 << " N\n";
}

int main()
{
	input();
	floodfill();
	output();
	return 0;
}

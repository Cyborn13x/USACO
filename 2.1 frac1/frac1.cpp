/*
USER: zobayer1
PROG: frac1
LANG: C++
*/

#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 161

bool flag[MAX][MAX];
vector< pair<int, int> > V;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
	return (p1.first * p2.second < p1.second * p2.first);
}

int main()
{
	int n, i, j, k;
	ifstream fin("frac1.in");
	ofstream fout("frac1.out");
	fin >> n;
	V.push_back(pair<int, int> (0,1));
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(!flag[i][j])
			{
				for(k=2;i*k<=n && j*k<=n; k++)
					flag[i*k][j*k] = true;
				V.push_back(pair<int, int> (i,j));
			}
		}
	}
	sort(V.begin(),V.end(),comp);
	k = V.size();
	for(i=0;i<k;i++)
		fout << V[i].first << "/" << V[i].second << "\n";
	fin.close();
	fout.close();
	return 0;
}

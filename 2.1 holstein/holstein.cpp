/*
USER: zobayer1
PROG: holstein
LANG: C++
*/

#include <fstream>
using namespace std;

int feed[15][25], req[25], scoop[15], bestf[15];
int best, numf, numv;

void dfs(int ifeed, int nfeed)
{
	int i;
	for(i=0;i<numv;i++)
		if(req[i]>0)
			break;
	if(i==numv)
	{
		best = nfeed;
		for(i=0;i<best;i++)
			bestf[i] = scoop[i];
		return;
	}
	for(;ifeed<numf && nfeed+1<best;ifeed++)
	{
		for(i=0;i<numv;i++)
			req[i] -= feed[ifeed][i];
		scoop[nfeed] = ifeed;
		dfs(ifeed+1,nfeed+1);
		for(i=0;i<numv;i++)
			req[i] += feed[ifeed][i];
	}
}

int main()
{
	int i, j;
	ifstream fin("holstein.in");
	ofstream fout("holstein.out");
	fin >> numv;
	for(i=0;i<numv;i++)
		fin >> req[i];
	fin >> numf;
	for(i=0;i<numf;i++)
		for(j=0;j<numv;j++)
			fin >> feed[i][j];
	best = numf+1;
	dfs(0,0);
	fout << best;
	for(i=0;i<best;i++)
		fout << " " << bestf[i]+1;
	fout << "\n";
	fin.close();
	fout.close();
	return 0;
}

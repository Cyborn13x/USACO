/*
USER: zobayer1
PROG: checker
LANG: C++
*/

#include <fstream>
using namespace std;

bool fx[14], fxy[25], fyx[25];
int n, ans[14], sum, sum2;

ifstream fin ("checker.in");
ofstream fout ("checker.out");

void dfs(int cur)
{
    if (cur==n+1)
	{
        sum++;
        if(ans[n]==n/2+1) sum2++;
        if(sum>3) return;
        for(int i=1;i<=n-1;i++)
			fout << ans[i] << ' ';
        fout << ans[n] << endl;
        if(sum==2 && n==6)
		{
            for(int i=n;i>=2;i--)
				fout << ans[i] << ' ';
            fout << ans[1] << endl;
        }
    }
    for(int i=1;i<=n;i++)
	{
		if(!fx[i] && !fxy[i+cur-2] && !fyx[i-cur+12])
		{
			ans[cur] = i;
			fx[i] = fxy[i+cur-2] = fyx[i-cur+12] = true;
			dfs(cur+1);
			fx[i] = fxy[i+cur-2] = fyx[i-cur+12] = false;
		}
	}
}

int main()
{
    fin >> n;
    for(int i=1;i<=n/2;i++)
	{
        fx[i] = fxy[i-1] = fyx[i+11] = true;
        ans[1] = i;
        dfs(2);
        fx[i] = fxy[i-1] = fyx[i+11] = false;
    }
    sum *= 2;
    if(n%2==1) sum += sum2*2;
    fout << sum << endl;
    return 0;
}

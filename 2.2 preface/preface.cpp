/*
USER: zobayer1
PROG: preface
LANG: C++
*/

#include <fstream>
using namespace std;

int cnt[7];
char digits[] = "IVXLCDM";

void units(int);
void tenth(int);
void hundr(int);
void thsnd(int);
void roman(int);

int main()
{
	int n, i;
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	fin >> n;
	for(i=1;i<=n;i++)
		roman(i);
	for(i=0;i<7;i++)
		if(cnt[i])
			fout << digits[i] << " " << cnt[i] << "\n";
	return 0;
}

void units(int n)
{ 
	switch(n)
	{
	case 3 : cnt[0]++;
	case 2 : cnt[0]++;
	case 1 : cnt[0]++;
	break;
	case 4 : cnt[0]++;
	case 5 : cnt[1]++;
	break;
	case 8 : cnt[0]++;
	case 7 : cnt[0]++;
	case 6 : cnt[0]++; cnt[1]++;
	break;
	case 9 : cnt[0]++; cnt[2]++;
	}
}

void tenth(int n)
{
	switch(n)
	{
	case 3 : cnt[2]++;
	case 2 : cnt[2]++;
	case 1 : cnt[2]++;
	break;
	case 4 : cnt[2]++;
	case 5 : cnt[3]++;
	break;
	case 8 : cnt[2]++;
	case 7 : cnt[2]++;
	case 6 : cnt[2]++; cnt[3]++;
	break;
	case 9 : cnt[2]++; cnt[4]++;
	}
}

void hundr(int n)
{
	switch(n)
	{
	case 3: cnt[4]++;
	case 2: cnt[4]++;
	case 1: cnt[4]++;
	break;
	case 4: cnt[4]++;
	case 5: cnt[5]++;
	break;
	case 8: cnt[4]++;
	case 7: cnt[4]++;
	case 6: cnt[4]++; cnt[5]++;
	break;
	case 9: cnt[4]++; cnt[6]++;
	}
}

void thsnd(int n)
{
	switch(n)
	{
	case 3: cnt[6]++;
	case 2: cnt[6]++;
	case 1: cnt[6]++;
	}
}

void roman(int n)
{
	thsnd((n/1000)%10);
	hundr((n/100)%10);
 	tenth((n/10)%10);
	units(n%10);
}

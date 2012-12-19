/*
USER: zobayer1
PROG: pprime
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define N 9991922
#define sqrtN 3162

#define gP(n) (prime[n>>6]&(1<<((n>>1)&31)))
#define rP(n) (prime[n>>6]&=~(1<<((n>>1)&31)))

unsigned int prime[N/64];
FILE *fi, *fo;

void sieve()
{
	register int i, j, k;
	memset(prime,-1,sizeof(prime));
	for(i=3;i<sqrtN;i+=2)
		if(gP(i))
			for(j=i*i, k=i<<1; j<N; j+=k)
				rP(j);
}

void digit1(int a, int b)
{
	if(a<=5 && b>=5) fprintf(fo,"5\n");
	if(a<=7 && b>=7) fprintf(fo,"7\n");
}

void digit2(int a, int b)
{
	if(a<=11 && b>=11) fprintf(fo,"11\n");
}

void digit3(int a, int b)
{
	int d1, d2, num;
	for(d1=1;d1<=9;d1+=2)
		for(d2=0;d2<=9;d2++)
		{
			num = d1*100 + d2*10 + d1;
			if(gP(num) && a<=num && b>=num)
				fprintf(fo,"%d\n",num);
			else if(num>b) return;
		}
}

void digit4(int a, int b)
{
	return;
}

void digit5(int a, int b)
{
	int d1, d2, d3, num;
	for(d1=1;d1<=9;d1+=2)
		for(d2=0;d2<=9;d2++)
			for(d3=0;d3<=9;d3++)
			{
				num = d1*10000 + d2*1000 + d3*100 + d2*10 + d1;
				if(gP(num) && a<=num && b>=num)
					fprintf(fo,"%d\n",num);
				else if(num>b) return;
			}
}

void digit6(int a, int b)
{
	return;
}

void digit7(int a, int b)
{
	int d1, d2, d3, d4, num;
	for(d1=1;d1<=9;d1+=2)
		for(d2=0;d2<=9;d2++)
			for(d3=0;d3<=9;d3++)
				for(d4=0;d4<=9;d4++)
				{
					num = d1*1000000 + d2*100000 + d3*10000 + +d4*1000 + d3*100 + d2*10 + d1;
					if(gP(num) && a<=num && b>=num)
						fprintf(fo,"%d\n",num);
					else if(num>b) return;
				}
}

void digit8(int a, int b)
{
	return;
}

void digit9(int a, int b)
{
	return;
}

int main()
{
	sieve();
	fi = fopen("pprime.in","r");
	fo = fopen("pprime.out","w");
	void (*func[10])(int, int) = {NULL};
	func[1] = &digit1;
	func[2] = &digit2;
	func[3] = &digit3;
	func[4] = &digit4;
	func[5] = &digit5;
	func[6] = &digit6;
	func[7] = &digit7;
	func[8] = &digit8;
	func[9] = &digit9;
	int a, b, na, nb, i;
	fscanf(fi,"%d%d",&a,&b);
	na = (int)(floor(log10((double)a))+1e-8)+1;
	nb = (int)(floor(log10((double)b))+1e-8)+1;
	for(i=na;i<=nb;i++)
		(*func[i])(a,b);
	return 0;
}
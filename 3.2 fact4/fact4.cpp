/*
USER: zobayer1
TASK: fact4
LANG: C++
*/

#include <stdio.h>

int main() {
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
	int n, i, res=1, k, a2=0, a5=0, a;
	scanf("%d", &n);
	for(i=1; i<=n; i++) {
		k = i;
		while(k%2==0) {
			k /= 2;
			a2++;
		}
		while(k%5==0) {
			k /= 5;
			a5++;
		}
		res = (res*(k%10))%10;
	}
	a = a2 - a5;
	for(i=1; i<=a; i++) res = (res*2)%10;
	printf("%d\n", res);
	return 0;
}

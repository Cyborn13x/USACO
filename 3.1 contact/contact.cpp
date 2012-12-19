/*
USER: zobayer1
TASK: contact
LANG: C++
*/

#include <cstdio>
#include <cctype>
#include <cassert>
#include <algorithm>
using namespace std;

const int BITS = 13;
const int SIZE = 1<<BITS;

struct item {
	unsigned bits;
	int cnt;
} seq[SIZE+1];

void count(unsigned bit, int n) {
	bit = (bit & ((1<<n)-1)) | (1<<n);
	seq[bit].cnt++;
}

void print(unsigned bits) {
	int i, f=0;
	for(i=13; i>=0; i--) {
		if(f) printf("%c", ((bits >> i) & 1) + '0');
		else if((bits >> i) & 1) f = 1;
	}
}

bool comp(const item &a, const item &b) {
	return (a.cnt==b.cnt)? a.bits < b.bits : a.cnt > b.cnt;
}

int main() {
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);

	int a, b, n, i, j, k, p, nbit = 0;
	unsigned bit = 0;
	char ch;

	scanf("%d%d%d", &a, &b, &n);

	for(i=k=0; i<=b; i++)
		for(j=0; j<(1<<i); j++)
			seq[++k].bits = k;

	while((ch=getchar())!=EOF) {
		if(!isdigit(ch)) continue;
		bit = (bit << 1) | (int)(ch - '0');
		if(nbit < b) nbit++;
		for(i=a; i<=nbit; i++) count(bit, i);
	}

	sort(seq, seq+(1<<(b+1)), comp);

	for(i=p=0; p<n && seq[i].cnt; p++) {
		printf("%d", seq[i].cnt);
		j = seq[i].cnt, k = 0;
		while(seq[i].cnt==j) {
			if(k%6==0) printf("\n");
			else printf(" ");
			print(seq[i].bits);
			k++, i++;
		}
		printf("\n");
	}
	return 0;
}

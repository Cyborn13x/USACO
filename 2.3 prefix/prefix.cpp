/*
USER: zobayer1
LANG: C++
TASK: prefix
ALGO: dp
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <set>
using namespace std;

#define MAX 200002

bool isok[MAX];

int main()
{
	freopen("prefix.in", "r", stdin);
	freopen("prefix.out", "w", stdout);
	set< string > dict;
	string word, seq, line, temp;
	while(cin >> word)
	{
		if(word == ".") break;
		dict.insert(word);
	}
	while(cin >> line) seq.append(line);
	int last = -1, len = seq.size();
	for(int i=0; i<len; i++)
	{
		if(i-last > 10) break;
		bool found = false;
		for(int j=9; j>=0 && !found; j--)
		{
			if((i < j) || (i && i-j && !isok[i-j] && !isok[i-j-1])) continue;
			temp = "";
			for(int k=i-j; k<=i; k++) temp.push_back(seq.at(k));
			if(dict.find(temp)!=dict.end()) found = true;
		}
		if(found)
		{
			last = i;
			isok[i] = true;
		}
	}
	printf("%d\n", last + 1);
	return 0;
}

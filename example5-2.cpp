#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int maxn=30;
int n;
vector<int>pile[maxn];

void find_block(int a,int& p,int& h)
{
	for (p=0;p<n;p++)
		for (h=0;h<pile[p].size();h++)
			if (pile[p][h]==a)
				return;
}

void clear_above(int p,int h)
{
	for (int i=h+1;i<pile[p].size();i++)
		pile[pile[p][i]].push_back(pile[p][i);
	pile[b].resize(h+1);
}


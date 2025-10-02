#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int id,n,m,i,j,x,y;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
inline void decode(int &l, int &r, int &k, ll lstans, int testop)
{
	lstans %= 19260817;
	if(testop)
	{
		l ^= lstans;
		l = (l % n + n) % n + 1;
		r ^= lstans; r = (r % n + n) % n + 1;
		if(l>r) swap(l, r);
		k ^=lstans;
		k =(k % min(r - l + 1,100)) + 1; 
	}
}
int main()
{
//	freopen("tree.in","r",stdin);
//	freopen("tree.out","w",stdout);
	id=read();
	bool op;
	op=read();
	n=read();
//	if(op==1)
	return 0;
}

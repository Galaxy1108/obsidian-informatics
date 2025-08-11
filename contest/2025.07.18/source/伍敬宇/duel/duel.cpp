#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 2e5 + 12;
char buf[SIZE+2],*iS,*iT;
inline char mget()
{
	if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
	return *(iS++);
}
inline int read()
{
	int x = 0;
	char ch = mget();
	while (ch<'0'||ch>'9') ch = mget();
	while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
	return x;
}
int n,m;
int p[MAXN];
int st[MAXN][21];
struct Operation{
	int tp,val1,val2;
}O[MAXN];
bool check1()
{
	for (int i=1;i<=m;i++)
		if (O[i].tp==1)
			return 0;
	return 1;
}
void work1()
{
	for (int i=1;i<=n;i++)
		st[i][0] = p[i];
	for (int k=1;(1<<k)<=n;k++)
		for (int l=1;l+(1<<k)-1<=n;l++)
			st[l][k] = abs(st[l][k-1] - st[l+(1<<(k-1))][k-1]);
	for (int i=1;i<=m;i++)
		printf("%d\n",st[O[i].val1][O[i].val2]);
}
bool check2()
{
	for (int i=1;i<=n;i++)
		if (p[i]>1) return 0;
	for (int i=1;i<=m;i++)
		if (O[i].tp == 1&&O[i].val2>1) return 0;
	return 1;
}
inline int lowbit(const int&x) {return x&(-x);}
struct FenwickTree{
	int bas[MAXN];
	void add(int id)
	{
		for (;id<=n;id+=lowbit(id))
			bas[id] ^= 1;
	}
	int query(int id)
	{
		int res = 0;
		for (;id;id-=lowbit(id))
			res ^= bas[id];
		return res;
	}
}tr;
void work2()
{
	for (int i=1;i<=n;i++)
		if (p[i]) tr.add(i);
	for (int i=1;i<=m;i++)
	{
		if (O[i].tp == 1) 
		{
			if (O[i].val2!=p[O[i].val1]) tr.add(O[i].val1);
			p[O[i].val1] = O[i].val2;
		}
		else if (O[i].tp==2)
		{
			printf("%d\n",tr.query(O[i].val1-1)^tr.query(O[i].val1-1+(1<<O[i].val2)));
		}
	}
}
int cal(int l,int k)
{
	if (k==0) return p[l];
	return abs(cal(l,k-1)-cal(l+(1<<(k-1)),k-1));
}
void work3()
{
	for (int i=1;i<=m;i++)
	{
		if (O[i].tp==1) p[O[i].val1] = O[i].val2;
		else if (O[i].tp==2)
		{
			int l = O[i].val1,k = O[i].val2;
			printf("%d\n",cal(l,k));
		}
	}
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n = read(),m = read();
	for (int i=1;i<=n;i++) p[i] = read();
	for (int i=1;i<=m;i++) O[i].tp = read(),O[i].val1 = read(),O[i].val2 = read();
	if (check1()) work1();
	else if (check2()) work2();
	else work3();
	return 0;
}

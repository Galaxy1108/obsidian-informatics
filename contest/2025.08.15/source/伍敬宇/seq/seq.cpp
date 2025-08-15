#include <cstdio>
#include <iostream>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 1e6 + 12;
const int MAXV = 1e5 + 12;
const int mod = 998244353;
char buf[SIZE+1],*iS,*iT;
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
int a[MAXN],b[MAXN],dp[MAXN],pos[MAXN];
int ton[MAXV],cur,rec[MAXN],ans;
inline void upd(int&x,int y)
{
	x += y;
	if (x>=mod) x -= mod;
}
inline int lowbit(int x) {return x&(-x);}
int bas[MAXN];
void add(int id,int x)
{
	for (;id<=1e5;id+=lowbit(id))
		upd(bas[id],x);
}
int query(int id)
{
	int res = 0;
	for (;id;id-=lowbit(id))
		upd(res,bas[id]);
	return res;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	n = read();
	for (int i=1;i<=n;i++) a[i] = read();
	m = read();
	for (int i=1;i<=m;i++) b[i] = read();
	for (int i=1;i<=1e5;i++) rec[i] = n+1;
	for (int i=n;i>=1;i--)
	{
		dp[i] = 1;
		upd(dp[i],cur);
		upd(cur,mod-ton[a[i]]);
		pos[i] = rec[a[i]];
		rec[a[i]] = i;
		ton[a[i]] = dp[i];
		upd(cur,ton[a[i]]);
	}
	for (int i=1;i<=1e5;i++) add(i,ton[i]);
	for (int i=1,j=0;i<=m;i++)
	{
		upd(ans,query(min((int)1e5,b[i]-1)));
		upd(ans,1);
		j++;
		if (j>n) break;
		add(a[j],mod-ton[a[j]]);
		ton[a[j]] = dp[pos[j]];
		add(a[j],ton[a[j]]);
		while (a[j]!=b[i]) 
		{
			j++;
			if (j>n) break;
			add(a[j],mod-ton[a[j]]);
			ton[a[j]] = dp[pos[j]];
			add(a[j],ton[a[j]]);
		}
		if (j>n) break;
	}
	printf("%d",ans);
	return 0;
}

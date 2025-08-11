#include <cstdio>
#include <map>
#include <iostream>
#include <queue>
#define encode ghjkl
#define decode yuiohjkl
using namespace std;
const int mod = 1e9 + 7;
long long n;
int k;
struct Node{
	int cnt[10];
};
long long encode(Node x)
{
	long long res = 0;
	for (int i=9;i>=1;i--)
		res = res*13 + x.cnt[i];
	return res;
}
long long getv(Node x)
{
	long long res = 1;
	for (int i=1;i<=9;i++)
	{
		while (x.cnt[i]--)
			res *= i;
	}
	return res;
}
Node decode(long long x)
{
	Node res;
	for (int i=1;i<=9;i++)
	{
		res.cnt[i] = x%13;
		x = x/13; 
	}
	return res;
}
inline void chk(int&x)
{
	if (x>=mod) x -= mod;
}
priority_queue<long long> q1;
priority_queue<__int128> q2;
map<long long,long long> f[3],g[3];
map<long long,long long> a;
int bs[15],len;
__int128 val[2000+12];
int main()
{
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	scanf("%lld%d",&n,&k);
	f[1][0] = 1;
	while (n)
	{
		bs[++len] = n%10;
		n /= 10;
	}
	for (int i=1;i<=len;i++)
	{
		for (map<long long,long long>::iterator it=f[0].begin();it!=f[0].end();it++)
		{
			Node cur = decode(it->first);
			for (int j=1;j<=bs[i];j++)
			{
				cur.cnt[j] ++;
				g[0][encode(cur)] += it->second;
				cur.cnt[j] --;
			}
			for (int j=bs[i]+1;j<=9;j++)
			{
				cur.cnt[j] ++;
				g[2][encode(cur)] += it->second;
				cur.cnt[j] --;
			}
		}
		for (map<long long,long long>::iterator it=f[1].begin();it!=f[1].end();it++)
		{
			Node cur = decode(it->first);
			for (int j=1;j<bs[i];j++)
			{
				cur.cnt[j] ++;
				g[0][encode(cur)] += it->second;
				cur.cnt[j] --;
			}
			if (bs[i])
			{
				cur.cnt[bs[i]] ++;
				g[1][encode(cur)] += it->second;
				cur.cnt[bs[i]] --;
			}
			for (int j=bs[i]+1;j<=9;j++)
			{
				cur.cnt[j] ++;
				g[2][encode(cur)] += it->second;
				cur.cnt[j] --;
			}
		}
		for (map<long long,long long>::iterator it=f[2].begin();it!=f[2].end();it++)
		{
			Node cur = decode(it->first);
			for (int j=1;j<bs[i];j++)
			{
				cur.cnt[j] ++;
				g[0][encode(cur)] += it->second;
				cur.cnt[j] --;
			}
			for (int j=max(bs[i],1);j<=9;j++)
			{
				cur.cnt[j] ++;
				g[2][encode(cur)] += it->second;
				cur.cnt[j] --;
			}
		}
		for (int t=0;t<=2;t++)
		{
			swap(f[t],g[t]);
			if (t<2||i<len)
			{
				for (map<long long,long long>::iterator it=f[t].begin();it!=f[t].end();it++)
				{
					a[getv(decode(it->first))] += it->second;
				}
			}
			g[t].clear();
		}
	}
	for (map<long long,long long>::iterator it=a.begin();it!=a.end();it++)
		q1.push(it->second);
	for (int i=1;i<=2000&&!q1.empty();i++)
	{
		val[i] = q1.top();
		q1.pop();
	}
	for (int i=1;i<=2000;i++)
		for (int j=1;j<=2000;j++)
			q2.push(((__int128)val[i])*val[j]);
	long long ans = 0;
	for (int i=1;i<=k;i++)
	{
		ans = (ans + q2.top())%mod;
		q2.pop();
	}
	printf("%lld",ans);
	return 0;
}

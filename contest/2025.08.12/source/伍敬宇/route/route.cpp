#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 95;
const int SIZE = 1<<21;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
	if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
	return *(iS++);
}
inline long long read()
{
	long long x = 0;
	char ch = mget();
	while (ch<'0'||ch>'9') ch = mget();
	while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
	return x;
}
long long s;
int n,m,q;
long long l[MAXN][MAXN],c[MAXN][MAXN];
long long dis1[MAXN][MAXN],dis2[MAXN][MAXN],dis3[MAXN][MAXN];
void B1(int st,long long x)
{
	for (int i=0;i<n;i++)
		dis1[st][i] = dis2[st][i] = 2e15;
	dis2[st][st] = 0;
	dis1[st][st] = x;
	for (int i=0;i<n;i++)
	{
		for (int u=0;u<n;u++)
			for (int v=0;v<n;v++)
			{
				long long ndis1,ndis2;
				if (dis1[st][u]+l[u][v]<=c[u][v]) ndis1 = dis1[st][u]+l[u][v],ndis2 = dis2[st][u];
				else ndis1 = l[u][v],ndis2 = dis2[st][u]+1;
				if (ndis2<dis2[st][v]||ndis2==dis2[st][v]&&ndis1<dis1[st][v])
					dis2[st][v] = ndis2,dis1[st][v] = ndis1;
			}
	}
}
void B2(int st)
{
	for (int i=0;i<n;i++)
		dis3[st][i] = -1;
	dis3[st][st] = s - 1;
	for (int i=0;i<n;i++)
	{
		for (int u=0;u<n;u++)
			for (int v=0;v<n;v++)
			{
				long long ndis;
				if (dis3[st][u]>=c[u][v]) ndis = c[u][v] - l[u][v];
				else ndis = dis3[st][u] - l[u][v];
				if (dis3[st][v]<ndis)
					dis3[st][v] = ndis;
			}
	}
}
int main()
{
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	n = read(),m = read(),s = read(),q = read();
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			l[i][j] = 2e15,c[i][j] = -1;
	for (int i=0;i<m;i++)
	{
		int u = read(),v = read();
		l[u][v] = l[v][u] = read();
		c[u][v] = c[v][u] = read();
	}
//	for (int i=0;i<n;i++) B1(i);
//	for (int i=0;i<n;i++) B2(i);
	while (q--)
	{
		int u = read(),v = read();
		long long t = read();
		B1(u,t);
//		if (dis3[v][u]>=t) 
//		{
//			printf("%lld\n",s-1-dis3[v][u]);
//			continue ;
//		}
//		long long ans = 2e18;
//		for (int ip=0;ip<n;ip++)
//			if (dis3[ip][u]>=t)
//				ans = min((__int128)ans,s - t + dis1[ip][v] + ((__int128)(dis2[ip][v]))*((__int128)s));
		printf("%lld\n",dis1[u][v]-t+dis2[u][v]*s);
	}
	return 0;
}

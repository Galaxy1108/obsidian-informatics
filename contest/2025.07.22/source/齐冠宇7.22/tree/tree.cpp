/*
不要卡我的常啊！！！！
QAQ
QAQ
QAQ
QAQ
QAQ
QAQ
QAQ
QAQ
QAQ
QAQ
QAQ
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5005,mod=998244353;
int n,m;
int l[N],r[N],ans[N];
int f[N][N],inv[N];
inline int qpow(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=res*a%mod;
		a=a*a%mod;
		b>>=1;		
	}
	return res;
}
inline void upd(int a,int b,int c,int d,int v)
{
	if(a>c || b>d)return;
	f[b][d]=(f[b][d]+v)%mod;
	f[a-1][d]=(f[a-1][d]-v+mod)%mod;
	f[b][c-1]=(f[b][c-1]-v+mod)%mod;
	f[a-1][c-1]=(f[a-1][c-1]+v)%mod;
}
inline void pu(int a,int b)
{
	f[a][b]=((f[a][b]+f[a+1][b])%mod+(f[a][b+1]-f[a+1][b+1]+mod)%mod)%mod;
}
signed main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;i++)
		cin>>l[i]>>r[i],inv[i]=qpow(r[i]-l[i]+1,mod-2);
	cin>>m;
	while(m--)
	{
		int u,v,w;
		cin>>u>>v>>w;
		int L=min(u,v),R=max(u,v);
		if(u!=v)
			upd(L,L,R,R,w);
	}
	for(int j=n;j>=1;j--)
	{
		for(int i=n;i>=j;i--)
			pu(i,j);
		for(int i=j-1;i>=1;i--)
		{
			pu(i,j);
			upd(l[j],min(r[j],i),i,i,f[i][j]*inv[j]%mod);
			upd(i,i,max(i,l[j]),r[j],f[i][j]*inv[j]%mod);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			ans[j]=(ans[j]+f[i][j])%mod;
	for(int i=2;i<=n;i++)
		cout<<ans[i]<<' ';
	return 0;
}

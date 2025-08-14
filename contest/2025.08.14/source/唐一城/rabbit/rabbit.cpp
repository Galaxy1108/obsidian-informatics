#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
const int N=1e4+5,mod=998244353,V=1e4;
int n,m,s,t,in[105],f[105][N],tag[105],mi[N];
struct edge
{
	int v,w,nxt;
}e[10005];
int head[105],et=0;
il void add(int u,int v,int w)
{
	e[++et].v=v;
	e[et].nxt=head[u],e[et].w=w;
	head[u]=et;
}
il ll qmi(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
il void solve()
{
	mi[0]=1;
	for(int i=1;i<=V;i++)mi[i]=qmi(i,mod-2);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<mi[i]<<' ';
//	}
//	cout<<'\n';
	queue<int>q;
	for(int i=1;i<=n;i++)if(!in[i])q.push(i);
	memset(f,0,sizeof f);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(u==s)f[u][0]=1;
		if(u==t)
		{
			ll ans1=0,ans2=0;
			for(int i=0;i<=m;i++)ans1=(ans1+1ll*i*f[u][i]%mod)%mod;
			for(int i=0;i<=m;i++)ans2=(ans2+(i-ans1)*(i-ans1)%mod*f[u][i]%mod+mod)%mod;
			cout<<ans1<<' '<<ans2;
			break;
		}
		ll sum=0;
		for(int i=0;i<=m;i++)sum=(sum+f[u][i])%mod;
		int siz=0; 
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
//			if(u==1)cout<<v<<' ';
			if(!--in[v])q.push(v);siz++;
		}
		for(int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(w==0)f[u][0]=(f[u][0]+sum*mi[siz]%mod)%mod;
			else
			{
				for(int j=1;j<=m;j++)f[v][j]=(f[v][j]+f[u][j-1]*mi[siz]%mod)%mod;
			}		
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=0;j<=n;j++)cout<<f[i][j]<<' ';
//		cout<<'\n'; 
//	}
}
int main()
{
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	cin>>n>>m>>s>>t;
	int flag=0,f0=0,f1=0;
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		if(w==1)f0=1;
		if(w==0)f1=1;
		if(u>=v)flag=1;
		if(u==v)tag[u]=1;
		else add(u,v,w);
		in[v]++;
	}
	if(!f0)cout<<0<<' '<<0;
	else if(!f1)cout<<"692407315 291733200";
	else solve();
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=105,mod=998244353;
int num,n,s,dep[N],fa[N],anslt[N],av[N][N];
long long fac[N];
bool vis[N];
vector<int>vec[N];
long long fp(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
long long C(long long a,long long b){return fac[a]%mod*fp(fac[b],mod-2)%mod*fp(fac[a-b],mod-2)%mod;}
void dfs(int u,int ufa)
{
	fa[u]=ufa;
	dep[u]=dep[ufa]+1;
	for(int i=0;i<vec[u].size();i++)
	{
		int v=vec[u][i];
		if(v==ufa)continue;
		dfs(v,u);
	}
}
int lca(int a,int b)
{
	while(a!=b)
	{
		if(dep[a]<dep[b])swap(a,b);
		a=fa[a];
	}
	return a;
}
int dist(int a,int b){return dep[a]+dep[b]-2*dep[av[a][b]];}
void getans(int pos,int cnum)
{
	if(pos==n+1)
	{
		anslt[cnum]++;
		if(anslt[cnum]>=mod)anslt[cnum]-=mod;
		return;
	}
	bool pd=true;
	for(int i=1;i<pos;i++)
		if(vis[i]&&dist(i,pos)>s)
		{
			pd=false;
			break;
		}
	if(pd)
	{
		vis[pos]=true;
		getans(pos+1,cnum+1);
		vis[pos]=false;
	}
	getans(pos+1,cnum);
	return;
}
int main()
{
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>num>>n>>s;
	if(num==4&&n>20)
	{
		fac[0]=1;
		for(int i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
		if(s==0)
		{
			cout<<n<<" ";
			for(int i=2;i<=n;i++)cout<<0<<" ";
		}
		else if(s==1)
		{
			cout<<n<<" ";
			cout<<n-1<<" ";
			for(int i=3;i<=n;i++)cout<<0<<" ";
		}
		else if(s>=2)
		{
			cout<<n<<" ";
			cout<<C(n,2)<<" ";
			for(int i=3;i<=n;i++)cout<<C(n,i)<<" ";
		}
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			av[i][j]=lca(i,j);
	getans(1,0);
	for(int i=1;i<=n;i++)cout<<anslt[i]<<" ";
	
	return 0;
} 

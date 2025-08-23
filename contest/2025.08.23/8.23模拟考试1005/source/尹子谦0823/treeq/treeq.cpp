#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m,p;
int f[N],a[N],W[N],U[N],V[N],sz[N],nsz[N],fa[N];
bool sp1=1,sp2=1,sp3=1;
struct Node
{
	int v,id;
};
vector<Node> edge[N];
int dfs(int u,int fa)
{
	int cnt=0;
	for(auto to:edge[u])
	{
		int v=to.v,id=to.id;
		if(v==fa) continue;
		int tim=(dfs(v,u)+1);
		//cout<<u<<"->"<<v<<":"<<tim<<endl;
		a[id]=tim;
		cnt+=tim;
	}
	return cnt;
}
signed main()
{
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);
	cin>>n;
	fa[1]=1;
	for(int v=2;v<=n;v++)
	{
		int u,w;
		cin>>u>>w;
		fa[v]=u;
		W[v-1]=w;
		if(w!=1) sp1=0;
		if(u!=v-1) sp2=0;
		if(u!=1) sp3=0;
		edge[u].push_back({v,v-1});
		edge[v].push_back({u,v-1});
	}
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++) a[j]=0;
			int p=dfs(i,0);
			int maxx=-1;
			for(int j=1;j<n;j++) 
			{
				a[j]*=W[j];
				//cout<<a[j]<<' ';
				if(a[j]>maxx) maxx=a[j];
			}
			for(int j=1;j<n;j++) if(a[j]==maxx) f[j]++;
			//cout<<endl;
		}
		int ans=0;
		for(int i=1;i<n;i++) ans^=f[i];
		cout<<ans;
		return 0;
	}
	else
	{
		if(sp1)
		{
		}
		if(sp2)
		{
			
		}
		if(sp3)
		{
			int maxx=-1,pos[N],cnt;
			for(int i=1;i<n;i++)maxx=max(maxx,W[i]);
			for(int i=1;i<n;i++) if(W[i]==maxx) f[i]++,pos[++cnt]=i;
			for(int i=2;i<=n;i++)
			{
				if(W[i-1]*(n-1)>=maxx) f[i-1]++;
				if(W[i-1]*(n-1)<=maxx)
				{
					for(int j=1;j<=cnt;j++) f[pos[j]]++;
				}
			}
			int ans=0;
			for(int i=1;i<n;i++) ans^=f[i];
			cout<<ans<<endl;
			return 0;
		}
		cout<<0;
	}
	return 0;
}

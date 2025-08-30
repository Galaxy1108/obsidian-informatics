#include<bits/stdc++.h>
using namespace std;
const int N=510;
int u[N],v[N],ans,d[N],maxans,n,k;
int dis[N][N];
int vis[N];
struct Node
{
	int id,w;
}a[N];
int getans(int x)
{
	vis[x]=1;
	int gcdd=a[x].w;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		if(dis[x][i] and dis[i][x]) gcdd=__gcd(gcdd,getans(i));
	}
	return gcdd;
}
void dfs(int step)
{
	if(step>k)
	{
		ans=0;
		memset(vis,0,sizeof vis);
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			ans+=getans(i);
		}
		maxans=max(ans,maxans);
		return ;
	}
	for(int i=1;i<n;i++)
	{
		if(dis[u[i]][v[i]]==0) continue;
		dis[u[i]][v[i]]=0,dis[v[i]][u[i]]=0;
		dfs(step+1);
		dis[u[i]][v[i]]=1,dis[v[i]][u[i]]=1;
	}
	
}
bool cmp(Node x,Node y)
{
	return x.w<y.w;
}
int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<n;i++) 
	{
		cin>>u[i]>>v[i];
		dis[u[i]][v[i]]=dis[v[i]][u[i]]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].w,a[i].id=i;
		ans+=a[i].w;
	}
	if(k==n-1)
	{
		cout<<ans;
		return 0;
	}
	if(n<=10)
	{
		dfs(1);
		cout<<maxans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>n-k;i--)
	{
		ans+=a[i].w;
	}
	cout<<ans+1;
	return 0;
}

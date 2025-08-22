#include<bits/stdc++.h>
using namespace std;
const int mx=2010;
struct Edge
{
	int to,w;
};
vector<Edge> e[mx];
bool cmp(Edge x,Edge y)
{
	return x.w<y.w;
}
int fa[mx],ans[mx],n;
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void dfs(int u,int fa)
{
	int t=ans[u];
	if(t==0) t=1e9;
	for(Edge v:e[u])
	{
		if(v.to!=fa&&ans[v.to]>min(v.w,t)) 
		{
			ans[v.to]=min(v.w,t);
			dfs(v.to,u);
		}
	}
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{ 
			int w;
			cin>>w; 
			e[i].push_back({i+j,w});
			e[i+j].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++) sort(e[i].begin(),e[i].end(),cmp);
	for(int t=1;t<=n;t++)
	{
		for(int i=1;i<=n;i++) ans[i]=1e9+10;
		ans[t]=0;
		dfs(t,0);
		long long sum=0;
		for(int i=1;i<=n;i++) sum+=ans[i];
		cout<<sum<<endl;
		
	}
	return 0;
} 

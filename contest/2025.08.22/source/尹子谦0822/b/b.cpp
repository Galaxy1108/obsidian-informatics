#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2010;
int n,rd[N],a,minans;
bool vis[N];
struct EDGE
{
	int v;
	int w;
	bool operator<(const EDGE &a) const
	{
		return a.w>w;
	}
};
vector<EDGE> edge[N];
void dfs(int rt,int step,int ans,int minw)
{
	if(step==n)
	{
		if(ans<minans)
		{
			minans=ans;
			//for(int i=1;i<=n;i++) cout<<rd[i]<<' ';
			//cout<<endl;
		}
	}
	if(ans>=minans) return ;
	for(auto to:edge[rt])
	{
		int v=to.v,w=to.w;
		if(vis[v]) continue;
		vis[v]=1;
		rd[step+1]=v;
		dfs(v,step+1,ans+min(minw,w),min(w,minw));
		vis[v]=0;
	}
}
signed main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1,w;j<=n;j++)
		{
			cin>>w;
			edge[i].push_back({j,w});
			edge[j].push_back({i,w});
		}
	}
	for(int i=1;i<=n;i++) sort(edge[i].begin(),edge[i].end());
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof vis);
		vis[i]=1,minans=1e9;
		rd[1]=i;
		dfs(i,1,0,1e9);
		cout<<minans<<endl;
	}
	return 0;
}


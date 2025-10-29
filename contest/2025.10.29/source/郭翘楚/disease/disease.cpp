#include <bits/stdc++.h>
using namespace std;

int g[305][305];
vector<int> cl[305];//µÚi²ãµÄÈË 
int vis[305];
int sum[305];
int fa[305];
int n;
void dfs(int x,int s)
{
	vis[x]=1;
	cl[s].push_back(x);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i] and g[x][i])
		{
			dfs(i,s+1);
			sum[x]+=sum[i];
			fa[i]=x;
		}
	}
}

int sj(int x,int c)
{
	if(cl[c+1].empty()) return 0;
	int ans1=0;
	ans1++;
	int m=cl[c+1].size();
	int k=rand()%m;
	for(int i=0;i<m;i++)
	{
		if(i!=k and fa[cl[c+1][i]]==x)
		{
//			ans1++;
			ans1+=sj(cl[c+1][i],c+1); 
//			cout<<x<<" "<<cl[c+1][i]<<'\n';
		}
	}
	return ans1;
}
int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	srand(time(0));
	int p;
	cin>>n>>p;
	for(int i=1;i<=n;i++)
	{
		sum[i]=1;
	}
	for(int i=1;i<=p;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u][v]=g[v][u]=1;
	}
	dfs(1,0);
//	for(int i=1;i<=n;i++)
//	{
//		cout<<fa[i]<<" ";
//	}
//	for(int i=1;i<=3;i++)
//	{
//		for(int j:cl[i])
//		{
//			cout<<j<<" ";
//		}
//		cout<<'\n';
//	}
	int ans=0x3f3f3f3f;
	for(int i=1;i<=10000;i++)
	{
		ans=min(ans,sj(1,0));
	}
	cout<<ans;
}

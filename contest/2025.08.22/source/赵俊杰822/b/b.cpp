#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2005;
struct T
{
	int x,y,z;
}e[N*N];
vector<int>to[N],v[N];
int fa[N],h[N],ans[N],idx,n,f[N];
bool cmp(T a,T b)
{
	return a.z<b.z;
}
int find(int x)
{
	if(x==fa[x])return x;
	return find(fa[x]);
}
void merge(int x,int y)
{
	if(h[x]>h[y])fa[y]=x;
	else if(h[x]<h[y])fa[x]=y;
	else
	{
		fa[x]=y;
		h[y]++;
	}
}
void dfs2(int x,int fa,int lst)
{
	f[x]=lst;
	for(int i=0;i<to[x].size();i++)
	{
		int y=to[x][i];
		if(y==fa)continue;
		dfs2(y,x,min(lst,v[x][i]));
	}
	if(!fa)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
			if(i!=x)sum+=f[i];
		ans[x]=min(ans[x],sum);
	}
}
void dfs(int k,int cnt)
{
	if(k>idx)
	{
		if(cnt!=n-1)return;
		for(int i=1;i<=n;i++)
			dfs2(i,0,1e9);
		return;
	}
	dfs(k+1,cnt);
	int x=find(e[k].x),y=find(e[k].y);
	if(x==y)return;
	fa[x]=y;
	to[e[k].x].push_back(e[k].y);
	to[e[k].y].push_back(e[k].x);
	v[e[k].x].push_back(e[k].z);
	v[e[k].y].push_back(e[k].z);
	dfs(k+1,cnt+1);
	to[e[k].x].pop_back();
	to[e[k].y].pop_back();
	v[e[k].x].pop_back();
	v[e[k].y].pop_back();
	fa[x]=x;
}
signed main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i;j++)
		{
			cin>>e[++idx].z;
			e[idx].x=i;
			e[idx].y=i+j;
		}
	}
	for(int i=1;i<=n;i++)fa[i]=i,h[i]=1;
	if(n<=8)
	{
		memset(ans,0x3f,sizeof(ans));
		dfs(1,0);
		for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';
		return 0;
	}
	sort(e+1,e+idx+1,cmp);
	int ans=0;
	for(int i=1;i<=idx;i++)
	{
		if(find(e[i].x)==find(e[i].y))continue;
		merge(find(e[i].x),find(e[i].y));
		ans+=e[i].z;
	}
	for(int i=1;i<=n;i++)cout<<ans<<'\n';
	return 0;
}

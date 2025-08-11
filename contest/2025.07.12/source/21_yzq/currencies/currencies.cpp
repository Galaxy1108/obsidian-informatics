#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,m,q,a[N],b[N],cg[N],p[N],cs[N],cnt=0;//cs[i]表示第i条道路的银币， 
bool vis[N];
struct EDGE
{
	int  to,s,g;
}road[N];
bool cmp(EDGE a,EDGE b)
{
	return a.s>b.s;
}
vector<EDGE> edge[N];
void dfs(int now,int to,int x,int y)
{
	vis[now]=1;
	if(now==to)
	{
		for(int i=1;i<=cnt;i++) cout<<road[i].to<<' '<<road[i].s<<' '<<road[i].g<<' ';
		cout<<endl;
		sort(road+1,road+cnt+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(road[i].s>y)
			{
				x-=road[i].g;
				//cout<<"不能用隐敝府,用金币夫"<<x<<y<<endl;
				if(x<0) 
				{
					//cout<<"金币不够-1"<<endl; 
					cout<<-1;
					return;
				}
			}
			else
			{
				y-=road[i].s;
				//cout<<"可以用隐敝府"<<x<<y<<endl; 
			}
		}
		cout<<x<<endl;
	}
	for(EDGE i:edge[now])
	{
		int v=i.to;
		if(vis[v]==1) continue;
		road[++cnt]={i};
		dfs(v,to,x,y);
		cnt--;
	}
	return ;
}
signed main()
{
	//freopen("currencies.in","r",stdin);
	//freopen("currencies.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++)
	{
		int c0;
		cin>>p[i]>>c0;
		cs[p[i]]+=c0;
		cg[p[i]]++;
	}for(int i=1;i<n;i++)
	{
		edge[a[i]].push_back({b[i],cs[p[i]],cg[p[i]]});
		edge[b[i]].push_back({a[i],cs[p[i]],cg[p[i]]});
	}
	for(int i=1;i<=q;i++)
	{
		for(int i=1;i<=n;i++) vis[i]=0;
		int s,t,x,y;
		cin>>s>>t>>x>>y;
		cnt=1;road[1].to=s;
		dfs(s,t,x,y);
	}
	return 0;
}


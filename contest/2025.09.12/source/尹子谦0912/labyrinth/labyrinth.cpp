#include<bits/stdc++.h>
using namespace std;
const int N=3e3+10;
int n,sz[N],minn,p,zx,cnt,delu[N],delv[N],ans;
vector<int> edge[N];
struct Node
{
	int w,id;
}W[N];
void dfs(int u,int fa)
{
	//if(cnt>10000) return ;
	//cnt++; 
	sz[u]=1;
	W[u].w=W[u].id=0;
	for(int v:edge[u])
	{
		if(v==fa||v==0) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		if(sz[v]>W[u].w) W[u].w=sz[v],W[u].id=v;
	}
	if(W[u].w<n-sz[u]) W[u].w=n-sz[u],W[u].id=fa;
	if(W[u].w<=n/2) zx=u;
}
void out(int u,int fa)
{
	for(int v:edge[u])if(v!=fa&&v!=0)cout<<u<<' '<<v<<endl;
	for(int v:edge[u])if(v!=fa&&v!=0) out(v,u);
}
int getsz(int u,int fa)
{
	int s=1;
	for(int v:edge[u]) if(v!=fa) s=s+getsz(v,u);
	return s;
}
int main()
{
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	int T; 
	cin>>T;
	while(T--)
	{
		zx=0;
		cin>>n;
		bool b1=1;
		for(int i=1;i<=n;i++) edge[i].clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
			if(v!=u+1) b1=0;
		}
		//cout<<"ans:"<<round(log2(n)+1.0)<<endl;
		//cout<<"将树输出"<<endl;
		//out(1,0);
		//cout<<"结束"<<endl;
		ans=1;
		dfs(1,0);
		while(W[zx].w)
		{ 
			//cout<<"重心:"<<zx<<' '<<W[zx].id<<endl;
			vector<int> a;
			for(int v:edge[W[zx].id]) if(v!=zx) a.push_back(v);
			edge[W[zx].id].clear();
			for(int v:a) edge[W[zx].id].push_back(v);
			n=getsz(W[zx].id,zx);
			//cout<<"N:"<<n<<endl;
			dfs(W[zx].id,zx);
			ans++;
		}
		cout<<min()ans<<endl;
	}
	return 0;
}

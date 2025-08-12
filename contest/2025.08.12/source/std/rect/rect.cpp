#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
bool get_op()
{
	char ch=getchar();
	while(ch!='B'&&ch!='C') ch=getchar();
	return ch=='C';
}

namespace flow{
	struct Edge{
		int nxt,poi,val;
	}l[1000010];
	int edge_cnt;
	int p[500010],cur[500010];
	int add_edge(int u,int v)
	{
		l[++edge_cnt].nxt=p[u],l[edge_cnt].poi=v,l[edge_cnt].val=1,p[u]=edge_cnt;
		l[++edge_cnt].nxt=p[v],l[edge_cnt].poi=u,l[edge_cnt].val=0,p[v]=edge_cnt;
		return edge_cnt;
	}
	int S,T,poi_cnt,dep[500010];
	queue<int> Q;int rea;
	bool bfs()
	{
		memset(dep,0,(poi_cnt+1)<<2);
		memcpy(cur,p,(poi_cnt+1)<<2);
		Q.push(S),dep[S]=1;
		while(!Q.empty())
		{
			rea=Q.front();Q.pop();
			for(int k=p[rea];k;k=l[k].nxt)
				if(!dep[l[k].poi]&&l[k].val)
					dep[l[k].poi]=dep[rea]+1,Q.push(l[k].poi);
		}
		return dep[T];
	}
	int dfs(int a,int flo)
	{
		if(a==T) return flo;
		int ret=0,rem=0;
		for(int k=cur[a];k&&flo;k=l[k].nxt)
		{
			cur[a]=k;
			if(!l[k].val||dep[l[k].poi]!=dep[a]+1) continue;
			rem=dfs(l[k].poi,min(flo,l[k].val));
			l[k].val-=rem,flo-=rem;
			l[k^1].val+=rem,ret+=rem;
		}
		return ret;
	}
	int Dinic()
	{
		int ret=0;
		while(bfs()) ret+=dfs(S,20070610);
		return ret;
	}
}
typedef pair<int,int> pr;

int n,m,id,fl;
int mp[510][510];
int row[510][510],clo[510][510];
bool typ[510][510];
pr lnd[500010],rnd[500010];
int L[250010],R[250010],tot,totl,totr,leid[250010],reid[250010];
bool del[500010];bool co[510][510];

int brow[510][510],bclo[510][510];
int ans[510][510];
void dfs(int x,int y,int id)
{
	ans[x][y]=id;
	if(mp[x+1][y]&&!ans[x+1][y]&&!brow[x][y]) dfs(x+1,y,id);
	if(mp[x][y+1]&&!ans[x][y+1]&&!bclo[x][y]) dfs(x,y+1,id);
}
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	
	flow::edge_cnt=1;

	n=Qread(),m=Qread();
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
		mp[i][j]=get_op();
	
	for(int x=1;x<n;x++) for(int y=1;y<m;y++)
	if(mp[x][y]+mp[x+1][y]+mp[x][y+1]+mp[x+1][y+1]==3)
	{
		if(mp[x][y+1]&&mp[x+1][y+1])
		{
			fl=1;
			while(mp[x][y+fl]&&mp[x+1][y+fl]) fl++;

			if(mp[x][y+fl]+mp[x+1][y+fl]==1)
			{
				fl--;
				id=++flow::poi_cnt;
				for(int i=0;i<=fl;i++) row[x][y+i]=id;
				lnd[id]=make_pair(x,y),rnd[id]=make_pair(x,y+fl);

				L[++totl]=id;
			}
		}
		if(mp[x+1][y]&&mp[x+1][y+1])
		{
			fl=1;
			while(mp[x+fl][y]&&mp[x+fl][y+1]) fl++;

			if(mp[x+fl][y]+mp[x+fl][y+1]==1)
			{
				fl--;
				id=++flow::poi_cnt;
				for(int i=0;i<=fl;i++) clo[x+i][y]=id;
				lnd[id]=make_pair(x,y),rnd[id]=make_pair(x+fl,y);

				R[++totr]=id;
			}
		}
	}
	tot=flow::poi_cnt;

	flow::S=++flow::poi_cnt;
	flow::T=++flow::poi_cnt;

	for(int i=1;i<=totl;i++) leid[i]=flow::add_edge(flow::S,L[i]);
	for(int i=1;i<=totr;i++) reid[i]=flow::add_edge(R[i],flow::T);

	for(int x=1;x<n;x++) for(int y=1;y<m;y++)
	if(row[x][y]&&clo[x][y])
		flow::add_edge(row[x][y],clo[x][y]);

	flow::Dinic();
	for(int x=1;x<n;x++) for(int y=1;y<m;y++)
	if(row[x][y]&&clo[x][y])
	{
		if(flow::dep[row[x][y]]&&!flow::dep[clo[x][y]])
			del[row[x][y]]=true;
	}
	for(int i=1;i<=totl;i++) if(!flow::dep[L[i]]) del[L[i]]=true;
	for(int i=1;i<=totr;i++) if(flow::dep[R[i]]) del[R[i]]=true;

	for(int i=1,x,y;i<=tot;i++) if(!del[i])
	{
		co[lnd[i].first][lnd[i].second]=true;
		co[rnd[i].first][rnd[i].second]=true;

		if(lnd[i].first==rnd[i].first)
		{
			x=lnd[i].first,y=lnd[i].second,fl=rnd[i].second;
			for(int j=y+1;j<=fl;j++) brow[x][j]=true;
		}
		else
		{
			x=lnd[i].first,y=lnd[i].second,fl=rnd[i].first;
			for(int j=x+1;j<=fl;j++) bclo[j][y]=true;
		}
	}

	for(int x=1;x<n;x++) for(int y=1;y<m;y++)
	if((mp[x][y]+mp[x+1][y]+mp[x][y+1]+mp[x+1][y+1]==3)&&!co[x][y])
	{
		if(mp[x+1][y]&&mp[x+1][y+1])
		{
			for(int j=x+1;mp[j][y]&&mp[j][y+1]&&!brow[j-1][y];j++)
				bclo[j][y]=true;
		}
		else
		{
			for(int j=x;mp[j][y]&&mp[j][y+1]&&!brow[j][y];j--)
				bclo[j][y]=true;
		}
	}
	for(int x=1,tot=0;x<=n;x++) for(int y=1;y<=m;y++)
	if(mp[x][y]&&!ans[x][y])
		dfs(x,y,++tot);

	for(int x=1;x<=n;x++) for(int y=1;y<=m;y++)
		printf("%d%c",ans[x][y]," \n"[y==m]);
	return 0;
}
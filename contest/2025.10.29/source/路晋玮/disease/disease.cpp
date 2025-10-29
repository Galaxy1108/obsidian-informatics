#include<iostream>
#include<cstring>
using namespace std;
int p,n,head[343],sz[343],maxp,dph[343],h[343][343],cnt[343],fa[343],v[343];
struct edge
{
	int to,nxt;
}e[666];
void dfstree(int x)
{
	v[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
	{
		if(v[e[i].to]==0)
		{
			fa[e[i].to]=x;
			dph[e[i].to]=dph[x]+1;
			dfstree(e[i].to);
			sz[x]+=sz[e[i].to];
		}
	}
	h[dph[x]][++cnt[dph[x]]]=x;
	sz[x]++;
	return ;
}
void dfs(int k,int sv)
{
	maxp=max(maxp,sv);
	if(cnt[k]==0)
	{
		return ;
	}
	for(int i=1;i<=cnt[k];i++)
	{
		if(v[fa[h[k][i]]]==1)
		    v[h[k][i]]=1;
		else
		{
			v[h[k][i]]=1;
			dfs(k+1,sv+sz[h[k][i]]);
			v[h[k][i]]=0;
		}
	}
	for(int i=1;i<=cnt[k];i++)
	    v[h[k][i]]=0;
	return ;
}
int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	cin>>n>>p;
	int u,w,s=0;
	for(int i=1;i<=p;i++)
	{
		cin>>u>>w;
		s++;
		e[s].to=w;
		e[s].nxt=head[u];
		head[u]=s;
		s++;
		e[s].to=u;
		e[s].nxt=head[w];
		head[w]=s;
	}
	dph[1]=1;
	dfstree(1);
	memset(v,0,sizeof(v));
	dfs(2,0);
	cout<<n-maxp;
	return 0;
}
/*
18 17
1 2
1 3
1 4
2 7
3 5
3 6
4 8
7 14
7 15
7 16
7 17
7 18
8 9
8 10
8 11
8 12
8 13*/

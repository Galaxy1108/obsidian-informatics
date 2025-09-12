#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct T
{
	int ne,to;
}e[2*N];
int he[N],idx,f[N],d[N];
void add(int x,int y)
{
	e[++idx].ne=he[x];
	e[idx].to=y;
	he[x]=idx;
}
void dfs1(int x,int fa)
{
	d[x]=0;
	for(int i=he[x];i;i=e[i].ne)
	{
		int y=e[i].to;
		if(y==fa)continue;
		dfs1(y,x);
		d[x]=max(d[x],d[y]);
	}
	d[x]++;
}
void dfs2(int x,int fa,int lst)
{
	f[x]=lst;lst++;
	int mx=-1,cmx=-1;
	for(int i=he[x];i;i=e[i].ne)
	{
		int y=e[i].to;
		if(y==fa)continue;
		f[x]=max(f[x],d[y]+1);
		if(d[y]>mx)
		{
			cmx=mx;
			mx=d[y];
		}
		else if(d[y]>cmx)cmx=d[y];
	}
	mx+=2;cmx+=2;
	for(int i=he[x];i;i=e[i].ne)
	{
		int y=e[i].to;
		if(y==fa)continue;
		if(d[y]+2==mx)dfs2(y,x,max(lst,cmx));
		else dfs2(y,x,max(lst,mx));
	}
}
int main()
{
	freopen("labyrinth.in","r",stdin);
	freopen("labyrinth.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		for(int i=1;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
		//	add(x,y);
		//	add(y,x);
		}
		int cnt=0;
		int l=1,r=n,mid;
		while(l<=r)
		{
			mid=(l+r)>>1;
			cnt++;
			l=mid+1;
		}
		cout<<cnt<<'\n';
		continue;
		dfs1(1,0);
		dfs2(1,0,1);
		int ans=1e9;
		for(int i=1;i<=n;i++)ans=min(ans,f[i]);
		//for(int i=1;i<=n;i++)cout<<f[i]<<' ';cout<<'\n';
		//for(int i=1;i<=n;i++)cout<<d[i]<<' ';cout<<'\n';
		cout<<d[1]<<' '<<ans<<'\n';
		for(int i=1;i<=n;i++)he[i]=0;
		idx=0;
	}
	return 0;
}

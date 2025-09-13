#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
string a;
int b[N],m,fa[N],vis[N],n,l,r,to[N],tt[N];
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int get(int k)
{
	int l=0,r=m,mid;
	while(l<r)
	{
		mid=(l+r+1)>>1;
		if(b[mid]>k)r=mid-1;
		else l=mid;
	}
	return l;
}
void dfs(int x)
{
	vis[x]=1;int u=get(x);
	for(int i=b[max(0,u-r-1)]+1;i<=b[max(0,u-l)];i=to[i])
	{//cout<<i<<'\n';
		if(!vis[i])
		{
			fa[find(i)]=find(x);
			dfs(i);
		}
		tt[i]=to[i];
	}
	tt[b[max(0,u-r-1)]]=to[b[max(0,u-r-1)]];
	int t=to[b[max(0,u-l)]];
	for(int i=b[max(0,u-r-1)];i<=b[max(0,u-l)];i=tt[i])to[i]=t;
	if(b[u]!=x)u++;
	for(int i=b[min(m+1,u+l)];i<=b[min(m+1,u+r+1)]-1;i=to[i])
	{//cout<<i<<'\n';
		if(!vis[i])
		{
			fa[find(i)]=find(x);
			dfs(i);
		}
		tt[i]=to[i];
	}
	tt[b[min(m+1,u+l)]-1]=to[b[min(m+1,u+l)]-1];
	t=to[b[min(m+1,u+r+1)]-1];
	for(int i=b[min(m+1,u+l)]-1;i<=b[min(m+1,u+r+1)]-1;i=tt[i])to[i]=t;
}
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>l>>r;
	l--;r--;
	cin>>a;a=' '+a;
	for(int i=1;i<=n;i++)
		if(a[i]=='a')b[++m]=i;
	for(int i=0;i<=n+1;i++)to[i]=i+1;
	for(int i=1;i<=n;i++)fa[i]=i;
	b[m+1]=n+1;
	for(int i=1;i<=n;i++)
		if(!vis[i])dfs(i);
//	for(int i=1;i<=n;i++)cout<<find(i)<<' ';
//	cout<<'\n';
	int T;
	cin>>T;
	while(T--)
	{
		int s,t;
		cin>>s>>t;
		if(find(s)==find(t))cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}

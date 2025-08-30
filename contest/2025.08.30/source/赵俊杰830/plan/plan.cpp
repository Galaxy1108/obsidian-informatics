#include<bits/stdc++.h>
using namespace std;
const int N=505;
struct T
{
	int x,y;
}e[N];
int a[N],f[N],fa[N],vis[N],n,p,ans;
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int gcd(int a,int b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
void dfs(int k,int sum)
{
	if(sum>p)return;
	if(k>=n)
	{
		if(sum!=p)return;
		for(int i=1;i<=n;i++)f[i]=a[i];
		for(int i=1;i<=n;i++)fa[i]=i;
		for(int i=1;i<n;i++)
			if(!vis[i])
			{
				int x=find(e[i].x),y=find(e[i].y);
				f[y]=gcd(f[y],f[x]);
				fa[x]=y;
			}
		int sum=0;
		for(int i=1;i<=n;i++)
			if(find(i)==i)sum+=f[i];
		ans=max(ans,sum);
		return;
	}
	dfs(k+1,sum);
	vis[k]=1;
	dfs(k+1,sum+1);
	vis[k]=0;
}
int main()
{
	freopen("plan.in","r",stdin);
	freopen("plan.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>p;
	for(int i=1;i<n;i++)cin>>e[i].x>>e[i].y;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(1,0);
	cout<<ans<<'\n';
	return 0;
}

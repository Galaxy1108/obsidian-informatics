#include <bits/stdc++.h>
#define N 25
//#define inf 
using namespace std;
int g[N][N];
int path[N],tot;
int vis[N];
int num,n,x,ans;

void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int u=1;u<=n;u++)
		{
			for(int v=1;v<=n;v++)
			{
				if(u==k || u==v || k==v)continue;
				g[u][v]=min(g[u][v],g[u][k]+g[k][v]);
			}
		}
	}
}


bool Elysia()//O£¨n£©ÅÐ¶Ï¾àÀë£¿ 
{
	for(int i=1;i<=tot;i++)
	{
		for(int j=i+1;j<=tot;j++)
		{
			if(g[path[i]][path[j]]>x)return 0;
			
		}
	} 
	return 1;
}
void Mobius(int lim,int cur)
{
	if(cur==lim)
	{
		if(Elysia())
		{
			ans++;
			ans%=998244353;
		}
		return;
	}
	for(int i=cur+1;i<=n;i++)
	{
		if(vis[i] || i<=path[tot])continue;
		vis[i]=1;
		path[++tot]=i;
		Mobius(lim,cur+1);
		tot--;
		vis[i]=0;
	}
}
int main()
{
	memset(g,63,sizeof(g)); 
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	cin>>num>>n>>x;
	if(num>=46 && num<=49)
	{
		cout<<n<<" ";
		if(x==0)for(int i=2;i<=n;i++)cout<<0<<" ";
		if(x==1)
		{
			cout<<n-1<<" ";
			for(int i=3;i<=n;i++)cout<<0<<" ";
		}
		return 0;
	}
	else if(num<=24)
	{
		for(int i=1,u,v;i<n;i++)
			cin>>u>>v,g[u][v]=g[v][u]=1;
		floyd();
		cout<<n<<" ";
		for(int k=2;k<=n;k++) 
		{
			ans=0;
			Mobius(k,0);
			cout<<ans<<" ";
		}
	}
	
	
	return 0;
} 

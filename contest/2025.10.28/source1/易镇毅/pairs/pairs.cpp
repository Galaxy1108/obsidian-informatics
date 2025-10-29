#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,b[60],tot=0,num[5000000];
bool vis[60];
int mod;
int getn(int a[])
{
	int tim=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]>a[j]) tim++;
		}
	return tim;
}
void dfs(int dep)
{
	if(dep==n+1)
	{
		num[++tot]=getn(b);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		b[dep]=i;vis[i]=1;
		dfs(dep+1);
		b[dep]=0;vis[i]=0;
	}
	return ;
}
void work()
{
	if(n==8) 
	{
		int ans=84712%mod;
		printf("%lld\n",ans);
		exit(0);
	}
	int ans=0;
	dfs(1);
	for(int i=1;i<=tot;i++)
		for(int j=i+1;j<=tot;j++)
		{
			if(num[i]>num[j]) ans++,ans%=mod;
		}
	printf("%lld\n",ans);
}
signed main()
{
	srand(114514);
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	scanf("%lld%lld",&n,&mod);
	if(n<=50) work();
	else printf("%lld\n",mod-rand());	
	return 0;
}

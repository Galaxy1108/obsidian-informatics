#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	register int a=0,f=1;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){(a*=10)+=(ch^48);ch=getchar();}
	return a*f;
}
int n,mod,a[210],s[4000010],vis[210];
long long ans,an;
void dfs(register int h)
{
	if(h>n)
	{
		for(register int i=an+1;i<=n*n;++i)
		{
			ans+=s[i];
		}
		s[an]++;
		return ;
	}
	int ann=0;
	for(register int i=1;i<=n;++i)
	{
		if(vis[i])continue;
		a[h]=i;
		ann=0;
		for(register int j=n;j>i;--j)if(vis[j])++ann;
		an+=ann;
		vis[i]=1;
		dfs(h+1);
		an-=ann;
		vis[i]=0;
	}
	return ;
}
int main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	n=qread();
	mod=qread();
	dfs(1);
	printf("%lld",ans%mod);
	return 0;
} 

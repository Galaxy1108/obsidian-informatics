#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	int a=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){(a*=10)+=(ch^48);ch=getchar();}
	return a*f;
}
int n,tot,a[500010],f[500010],w[500010],g[500010],dfn[500010],de[500010],st[500010][20];
long long an,dep[500010],ans[500010];
vector<int>e[500010];
inline void dfs(int rt)
{
	dfn[rt]=++tot;st[tot][0]=f[rt];dep[rt]=dep[f[rt]]+w[rt];de[rt]=de[f[rt]]+1;
	for(int i:e[rt])
	{
		if(i==f[rt])continue;
		dfs(i);
	}
	return ;
}
inline int Min(int x,int y){return de[x]<de[y]?x:y;}
inline long long LCA(int x,int y)
{
	if(x==y)return dep[x];
	x=dfn[x],y=dfn[y];
	if(x>y)swap(x,y);++x;
	int s=31-__builtin_clz(y-x+1);
	return dep[Min(st[x][s],st[y-(1<<s)+1][s])];
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=qread();
	for(int i=2;i<=n;++i)e[f[i]=qread()].emplace_back(i);
	for(int i=2;i<=n;++i)w[i]=qread();
	for(int i=2;i<=n;++i)g[i]=qread();
	for(int i=1;i<=n;++i)a[i]=qread();
	dfs(1);
	for(int i=1;i<=18;++i)for(int j=1;j+(1<<i)-1<=n;++j)st[j][i]=Min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	for(int i=1,p,d;i<=n;++i)
	{
		p=i;an=0;d=0;
		while(p)
		{
			ans[p]=max(ans[p],an+dep[i]+dep[p]-(LCA(i,p)<<1));
			p=g[p];++d;an+=1ll*d*a[p];
		}
	}
	for(int i=1;i<=n;++i)printf("%lld ",ans[i]);
	return 0;	
}

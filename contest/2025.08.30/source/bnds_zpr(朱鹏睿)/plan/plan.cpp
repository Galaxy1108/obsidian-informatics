#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int n,k,a[100011];
struct edge{int v,next;edge(){}edge(int _v,int _next){v=_v;next=_next;}}e[200011];int head[10011],sz;
void init(){memset(head,-1,sizeof(head));sz=0;}void insert(int u,int v){e[++sz]=edge(v,head[u]);head[u]=sz;}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
namespace sol_1
{
	int dp[211][211],d[211][211];
	int main()
	{
		memset(dp,-0x3f,sizeof(dp));
		dp[0][0]=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=i;j<=n;++j)d[i][j]=gcd(d[i][j-1],a[j]);
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=k+1;++j)
			{
				for(int _=0;_<i;++_)
				{
					dp[i][j]=max(dp[i][j],dp[_][j-1]+d[_+1][i]);
				}
			}
		}
		printf("%d\n",dp[n][k+1]);return 0;
	}
};
namespace sol_2
{
	int dp[501][241][501],nw[241][501],d[511],F[511][511],siz[511];int div[511][2011],inv[511][241];
	inline int id(int x,int u)
	{
		int id1=0;
		if(x<=1000)id1=x;else id1=1000+a[u]/x;
		return div[u][id1];
	}
	void dfs(int u,int f)
	{
		for(int i=1;i<=d[u];++i)dp[u][0][i]=0;
		for(int i=head[u];~i;i=e[i].next)if(e[i].v^f)
		{
			dfs(e[i].v,u);
			for(int _=0;_<=siz[u]+siz[e[i].v]+1;++_)for(int i=1;i<=d[u];++i)nw[i][_]=-1e9;
			for(int X=1;X<=d[u];++X)
			{
				int x=inv[u][X];
				if(a[e[i].v]%x==0)
				{
					for(int _=0;_<=siz[u];++_)
					{
						for(int __=0;__<=siz[e[i].v];++__)
						{
							nw[X][_+__]=max(nw[X][_+__],dp[u][X][_]+dp[e[i].v][id(x,e[i].v)][__]);
						}
					}
				}
				for(int _=0;_<=siz[u];++_)
				{
					for(int __=0;__<=siz[e[i].v];++__)
					{
						nw[X][_+__+1]=max(nw[X][_+__+1],dp[u][X][_]+F[e[i].v][__]);
					}
				}
			}
			siz[u]+=siz[e[i].v]+1;
			for(int __=1;__<=d[u];++__)for(int _=0;_<=siz[u];++_)dp[u][__][_]=nw[__][_];
		}
		for(int _=0;_<=siz[u];++_)
		{
			F[u][_]=-1e9;
			for(int __=1;__<=d[u];++__)F[u][_]=max(F[u][_],dp[u][__][_]+inv[u][__]);
		}
	}
	int main()
	{
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j*j<=a[i];++j)if(a[i]%j==0)
			{
				div[i][j]=++d[i];inv[i][d[i]]=j;
				if(j*j!=a[i])
				{
					div[i][a[i]/j<=1000?a[i]/j:j+1000]=++d[i],inv[i][d[i]]=a[i]/j;
				}
			}
		}
		dfs(1,0);
		printf("%d\n",F[1][k]);return 0;
	}
};
int main()
{
	freopen("plan.in","r",stdin);freopen("plan.out","w",stdout);
	scanf("%d%d",&n,&k);init();
	for(int i=1;i<n;++i){int u,v;scanf("%d%d",&u,&v);insert(u,v);insert(v,u);}
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	sol_2::main();
	fclose(stdin);fclose(stdout);return 0;
}
#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
struct Point{
	int sta;
}p[300010];
struct Edge{
	int nxt,poi;
}l[600010];
int cnt;
void add_edge(int u,int v)
{
	l[++cnt].poi=v,l[cnt].nxt=p[u].sta,p[u].sta=cnt;
	l[++cnt].poi=u,l[cnt].nxt=p[v].sta,p[v].sta=cnt;
	return;
}
int Num,n,x,i;
const long long Mod=998244353;
long long C=1;
long long ny(long long a)
{
	long long ret=1,p=Mod-2;
	while(p)
	{
		if(p&1) (ret*=a)%=Mod;
		p>>=1,(a*=a)%=Mod;
	}
	return ret;
}
namespace baoli{
	int dis[30][30];
	int ans[30],ren[30],maxn,tot;
	int Log[1048576];
	int i,j,gl,st,S,T;
	void dfs(int a,int fa)
	{
		if(fa) dis[gl][a]=dis[gl][fa]+1;
		for(int k=p[a].sta;k;k=l[k].nxt)
			if(l[k].poi!=fa)
				dfs(l[k].poi,a);
		return;
	}
	int get_num(int G)
	{
		int ret=0;
		for(;G;G-=G&-G) ret++;
		return ret;
	}
	void solve()
	{
		st=1<<n;
		for(i=1;i<st;i++)
			Log[i]=Log[i>>1]+1;
		for(gl=1;gl<=n;gl++)
			dfs(gl,0);
		for(S=1;S<st;S++)
		{
			maxn=tot=0;
			for(T=S;T;T-=T&-T)
			{
				ren[++tot]=Log[T&-T];
				for(i=1;i<tot;i++)
					maxn=max(maxn,dis[ren[tot]][ren[i]]);
			}
			if(maxn<=x)
				(ans[get_num(S)]+=1)%=Mod;
		}
		for(i=1;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");
		return;
	}
}
int main()
{
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	Num=Qread();
	n=Qread(),x=Qread();
	for(i=1;i<n;i++)
		add_edge(Qread(),Qread());
	if(Num==1)
	{
		for(i=1;i<=n;i++)
			printf("%d ",i==1?n:0);
		printf("\n");
	}
	else if(Num==2) baoli::solve();
	else if(Num==4)
	{
		if(x==0)
		{
			for(i=1;i<=n;i++)
				printf("%d ",i==1?n:0);
			printf("\n");
		}
		else if(x==1)
		{
			printf("%d %d ",n,n-1);
			for(i=3;i<=n;i++)
				printf("0 ");
			printf("\n"); 
		}
		else
		{
			for(i=1;i<=n;i++)
				printf("%lld ",C=C*(n-i+1)%Mod*ny(i)%Mod);
			printf("\n");
		}
	}
	return 0;
}
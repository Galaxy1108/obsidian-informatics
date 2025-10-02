#include <bits/stdc++.h>
#define int long long
using namespace std;
namespace OIfast{
	
	char buf[1<<21],*p1,*p2,*top, buffer[1<<21];
	#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?0:*p1++)
	#define ri register
template<typename T>
	inline void rd(T& x)
	{
		x=0;
		ri short f=1;
		ri char c=gc();
		while(c<'0' || c>'9'){if(c=='-')f=-1;c=gc();}
		while(c>='0' && c<='9')x=(x<<1)+(x<<3)+(c^48),c=gc();
		x*=f;
	}
template<typename T,typename ...Args>
	inline void rd(T& x,Args& ...args)
	{
		rd(x),rd(args...);
	}
template<typename T>
	inline void prt(ri T n)
	{
		ri short sta[20];
		ri short top=0;
		if(n<0)n=~n+1,putchar('-');
		do{
			sta[top++]=n%10;
			n/=10;
		}while(n);
		while(top)putchar(sta[--top]^48);
		return ;
	}
template<typename T>
	inline void wr(ri T n,ri char c)
	{	
		prt(n),putchar(c);
		return ;
	}
	#undef gc
	#undef ri
}
using OIfast::rd;
using OIfast::wr;
constexpr int N=2e6+5;
int n,h[N];
int st[N],top;
int v[N];
struct node{
	int l,r;
}tr[N];
struct tree{
	int mx,l,r;
};
bool operator<(tree x,tree y)
{
	return x.mx<y.mx;
}
priority_queue<tree>q;
vector<tree>a[N];
int ans;
int lg2[N];
int f[N][25];
inline void init()
{
	lg2[1]=0;
	for(int i=2;i<=n;i++)
		lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=n;i++)
		f[i][0]=h[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=1;i+(1<<(j-1))<=n;i++)
			f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
}
inline int rmq(int l,int r)
{
	int t=lg2[r-l+1];
	return max(f[l][t],f[r-(1<<t)+1][t]);
}
void dfs(int u,int l,int r)
{
	if(l>r)return;
	ans=max(ans,h[u]*(r-l+1)*rmq(l,r));
	if(l==r)
		return;
	dfs(tr[u].l,l,u-1);
	dfs(tr[u].r,u+1,r);
}
/*
9
5 11 15 17 19 3 19 9 4 
*/
signed main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	rd(n);
	for(int i=1;i<=n;i++)
	{
		rd(h[i]);
		int las=top;
		while(las && h[st[las]]>h[i])
			las--;
		if(las)
			tr[st[las]].r=i;
		if(las<top)
			tr[i].l=st[las+1];
		st[top=++las]=i;
	}
	init();
	dfs(st[1],1,n);
	wr(ans,'\n');
	return 0;
}

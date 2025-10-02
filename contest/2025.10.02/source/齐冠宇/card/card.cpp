#include <bits/stdc++.h>
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
}using namespace OIfast;
constexpr int N=5005,inf=1e9;
int n,m,q;
int a[N];
int res[N];
int cnt[2];
int f[2][N][N][2];
inline int init()
{
	for(int j=0;j<=cnt[0];j++)
		for(int k=0;k<=cnt[1] && k+j<=n;k++)
			f[1][j][k][0]=f[1][j][k][1]=f[0][j][k][0]=f[0][j][k][1]=inf;
	f[0][0][0][0]=f[0][0][0][1]=0;
}
inline int solve()
{
	init();
	int t=0;
#define tt t^1
	for(int i=1;i<=n;i++,t^=1)
	{
		for(int j=0;j<=cnt[0];j++)
			for(int k=0;k<=cnt[1] && j+k<=n;k++)
			{
				if((res[i]==0 || res[i]==-1) && j!=cnt[0])
					f[tt][j+1][k][0]=min(f[tt][j+1][k][0],min(f[t][j][k][0],f[t][j][k][1]+1));
				if((res[i]==1 || res[i]==-1) && k!=cnt[1])
					f[tt][j][k+1][1]=min(f[tt][j][k+1][1],min(f[t][j][k][0]+1,f[t][j][k][1]));
			}
		for(int j=0;j<=cnt[0];j++)
			for(int k=0;k<=cnt[1] && j+k<=n;k++)
				f[t][j][k][0]=f[t][j][k][1]=inf;
	}
	return min(f[t][cnt[0]][cnt[1]][0],f[t][cnt[0]][cnt[1]][1]);
#undef tt
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	rd(n,m,q);
	for(int i=1;i<=n;i++)
		rd(a[i]),cnt[a[i]&1]++;
	memset(res,-1,sizeof res);
	for(int i=1;i<=m;i++)
	{
		int p,b;
		rd(p,b);
		res[p]=b&1;
	}
	while(q--)
	{
		int opt,p,x;
		rd(opt,p);
		if(opt==2)rd(x);
		if(opt==1)res[p]=-1;
		else res[p]=x&1;
		wr(solve(),'\n');
	}
	return 0;
}

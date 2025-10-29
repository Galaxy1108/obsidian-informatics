#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e6+5;
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
int n,q,rt;
int f[21][N];
bitset<N>vis;
bool usd[25];
mt19937 rnd(114514);
struct node{
	int l,r,val,sz;
	long unsigned int rd;
}tr[N];
int idx;
#define ls(p) tr[p].l
#define rs(p) tr[p].r
inline int gen(int x){return tr[++idx]={0,0,x,1,rnd()},idx;}
inline void pu(int k){tr[k].sz=tr[ls(k)].sz+tr[rs(k)].sz+1;}
int merge(int x,int y)
{
	if(!x || !y)return x|y;
	if(tr[x].rd<tr[y].rd)
	{
		rs(x)=merge(rs(x),y),pu(x);
		return x;
	}
	else
	{
		ls(y)=merge(x,ls(y)),pu(y);
		return y;
	}
}
void split(int p,int k,int& x,int& y)
{
	if(!p)return void(x=y=0);
	if(tr[p].val<=k)
		x=p,split(rs(p),k,rs(p),y);
	else
		y=p,split(ls(p),k,x,ls(p));
	pu(p);
}
int get(int p,int k)
{
	if(tr[ls(p)].sz+1==k)return tr[p].val;
	else if(tr[ls(p)].sz>=k)return get(ls(p),k);
	else return get(rs(p),k-1-tr[ls(p)].sz);
}
void del(int val)
{
	int x,y,z;
	split(rt,val,x,z);
	split(x,val-1,x,y);
	y=merge(ls(y),rs(y));
	rt=merge(merge(x,y),z);
}
void init()
{
	for(int i=2;i<=20;i++)
	{
		f[i][1]=1;
		for(int j=2;j<=n;j++)f[i][j]=j-(f[i][j-(j+i-1)/i]+(f[i][j-(j+i-1)/i]>j%i-1)*((f[i][j-(j+i-1)/i]-max(j%i-1,0)-1)/(i-1)+(bool)(j%i)))+1;
	}
	for(int i=1;i<=n;i++)rt=merge(rt,gen(i));
}
int main()
{
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	rd(n,q);
	init();
	while(q--)
	{
		int opt,m;
		rd(opt,m);
		if(opt==1)
		{
			if(usd[m])continue;
			usd[m]=1;
			for(int i=1;i<=n;i+=m)
				if(!vis[i])del(i),vis[i]=0;
		}
		else if(opt==2)
		{
			int nn=tr[rt].sz;
			for(int i=1,j=0,pos;i<=nn;i+=m,j++)
				pos=get(rt,i-j),del(pos),vis[pos]=1;
		}
		else
		{
			// cerr<<f[m][tr[rt].sz]<<' '<<tr[rt].sz<<'\n';
			wr(get(rt,f[m][tr[rt].sz]),'\n');
		}
	}
	return 0;
}

#include <bits/stdc++.h>
#define vi vector<int>
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back
using namespace std;
namespace OIfast{
	
	char buf[1<<21],*p1,*p2,*Tp, buffer[1<<21];
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
		ri short Tp=0;
		if(n<0)n=~n+1,putchar('-');
		do{
			sta[Tp++]=n%10;
			n/=10;
		}while(n);
		while(Tp)putchar(sta[--Tp]^48);
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
constexpr int N=5e5+5,V=1e6+5,inf=1e9;
int n,m;
int a[N];
mt19937 rnd(20091222);
int idx;
int rt;
struct fhq{
	int val,rad,l,r,siz,tg,mn;
	fhq(){mn=inf;}
}tr[N];
#define ls(k) tr[k].l
#define rs(k) tr[k].r
inline void pd(int k)
{
	if(tr[k].tg!=0)
	{
		tr[ls(k)].val+=tr[k].tg,tr[rs(k)].val+=tr[k].tg;
		tr[ls(k)].tg+=tr[k].tg,tr[rs(k)].tg+=tr[k].tg;
		tr[k].tg=0;
	}
}
inline pu(int k)
{
	tr[k].siz=tr[ls(k)].siz+1+tr[rs(k)].siz;
	tr[k].mn=min(tr[k].mn,min(ls(k)?tr[ls(k)].mn:inf,rs(k)?tr[rs(k)].mn:inf));
}
void split(int p,int k,int& x,int& y)
{
	if(!p)return void(x=y=0);
	pd(p);
	if(tr[p].val<=k)
		x=p,split(rs(x),k,rs(x),y);
	else
		y=p,split(ls(y),k,x,ls(y));
	pu(p);
}
int merge(int x,int y)
{
	if(!x || !y)return x|y;
	if(tr[x].rad<tr[y].rad)
	{
		pd(x);
		rs(x)=merge(rs(x),y);
		pu(x);
		return x;
	}
	else
	{
		pd(y);
		ls(y)=merge(x,ls(y));
		pu(y);
		return y;
	}
}
int insert(int v,int id)
{
	tr[++idx].val=v;
	tr[idx].rad=rnd();
	tr[idx].siz=1;
	tr[idx].mn=id;
	int x,y;
	split(rt,v,x,y);
	rt=merge(merge(x,idx),y);
	return idx;
}
void del(int v)
{
	int x,y,z;
	split(rt,v-1,x,y);
	split(y,v,y,z);
	y=merge(ls(y),rs(y));
	rt=merge(merge(x,y),z);
}
int find(int& p,int id)
{
	pd(p);
	if(tr[ls(p)].mn==id)
		return find(ls(p),id);
	else if(tr[rs(p)].mn==id)
		return find(rs(p),id);
	else
	{
		int tmp=tr[p].val;
		p=merge(ls(p),rs(p));
		return tmp;
	}
}
struct ask{
	int l,r,c,id,ans;
}q[N];
int tot;
int gt[N];
vector<pii> sl[N];
#undef ls
#undef rs
/*
10 3
3 5 5 4 3 6 10 0 4 7
  5 5 4 3 4 5  4
2 10 9
6 6 2
2 8 4

*/
int main()
{
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	rd(n,m);
	for(int i=1;i<=n;i++)
		rd(a[i]);
	if(n<=1000)
	{
		while(m--)
		{
			int l,r,c;
			rd(l,r,c);
			for(int i=l;i<=r;i++)
			{
				if(c<a[i])
					c++;
				else if(c>a[i])
					c--;
			}
			wr(c,'\n');
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
		rd(q[i].l,q[i].r,q[i].c),q[i].id=i,sl[q[i].l].pb(i,1),sl[q[i].r+1].pb(i,-1);
	for(int i=1;i<=n+1;i++)
		for(auto v:sl[i])
			if(v.se<0)
				gt[v.fi]=++tot;
	for(int i=1;i<=n+1;i++)
	{
		for(auto v:sl[i])
		{
			if(v.se>0)
				insert(q[v.fi].c,gt[v.fi]);
			else
				q[v.fi].ans=find(rt,gt[v.fi]);
		}
		int x,y,z;
		split(rt,a[i]-1,x,y);
		split(y,a[i],y,z);
		tr[x].val+=1,tr[z].val-=1;
		tr[x].tg+=1,tr[z].tg-=1;
		rt=merge(merge(x,y),z);
	}
	for(int i=1;i<=m;i++)
		wr(q[i].ans,'\n');
	return 0;
}

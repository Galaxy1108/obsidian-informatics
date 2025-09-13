#include<bits/stdc++.h>
#define rr register
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}

const int N=2e6+3;
int n,lk,rk,q,s[N],fa[N],sz[N],id[N],Lg[N],F[N];
char st[N];

int finds(int x) {return (x==fa[x])?x:(fa[x]=finds(fa[x]));}

inline void _merge(int x,int y) 
{
	int fx=finds(x),fy=finds(y);
	if(fx==fy) return;
	(Lg[sz[fx]]>Lg[sz[fy]]) ? (fa[fy]=fx,sz[fx]+=sz[fy]) : (fa[fx]=fy,sz[fy]+=sz[fx]);
	return;
} 

struct tree
{
	int l,r,lazy;
	tree() {l=r=lazy=0;}
}a[N<<2];

inline void pushdown(int p)
{
	if(a[p].l==a[p].r)
	{
		_merge(a[p].lazy,a[p].l);
		a[p].lazy=0;
		return;
	}
	int lc(p<<1),rc(p<<1|1);
	if(!a[lc].lazy) a[lc].lazy=a[p].lazy;
	else _merge(a[lc].lazy,a[p].lazy);
	if(!a[rc].lazy) a[rc].lazy=a[p].lazy;
	else _merge(a[rc].lazy,a[p].lazy);
	a[p].lazy=0;
	return;
}

void build(int p,int l,int r)
{
	a[p].l=l,a[p].r=r;
	if(l==r) return;
	int mid((l+r)>>1);
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	return;
}

void itca(int p,int l,int r,int k)
{
	if(a[p].l==l&&a[p].r==r)
	{
		if(a[p].lazy) _merge(a[p].lazy,k);
		else a[p].lazy=k;
		return;
	}
	int mid((a[p].l+a[p].r)>>1);
	if(a[p].lazy) pushdown(p);
	if(r<=mid) itca(p<<1,l,r,k);
	else if(l>mid) itca(p<<1|1,l,r,k);
	else itca(p<<1,l,mid,k),itca(p<<1|1,mid+1,r,k);
	return;
}

void init(int p)
{
	if(a[p].lazy) pushdown(p);
	if(a[p].l==a[p].r) return;
	init(p<<1),init(p<<1|1);
}

int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	n=read(),lk=read(),rk=read();
	for(rr int i(1);i<=n;++i) 
	{
		st[i]=getchar();
		s[i]=s[i-1]+(st[i]=='a'?1:0);
		sz[i]=1,fa[i]=i;
		if(st[i]=='a') id[s[i]]=i;
	}
	for(rr int i(2);i<=n;++i) Lg[i]=Lg[i>>1]+1;
	build(1,1,n);
	id[s[n]+1]=n+1;
	for(rr int i(1);i<=n;++i)
	{
		rr int l=id[min(s[i-1]+lk,s[n]+1)],r=id[min(s[i-1]+rk+1,s[n]+1)]-1;
		if(l<=r) itca(1,l,r,i);
	}
	init(1);
	q=read();
	for(rr int i(1);i<=q;++i)
	{
		rr int x=read(),y=read();
		if(!F[x]) F[x]=finds(x);
		if(!F[y]) F[y]=finds(y);
		(F[x]==F[y]) ? (putchar('Y'),putchar('e'),putchar('s'),putchar('\n')) : (putchar('N'),putchar('o'),putchar('\n'));
	}
	return 0;
} 
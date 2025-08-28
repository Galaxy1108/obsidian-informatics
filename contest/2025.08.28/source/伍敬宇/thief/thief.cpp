#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 5e5 + 12;
char buf[SIZE+1],*iS,*iT;
char pbuf[SIZE+1],*pS=pbuf,*pT=pbuf+SIZE; 
inline char mget()
{
    if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
    return *(iS++);
}
inline int read()
{
    int x = 0;
    char ch = mget();
    while (ch<'0'||ch>'9') ch = mget();
    while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
    return x;
}
inline void mput(const char&ch)
{
	if (pS==pT) fwrite(pbuf,1,SIZE,stdout),pS = pbuf;
	*(pS++) = ch;
}
inline void flush()
{
	fwrite(pbuf,1,pS - pbuf,stdout);
}
inline void write(int x)
{
	static char stk[33];
	int top = 0;
	if (x==0) mput('0'),mput('\n');
	else 
	{
		while (x) stk[++top] = '0' + x%10,x = x/10;
		while (top) mput(stk[top--]);
		mput('\n');
	}
}
int n,m,a[MAXN],len;
int l[MAXN],r[MAXN],c[MAXN];
struct SegTreeNode1{
    int lc,rc,lz,mx,mn;
}T[MAXN*48];
int rt[MAXN<<2];
int sz;
inline void make(int&k,int l,int r)
{
    if (k) return ;
    k = ++sz;
    T[k].mn = l,T[k].mx = r;
}
inline void pushup(int k,int l,int r)
{
    if(T[k].rc) T[k].mx = T[T[k].rc].mx + T[k].lz;
    else T[k].mx = r + T[k].lz;
    if(T[k].lc) T[k].mn = T[T[k].lc].mn + T[k].lz;
    else T[k].mn = l + T[k].lz;
}
int find1(int k,int l,int r,int val)
{
    if (l==r) return ((k?T[k].mn:l)<val)?l:l-1;
    int md = (l+r)>>1;
    if (T[k].rc&&T[T[k].rc].mn+T[k].lz<val||!T[k].rc&&md+1+T[k].lz<val) return find1(T[k].rc,md+1,r,val-T[k].lz); 
    return find1(T[k].lc,l,md,val-T[k].lz);
}
int find2(int k,int l,int r,int val)
{
    if (l==r) return ((k?T[k].mx:l)>val)?l:l+1;
    int md = (l+r)>>1;
    if (T[k].lc&&T[T[k].lc].mx+T[k].lz>val||!T[k].lc&&md+T[k].lz>val) return find2(T[k].lc,l,md,val-T[k].lz); 
    return find2(T[k].rc,md+1,r,val-T[k].lz);
}
int query(int k,int l,int r,int pos)
{
    if (l==r) return k?T[k].mn:l;
    int md = (l+r)>>1;
    if (pos<=md) return query(T[k].lc,l,md,pos) + T[k].lz;
    return query(T[k].rc,md+1,r,pos) + T[k].lz;
}
void add(int&k,int l,int r,int L,int R,int val)
{
    if (r<L||l>R) return ;
    make(k,l,r);
    if (L<=l&&r<=R)
    {
        T[k].mn += val,T[k].mx += val,T[k].lz += val;
        return ;
    }
    int md = (l+r)>>1;
    add(T[k].lc,l,md,L,R,val),add(T[k].rc,md+1,r,L,R,val);
    pushup(k,l,r);
}
void build(int k,int l,int r)
{
    for (int i=l;i<=r;i++)
    {
        int id1 = find1(rt[k],0,len,a[i]);
        int id2 = find2(rt[k],0,len,a[i]);
        add(rt[k],0,len,0,id1,+1);
        add(rt[k],0,len,id2,len,-1);
    }
    if (l==r) return ;
    int md = (l+r)>>1;
    build(k<<1,l,md),build(k<<1|1,md+1,r);
}
int ask(int k,int l,int r,int L,int R,int c)
{
    if (r<L||l>R) return c;
    if (L<=l&&r<=R) return query(rt[k],0,len,c);
    int md = (l+r)>>1;
    int cur = ask(k<<1,l,md,L,R,c);
    return ask(k<<1|1,md+1,r,L,R,cur);
}
int ans[MAXN],p[MAXN];
bool cmp(int x,int y)
{
    return r[x] < r[y];
}
bool check()
{
    for (int i=1;i<=m;i++)
        if (l[i]!=1) return 0;
    return 1;
}
void work()
{
    int rt = 0;
    for (int i=1;i<=m;i++) p[i] = i;
    sort(p+1,p+m+1,cmp);
    for (int i=1,cr=0;i<=m;i++)
    {
        while (cr<r[p[i]])
        {
            cr++;
            int id1 = find1(rt,0,len,a[cr]);
            int id2 = find2(rt,0,len,a[cr]);
            add(rt,0,len,0,id1,+1);
            add(rt,0,len,id2,len,-1);
        }
        ans[p[i]] = query(rt,0,len,c[p[i]]);
    }
    for (int i=1;i<=m;i++)
        write(ans[i]);
    flush();
}
int main()
{
    freopen("thief.in","r",stdin);
    freopen("thief.out","w",stdout);
    n = read(),m = read();
    for (int i=1;i<=n;i++) a[i] = read(),len = max(len,a[i]);
    for (int i=1;i<=m;i++) l[i] = read(),r[i] = read(),c[i] = read(),len = max(len,c[i]);
    if (check())
    {
        work();
        return 0;
    }
    build(1,1,n);
    for (int i=1;i<=m;i++)
    {
        write(ask(1,1,n,l[i],r[i],c[i]));
    }
    flush();
    return 0;
}
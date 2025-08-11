#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e6 + 12;
const int SIZE = 1<<21;
char buf[SIZE+1],*iS,*iT;
int seed = 20100415;
inline int rnd()
{
	return seed = seed*seed + seed + 3;
}
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
int n,q,p[MAXN],d[MAXN];
struct TreeNode{
	int v,wt;
	int lc,rc;
	int sum;
}T[MAXN];
int sz;
inline void pushup(int k)
{
	T[k].sum = T[T[k].lc].sum + T[T[k].rc].sum + 1;
}
int query(int k,int pos)
{
	if (pos<=T[T[k].lc].sum) return query(T[k].lc,pos);
	if (pos==T[T[k].lc].sum+1) return T[k].v;
	return query(T[k].rc,pos - (T[T[k].lc].sum+1));
}
void split(int k,int lm,int&x,int&y)
{
	if (k==0)
	{
		x = y = 0;
		return ;
	}
	if (lm>=T[T[k].lc].sum+1)
	{
		x = k;
		split(T[k].rc,lm-(T[T[k].lc].sum+1),T[k].rc,y);
		pushup(k);
	}
	else 
	{
		y = k;
		split(T[k].lc,lm,x,T[k].lc);
		pushup(k);
	}
}
int merge(int x,int y)
{
	if (x==0||y==0) return x+y;
	if (T[x].wt>T[y].wt)
	{
		T[x].rc = merge(T[x].rc,y);
		pushup(x);
		return x; 
	}
	else 
	{
		T[y].lc = merge(x,T[y].lc);
		pushup(y);
		return y;
	}
}
inline int lowbit(int x){return x&(-x);}
struct SegmentTree{
	int T[MAXN<<2];
	void add(int k,int l,int r,int pos,int val)
	{
		if (l==r)
		{
			T[k] += val;
			return ;
		}
		int md = (l+r)>>1;
		if (pos<=md) add(k<<1,l,md,pos,val);
		else add(k<<1|1,md+1,r,pos,val);
		T[k] = T[k<<1] + T[k<<1|1];
	}
	int find(int k,int l,int r,int val)
	{
		if (l==r) return (T[k]>=val)?l:l-1;
		int md = (l+r)>>1;
		if (T[k<<1]>=val) return find(k<<1,l,md,val);
		return find(k<<1|1,md+1,r,val-T[k<<1]);
	}
	int query(int k,int l,int r,int pos)
	{
		if (l>pos) return 0;
		if (r<=pos) return T[k];
		int md = (l+r)>>1;
		return query(k<<1,l,md,pos) + query(k<<1|1,md+1,r,pos);
	}
}tr;
struct QueryNode{
	int id,t,x;
	bool operator<(const QueryNode&rhs) const{
		return t<rhs.t;
	}
}Q[MAXN];
int rt[MAXN],stk[MAXN],top,ct,ans[MAXN];
int temp[MAXN],len;
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	n = read(),q = read();
	for (int i=1;i<=n;i++) p[i] = read();
	stk[0] = n+1;
	for (int i=n;i>=1;i--)
	{
		while (top&&p[stk[top]]<=p[i]) top--;
		d[p[i]] = stk[top] - i;
		stk[++top] = i;
	}
	while (top)
	{
		int x = stk[top--];
		for (int i=x;i<stk[top];i++)
		{
			sz++;
			T[sz].wt = rnd();
			T[sz].v = p[i];
			T[sz].sum = 1;
			rt[p[x]] = merge(rt[p[x]],sz);
		}
		tr.add(1,1,n,p[x],T[rt[p[x]]].sum);
	}
	for (int i=1;i<=q;i++)
		Q[i].id = i,Q[i].t = read(),Q[i].x = read();
	sort(Q+1,Q+q+1);
	for (int i=1;i<=q;i++)
	{
		while (ct<Q[i].t)
		{
			ct++;
			int res = tr.find(1,1,n,n/2);
			if (tr.query(1,1,n,res)==n/2)
			{
				ct = 1e9;
				break;
			}
			tr.add(1,1,n,res,-T[rt[res]].sum);
			int fst = n/2 - tr.query(1,1,n,res-1);
			split(rt[res],fst,temp[1],temp[2]);
			len = 2;
			while (1)
			{
				int x = query(temp[len],1);
				if (d[x]>=T[temp[len]].sum) break;
				split(temp[len],d[x],temp[len],temp[len+1]);
				len++;
			}
			for (int i=1;i<=len;i++)
			{
				int x = query(temp[i],1);
				rt[x] = temp[i];
				tr.add(1,1,n,x,T[rt[x]].sum);
			}
		}
		int res = tr.find(1,1,n,Q[i].x);
		ans[Q[i].id] = query(rt[res],Q[i].x - tr.query(1,1,n,res-1));
	}
	for (int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}

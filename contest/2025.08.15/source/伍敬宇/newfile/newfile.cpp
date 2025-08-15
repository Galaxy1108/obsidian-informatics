#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 1<<21;
const int MAXN = 1e5 + 12;
const int mod = 1e9 + 9;
char buf[SIZE+1],*iS,*iT;
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
struct SegTreeNode{
	long long sum,hsum,len;
	long long lz1,lz2,sk;
};
struct SegmentTree{
	SegTreeNode T[MAXN<<2];
	void build(int k,int l,int r)
	{
		T[k].len = r - l + 1;
		if (l==r) return ;
		int md = (l+r)>>1;
		build(k<<1,l,md),build(k<<1|1,md+1,r);
	}
	void pushup(int k)
	{
		T[k].sum = (T[k<<1].sum + T[k<<1|1].sum)%mod;
		T[k].hsum = (T[k<<1].hsum + T[k<<1|1].hsum)%mod;
	}
	void opt(int k,long long lz1,long long lz2,long long sk)
	{
		T[k].hsum = (T[k].hsum + lz2*T[k].len + T[k].sum*sk)%mod;
		T[k].sum = (T[k].sum + lz1*T[k].len)%mod;
		T[k].lz2 = (T[k].lz2 + T[k].lz1*sk + lz2)%mod;
		T[k].lz1 = (T[k].lz1+lz1)%mod;
		T[k].sk = (T[k].sk+sk)%mod;
	}
	void pushdown(int k)
	{
		opt(k<<1,T[k].lz1,T[k].lz2,T[k].sk);
		opt(k<<1|1,T[k].lz1,T[k].lz2,T[k].sk);
		T[k].lz1 = T[k].lz2 = T[k].sk = 0;
	}
	void add(int k,int l,int r,int L,int R,int val)
	{
		if (L<=l&&r<=R) return opt(k,val,0,0),void();
		if (r<L||l>R) return ;
		int md = (l+r)>>1;
		pushdown(k);
		add(k<<1,l,md,L,R,val),add(k<<1|1,md+1,r,L,R,val);
		pushup(k);
	}
	long long query(int k,int l,int r,int L,int R)
	{
		if (L<=l&&r<=R) return T[k].hsum;
		if (r<L||l>R) return 0;
		int md = (l+r)>>1;
		pushdown(k);
		return (query(k<<1,l,md,L,R) + query(k<<1|1,md+1,r,L,R))%mod;
	}
}sgt; 
int n,m,q;
long long ans[MAXN];
struct Operation{
	int l,r,x;
}O[MAXN];
struct QueryNode{
	int l,r,id;
};
vector<QueryNode> Q[MAXN];
int main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	n = read(),m = read(),q = read();
	for (int i=1;i<=m;i++) O[i].l = read(),O[i].r = read(),O[i].x = read();
	for (int i=1;i<=q;i++)
	{
		int u = read(),d = read(),l = read(),r = read();
		if (u>0) Q[u-1].push_back({l,r,-i});
		Q[d].push_back({l,r,i});
	}
	sgt.build(1,1,n);
	for (int i=1;i<=m;i++)
	{
		sgt.add(1,1,n,O[i].l,O[i].r,O[i].x);
		sgt.opt(1,0,0,1);
		for (int j=0;j<Q[i].size();j++)
		{
			int l = Q[i][j].l,r = Q[i][j].r,id = Q[i][j].id;
			if (id<0) ans[-id] = (ans[-id] - sgt.query(1,1,n,l,r) + mod)%mod;
			else ans[id] = (ans[id] + sgt.query(1,1,n,l,r))%mod;
		}
	}
	for (int i=1;i<=q;i++) printf("%lld\n",ans[i]);
	return 0;
}

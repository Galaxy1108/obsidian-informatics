#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
long long Qread()
{
	long long x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}

struct Func{long long v,c;inline long long f(int x){return v-x*c;}};
#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid (l+r>>1)
namespace LC_Tree{
	Func s[800010];
	void ins_func(int pos,Func u,int l,int r)
	{
		if(u.f(mid)<s[pos].f(mid)) swap(u,s[pos]);
		if(u.f(l)<s[pos].f(l)) ins_func(ls,u,l,mid);
		if(u.f(r)<s[pos].f(r)) ins_func(rs,u,mid+1,r);
	}
	long long qry_min(int x,int pos,int l,int r)
	{
		if(l==r) return s[pos].f(x);
		if(x<=mid) return min(qry_min(x,ls,l,mid),s[pos].f(x));
		else return min(qry_min(x,rs,mid+1,r),s[pos].f(x));
	}
	void reset(int pos,int l,int r)
	{
		if(s[pos].v==inf) return;
		s[pos].v=inf;
		if(l<r) reset(ls,l,mid),reset(rs,mid+1,r);
	}
}
#undef ls
#undef rs
#undef mid

int n,q,C;
long long a[200010];
int op[200010];
long long l[200010],r[200010];
vector<int> nd[200010];
void solve(int l,int r,vector<int> &P)
{
	// printf("solve(%d %d[",l,r);
	// for(int g:P) printf("%d ",g);
	// printf("])\n");

	if(P.empty()) return;
	if(l==r) return nd[l]=P,void();
	int mid=(l+r>>1);vector<int> Pl,Pr;
	for(int i=l;i<=mid;i++) if(op[i]==1)
		LC_Tree::ins_func(1,Func{::l[i],::r[i]},1,n);
	for(int g:P) if(LC_Tree::qry_min(g,1,1,n)<a[g]) Pl.push_back(g);
		else Pr.push_back(g);
	LC_Tree::reset(1,1,n);
	solve(l,mid,Pl),solve(mid+1,r,Pr);
}

//calc S
struct BIT{
	long long num[200010];
	void add(int x,long long k){for(;x<=n;x+=(x&-x)) num[x]+=k;}
	long long sum(int x){long long ret=0;for(;x;x-=(x&-x)) ret+=num[x];return ret;}
	long long sum(int l,int r){return sum(r)-sum(l-1);}
}S1,S2;

//calc T
#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid (l+r>>1)
namespace Sege{
	struct Node{
		long long sum,sum_;int lid;
		long long rv,c,cnt;
	}s[800010];
	void update(int pos)
	{
		s[pos].sum=s[ls].sum+s[rs].sum;
	}
	void giv_laz(int pos,long long rv,long long c)
	{
		if(rv>=0) s[pos].rv=rv,s[pos].c=c,s[pos].sum=rv*s[pos].cnt+c*s[pos].sum_;
		else s[pos].c+=c,s[pos].sum+=c*s[pos].sum_;
	}
	void pushdown(int pos)
	{
		if(s[pos].rv!=-1||s[pos].c)
			giv_laz(ls,s[pos].rv,s[pos].c),giv_laz(rs,s[pos].rv,s[pos].c)
			,s[pos].rv=-1,s[pos].c=0;
	}
	long long get_num(int x,int pos,int l,int r)
	{
		if(l==r) return s[pos].sum;
		if(x<=mid) return pushdown(pos),get_num(x,ls,l,mid);
		else return pushdown(pos),get_num(x,rs,mid+1,r);
	}
	long long range_sum(int L,int R,int pos,int l,int r)
	{
		if(L<=l&&r<=R) return s[pos].sum;
		if(R<=mid) return pushdown(pos),range_sum(L,R,ls,l,mid);
		if(mid<L) return pushdown(pos),range_sum(L,R,rs,mid+1,r);
		return pushdown(pos),range_sum(L,R,ls,l,mid)+range_sum(L,R,rs,mid+1,r);
	}
	void range_tp(int L,int R,long long rv,int pos,int l,int r)
	{
		if(L<=l&&r<=R) return giv_laz(pos,rv,0);
		if(R<=mid) return pushdown(pos),range_tp(L,R,rv,ls,l,mid),update(pos);
		if(mid<L) return pushdown(pos),range_tp(L,R,rv,rs,mid+1,r),update(pos);
		return pushdown(pos),range_tp(L,R,rv,ls,l,mid),range_tp(L,R,rv,rs,mid+1,r),update(pos);
	}
	int get_f_sm(long long U,int pos,int l,int r)
	{
		if(l==r) return l;
		pushdown(pos);
		if(s[ls].lid&&U<get_num(s[ls].lid,ls,l,mid)) return get_f_sm(U,ls,l,mid);
		else return get_f_sm(U,rs,mid+1,r);
	}
	void change_num(long long num,int id,int pos,int l,int r)
	{
		s[pos].sum+=num,s[pos].sum_+=id,s[pos].lid=max(s[pos].lid,id);
		s[pos].cnt++;
		if(l==r) return;
		if(id<=mid) return pushdown(pos),change_num(num,id,ls,l,mid);
		else return pushdown(pos),change_num(num,id,rs,mid+1,r);
	}
}
#undef ls
#undef rs
#undef mid
int main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	
	n=Qread(),q=Qread();
	for(int i=1;i<=n;i++) a[i]=Qread();
	for(int i=1;i<=q;i++)
	{
		op[i]=Qread();
		if(op[i]==1) l[i]=Qread(),r[i]=C;
		else if(op[i]==3) l[i]=Qread(),r[i]=Qread();
		else C++;
	}

	//solve time every node change from S to T
	vector<int> P;
	LC_Tree::reset(1,1,n);
	for(int i=1;i<=q;i++) if(op[i]==1)
		LC_Tree::ins_func(1,Func{l[i],r[i]},1,n);
	for(int i=1;i<=n;i++) if(LC_Tree::qry_min(i,1,1,n)<a[i]) P.push_back(i);
	LC_Tree::reset(1,1,n);
	solve(1,q,P);

	//solve the answer
	for(int i=1;i<=n;i++) S1.add(i,a[i]),S2.add(i,i);

	C=0;long long ans=0;
	for(int i=1,tk;i<=q;i++)
	{
		if(op[i]==1)
		{
			if(Sege::s[1].lid&&l[i]<Sege::get_num(Sege::s[1].lid,1,1,n))
			{
				tk=Sege::get_f_sm(l[i],1,1,n);
				Sege::range_tp(tk,n,l[i],1,1,n);
			}

			for(int g:nd[i])
			{
				S1.add(g,-a[g]),S2.add(g,-g);
				Sege::change_num(l[i],g,1,1,n);
			}
		}
		else if(op[i]==2)
		{
			C++;
			Sege::giv_laz(1,-1,1);
		}
		else
		{
			ans=S1.sum(l[i],r[i])+S2.sum(l[i],r[i])*C+Sege::range_sum(l[i],r[i],1,1,n);
			printf("%lld\n",ans);
		}
	}
	return 0;
}
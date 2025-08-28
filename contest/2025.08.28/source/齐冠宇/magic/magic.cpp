#include <bits/stdc++.h>
//#define int long long
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
constexpr int N=2.5e5+5,mod=998244353;
bool m1;
int n,q;
int a[N],b[N],c[N];
inline int add(int x,int y)
{
	x+=y;return x>mod?x-mod:x;
}
inline int mul(int x,int y)
{
	int res=x*y-(int)((double)x*y/mod+0.1)*mod;
	return res<0?res+mod:res;
}
struct mat{
	int a[4][4];
	mat(){memset(a,0,sizeof a);}
	inline void set(){memset(a,0,sizeof a);a[0][0]=a[1][1]=a[2][2]=a[3][3]=1;}
	inline bool chk()
	{
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
			{
				if(i!=j && a[i][j])
					return 1;
				if(i==j && a[i][j]!=1)
					return 1;
			}
		return 0;
	}
};
inline mat operator+(const mat& x,const mat& y)
{
	mat z;
	z.a[0][0]=add(x.a[0][0],y.a[0][0]);
	z.a[0][1]=add(x.a[0][1],y.a[0][1]);
	z.a[0][2]=add(x.a[0][2],y.a[0][2]);
	z.a[0][3]=add(x.a[0][3],y.a[0][3]);
	z.a[1][0]=add(x.a[1][0],y.a[1][0]);
	z.a[1][1]=add(x.a[1][1],y.a[1][1]);
	z.a[1][2]=add(x.a[1][2],y.a[1][2]);
	z.a[1][3]=add(x.a[1][3],y.a[1][3]);
	z.a[2][0]=add(x.a[2][0],y.a[2][0]);
	z.a[2][1]=add(x.a[2][1],y.a[2][1]);
	z.a[2][2]=add(x.a[2][2],y.a[2][2]);
	z.a[2][3]=add(x.a[2][3],y.a[2][3]);
	z.a[3][0]=add(x.a[3][0],y.a[3][0]);
	z.a[3][1]=add(x.a[3][1],y.a[3][1]);
	z.a[3][2]=add(x.a[3][2],y.a[3][2]);
	z.a[3][3]=add(x.a[3][3],y.a[3][3]);
//	for(int i=0;i<4;i++)
//		for(int j=0;j<4;j++)
//			z.a[i][j]=add(x.a[i][j],y.a[i][j]);
	return z;
}
inline mat operator*(const mat& x,const mat& y)
{
	mat z;
	z.a[0][0]=add(z.a[0][0],mul(x.a[0][0],y.a[0][0]));
	z.a[0][0]=add(z.a[0][0],mul(x.a[0][1],y.a[1][0]));
	z.a[0][0]=add(z.a[0][0],mul(x.a[0][2],y.a[2][0]));
	z.a[0][0]=add(z.a[0][0],mul(x.a[0][3],y.a[3][0]));
	z.a[0][1]=add(z.a[0][1],mul(x.a[0][0],y.a[0][1]));
	z.a[0][1]=add(z.a[0][1],mul(x.a[0][1],y.a[1][1]));
	z.a[0][1]=add(z.a[0][1],mul(x.a[0][2],y.a[2][1]));
	z.a[0][1]=add(z.a[0][1],mul(x.a[0][3],y.a[3][1]));
	z.a[0][2]=add(z.a[0][2],mul(x.a[0][0],y.a[0][2]));
	z.a[0][2]=add(z.a[0][2],mul(x.a[0][1],y.a[1][2]));
	z.a[0][2]=add(z.a[0][2],mul(x.a[0][2],y.a[2][2]));
	z.a[0][2]=add(z.a[0][2],mul(x.a[0][3],y.a[3][2]));
	z.a[0][3]=add(z.a[0][3],mul(x.a[0][0],y.a[0][3]));
	z.a[0][3]=add(z.a[0][3],mul(x.a[0][1],y.a[1][3]));
	z.a[0][3]=add(z.a[0][3],mul(x.a[0][2],y.a[2][3]));
	z.a[0][3]=add(z.a[0][3],mul(x.a[0][3],y.a[3][3]));
	z.a[1][0]=add(z.a[1][0],mul(x.a[1][0],y.a[0][0]));
	z.a[1][0]=add(z.a[1][0],mul(x.a[1][1],y.a[1][0]));
	z.a[1][0]=add(z.a[1][0],mul(x.a[1][2],y.a[2][0]));
	z.a[1][0]=add(z.a[1][0],mul(x.a[1][3],y.a[3][0]));
	z.a[1][1]=add(z.a[1][1],mul(x.a[1][0],y.a[0][1]));
	z.a[1][1]=add(z.a[1][1],mul(x.a[1][1],y.a[1][1]));
	z.a[1][1]=add(z.a[1][1],mul(x.a[1][2],y.a[2][1]));
	z.a[1][1]=add(z.a[1][1],mul(x.a[1][3],y.a[3][1]));
	z.a[1][2]=add(z.a[1][2],mul(x.a[1][0],y.a[0][2]));
	z.a[1][2]=add(z.a[1][2],mul(x.a[1][1],y.a[1][2]));
	z.a[1][2]=add(z.a[1][2],mul(x.a[1][2],y.a[2][2]));
	z.a[1][2]=add(z.a[1][2],mul(x.a[1][3],y.a[3][2]));
	z.a[1][3]=add(z.a[1][3],mul(x.a[1][0],y.a[0][3]));
	z.a[1][3]=add(z.a[1][3],mul(x.a[1][1],y.a[1][3]));
	z.a[1][3]=add(z.a[1][3],mul(x.a[1][2],y.a[2][3]));
	z.a[1][3]=add(z.a[1][3],mul(x.a[1][3],y.a[3][3]));
	z.a[2][0]=add(z.a[2][0],mul(x.a[2][0],y.a[0][0]));
	z.a[2][0]=add(z.a[2][0],mul(x.a[2][1],y.a[1][0]));
	z.a[2][0]=add(z.a[2][0],mul(x.a[2][2],y.a[2][0]));
	z.a[2][0]=add(z.a[2][0],mul(x.a[2][3],y.a[3][0]));
	z.a[2][1]=add(z.a[2][1],mul(x.a[2][0],y.a[0][1]));
	z.a[2][1]=add(z.a[2][1],mul(x.a[2][1],y.a[1][1]));
	z.a[2][1]=add(z.a[2][1],mul(x.a[2][2],y.a[2][1]));
	z.a[2][1]=add(z.a[2][1],mul(x.a[2][3],y.a[3][1]));
	z.a[2][2]=add(z.a[2][2],mul(x.a[2][0],y.a[0][2]));
	z.a[2][2]=add(z.a[2][2],mul(x.a[2][1],y.a[1][2]));
	z.a[2][2]=add(z.a[2][2],mul(x.a[2][2],y.a[2][2]));
	z.a[2][2]=add(z.a[2][2],mul(x.a[2][3],y.a[3][2]));
	z.a[2][3]=add(z.a[2][3],mul(x.a[2][0],y.a[0][3]));
	z.a[2][3]=add(z.a[2][3],mul(x.a[2][1],y.a[1][3]));
	z.a[2][3]=add(z.a[2][3],mul(x.a[2][2],y.a[2][3]));
	z.a[2][3]=add(z.a[2][3],mul(x.a[2][3],y.a[3][3]));
	z.a[3][0]=add(z.a[3][0],mul(x.a[3][0],y.a[0][0]));
	z.a[3][0]=add(z.a[3][0],mul(x.a[3][1],y.a[1][0]));
	z.a[3][0]=add(z.a[3][0],mul(x.a[3][2],y.a[2][0]));
	z.a[3][0]=add(z.a[3][0],mul(x.a[3][3],y.a[3][0]));
	z.a[3][1]=add(z.a[3][1],mul(x.a[3][0],y.a[0][1]));
	z.a[3][1]=add(z.a[3][1],mul(x.a[3][1],y.a[1][1]));
	z.a[3][1]=add(z.a[3][1],mul(x.a[3][2],y.a[2][1]));
	z.a[3][1]=add(z.a[3][1],mul(x.a[3][3],y.a[3][1]));
	z.a[3][2]=add(z.a[3][2],mul(x.a[3][0],y.a[0][2]));
	z.a[3][2]=add(z.a[3][2],mul(x.a[3][1],y.a[1][2]));
	z.a[3][2]=add(z.a[3][2],mul(x.a[3][2],y.a[2][2]));
	z.a[3][2]=add(z.a[3][2],mul(x.a[3][3],y.a[3][2]));
	z.a[3][3]=add(z.a[3][3],mul(x.a[3][0],y.a[0][3]));
	z.a[3][3]=add(z.a[3][3],mul(x.a[3][1],y.a[1][3]));
	z.a[3][3]=add(z.a[3][3],mul(x.a[3][2],y.a[2][3]));
	z.a[3][3]=add(z.a[3][3],mul(x.a[3][3],y.a[3][3]));
//	for(int i=0;i<4;i++)
//		for(int j=0;j<4;j++)
//			for(int k=0;k<4;k++)
//				z.a[i][j]=add(z.a[i][j],mul(x.a[i][k],y.a[k][j]));
	return z;
}
inline mat operator^(const mat& x,const mat& y)
{
	mat z;
	z.a[0][0]=add(z.a[0][0],mul(x.a[0][0],y.a[0][0]));
	z.a[0][0]=add(z.a[0][0],mul(x.a[0][1],y.a[1][0]));
	z.a[0][0]=add(z.a[0][0],mul(x.a[0][2],y.a[2][0]));
	z.a[0][0]=add(z.a[0][0],mul(x.a[0][3],y.a[3][0]));
	z.a[1][0]=add(z.a[1][0],mul(x.a[1][0],y.a[0][0]));
	z.a[1][0]=add(z.a[1][0],mul(x.a[1][1],y.a[1][0]));
	z.a[1][0]=add(z.a[1][0],mul(x.a[1][2],y.a[2][0]));
	z.a[1][0]=add(z.a[1][0],mul(x.a[1][3],y.a[3][0]));
	z.a[2][0]=add(z.a[2][0],mul(x.a[2][0],y.a[0][0]));
	z.a[2][0]=add(z.a[2][0],mul(x.a[2][1],y.a[1][0]));
	z.a[2][0]=add(z.a[2][0],mul(x.a[2][2],y.a[2][0]));
	z.a[2][0]=add(z.a[2][0],mul(x.a[2][3],y.a[3][0]));
	z.a[3][0]=add(z.a[3][0],mul(x.a[3][0],y.a[0][0]));
	z.a[3][0]=add(z.a[3][0],mul(x.a[3][1],y.a[1][0]));
	z.a[3][0]=add(z.a[3][0],mul(x.a[3][2],y.a[2][0]));
	z.a[3][0]=add(z.a[3][0],mul(x.a[3][3],y.a[3][0]));
//	for(int i=0;i<4;i++)
//		for(int j=0;j<4;j++)
//			for(int k=0;k<4;k++)
//				z.a[i][j]=add(z.a[i][j],mul(x.a[i][k],y.a[k][j]));
	return z;
}
struct node{
	mat sm,tg;
}tr[N<<2];
bool m2;
#define ls k<<1
#define rs k<<1|1
inline void pu(int k)
{
	tr[k].sm=tr[ls].sm+tr[rs].sm;
}
inline void pd(int k)
{
	if(tr[k].tg.chk())
	{	
		tr[ls].sm=tr[k].tg^tr[ls].sm,tr[ls].tg=tr[k].tg*tr[ls].tg;
		tr[rs].sm=tr[k].tg^tr[rs].sm,tr[rs].tg=tr[k].tg*tr[rs].tg;
		tr[k].tg.set();
	}
}
void build(int k,int l,int r)
{
	tr[k].tg.set();
	if(l==r)
	{
		tr[k].sm.a[0][0]=a[l];
		tr[k].sm.a[1][0]=b[l];
		tr[k].sm.a[2][0]=c[l];
		tr[k].sm.a[3][0]=1;
		return;
	}
	int mid=l+r>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pu(k);
}
void upd(int k,int l,int r,int L,int R,int typ,int vl)
{
	if(r<L || R<l)
		return;
	if(L<=l && r<=R)
	{
		mat val;
		val.set();
		if(typ==1)
			val.a[0][1]=1;
		else if(typ==2)
			val.a[1][2]=1;
		else if(typ==3)
			val.a[2][0]=1;
		else if(typ==4)
			val.a[0][3]=vl;
		else if(typ==5)
			val.a[1][1]=vl;
		else if(typ==6)
			val.a[2][2]=0,val.a[2][3]=vl;
		tr[k].sm=val^tr[k].sm,tr[k].tg=val*tr[k].tg;
		return;
	}
	pd(k);
	int mid=l+r>>1;
	upd(ls,l,mid,L,R,typ,vl);
	upd(rs,mid+1,r,L,R,typ,vl);
	pu(k);
}
mat query(int k,int l,int r,int L,int R)
{
	if(r<L || R<l)
		return mat();
	if(L<=l && r<=R)
		return tr[k].sm;
	pd(k);
	int mid=l+r>>1;
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
#undef ls
#undef rs
signed main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
//	cerr<<fabs(&m1-&m2)/1024.0/1024.0<<"MB";
	rd(n);
	for(int i=1;i<=n;i++)
		rd(a[i]),rd(b[i]),rd(c[i]);
	build(1,1,n);
	rd(q);
	while(q--)
	{
		int opt,l,r,v=0;
		rd(opt,l,r);
		if(4<=opt && opt<=6)rd(v);
		if(opt!=7)upd(1,1,n,l,r,opt,v);
//		mat ret=query(1,1,n,l,r);
//		cout<<"!"<<ret.a[0][0]<<' '<<ret.a[1][0]<<' '<<ret.a[2][0]<<'\n'; 
		else
		{
			mat ret=query(1,1,n,l,r);
			wr(ret.a[0][0],' '),wr(ret.a[1][0],' '),wr(ret.a[2][0],'\n');
		}
	}
	return 0;
}

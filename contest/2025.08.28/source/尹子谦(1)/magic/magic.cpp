#include<bits/stdc++.h>
#define ls p*2
#define rs p*2+1
#define int long long
using namespace std;
const int N=270010,M=998244353;
struct TREE
{
	int l,r;
	int s,h,t;
	int a,b,c;
	int sp,ht,tc;
}tr[N<<2];
void read(int &x) 
{
  bool neg = false;
  x = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') 
  {
    if (ch == '-') neg = true;
    ch = getchar();
  }
  if (neg) 
  {
    while (ch >= '0' && ch <= '9') 
	{
      x = x * 10 + ('0' - ch);
      ch = getchar();
    }
  }
   else 
  {
    while (ch >= '0' && ch <= '9')
	 {
      x = x * 10 + (ch - '0');
      ch = getchar();
    }
  }
}
struct ANS
{
	int s,h,t;
};
ANS pls(ANS a,ANS b)
{
	ANS c;
	c.h=(a.h+b.h)%M;
	c.s=(a.s+b.s)%M;
	c.t=(a.t+b.t)%M;
	return c;
}
int h[N],s[N],t[N],n,m;
void push_down(int p)
{
	if(tr[p].a||tr[p].b||tr[p].c||tr[p].sp||tr[p].ht!=1||tr[p].tc!=M+1)
	{
		int ll=tr[ls].l,lr=tr[ls].r,rl=tr[rs].l,rr=tr[rs].r;
		int al=tr[ls].s,ar=tr[rs].s;
		int bl=tr[ls].h,br=tr[rs].h;
		int cl=tr[ls].t,cr=tr[rs].t;
		tr[ls].s=(tr[ls].s+bl*tr[p].a%M+(lr-ll+1)*tr[p].sp%M)%M;
		tr[rs].s=(tr[rs].s+br*tr[p].a%M+(rr-rl+1)*tr[p].sp%M)%M;
		tr[ls].a=(tr[ls].a+tr[p].a)%M;
		tr[rs].a=(tr[rs].a+tr[p].a)%M;
		tr[ls].sp=(tr[ls].sp+tr[p].sp)%M;
		tr[rs].sp=(tr[rs].sp+tr[p].sp)%M;
		tr[ls].h=(tr[ls].h*tr[p].ht+tr[p].b*cl)%M;
		tr[rs].h=(tr[rs].h*tr[p].ht+tr[p].b*cr)%M;
		tr[ls].b=(tr[ls].b+tr[p].b)%M;
		tr[rs].b=(tr[rs].b+tr[p].b)%M;
		tr[ls].ht=tr[ls].ht*tr[p].ht%M;
		tr[rs].ht=tr[rs].ht*tr[p].ht%M;
		if(tr[p].tc!=-1)tr[ls].t=((lr-ll+1)*tr[p].tc%M),tr[rs].t=((rr-rl+1)*tr[p].tc%M);
		else tr[ls].t=(tr[ls].t+tr[p].c*al%M)%M,tr[rs].t=(tr[rs].t+tr[p].c*ar%M)%M;
		tr[ls].tc=tr[p].tc,tr[rs].tc=tr[p].tc;
		tr[ls].c=(tr[ls].c+tr[p].c),tr[rs].c=(tr[rs].c+tr[p].c);
		tr[p].a=tr[p].b=tr[p].c=tr[p].sp=0,tr[p].tc=-1,tr[p].ht=1;
	}
}
void push_downww(int p)
{
	int ll=tr[ls].l,lr=tr[ls].r,rl=tr[rs].l,rr=tr[rs].r;
	if(tr[p].ht!=1)
	{
		tr[ls].h=(tr[ls].h*tr[p].ht)%M;
		tr[rs].h=(tr[rs].h*tr[p].ht)%M;
		tr[ls].ht=tr[ls].ht*tr[p].ht%M;
		tr[rs].ht=tr[rs].ht*tr[p].ht%M;
	}
	if(tr[p].tc!=-1)
	{
		tr[ls].t=(lr-ll+1)*tr[p].tc%M;
		tr[rs].t=(rr-rl+1)*tr[p].tc%M;
		tr[ls].tc=tr[p].tc%M;
		tr[rs].tc=tr[p].tc%M;
	}
	if(tr[p].sp!=0)
	{
		tr[ls].sp=(tr[ls].sp+tr[p].sp)%M;
		tr[rs].sp=(tr[rs].sp+tr[p].sp)%M;
		tr[ls].s=(tr[ls].s+(lr-ll+1)*tr[p].sp%M)%M;
		tr[rs].s=(tr[rs].s+(rr-rl+1)*tr[p].sp%M)%M;
	}
	tr[p].sp=0,tr[p].ht=1,tr[p].tc=-1;
}
void push_up(int p)
{
	tr[p].h=(tr[ls].h+tr[rs].h)%M;
	tr[p].s=(tr[ls].s+tr[rs].s)%M;
	tr[p].t=(tr[ls].t+tr[rs].t)%M;
}
void build(int p,int l,int r)
{
	tr[p].l=l,tr[p].r=r;
	tr[p].ht=1,tr[p].tc=-1;
	if(l==r)
	{
		tr[p].h=h[l],tr[p].s=s[l],tr[p].t=t[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	push_up(p);
}
void add(int p,int l,int r,int op)
{
	push_downww(p);
	int L=tr[p].l,R=tr[p].r;
	if(L>=l&&R<=r)
	{
		if(op==1) tr[p].s=(tr[p].s+tr[p].h)%M,tr[p].a++;
		if(op==2) tr[p].h=(tr[p].h+tr[p].t)%M,tr[p].b++;
		if(op==3) tr[p].t=(tr[p].t+tr[p].s)%M,tr[p].c++;
		return ;
	}
	int mid=(L+R)>>1;
	if(mid>=l) add(ls,l,r,op);
	if(mid<r) add(rs,l,r,op);
	push_up(p);
}
void change(int p,int l,int r,int op,int v)
{
	push_downww(p);
	int L=tr[p].l,R=tr[p].r;
	if(L>=l&&R<=r)
	{
		if(op==1) tr[p].s=(tr[p].s+(R-L+1)*v)%M,tr[p].sp+=v;
		if(op==2) tr[p].h=v*tr[p].h%M,tr[p].ht=tr[p].ht*v%M;
		if(op==3) tr[p].t=v*(R-L+1)%M,tr[p].tc=v;
		return ;
	}
	int mid=(L+R)>>1;
	if(mid>=l) change(ls,l,r,op,v);
	if(mid<r) change(rs,l,r,op,v);
	push_up(p);
}
ANS ask(int p,int l,int r)
{
	push_downww(p);
	int L=tr[p].l,R=tr[p].r;
	if(L>=l&&R<=r) return {tr[p].s,tr[p].h,tr[p].t};
	int mid=(L+R)>>1;
	ANS ans={0,0,0};
	if(mid>=l) ans=pls(ans,ask(ls,l,r));
	if(mid<r)  ans=pls(ans,ask(rs,l,r));
	return ans;
}
signed  main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(s[i]),read(h[i]),read(t[i]);
	read(m);
	if(n*m<=1e7)
	{
		while(m--)
		{
			int op,l,r,v;
			read(op),read(l),read(r);
			if(op==1)
			{
				for(int i=l;i<=r;i++)  s[i]=(s[i]+h[i])%M;
			}
			if(op==2)
			{
				for(int i=l;i<=r;i++)  h[i]=(t[i]+h[i])%M;
			}
			if(op==3)
			{
				for(int i=l;i<=r;i++)  t[i]=(t[i]+s[i])%M;
			}
			if(op==4)
			{
				read(v);
				for(int i=l;i<=r;i++)  s[i]=s[i]+v%M;
			}
			if(op==5)
			{
				read(v);
				for(int i=l;i<=r;i++)  h[i]=h[i]*v%M;
			}
			if(op==6)
			{
				read(v);
				for(int i=l;i<=r;i++)  t[i]=v%M;
			}
			if(op==7)
			{
				int a=0,b=0,c=0;
				for(int i=l;i<=r;i++) a=(a+s[i])%M,b=(b+h[i])%M,c=(c+t[i])%M;
				cout<<a<<' '<<b<<' '<<c<<endl;
			}
		}
		return 0;
	}
	build(1,1,n);
	while(m--)
	{
		int op,l,r,v;
		read(op),read(l),read(r);
		if(op==1)
		{
			add(1,l,r,1);
		}
		if(op==2)
		{
			add(1,l,r,2);
		}
		if(op==3)
		{
			add(1,l,r,3);
		}
		if(op==4)
		{
			read(v);
			change(1,l,r,1,v);
		}
		if(op==5)
		{
			read(v);
			change(1,l,r,2,v);
		}
		if(op==6)
		{
			read(v);
			change(1,l,r,3,v);
		}
		if(op==7)
		{
			ANS ans=ask(1,l,r);
			cout<<ans.s%M<<' '<<ans.h%M<<' '<<ans.t%M<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int mod=998244353;
const int mx=250010;
int n,m;
long long a[mx],b[mx],c[mx];
long long getm(long long x) { return x%mod; }
/*
struct segT
{
	int l,r;
	long long a,b,c;
	long long f1,f2,f3,f4,f5,f6;
}t[mx*4];

void pushup(int p)
{
	t[p].a=getm(t[p*2].a+t[p*2+1].a);
	t[p].b=getm(t[p*2].b+t[p*2+1].b);
	t[p].c=getm(t[p*2].c+t[p*2+1].c);
}
void build(int p,int l,int r)
{
	t[p].l=l,t[p].r=r;
	if(l==r)
	{
		t[p].a=a[l],t[p].b=b[l],t[p].c=c[l];
		return;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	pushup(p);
}
void pushdown(int p)
{
	if(t[p].f1)
	{
		t[p*2].a=getm(t[p*2].a+t[p*2].b);
		t[p*2+1].a=getm(t[p*2+1].a+t[p*2+1].b);
		t[p*2].f1=1;
		t[p*2+1].f1=1;
		t[p].f1=0;
	}
	if(t[p].f2)
	{
		t[p*2].b=getm(t[p*2].b+t[p*2].c);
		t[p*2+1].b=getm(t[p*2+1].b+t[p*2+1].c);
		t[p*2].f2=1;
		t[p*2+1].f2=1;
		t[p].f2=0;
	}
	if(t[p].f3)
	{
		t[p*2].c=getm(t[p*2].c+t[p*2].a);
		t[p*2+1].c=getm(t[p*2+1].c+t[p*2+1].a);
		t[p*2].f3=1;
		t[p*2+1].f3=1;
		t[p].f3=0;
	}
	if(t[p].f4)
	{
		t[p*2].a=getm(t[p*2].a+getm(t[p].f4*(t[p*2].r-t[p*2].l+1)));
		t[p*2+1].a=getm(t[p*2+1].a+getm(t[p].f4*(t[p*2+1].r-t[p*2+1].l+1)));
		t[p*2].f4=getm(t[p*2].f4+t[p].f4);
		t[p*2+1].f4=getm(t[p*2+1].f4+t[p].f4);
		t[p].f4=0;
	}
	if(t[p].f5)
	{
		t[p*2].b=getm(t[p*2].b*t[p].f5);
		t[p*2+1].b=getm(t[p*2+1].b*t[p].f5);
		t[p*2].f5=getm(t[p*2].f5*t[p].f5);
		t[p*2+1].f5=getm(t[p*2+1].f5*t[p].f5);
		t[p].f5=0;
	}
	if(t[p].f6)
	{
		t[p*2].c=getm(t[p].f6*(t[p*2].r-t[p*2].l+1));
		t[p*2+1].c=getm(t[p].f6*(t[p*2+1].r-t[p*2+1].l+1));
		t[p*2].f6=t[p].f6;
		t[p*2+1].f6=t[p].f6;
		t[p].f6=0;
	}
}
void update(int p,int l,int r,int o,int v)
{
	if(t[p].l>=l&&t[p].r<=r)
	{
		if(o==1)
		{
			t[p].a=getm(t[p].a+t[p].b);
			t[p].f1=1;
			return;
		}
		if(o==2)
		{
			t[p].b=getm(t[p].b+t[p].c);
			t[p].f2=1;
			return;
		}
		if(o==3)
		{
			t[p].c=getm(t[p].c+t[p].a);
			t[p].f3=1;
			return;
		}
		if(o==4)
		{
			t[p].a=getm(t[p].a+getm((t[p].r-t[p].l+1)*v));
			t[p].f4=v;
			return;
		}
		if(o==5)
		{
			t[p].b=getm(t[p].b*v);
			t[p].f5=v;
			return;
		}
		if(o==6)
		{
			t[p].c=getm((t[p].r-t[p].l+1)*v);
			t[p].f6=v;
			return;
		}
	}
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	if(l<=mid) update(p*2,l,r,o,v);
	if(r>mid) update(p*2+1,l,r,o,v);
	pushup(p);
}
long long querya(int p,int l,int r)
{
	long long res=0;
	if(t[p].l>=l&&t[p].r<=r)
		return t[p].a;
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	if(l<=mid) res=getm(res+querya(p*2,l,r));
	if(r>mid) res=getm(res+querya(p*2+1,l,r));
	return res;
}
long long queryb(int p,int l,int r)
{
	long long res=0;
	if(t[p].l>=l&&t[p].r<=r)
		return t[p].b;
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	if(l<=mid) res=getm(res+queryb(p*2,l,r));
	if(r>mid) res=getm(res+queryb(p*2+1,l,r));
	return res;
}
long long queryc(int p,int l,int r)
{
	long long res=0;
	if(t[p].l>=l&&t[p].r<=r)
		return t[p].c;
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	if(l<=mid) res=getm(res+queryc(p*2,l,r));
	if(r>mid) res=getm(res+queryc(p*2+1,l,r));
	return res;
}
*/
signed main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	//build(1,1,n);
	
	cin>>m;
	/*
	while(m--)
	{
		int o,l,r,v;
		cin>>o>>l>>r;
		if(o>=1&&o<=3)
		{
			v=-1;
			update(1,l,r,o,v);
		}
		else if(o>=4&&o<=6)
		{
			cin>>v;
			update(1,l,r,o,v);
		}
		else if(o==7) 
			cout<<querya(1,l,r)<<' '<<queryb(1,l,r)<<' '<<queryc(1,l,r)<<endl;
	}
	*/
	while(m--)
	{
		int o,l,r,v;
		cin>>o>>l>>r;
		if(o==1) for(int i=l;i<=r;i++) a[i]=getm(a[i]+b[i]);
		if(o==2) for(int i=l;i<=r;i++) b[i]=getm(b[i]+c[i]);
		if(o==3) for(int i=l;i<=r;i++) c[i]=getm(c[i]+a[i]);
		if(o==4) 
		{
			cin>>v;
			for(int i=l;i<=r;i++) a[i]=getm(a[i]+v);
		}
		if(o==5)
		{
			cin>>v;
			for(int i=l;i<=r;i++) b[i]=getm(b[i]*v);
		}
		if(o==6)
		{
			cin>>v;
			for(int i=l;i<=r;i++) c[i]=v;
		}
		if(o==7)
		{
			long long ans1=0,ans2=0,ans3=0;
			for(int i=l;i<=r;i++)
			{
				ans1=getm(ans1+a[i]);
				ans2=getm(ans2+b[i]);
				ans3=getm(ans3+c[i]);
			}
			cout<<ans1<<' '<<ans2<<' '<<ans3<<endl;
		}
	}
	return 0;
} 

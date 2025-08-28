#include<bits/stdc++.h>
using namespace std;
const int N=250005;
const int MOD=998244353;
typedef long long ll;
struct T
{
	ll a,b,c,ad,mu,to;
}a[N],w[8*N];
T merge(T a,T b)
{
	return {(a.a+b.a)%MOD,(a.b+b.b)%MOD,(a.c+b.c)%MOD,0,0,0};
}
void pushup(int u)
{
	w[u].a=(w[u<<1].a+w[u<<1|1].a)%MOD;
	w[u].b=(w[u<<1].b+w[u<<1|1].b)%MOD;
	w[u].c=(w[u<<1].c+w[u<<1|1].c)%MOD;
}
void pushdown(int u,int l,int r)
{
	ll ad=w[u].ad,mu=w[u].mu,to=w[u].to,mid=(l+r)>>1;
	ll x=mid-l+1,y=r-mid;
	w[u].ad=0;w[u].mu=1;w[u].to=-1;
	w[u<<1].ad+=ad;w[u<<1|1].ad+=ad;
	w[u<<1].a+=ad*x;w[u<<1|1].a+=ad*y;
	w[u<<1].mu*=mu;w[u<<1|1].mu*=mu;
	w[u<<1].b*=mu;w[u<<1|1].b*=mu;
	if(to!=-1)
	{
		w[u<<1].to=to;w[u<<1|1].to=to;
		w[u<<1].c=x*to;w[u<<1|1].c=y*to;
	}
	w[u<<1].a%=MOD;w[u<<1|1].a%=MOD;
	w[u<<1].b%=MOD;w[u<<1|1].b%=MOD;
	w[u<<1].c%=MOD;w[u<<1|1].c%=MOD;
	w[u<<1].ad%=MOD;w[u<<1|1].ad%=MOD;
	w[u<<1].mu%=MOD;w[u<<1|1].mu%=MOD;
	w[u<<1].to%=MOD;w[u<<1|1].to%=MOD;
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		w[u]={a[l].a,a[l].b,a[l].c,0,1,-1};
		return;
	}
	w[u].ad=0;w[u].mu=1;w[u].to=-1;
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
void add(int u,int l,int r,int x,int y,ll k)
{
	pushdown(u,l,r);
	if(l>=x&&r<=y)
	{
		w[u].a+=1ll*(r-l+1)*k;
		w[u].ad=(w[u].ad+k)%MOD;
		w[u].a%=MOD;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=x)add(u<<1,l,mid,x,y,k);
	if(mid<y)add(u<<1|1,mid+1,r,x,y,k);
	pushup(u);
}
void mul(int u,int l,int r,int x,int y,ll k)
{
	pushdown(u,l,r);
	if(l>=x&&r<=y)
	{
		w[u].b=w[u].b*k%MOD;
		w[u].mu=w[u].mu*k%MOD;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=x)mul(u<<1,l,mid,x,y,k);
	if(mid<y)mul(u<<1|1,mid+1,r,x,y,k);
	pushup(u);
}
void to(int u,int l,int r,int x,int y,ll k)
{
	pushdown(u,l,r);
	if(l>=x&&r<=y)
	{
		w[u].c=1ll*(r-l+1)*k%MOD;
		w[u].to=k;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=x)to(u<<1,l,mid,x,y,k);
	if(mid<y)to(u<<1|1,mid+1,r,x,y,k);
	pushup(u);
}
T get(int u,int l,int r,int x,int y)
{
	pushdown(u,l,r);
	if(l>=x&&r<=y)return w[u];
	int mid=(l+r)>>1;
	if(mid>=x&&mid<y)
		return merge(get(u<<1,l,mid,x,y),get(u<<1|1,mid+1,r,x,y));
	if(mid>=x)return get(u<<1,l,mid,x,y);
	return get(u<<1|1,mid+1,r,x,y);
}
int main()
{
//	freopen("magic.in","r",stdin);
//	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
	int q;
	cin>>q;
	if(n<=10000&&q<=10000)
	{
		while(q--)
		{
			int op,l,r,v;
			cin>>op>>l>>r;
			if(op==1)
				for(int i=l;i<=r;i++)a[i].a+=a[i].b;
			else if(op==2)
				for(int i=l;i<=r;i++)a[i].b+=a[i].c;
			else if(op==3)
				for(int i=l;i<=r;i++)a[i].c+=a[i].a;
			else if(op==4)
			{
				cin>>v;
				for(int i=l;i<=r;i++)a[i].a+=v;
			}
			else if(op==5)
			{
				cin>>v;
				for(int i=l;i<=r;i++)a[i].b*=v;
			}
			else if(op==6)
			{
				cin>>v;
				for(int i=l;i<=r;i++)a[i].c=v;
			}
			else
			{
				ll x=0,y=0,z=0;
				for(int i=l;i<=r;i++)
				{
					x+=a[i].a;
					y+=a[i].b;
					z+=a[i].c;
				}
				cout<<x%MOD<<' '<<y%MOD<<' '<<z%MOD<<'\n';
			}
			for(int i=l;i<=r;i++)
			{
				a[i].a%=MOD;
				a[i].b%=MOD;
				a[i].c%=MOD;
			}
		}
		return 0;
	}
	build(1,1,n);
	while(q--)
	{
		int op,l,r,v;
		cin>>op>>l>>r;
		if(op==4)
		{
			cin>>v;
			add(1,1,n,l,r,v);
		}
		else if(op==5)
		{
			cin>>v;
			mul(1,1,n,l,r,v);
		}
		else if(op==6)
		{
			cin>>v;
			to(1,1,n,l,r,v);
		}
		else if(op==7)
		{
			T s=get(1,1,n,l,r);
			cout<<s.a<<' '<<s.b<<' '<<s.c<<'\n';
		}
	}
	return 0;
}

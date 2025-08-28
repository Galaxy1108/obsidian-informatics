#include<bits/stdc++.h>
using namespace std;
const int N=200005;
typedef long long ll;
struct T
{
	ll sum,cnt,mx,se,t1,t2;
}w[8*N];
ll a[N];
void pushup(int u)
{
	w[u].sum=w[u<<1].sum+w[u<<1|1].sum;
	w[u].mx=max(w[u<<1].mx,w[u<<1|1].mx);
	if(w[u<<1].mx==w[u<<1|1].mx)
	{
		w[u].cnt=w[u<<1].cnt+w[u<<1|1].cnt;
		w[u].se=max(w[u<<1].se,w[u<<1|1].se);
	}
	if(w[u<<1].mx>w[u<<1|1].mx)
	{
		w[u].cnt=w[u<<1].cnt;
		w[u].se=max(w[u<<1].se,w[u<<1|1].mx);
	}
	if(w[u<<1].mx<w[u<<1|1].mx)
	{
		w[u].cnt=w[u<<1|1].cnt;
		w[u].se=max(w[u<<1].mx,w[u<<1|1].se);
	}
}
void pushdown(int u,int l,int r)
{
	ll t1=w[u].t1,t2=w[u].t2,mid=(l+r)>>1;
	w[u].t1=1e18;w[u].t2=0;
	if(w[u<<1].mx>t1)
		w[u<<1].sum-=(w[u<<1].mx-t1)*w[u<<1].cnt;
	if(w[u<<1|1].mx>t1)
		w[u<<1|1].sum-=(w[u<<1|1].mx-t1)*w[u<<1|1].cnt;
	w[u<<1].mx=min(w[u<<1].mx,t1);
	w[u<<1|1].mx=min(w[u<<1|1].mx,t1);
	w[u<<1].mx+=t2;w[u<<1|1].mx+=t2;
	w[u<<1].se+=t2;w[u<<1|1].se+=t2;
	w[u<<1].sum+=t2*(mid-l+1);
	w[u<<1|1].sum+=t2*(r-mid);
	w[u<<1].t1=min(w[u<<1].t1,t1);
	w[u<<1|1].t1=min(w[u<<1|1].t1,t1);
	w[u<<1].t2+=t2;w[u<<1|1].t2+=t2;
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		w[u]={a[l],1,a[l],-1e18,1e18,0};
		return;
	}
	w[u].t1=1e18;
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
void mn(int u,int l,int r,int x,int y,ll k)
{
	pushdown(u,l,r);
	if(w[u].mx<=k)return;
	if(l>=x&&r<=y&&w[u].se<k)
	{
		ll v=w[u].mx-k;
		w[u].sum-=v*w[u].cnt;
		w[u].mx=k;
		w[u].t1=k;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=x)mn(u<<1,l,mid,x,y,k);
	if(mid<y)mn(u<<1|1,mid+1,r,x,y,k);
	pushup(u);
}
void add(int u,int l,int r,int x,int y,ll k)
{
	pushdown(u,l,r);
	if(l>=x&&r<=y)
	{
		w[u].mx+=k;
		w[u].se+=k;
		w[u].sum+=1ll*(r-l+1)*k;
		w[u].t2=k;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=x)add(u<<1,l,mid,x,y,k);
	if(mid<y)add(u<<1|1,mid+1,r,x,y,k);
	pushup(u);
}
ll get(int u,int l,int r,int x,int y)
{
	pushdown(u,l,r);
	if(l>=x&&r<=y)return w[u].sum;
	ll mid=(l+r)>>1,sum=0;
	if(mid>=x)sum+=get(u<<1,l,mid,x,y);
	if(mid<y)sum+=get(u<<1|1,mid+1,r,x,y);
	return sum;
}
int main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,T;
	cin>>n>>T;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=5000&&T<=5000)
	{
		while(T--)
		{
			ll op;
			cin>>op;
			if(op==1)
			{
				ll v;
				cin>>v;
				for(int i=1;i<=n;i++)a[i]=min(a[i],v);
			}
			else if(op==2)
				for(int i=1;i<=n;i++)a[i]+=i;
			else
			{
				ll sum=0,l,r;
				cin>>l>>r;
				for(int i=l;i<=r;i++)sum+=a[i];
				cout<<sum<<'\n';
			}
		}
		return 0;
	}
	build(1,1,n);
	while(T--)
	{
		ll op;
		cin>>op;
		if(op==1)
		{
			ll v;
			cin>>v;
			mn(1,1,n,1,n,v);
		}
		else if(op==2)
		{
			for(int i=1;i<=n;i++)add(1,1,n,i,i,i);
		}
		else
		{
			ll l,r;
			cin>>l>>r;
			cout<<get(1,1,n,l,r)<<'\n';
		}
	}
	return 0;
}

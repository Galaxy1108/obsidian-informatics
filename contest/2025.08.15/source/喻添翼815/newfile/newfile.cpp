#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
const int mod=1e9+9;
int n,m,q,cnt;
int rt[mx];
struct segT
{
	int l,r;
	long long sum;
}t[mx*1000];
int clone(int p)
{
	t[++cnt]=t[p];
	return cnt;
}
int build(int p,int l,int r)
{
	p=++cnt;
	if(l==r)
	{
		t[p].sum=0;
		return p;
	}
	int mid=(l+r)/2;
	t[p].l=build(t[p].l,l,mid);
	t[p].r=build(t[p].r,mid+1,r);
	return p;
}
int update(int p,int l,int r,int L,int R,int x)
{
	int pos=clone(p);
	if(l>=L&&r<=R)
	{
		t[pos].sum=(t[pos].sum+(r-l+1)*x%mod)%mod;
		return pos;
	}
	int mid=(l+r)/2;
	if(L<=mid) t[pos].l=update(t[pos].l,l,mid,L,R,x);
	if(R>mid) t[pos].r=update(t[pos].r,mid+1,r,L,R,x);
	return pos;
}
__int128 query(int p,int l,int r,int L,int R)
{
	if(l>=L&&r<=R)
	{
		return t[p].sum;
	}
	__int128 res=0;
	int mid=(l+r)/2;
	if(L<=mid) res=(res+query(t[p].l,l,mid,L,R))%mod;
	if(R>mid) res=(res+query(t[p].r,mid+1,r,L,R))%mod;
	return res;
}
int main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	rt[0]=build(0,1,n);
	for(int i=1;i<=m;i++)
	{
		int l,r,x;
		cin>>l>>r>>x;
		rt[i]=update(rt[i-1],1,n,l,r,x);
	}
	for(int i=1;i<=q;i++)
	{
		int u,d,l,r;
		cin>>u>>d>>l>>r;
		__int128 ans=0;
		long long Ans=0;
		for(int j=u;j<=d;j++)
			ans=(ans+query(rt[j],1,n,l,r))%mod;
		Ans=ans;
		cout<<Ans<<"\n";
	}
	return 0;
} 

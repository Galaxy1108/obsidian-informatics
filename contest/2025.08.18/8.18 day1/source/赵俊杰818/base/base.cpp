#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2005;
struct T
{
	int sum,mnl,mnr,mn;
}w[8*N];
int a[N][2],s[N];
T merge(T a,T b)
{
	T ans;
	ans.sum=a.sum+b.sum;
	ans.mnl=min(a.mnl,a.sum+b.mnl);
	ans.mnr=min(b.mnr,b.sum+a.mnr);
	ans.mn=min(min(a.mn,b.mn),a.mnr+b.mnl);
	return ans;
}
void pushup(int u)
{
	w[u]=merge(w[u<<1],w[u<<1|1]);
}
void build(int u,int l,int r)
{
	if(l==r)
	{
		w[u]={a[l][0],a[l][0],a[l][0],a[l][0]};
		return;
	}
	int mid=(l+r)>>1;
	build(u<<1,l,mid);
	build(u<<1|1,mid+1,r);
	pushup(u);
}
T get(int u,int l,int r,int x,int y)
{
	if(l>=x&&r<=y)return w[u];
	int mid=(l+r)>>1;
	if(mid>=x&&mid<y)return merge(get(u<<1,l,mid,x,y),get(u<<1|1,mid+1,r,x,y));
	if(mid>=x)return get(u<<1,l,mid,x,y);
	return get(u<<1|1,mid+1,r,x,y);
}
signed main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i][0];
	for(int i=1;i<=n;i++)cin>>a[i][1];
	build(1,1,n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i][0]+a[i][1];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i-2;j++)
			ans=max(ans,s[i]-s[j-1]-get(1,1,n,j+1,i-1).mn);
	}
	cout<<ans<<'\n';
	return 0;
}

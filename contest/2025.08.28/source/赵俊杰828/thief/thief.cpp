#include<bits/stdc++.h>
using namespace std;
const int N=500005;
typedef long long ll;
ll a[N];
struct T
{
	int a[21];
}w[4*N];
T merge(T a,T b)
{
	T ans;
	for(int i=0;i<=20;i++)
		ans.a[i]=b.a[a.a[i]];
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
		for(int i=0;i<=20;i++)
		{
			if(i<a[l])w[u].a[i]=i+1;
			if(i>a[l])w[u].a[i]=i-1;
			if(i==a[l])w[u].a[i]=i;
		}
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
int main()
{
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,T;
	cin>>n>>T;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=1000&&T<=1000)
	{
		while(T--)
		{
			int l,r,k;
			cin>>l>>r>>k;
			for(int i=l;i<=r;i++)
			{
				if(k<a[i])k++;
				if(k>a[i])k--;
			}
			cout<<k<<'\n';
		}
		return 0;
	}
	build(1,1,n);
	while(T--)
	{
		int l,r,k;
		cin>>l>>r>>k;
		cout<<get(1,1,n,l,r).a[k]<<'\n';
	}
	return 0;
}

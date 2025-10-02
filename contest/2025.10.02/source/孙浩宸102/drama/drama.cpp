#include<bits/stdc++.h>
#define il inline
using namespace std;
using ll=long long;
__int128 ans=-0x3f3f;
const int N=2000099;
ll a[N],tree[N<<2],tree2[N<<2];
il ll ls(ll p)
{
	return p<<1;
}
il ll rs(ll p)
{
	return p<<1|1;
}
il void push_up(ll p)
{
	tree[p]=max(tree[ls(p)],tree[rs(p)]);
}
il void push_up2(ll p)
{
	tree2[p]=min(tree2[ls(p)],tree2[rs(p)]);
}
il void build(ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree[p]=a[pl];
		return;
	}
	ll mid=(pl+pr)>>1;
	build(ls(p),pl,mid);
	build(rs(p),mid+1,pr);
	push_up(p);
}
il void build2(ll p,ll pl,ll pr)
{
	if(pl==pr)
	{
		tree2[p]=a[pl];
		return;
	}
	ll mid=(pl+pr)>>1;
	build2(ls(p),pl,mid);
	build2(rs(p),mid+1,pr);
	push_up2(p);
}
il ll querymax(ll L,ll R,ll p,ll pl,ll pr)
{
	if(L<=pl&&pr<=R)
		return tree[p];
	ll w=0;
	ll mid=(pl+pr)>>1;
	if(L<=mid)
		w=max(w,querymax(L,R,ls(p),pl,mid));
	if(mid+1<=R)
		w=max(w,querymax(L,R,rs(p),mid+1,pr));
	return w;
}
il ll querymin(ll L,ll R,ll p,ll pl,ll pr)
{
	if(L<=pl&&pr<=R)
		return tree2[p];
	ll w=0x3f3f3f3f;
	ll mid=(pl+pr)>>1;
	if(L<=mid)
		w=min(w,querymin(L,R,ls(p),pl,mid));
	if(mid+1<=R)
		w=min(w,querymin(L,R,rs(p),mid+1,pr));
	return w;
}
il void shuchu(__int128 x)
{
	vector<short> ve;
	while(x>0)
	{
		ve.push_back(x%10);
		x/=10;
	}
	for(int i=ve.size()-1;i>=0;i--)
	{
		cout<<ve[i];
	}
}
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	build(1,1,n);
	build2(1,1,n);
//	cout<<1<<endl;
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<endl;
		for(int j=1;j<=i;j++)
		{
//			long long aa=querymax(j,i,1,1,n),bb=querymin(j,i,1,1,n);
			if(ans<querymax(j,i,1,1,n)*querymin(j,i,1,1,n)*(i-j+1))
			{
				ans=querymax(j,i,1,1,n)*querymin(j,i,1,1,n)*(i-j+1);
			}
		}
	}
	shuchu(ans);
	return 0;
}

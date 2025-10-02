#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(2)
using namespace std;
const int  mx=2e6+100;
int m=0;
int a[mx];
int n;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
//struct tree
//{
//	int l,r,minn,maxn;
//}t[4*mx];
//void pushup(int p)
//{
//	t[p].minn=min(t[p<<1].minn,t[p<<1|1].minn);
//	t[p].maxn=max(t[p<<1].maxn,t[p<<1|1].maxn);
//}
//void build(int p,int l,int r)
//{
//	t[p].l=l,t[p].r=r;
//	if(l==r) 
//	{
//		t[p].maxn=a[l];
//		t[p].minn=a[l];
//		return ;
//	}
//	int mid=(l+r)/2;
//	build(p<<1,l,mid);
//	build(p<<1|1,mid+1,r);
//	m=max(m,p*2+1);
//	pushup(p);
//}
//int askmax(int p,int l,int r)
//{
//	if(t[p].l>=l&&t[p].r<=r) return t[p].maxn;
//	int mid=(t[p].l+t[p].r)/2,maxn=0;
//	if(l<=mid) maxn=max(maxn,askmax(t[p<<1],l,r));
//	if(r>mid) maxn=max(maxn,askmax(t[p<<1|1],l,r));
//	return maxn;
//}
//int askmin(int p,int l,int r)
//{
//	if(t[p].l>=l&&t[p].r<=r) return t[p].minn;
//	int mid=(t[p].l+t[p].r)/2,minn=2e9;
//	if(l<=mid) minn=min(minn,askmin(p<<1,l,r));
//	if(r>mid) minn=min(minn,askmin(p<<1|1,l,r));
//	return minn;
//}
signed main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	n=fread();
	for(int i=1;i<=n;i++) a[i]=fread();
//	build(1,1,n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int maxn=0,minn=2e9;
		for(int j=i;j<=n;j++)
		{
			maxn=max(maxn,a[j]);
			minn=min(minn,a[j]);
			ans=max(ans,maxn*minn*(j-i+1));
		}
	}
	cout<<ans;
	return 0;
}
/*
9
5 11 15 17 19 3 19 9 4
*/

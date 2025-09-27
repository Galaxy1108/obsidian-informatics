#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],b[N],n,m;
bool ok(int k)
{
	int r=1;
	for(int i=1;i<=n;i++)
	{
		while(r<=m&&b[r]<a[i]-k)r++;
		if(r>m||b[r]>a[i]+k)return 0;
		r++;
	}
	return 1;
}
int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	if(n>m)
	{
		for(int i=1;i<=n;i++)cin>>b[i];
		for(int i=1;i<=m;i++)cin>>a[i];
		swap(n,m);
	}
	else
	{
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=m;i++)cin>>b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	int l=0,r=1000000000,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(ok(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<'\n';
	return 0;
}

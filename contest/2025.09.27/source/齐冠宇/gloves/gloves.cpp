#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e5+5,inf=1e9;
int n,m;
int a[N],b[N];
int ans=inf;
bool chk(int mid)
{
	int mx=0;
	for(int i=1,j=1;i<=n;i++,j++)
		while(abs(a[i]-b[j])>mid)
		{
			if(j==m)return false;
			j++;
		}
	return true;
}
int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i];
	if(n>m)
	{
		for(int i=1;i<=max(n,m);i++)
			swap(a[i],b[i]);
		swap(n,m);
	}
	sort(a+1,a+1+n),sort(b+1,b+1+m);
	int l=0,r=inf;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(chk(mid))ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans;
	return 0;
}

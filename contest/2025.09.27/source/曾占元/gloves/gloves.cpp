#include<bits/stdc++.h>
#define int long long
using namespace std;
int l[100005],r[100005];
int f(int x,int y)
{
	if(x>=y)
		return x-y;
	return y-x;
}
signed main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	int n,m,ans,ans1=0,ans2=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>l[i];
	for(int i=1;i<=m;i++)
		cin>>r[i];
	sort(l+1,l+n+1);
	sort(r+1,r+m+1);
	int k=min(m,n);
	for(int i=1;i<=k;i++)
		ans1=max(ans1,f(l[n-i+1],r[m-i+1]));
	for(int i=1;i<=k;i++)
		ans2=max(ans2,f(l[i],r[i]));
	ans=min(ans1,ans2);
	cout<<ans;
	return 0;
}

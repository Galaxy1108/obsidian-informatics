#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=2005;
int n;
int a[N][2];
int pre[N];
int suf[N];
int mxp[N],mxs[N];
int s[N];
int ans;
signed main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i][0];
	for(int i=1;i<=n;i++)
		cin>>a[i][1],s[i]=s[i-1]+a[i][1];
	for(int i=1,mn=0;i<=n;i++)
	{
		pre[i]=pre[i-1]+a[i][0]+a[i][1];
		mxp[i]=pre[i]-mn;
		mn=min(mn,pre[i]);
	}
	for(int i=n,mn=0;i>=1;i--)
	{
		suf[i]=suf[i+1]+a[i][0]+a[i][1];
		mxs[i]=suf[i]-mn;
		mn=min(mn,suf[i]);
	}
	for(int i=2;i<n;i++)
		for(int j=i;j<n;j++)
			ans=max(ans,s[j]-s[i-1]+mxp[i-1]+mxs[j+1]);
	cout<<ans;
	return 0;
}

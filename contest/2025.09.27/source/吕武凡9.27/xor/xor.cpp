#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100010];
int dp[3010][3010];
int maxn[3010][3010];
int ans=0;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int len=1;len<=n;len++)
	{
		for(int l=1,r=l+len-1;l<=n,r<=n;l++,r++)
		{
			if(len==1)
			{
				dp[l][r]=a[l];
				maxn[l][r]=a[l];
			}
			else
			{
				dp[l][r]=(a[l] xor dp[l+1][r]);
				maxn[l][r]=max(a[l],maxn[l+1][r]);
			}
			if(dp[l][r]<=maxn[l][r])
			{
				ans++;
			}
		}
	}
	cout<<ans<<endl;
}

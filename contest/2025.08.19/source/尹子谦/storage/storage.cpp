#include<bits/stdc++.h> 
#define int long long
using namespace std;
const int N=1e4+10;
int dp[N],x[N],p[N],c[N],prep[N],prepx[N],n;
signed main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	cin>>n;
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for(int i=1;i<=n;i++) cin>>x[i]>>p[i]>>c[i],prep[i]=prep[i-1]+p[i],prepx[i]=prepx[i-1]+x[i]*p[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			dp[i]=min(dp[i],dp[j]+(prep[i-1]-prep[j])*x[i]-(prepx[i-1]-prepx[j]));
		}
		dp[i]+=c[i];
	}
	cout<<dp[n];
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
const int N=1e5+56,mod=1e9+9;
int n,m,q;
ll sum[5005][5005];
int main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1,l,r,x;i<=m;i++)
	{
		cin>>l>>r>>x;
		for(int j=1;j<=n;j++)sum[i][j]=sum[i-1][j];
		for(int j=l;j<=r;j++)sum[i][j]+=x;
	}
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)sum[i][j]+=sum[i][j-1];
	int l1,l2,r1,r2;
	while(q--)
	{
		cin>>l1>>r1>>l2>>r2;
		ll ans=0;
		for(int i=l1;i<=r1;i++)
		{
			ans=(ans+(sum[i][r2]-sum[i][l2-1])%mod)%mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}


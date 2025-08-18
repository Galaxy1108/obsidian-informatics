#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[10005][105],a[10005];
int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<m-j-1;k++)
			{
				if(i-j-1>=0)f[i][j]=min(f[i][j],a[i-j]+f[i-j-1][k]);
				else f[i][j]=0;
			}
		}
	}
	ll ans=1e18;
	for(int j=0;j<m;j++)ans=min(ans,f[n][j]);
	cout<<ans<<'\n';
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
ll f[205][1<<8][8][55],a[205];
int get(ll x)
{
	int cnt=0;
	while(x)
	{
		cnt++;
		x=x&(x-1);
	}
	return cnt;
}
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<k;i++)
		f[0][0][i][0]=1;
	for(int i=1;i<=n;i++)
	{
		f[i][0][0][0]=1;
		for(int j=0;j<(1<<k);j++)
		{
			if(get(j)>a[i])continue;
			for(int u=1;u<=k;u++)
			{
				for(int p=0;p<(1<<k);p++)
				{
					for(int t=0;t<=u*(u+1)/2;t++)
					{
						int v=get(j&((1<<u)-1));
						if(t<get(v))continue;
						if(!f[i-1][p][k][a[i-1]])continue;
						if(t-get(v)>a[i-1])continue;
						f[i][j][u][t]+=f[i-1][p][u-1][t-get(v)];
						f[i][j][u][t]%=MOD;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<(1<<k);i++)
		ans+=f[n][i][k][a[n]];
	cout<<ans%MOD<<'\n';
	return 0;
}

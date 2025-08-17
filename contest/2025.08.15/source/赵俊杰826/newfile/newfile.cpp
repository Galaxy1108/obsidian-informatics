#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int MOD=1000000009;
typedef long long ll;
ll f[N][N];
int main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,T;
	cin>>n>>m>>T;
	for(int i=1;i<=m;i++)
	{
		int l,r,x;
		cin>>l>>r>>x;
		for(int j=1;j<=n;j++)
			f[i][j]=f[i-1][j];
		for(int j=l;j<=r;j++)
			f[i][j]=(f[i][j]+x)%MOD;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f[i][j]+=f[i][j-1];
			f[i][j]%=MOD;
		}
	}
	while(T--)
	{
		int x,y,l,r;
		ll ans=0;
		cin>>x>>y>>l>>r;
		for(int i=x;i<=y;i++)
			ans+=f[i][r]-f[i][l-1];
		cout<<(ans%MOD+MOD)%MOD<<'\n';
	}
	return 0;
}

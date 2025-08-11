#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int f[N][N],a[N];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		memset(f,0,sizeof(f));
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;i++)cin>>a[i];
		for(int i=1;i<=m;i++)
		{
			for(int j=0;j<=n;j++)
			{
				if(j>m)break;
				f[i][j]=max(f[i-1][j]+a[j],f[i+1][j-1]-a[i]);
			}
		}
		int ans=0;
		for(int j=0;j<=n;j++)
			ans=max(ans,f[1][j]);
		cout<<ans<<'\n';
	}
	return 0;
}

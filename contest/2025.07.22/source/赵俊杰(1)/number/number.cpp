#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int f[N][N],a[N],x[N];
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
		memset(x,0,sizeof(x));
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=m;i++)cin>>a[i];
		if(n<=2&&m<=20)
		{
			int ans=0;
			for(int i=0;i<(1<<m);i++)
			{
				x[0]=0;x[1]=0;
				for(int j=1;j<=m;j++)
					if(i&(1<<(j-1)))
						x[1]=a[j]-x[1];
					else
						x[0]=a[j]-x[0];
				ans=max(ans,x[0]+x[1]);
			}
			cout<<ans<<'\n';
			continue;
		}
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

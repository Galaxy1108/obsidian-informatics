#include<bits/stdc++.h>
using namespace std;
const int N=10000+5;

int n,m;
int f[N][103][2];
int a[N];

int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
if(m==2)
{
	int ans=0;
	for(int i=1;i<=n;i++)ans+=a[i];
	cout<<ans<<endl;return 0;
}

	memset(f,0x3f,sizeof(f));
	f[1][0][1]=a[1];
	f[1][1][0]=0;f[1][0][0]=0;f[1][1][1]=a[1];
	f[0][1][0]=0;f[0][0][1]=0;f[0][0][0]=0;f[0][1][1]=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			f[i][j][0]=min(f[i-1][j+1][0] , f[i-1][j][1] );
			f[i][j][1]=min(f[i-1][j][1] , f[i-1][j+1][0] ) +a[i] ;
		}
	}
	int ans=0x3f3f3f3f;
	for(int i=0;i<=m-2;i++)
	{
		ans=min(ans,f[n][i][0]);
		ans=min(ans,f[n][i][1]);
	}
	cout<<ans<<endl;
	return 0;
}

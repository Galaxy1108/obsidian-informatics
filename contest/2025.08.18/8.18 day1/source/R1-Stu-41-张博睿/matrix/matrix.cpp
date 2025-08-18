#include<bits/stdc++.h>
using namespace std;
const int N=105;

int n,m,k;
int a[N][3];
int f[N][12][2][2];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}

if(m==1)
{
	f[1][1][1][0]=a[1][1];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			f[i][j][0][0]=max(f[i-1][j][0][0],f[i-1][j][1][0]);
			f[i][j][1][0]=max(f[i-1][j-1][0][0] +a[i][1] ,f[i-1][j][1][0] +a[i][1]);
		}
	}
	cout<<max(f[n][k][0][0],f[n][k][1][0])<<endl;
	return 0;
}
	f[1][1][1][0]=a[1][1];
	f[1][1][0][1]=a[1][2];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			f[i][j][0][0]=max( f[i-1][j][0][1] , max( f[i-1][j][1][0], max( f[i-1][j][0][0] , f[i-1][j][1][1] ) )   ) ;
			f[i][j][1][0]=max( f[i-1][j-1][0][1],max( f[i-1][j][1][0] ,max( f[i-1][j-1][0][0],f[i-1][j][1][1]  ) ) )+a[i][1];
			f[i][j][0][1]=max( f[i-1][j-1][1][0],max( f[i-1][j][0][1] , max( f[i-1][j-1][0][0] , f[i-1][j][1][1] ) )  ) +a[i][2];
			f[i][j][1][1]=max( f[i-1][j][1][1] ,max( f[i-1][j-1][1][0] , max(f[i-1][j-1][0][1] , f[i-1][j-1][0][0] ) )  ) +a[i][1]+a[i][2];
		}
	}
	cout<<max( f[n][k][0][1], max( f[n][k][1][0],max( f[n][k][1][1] , f[n][k][0][0] ) ) )<<endl;
	
	return 0;
}

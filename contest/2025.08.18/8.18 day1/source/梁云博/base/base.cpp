#include <bits/stdc++.h>
#define N 2005
#define int long long
using namespace std;
int n;
int s[3][N];
int f[N];//以i结尾的最大矩形 
int line1[N];
int d[N][N];//第一行l,r间的最daziduan和 
int res[N][N];
signed main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	cin>>n;
	memset(d,0x80,sizeof(d));
	memset(res,0x80,sizeof(res));
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>s[i][j];
			if(i==1)line1[j]=d[j][j]=-s[i][j];
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	for(int l=1;l<=n;l++)//以l为起点的，r结尾的最大子段和 
	{
		res[l][l]=d[l][l];
		for(int r=l+1;r<=n;r++)
		{
			d[l][r]=max(d[r][r],d[l][r-1]+d[r][r]);
			res[l][r]=max(res[l][r-1],d[l][r]);
		}
	}
	int ans=-1e9;
	for(int len=3;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			ans=max(ans,s[2][r]-s[2][l-1]+res[l+1][r-1]);
		}
	}cout<<ans;
	return 0;
}

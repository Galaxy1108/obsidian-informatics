#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e4+5;
int n,m;
int a[N];
int f[2][105][105];
int t;
int ans;
int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m>=n)
	{
		sort(a+1,a+1+n);
		return cout<<a[1]+a[2],0;
	}
	memset(f,0x3f,sizeof f);
	ans=f[0][0][0];
	for(int i=1;i<m;i++)
		for(int j=i+1;j<=m;j++)
			f[t][i][j]=a[i]+a[j];
#define tt (t^1)
	for(int i=m+1;i<=n;i++,t^=1)
	{
		for(int j=1;j<m;j++)
			for(int k=j+1;k<=m;k++)
			{
				if(k!=m)
				{
					f[tt][j][k]=f[t][j+1][k+1];
					f[tt][j][k]=min(f[tt][j][k],min(f[t][1][j+1]+a[i+k-m],f[t][1][k+1]+a[i+j-m])); 
				}
				else
					f[tt][j][k]=f[t][1][j+1]+a[i+k-m];
			}
		for(int i=1;i<m;i++)
			for(int j=i+1;j<=m;j++)
				f[t][i][j]=ans;
	}
#undef tt
	for(int i=1;i<m;i++)
		for(int j=i+1;j<=m;j++)
			ans=min(ans,f[t][i][j]);
	cout<<ans;
	return 0;
}

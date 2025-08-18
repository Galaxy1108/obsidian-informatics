#include<bits/stdc++.h>
using namespace std;
int n,m,k1;
int a[151][3],s[151][3],s1[151],f[151][3][15];
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m>>k1;
	for(int i=1;i<=n;i++){
		s1[i]=s1[i-1];
		for(int j=1;j<=m;j++)cin>>a[i][j],s[i][j]=s[i-1][j]+a[i][j],s1[i]+=a[i][j];
	}
	for(int k=1;k<=k1;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				f[i][j][k]=max(f[i-1][j][k],max(f[i-1][j][k-1]+a[i][j],f[i-1][j][k]+a[i][j]));
			}
		}
	}
	int maxn=max(f[n][1][k1],f[n][2][k1]);
	for(int k=1;k<k1;k++)
	{
		maxn=max(maxn,f[n][1][k]+f[n][2][k1-k]);
	}
	cout<<maxn<<endl;
	return 0;
}

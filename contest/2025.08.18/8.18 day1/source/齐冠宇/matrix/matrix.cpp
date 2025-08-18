#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=105;
int n,m,k;
int a[N][5];
int f[N][15][3],g[N][15][3];
int s[N][5];
int ans;
signed main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j],s[i][j]=s[i-1][j]+a[i][j];
	memset(f,0xc0,sizeof f);
	ans=f[0][0][0];
	f[0][0][0]=f[0][0][1]=f[0][0][2]=0;
	if(m==1)
		for(int i=1;i<=n;i++)
		{
			f[i][0][0]=0;
			for(int t=1;t<=k;t++)
				for(int j=i;j;j--)
					for(int l=j-1;~l;l--)
						f[i][t][0]=max(f[i][t][0],s[i][1]-s[j-1][1]+f[l][t-1][0]);
			ans=max(ans,f[i][k][0]);
		}
	else
		for(int i=1;i<=n;i++)
		{
			f[i][0][0]=f[i][0][1]=f[i][0][2]=0;
			for(int t=1;t<=k;t++)
				for(int j=i;j;j--)
				{
					for(int l=j-1;~l;l--)
						for(int p=0;p<3;p++)
						{
							if(p==0 || p==1)
							{
								if(f[i][t][p]<s[i][p+1]-s[j-1][p+1]+f[l][t-1][p])
									f[i][t][p]=s[i][p+1]-s[j-1][p+1]+f[l][t-1][p],g[i][t][p]=g[l][t-1][p];
								if(f[i][t][p]<s[i][p+1]-s[j-1][p+1]+f[l][t-1][2])
									f[i][t][p]=s[i][p+1]-s[j-1][p+1]+f[l][t-1][2],g[i][t][p]=l;
							}
							else
							{
								if(f[i][t][p]<s[i][1]-s[j-1][1]+s[i][2]-s[j-1][2]+f[l][t-1][2])
									f[i][t][p]=s[i][1]-s[j-1][1]+s[i][2]-s[j-1][2]+f[l][t-1][2],g[i][t][p]=l;
								if(f[i][t][p]<s[i][1]-s[j-1][1]+s[i][2]-s[j-1][2]+f[l][t-1][0])
									f[i][t][p]=s[i][1]-s[j-1][1]+s[i][2]-s[j-1][2]+f[l][t-1][0],g[i][t][p]=l;
								if(f[i][t][p]<s[i][1]-s[j-1][1]+s[i][2]-s[j-1][2]+f[l][t-1][1])
									f[i][t][p]=s[i][1]-s[j-1][1]+s[i][2]-s[j-1][2]+f[l][t-1][1],g[i][t][p]=l;
							}
						}
					for(int l=i;l;l--)
						for(int p=0;p<2;p++)
							if(j>g[l][t-1][p^1])
								if(f[i][t][p]<s[i][p+1]-s[j-1][p+1]+f[l][t-1][p^1])
									f[i][t][p]=s[i][p+1]-s[j-1][p+1]+f[l][t-1][p^1],g[i][t][p]=l;
				}
			ans=max(ans,max(max(f[i][k][0],f[i][k][1]),f[i][k][2]));
		}
	cout<<ans;
	return 0;
}

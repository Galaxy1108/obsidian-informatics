#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[10005],f[10005][105],g[10005],ans=10000000000000;
//f{i,j} = 刷第i个，上一个刷i-1~i-j 
signed main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	memset(f,0x3f,sizeof(f));
	for(int i = 0; i <= 102; i++) f[0][i]=0;
	for(int i = 1; i <= n; i++)
	{
		int nmin=100000000000000;
		for(int j = 1; j <= m-1; j++)
		{
			//if(i-j<0) continue;
			if(i-j>=0) nmin=min(nmin,f[i-j][m-j]);
			//cout<<f[i-j][m-j]<<endl;
			f[i][j]=min(nmin,f[i][j-1])+a[i];
			if(i-j>=n-m+1) ans=min(ans,f[i][j]);
			//cout<<f[i][j]<<" ";
		}
		//cout<<endl;
	 } 
	cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[2][4005][4005],n,m,p,g[4005][4005];
void calc(int x)
{
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			g[i][j]=g[i-1][j]+g[i][j-1]+f[x][i][j]-g[i-1][j-1];
			g[i][j]%=p;
		}
	}
	return;
}
int get(int la,int lb,int ra,int rb)
{
	//(la,ra)~(lb,rb);
	return ((g[lb][rb]-g[la-1][rb]-g[lb][ra-1]+g[la-1][ra-1])%p+p)%p;
}
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>p;
	if(m==1)
	{
		cout<<1;
		return 0;
	 } 
	for(int i = 1; i <= m; i++)
	{
		for(int j = i; j <= m; j++)
		{
			f[1][i][j]=1;
		}
	}
	calc(1);
	for(int i = 2; i <= n; i++)
	{
		for(int lp = 1; lp <= m; lp++)
		{
			for(int rp = lp; rp <= m; rp++)
			{
				//f[i&1][lp][rp]=0;
				//if(lp>1) f[i&1][lp][rp]+=get(1,lp-1,lp,rp);
				f[i&1][lp][rp]=(((g[rp][m]-g[0][m]-g[rp][lp-1]+g[0][lp-1])%p+p)%p);
				f[i&1][lp][rp]%p;
				//cout<<f[i&1][lp][rp]<<" ";
			}
			//cout<<endl;
		}
		for(int ii = 1; ii <= m; ii++)
		{
			for(int jj = 1; jj <= m; jj++)
			{
				g[ii][jj]=g[ii-1][jj]+g[ii][jj-1]+f[i&1][ii][jj]-g[ii-1][jj-1];
				g[ii][jj]%=p;
			}
		}
	}
	long long ans=0;
	for(int i = 1; i <= m; i++)
	{
		for(int j = i; j <= m; j++)
		{
			ans+=f[n&1][i][j];
			ans%=p;
		}
	}
	cout<<ans<<endl;
}

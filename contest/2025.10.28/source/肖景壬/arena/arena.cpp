#include<bits/stdc++.h>
using namespace std;
#define int long long
#define XaoWa118 998244353
int comb[505][505],f[505][505],n,x,ans;
int fpow(int xx,int yy,int mod)
{
	if(yy==0) return 1;
	if(yy==1) return xx;
	int ret=fpow(xx,yy>>1,mod);
	ret*=ret;
	ret%=mod;
	if(yy&1)
	{
		ret*=xx;
		ret%=mod;
	}
	return ret;
}
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>x;
	for(int i = 0; i <= 500; i++) comb[i][0]=1;
	for(int i = 1; i <= 500; i++)
	{
		for(int j = 1; j <= i; j++)
		{
			comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%XaoWa118; 
		}
	}
	for(int i = 2; i <= n; i++)
	{
		for(int j = 1; j <= x; j++)
		{
			if(j<i)
			{
				f[i][j]=((fpow(j,i,XaoWa118)-fpow(j-1,i,XaoWa118))%XaoWa118+XaoWa118)%XaoWa118;
			}
			else
			{
				for(int k = 1; k <= i; k++)
				{
					f[i][j]+=(((fpow(i-1,i-k,XaoWa118)*f[k][j-i+1])%XaoWa118)*comb[i][k]);
					f[i][j]%=XaoWa118;
				}
			}
		}
	}
	for(int i = 1; i <= x; i++)
	{
		ans+=f[n][i];
		ans%=XaoWa118;
	}
	cout<<ans<<endl;
}

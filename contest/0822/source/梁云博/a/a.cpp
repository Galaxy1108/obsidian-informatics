#include <bits/stdc++.h>
#define N 5005
#define int long long 
using namespace std;
int n,m,p;
int f[2][N][N];//第i个区间是以j为结尾，len为长度的最大和 
void clear(int x)
{
	for(int j=1;j<=m;j++)
	{
		for(int len=1;len<=j;len++)
		{
			f[x][j][len]=0;
		}
	}
}
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>p;
	if(n==1)
	{
		cout<<(((m+1)%p)*m/2)%p;
		return 0;
	}
	else if(m==1)
	{
		cout<<1;
		return 0;
	}
	for(int j=1;j<=m;j++)//当i为1时，所有的j和len都会有1种 
		for(int len=1;len<=j;len++)
			f[1][j][len]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int preks=0,sufks=0;
			for(int len=1;len<=j;len++)
			{
				//k在j前面
				//前面的随着len改变会拓宽1，只需要计算拓宽的就好了
				for(int kl=1;kl<=j-len+1;kl++)preks=(preks+f[(i+1)&1][j-len+1][kl])%p;
				f[i&1][j][len]=(f[i&1][j][len]+preks)%p;
				if(!sufks)
				{
					for(int k=j+1;k<=m;k++)//k在j后面 
					{
						for(int kl=k-j+1;kl<=k;kl++)
						{
							sufks=(sufks+f[(i+1)&1][k][kl])%p;
							f[i&1][j][len]=(f[i&1][j][len]+f[(i+1)&1][k][kl])%p;
						}
					}
				}
				else f[i&1][j][len]=(f[i&1][j][len]+sufks)%p;
			}
		}
		clear((i+1)&1);
	}
	int ans=0;
	for(int j=1;j<=m;j++)
		for(int len=1;len<=j;len++)
			ans=(ans+f[n&1][j][len])%p;
	cout<<ans;
	return 0;
}
/*

*/

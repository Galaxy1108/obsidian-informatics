#include<bits/stdc++.h>
using namespace std;
long long f[205][605][605],n,m,p;
int main()
{
	cin>>n>>m>>p;
	for(int i = 1; i <= m; i++)
	{
		for(int j = i; j <= m; j++)
		{
			f[1][i][j]=1;
		}
	}
	for(int i = 1; i < n; i++)
	{
		cout<<i<<endl;
		for(int la = 1; la <= m; la++)
		{
			for(int ra = la; ra <= m; ra++)
			{
				for(int lb = 1; lb <= m; lb++)
				{
					for(int rb = lb; rb <= m; rb++)
					{
						if((lb>=la&&lb<=ra)||(rb>=la&&rb<=ra))
						{
							f[i+1][lb][rb]+=f[i][la][ra];
							f[i+1][lb][rb]%=p;
						}
					}
				}
			}
		}
	}
	long long ans=0;
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			ans+=f[n][i][j];
			ans%=p;
		}
	}
	cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int XaoWa118 = 9999973; 
int f[105][105][105],n,m;
signed main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	f[0][0][0]=1;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			for(int k = 0; k <= m; k++)
			{
				f[i][j][k]%=XaoWa118;
				if(j+k>m) break;
				//cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
				f[i+1][j][k]+=f[i][j][k];
				f[i+1][j+1][k]+=f[i][j][k]*(m-j-k);
				if(j>0) f[i+1][j-1][k+1]+=f[i][j][k]*j;
				f[i+1][j+2][k]+=f[i][j][k]*(((m-j-k)*(m-j-k-1)/2)%XaoWa118);
				f[i+1][j][k+1]+=f[i][j][k]*(((m-j-k)*j)%XaoWa118);
				//if(j>0) f[i+1][j-1][k+1]+=f[i][j][k]*(((m-j-k)*j)%XaoWa118);
				if(j>1) f[i+1][j-2][k+2]+=f[i][j][k]*((j*(j-1)/2)%XaoWa118);
			}
		}
	}
	int ans=0;
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= m; j++)
		{
			//cout<<i<<" "<<j<<" "<<f[n][i][j]<<endl;
			if(i+j>m) break;
			ans+=f[n][i][j];
			ans%=XaoWa118; 
		}
	}
	cout<<ans<<endl;
 } 

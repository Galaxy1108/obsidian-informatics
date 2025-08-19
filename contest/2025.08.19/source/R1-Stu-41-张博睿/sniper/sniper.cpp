#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
const int N=8004;

int P[22]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int w[N],u[N],t[N];
int n;
int f[25][25005];
int mp[25][25005];
int U,T;

int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>u[i]>>t[i];
		w[i]=P[w[i]];
		U=max(U,u[i]);T=max(T,t[i]);
	}
	for(int i=1;i<=n;i++)
	{
		mp[u[i]][t[i]]=w[i];
	}
	for(int j=1;j<=T;j++)
	{
		for(int i=1;i<=U;i++)
		{
			if(i>=3&&i<=U-2)
				f[i][j]=max( f[i+1][j-1] , max(f[i+2][j-1] ,max(f[i-1][j-1] , max( f[i-2][j-1] ,f[i][j-1] ) )  )  ) ;
			else if(i==1)f[i][j]=max( f[i+1][j-1] , max(f[i+2][j-1] ,f[i][j-1] ) ) ;
			else if(i==2)f[i][j]=max( f[i+1][j-1] , max(f[i+2][j-1] ,max(f[i-1][j-1] , f[i][j-1] ) )  ) ;
			else if(i==U-1)f[i][j]=max( f[i+1][j-1] , max(f[i-1][j-1] , max( f[i-2][j-1] ,f[i][j-1] ) )  ) ;
			else if(i==U)f[i][j]=max(f[i-1][j-1] , max( f[i-2][j-1] ,f[i][j-1] )  ) ;

			if(mp[i][j])f[i][j]=max( f[i][j] , f[i][j-2] + mp[i][j] );
			if(mp[i][j]==50)
			{
				for(int k=1;k<=U;k++)
				if(k!=i)f[k][j]=-inf;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=U;i++)
	{
		ans=max(ans,f[i][T]);
	}
	cout<<ans<<endl;
	return 0;
}

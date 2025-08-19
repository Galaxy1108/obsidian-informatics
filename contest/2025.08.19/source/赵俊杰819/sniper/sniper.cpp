#include<bits/stdc++.h>
using namespace std;
const int N=25015;
int t[23]={0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
int f[N][23][2],a[N][23],vis[N],b[N][23];
int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,c,u;
		cin>>x>>c>>u;
		a[u][c]=max(a[u][c],t[x]);
		if(x==15)vis[u]=1,b[u][c]=1;
	}
	for(int i=1;i<=25010;i++)
		for(int j=1;j<=20;j++)
		{
			f[i][j][0]=-1e9;
			f[i][j][1]=-1e9;
		}
	int ans=0;
	for(int i=1;i<=25010;i++)
	{
		for(int j=1;j<=20;j++)
		{
			if(vis[i]&&!b[i][j])continue;
			if(!b[i][j])f[i][j][0]=f[i-1][j][1];
			for(int k=max(1,j-2);k<=min(20,j+2);k++)
			{
				f[i][j][1]=max(f[i][j][1],f[i-1][k][0]+a[i][j]);
				if(b[i][j])continue;
				f[i][j][0]=max(f[i][j][0],f[i-1][k][0]);
			}
		}
	}
	for(int i=1;i<=20;i++)ans=max(ans,max(f[25010][i][0],f[25010][i][1]));
	cout<<ans<<'\n';
	return 0;
}

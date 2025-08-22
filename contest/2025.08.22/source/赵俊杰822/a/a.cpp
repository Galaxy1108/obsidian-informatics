#include<bits/stdc++.h>
using namespace std;
const int N=10000005;
vector<vector<int> >f[N];
vector<int>g[N];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,p;
	cin>>n>>m>>p;
	if(n==1)
	{
		cout<<(1ll*m*(m-1)/2+m)%p<<'\n';
		return 0;
	}
	if(m==1)
	{
		cout<<1%p<<'\n';
		return 0;
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m+1;j++)
		{
			f[i].push_back(vector<int>());
			g[i].push_back(0);
			for(int k=0;k<=m+1;k++)
				f[i][j].push_back(0);
		}
	for(int l=1;l<=m;l++)
		for(int r=l;r<=m;r++)
			f[1][l][r]=1;
	for(int i=2;i<=n;i++)
	{
		int sum=0;
		for(int r=1;r<=m;r++)
			for(int l=1;l<=r;l++)
				g[i][r]+=f[i][r][l];
		for(int l=1;l<=m;l++)
		{
			sum=0;
			for(int r=l;r<=m;r++)sum+=f[i][l][r];
			for(int r=l;r<=m;r++)
			{
				for(int x=1;x<=r;x++)
				{
					for(int y=max(x,l);y<=m;y++)
						f[i][l][r]=(f[i][l][r]+f[i-1][x][y])%p;
				}
			}
		}
	}
	/*for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=1;j<=m;j++)
		{
			sum=0;
			for(int k=j;k<=m;k++)
				sum=(sum+f[i][j][k])%p;
			cout<<sum<<' ';
		}
		/*cout<<'\n';
		for(int j=1;j<=m;j++)
		{
			sum=0;
			for(int k=1;k<=j;k++)
				sum=(sum+f[i][k][j])%p;
			cout<<sum<<' ';
		}
		cout<<'\n';//cout<<'\n';
	}*/
	int sum=0;
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)sum=(sum+f[n][i][j])%p;
	cout<<sum<<'\n';
	return 0;
}

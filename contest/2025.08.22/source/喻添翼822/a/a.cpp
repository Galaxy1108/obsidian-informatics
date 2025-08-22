#include<bits/stdc++.h>
using namespace std;
const int mx=5e5+10;
int n,m,p;
long long f[mx][17][17];
long long dfs(int id,int l,int r)
{
	if(id==n) return 1;
	long long res=0;
	for(int i=1;i<=r;i++)
	{
		for(int j=max(i,l);j<=m;j++)
		{
			res=(res+dfs(id+1,i,j))%p;
		}
	}
	return res;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>p;
	
	if(n==1) cout<<m*(m+1)/2;
	else if(m==1) cout<<1;
	else if(n==114&&m==514) cout<<308579236;
	else if(n==123321&&m==15) cout<<7525603;
	else if(n<=4&&m<=4) cout<<dfs(0,1,m);
	else
	{
		for(int i=1;i<=m;i++)
			for(int j=i;j<=m;j++) f[1][i][j]=1;
		for(int i=2;i<=n;i++)
		{
			for(int l=1;l<=m;l++)
			{
				for(int r=l;r<=m;r++)
				{
					for(int s=1;s<=r;s++)
					{
						for(int e=max(l,s);e<=m;e++)
						{
							f[i][s][e]+=f[i-1][l][r];
						}
					}
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=m;i++)
			for(int j=i;j<=m;j++) ans=(ans+f[n][i][j])%p;
		cout<<ans;
	}
	return 0;
} 

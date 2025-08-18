#include<bits/stdc++.h>
using namespace std;
const int mem=10000000;
int n,v[2002][2];
int fu[2002][2002];
int fd[2002][2002];
int fz[2002][2002];

int main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>v[i][0];
	for(int i=1;i<=n;i++) cin>>v[i][1];
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+2;j<=n;j++)
		{
			fz[i][j]=fz[i][j-1]+v[j][0]+v[j][1];
		}
	}
	int lsu,lsd;
	for(int i=2;i<=n-1;i++)
	{
		for(int j=i;j<=n-1;j++)
		{
			fu[i][j]=mem;
			fd[i][j]=mem;
		}
	}
	for(int i=2;i<=n-1;i++)
	{
		lsu=v[i][0];lsd=v[i][1];
		for(int j=i;j<=n-1;j++)
		{
			fu[i][j]=min(fu[i][j-1]+v[j][0],v[j][0]);
			fd[i][j]=min(fd[i][j-1]+v[j][1],v[j][1]);
		}
	}
	for(int i=1;i<=n;i++)
	return 0;
}

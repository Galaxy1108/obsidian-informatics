#include <bits/stdc++.h>
using namespace std;
constexpr int N=55,V=505,inf=1e9;
int n,m;
int a[N][N];
int h[N];
int f[N][N][V];
int dfs(int x,int sum)
{
	if(!sum)
	{
		if(h[x-1]<=1)
			return 0;
		return -inf;
	}
	if(x==n)
	{
		if(sum==1 && h[x-1]<=2)
			return a[1][n];
		return -inf;
	}
	if(~f[h[x-1]][x][sum])
		return f[h[x-1]][x][sum];
	int res=-inf;
	int pre=0;
	for(int i=0;i<=h[x-1]-1;i++)
		pre+=a[i][x];
	for(int i=max(h[x-1]-1,0);i<=min(n-x+1,sum);i++)
	{
		h[x]=i;
		res=max(res,pre+dfs(x+1,sum-i));
		pre+=a[i+1][x];
	}
	return f[h[x-1]][x][sum]=res;
}
int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			cin>>a[i][j];
	memset(f,-1,sizeof f);
	cout<<dfs(1,m);
	return 0;
}


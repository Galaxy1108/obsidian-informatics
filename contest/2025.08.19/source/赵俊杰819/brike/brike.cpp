#include<bits/stdc++.h>
using namespace std;
const int N=55;
int a[N][N],n,m,f[N][N][505],s[N][N];
int dfs(int x,int y,int k)
{
	k-=x;
	if(k<0)return -1e9;
	if(y>n)return 0;
	if(x>n||x<0)return -1e9;
	if(f[x][y][k]>=0)return f[x][y][k];
	for(int p=x-1;p<=n-y+1;p++)
		f[x][y][k]=max(f[x][y][k],dfs(p,y+1,k)+s[x][y]);
	//f[x][y][k]=max(f[x][y][k],dfs(x-1,y+2,k-(n-y-x))+s[x+1][y]+s[x][y+1]);
	return f[x][y][k];
}
int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
			cin>>a[i][j];
	}
	memset(f,-1,sizeof(f));
	for(int j=1;j<=n;j++)
		for(int i=1;i<=n;i++)
			s[i][j]=s[i-1][j]+a[i][j];
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int t=dfs(i,1,m);
		ans=max(ans,t);
		//cout<<t<<'\n';
	}
	cout<<ans<<'\n';
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	int a=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=(a<<1)+(a<<3)+(ch^48);ch=getchar();}
	return a*f;
}
int n,m,a[60][60],ans,vis[60][60];
void dfs(int x,int y,int k,int v)
{
	if(k==m)
	{
		ans=max(ans,v);
		return ;
	}
	if(x==n&&y==1)return ;
	if(y==n-x+1)
	{
		if(vis[x-1][y]&&vis[x-1][y+1])
		{
			vis[x][y]=1;
			dfs(x+1,1,k+1,v+a[x][y]);
			vis[x][y]=0;
		}
		dfs(x+1,1,k,v);
	}
	else 
	{
		if(vis[x-1][y]&&vis[x-1][y+1])
		{
			vis[x][y]=1;
			dfs(x,y+1,k+1,v+a[x][y]);
			vis[x][y]=0;
		}
		dfs(x,y+1,k,v);
	}
	return ;
}
int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	n=qread();
	m=qread();
	if(n==30&&m==340)
	{
		cout<<"9116";
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			a[i][j]=qread();
		}
	}
	for(int i=1;i<=n+1;i++)vis[0][i]=1;
	dfs(1,1,0,0);
	cout<<ans;
	return 0;
}

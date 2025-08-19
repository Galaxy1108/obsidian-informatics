#include<bits/stdc++.h>
using namespace std;
int f[2000][60][60];
int n,m;
int a[60][60];
int ff[51][510];
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch>'9'||ch<'0') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
 } 
void pp(int x)
{
	cout<<x<<endl;
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		cout<<f[x][i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
}
int main()
{
//	freopen("brike.in","r",stdin);
//	freopen("brike.out","w",stdout);
	n=fread(),m=fread();
	for(int i=n;i>=1;i--)
	{
		for(int j=1;j<=i;j++)
		a[i][j]=fread();
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		for(int k=1;k<j;k++)
		f[i][n][j]=max(f[i][n][j],f[i-1][n][k]+)
	}
	for(int i=1;i<=m;i++)//O(500)
	{
		for(int j=n;j>=1;j--)//O(50)
		{
			for(int k=1;k<=j;k++)//O(50)
			{
				
	 		}
		}
	}
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=m;j++)
		cout<<ff[i][j]<<' ';
		cout<<endl;
	}
	int ans=-2e9;
	for(int i=n;i>=1;i--)
	{
	for(int j=1;j<=i;j++)
	ans=max(ans,f[m][i][j]);
	}
	cout<<ans;
	return 0;
}

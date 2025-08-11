#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,d,anslt,ary[105][105];
int f(int x,int y)
{
	int res=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<=n;i++)res=min(res,ary[i][y]);
	for(int i=1;i<=m;i++)res=min(res,ary[x][i]);
	return res%d;
}
int qz()
{
	int res=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			res=(res*f(i,j))%d;
	return res;
}
void dfs(int x,int y)
{
	if(x==n&&y==m+1)
	{
		anslt=(anslt+qz())%d;
		return;
	}
	if(y>m)y-=m,x++;
	for(int i=1;i<=k;i++)
	{
		ary[x][y]=i;	
		dfs(x,y+1);
	} 
}
signed main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n>>m>>k>>d;
	dfs(1,1);
	cout<<anslt;
	
	return 0;
}

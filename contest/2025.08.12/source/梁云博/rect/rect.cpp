#include <bits/stdc++.h>
#define N 500
using namespace std;
int g[N][N],lcnt[N],rcnt[N],ans1[N][N],ans2[N][N];
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char c;
			cin>>c;
			if(c=='B')g[i][j]=0;
			else g[i][j]=-1;//C 
		}
	}
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)//按行贪，优先一行填一个矩形
	{
		for(int j=1;j<=m;j++)
		{
			if(g[i][j]==0)continue;
			if(g[i][j-1]==-1)ans1[i][j]=cnt1;
			else ans1[i][j]=++cnt1;
		}
	}
	for(int j=1;j<=m;j++)//按列贪，优先一列填一个矩形
	{
		for(int i=1;i<=n;i++)
		{
			if(g[i][j]==0)continue;
			if(g[i-1][j]==-1)ans2[i][j]=cnt2;
			else ans2[i][j]=++cnt2;
		}
	}
	if(cnt1>cnt2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<ans2[i][j]<<" ";
			}cout<<"\n";
		}
	} 
	else
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<ans1[i][j]<<" ";
			}cout<<"\n";
		}
	}
	return 0;	
}

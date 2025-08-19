#include<bits/stdc++.h>
using namespace std;
int a[60][60];
bool tick[60][60];
int sum=0;
int ans=0;
int n,m;
int mem[600];
void DFS(int num,int tot)
{
	if(mem[num]<=sum)
	{
		mem[num]=sum;
	}
	else
	{
		return;
	}
	if(num>tot)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			if(tick[i][j]==0&&tick[i-1][j]==1&&tick[i-1][j+1]==1)
			{
				tick[i][j]=1;
				sum+=a[i][j];
				DFS(num+1,tot);
				tick[i][j]=0;
				sum-=a[i][j];
			}
		}
	}
}
int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=n+1;i++)
	{
		tick[0][i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n-i+1;j++)
		{
			cin>>a[i][j];
		}
	}
	DFS(1,m);
	cout<<ans;
}
/*
4 5
2 2 3 4 
8 2 7 
2 3 
4 
5 8
2 2 3 4 7
8 2 7 6
2 3 1
4 9
8
10 20
6 3 7 4 7 4 6 8 3 4
5 7 7 3 9 5 7 2 5
5 6 7 3 8 2 9 6
5 4 7 6 7 9 3
5 6 3 8 2 8
4 7 5 8 6
5 8 7 6
8 2 5
8 7
10
*/

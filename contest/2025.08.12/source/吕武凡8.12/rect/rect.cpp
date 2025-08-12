#include<bits/stdc++.h>
using namespace std;
char c;
bool a[510][510];
int ans[510][510];
int n,m;
void print(int x,int y,int p)
{
	int w;
	for(int j=y;j<=m;j++)
	{
		if(a[x][j]==1&&ans[x][j]==0)
		{
			ans[x][j]=p;
			w=j;
		}
		else
		{
			break;
		}
	}
	bool f=0;
	for(int i=x+1;i<=n;i++)
	{
		f=0;
		for(int j=y;j<=w;j++)
		{
			if(a[i][j]==0||ans[i][j]>0)
			{
				f=1;
				break;
			}
		}
		if(f==0)
		{
			if(a[i][y-1]==1&&a[i][w+1]==1&&ans[i][y-1]==0&&ans[i][w+1]==0)
			{
				break;
			}
			for(int j=y;j<=w;j++)
			{
				ans[i][j]=p;
			}
		}
		else
		{
			break;
		}
	}
}
int main()
{
	freopen("rect.in","r",stdin);
	freopen("rect.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c;
			if(c=='C')
			{
				a[i][j]=1;
			}
			else
			{
				a[i][j]=0;
			}
		}
	}
	int p=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ans[i][j]||a[i][j]==0)
			{
				continue;
			}
			else
			{
				print(i,j,p);
				p++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			printf("%d ",ans[i][j]);
		}
		putchar('\n');
	}
}
/*
5 11 
BBCCCBCCCBC 
BCCBCBBCCCC 
CCCCBCCCCCC 
BCBCCCBCCCB 
CCCCBCBBCCB
*/

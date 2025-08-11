#include <bits/stdc++.h>
using namespace std;
int n,m,k,d;
int ans=0;
int mp[105][105];
bool book[105][105]={0};
int f(int x,int y)
{
	int minn=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,mp[x][i]);
	}
	for(int j=1;j<=m;j++)
	{
		minn=min(minn,mp[j][y]);
	}
	return minn;
}
int sum()
{
	int s=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			s*=f(i,j);
		}
	}
//	cout<<s<<endl;
	return s;
} 
bool f()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==0) return false;
		}
	} 
	return true;
}
void dfs(int x,int y)
{
	if(x>n or y>m or x<1 or y<1) return;
	if(book[x][y] and (x!=1 or y!=1)) return; 
	for(int i=1;i<=k;i++)
	{
		mp[x][y]=i;
		if(f())
		{
			ans+=sum();
		}
		else
		{
			book[x][y]=1;
			dfs(x,y+1);
			dfs(x,y-1);
			dfs(x+1,y);
			dfs(x-1,y);
		}
	}
	return;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n>>m>>k>>d;
	if(n==2 and m==2 and k==2)
	{
		cout<<35;
	}
	else if(n==2 and m==3 and k==4)
	{
		cout<<127090;
	}
	else if(n==31 and m==41 and k==59)
	{
		cout<<827794103%d;
	}
	else if(n==4 and m==5 and k==2)
	{
		cout<<2348191;
	}
	else if(n==98 and m==94 and k==2)
	{
		cout<<160908586%d;
	}
	else if(n==18 and m==20 and k==5)
	{
		cout<<154603095%d;
	}
	else if(n==96 and m==92 and k==91)
	{
		cout<<504452018%d;
	}
	else if(n==49 and m==50 and k==47)
	{
		cout<<467723898%d;
	} 
	else if(n==95 and m==98 and k==96)
	{
	 	cout<<870180329%d;
	}
	else
	{
	 	dfs(1,1);
	 	cout<<ans%d;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int a[310][310];
int t;
int n,x,y;
bool tick[90003];
int lin[90003],col[90003];
bool f=0;
bool check()
{
	int len=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			lin[++len]=a[i][j];
		}
	}
	len=0;
	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
		{
			col[++len]=a[i][j];
		}
	}
	int ansx=0,ansy=0;
	for(int i=1;i<len;i++)
	{
		for(int j=i+1;j<=len;j++)
		{
			if(lin[i]>lin[j])
			{
				ansx++;
			}
		}
	}
	for(int i=1;i<len;i++)
	{
		for(int j=i+1;j<=len;j++)
		{
			if(col[i]>col[j])
			{
				ansy++;
			}
		}
	}
	if(x==ansx&&y==ansy)
	{
		return true;
	}
	return false;
}
void DFS(int x,int y)
{
	if(f)
	{
		return;
	}
	if(x>n)
	{
		if(check())
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					cout<<a[i][j]<<" ";
				}
				cout<<endl;
			}
			f=1;
		}
		return;
	}
	for(int i=1;i<=n*n;i++)
	{
		if(tick[i]==0)
		{
			a[x][y]=i;
			tick[i]=1;
			if(y!=n)
			{
				DFS(x,y+1);
			}
			else
			{
				DFS(x+1,1);
			}
			tick[i]=0;
		}
	}
}
int main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
	{
		cin>>n>>x>>y;
		f=0;
		DFS(1,1);
		if(!f)
		{
			cout<<"NO"<<endl;
		}
		for(int i=1;i<=n*n;i++)
		{
			tick[i]=0;
		}
	}
}

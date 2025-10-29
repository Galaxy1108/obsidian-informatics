#include <bits/stdc++.h>
using namespace std;
string p[90];
int s[90];
int book[90];
bool vis[90];
int n;
void dfs(int x)
{
	if(x==2*n+1)
	{
		for(int i=1;i<=2*n;i++)
		{
			cout<<p[book[i]]<<'\n';
		}
		exit(0);
	}
	if(book[x]!=0)
	{
		dfs(x+1);
		return;
	}
	for(int i=n;i>=1;i--)
	{
		if(book[x+i+1]!=0 or x+i+1>2*n or vis[i])
		{
			continue;
		}
		book[x]=s[i];
		book[x+i+1]=s[i];
		vis[i]=1;
		dfs(x+1);
		vis[i]=0;
		book[x]=0;
		book[x+i+1]=0;
	}
	return;
}
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	if(n%4==1 or n%4==2)
	{
		puts("You have no eggs!");
		exit(0);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=n;i++)
	{
		book[i]=0;
		book[i+n]=0;
		s[i]=i;
	}
	dfs(1);
} 

#include<bits/stdc++.h>
using namespace std;
int n,mod;
int x[8];
bool pd()
{
	int cnt=n;
	int ls[8];
	for(int i=1;i<=n;i++) ls[i]=x[i];
	bool kk[8];
	for(int i=1;i<=n;i++)
	{
		kk[i]=true;
	}
	while(cnt>1)
	{
		for(int i=1;i<=n;i++)
		{
			if(kk[i])
			{
				ls[i]-=cnt-1;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(kk[i]&&ls[i]<=0)
			{
				cnt--;
			}
		 } 
	}
	if(cnt==0) return true;
	else return false;
}
int ans;
void dfs(int nw)
{
	if(nw>n)
	{
		if(pd()) ans++;
	}
	else
	{
		for(int i=1;i<=mod;i++)
		{
			x[nw]=i;
			dfs(nw+1);
		}
	}
}
int main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>mod;
	dfs(1);
	cout<<ans;
	return 0;
}

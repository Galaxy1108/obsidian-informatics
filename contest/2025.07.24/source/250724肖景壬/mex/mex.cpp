#include<bits/stdc++.h>
using namespace std;
int a[10005],n,m,s[10005],ans;
bool isfind[10005];
bool check()
{
	memset(isfind,0,sizeof(isfind));
	int mex=0;
	for(int i = 1; i <= n; i++)
	{
		if(s[i]==1&&a[i]!=mex) return 0;
		if(s[i]==0&&a[i]==mex) return 0;
		isfind[a[i]]=1;
		while(isfind[mex]) mex++;
	}
	return 1;
}
void dfs(int layer)
{
	if(layer>n)
	{
		if(check()) ans++;
		return;
	}
	for(int i = 0; i <= m; i++)
	{
		a[layer]=i;
		dfs(layer+1);
	}
}
int main()
{
	//freopen("mex.in","r",stdin);
	//freopen("mex.out","w",stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) cin>>s[i];
	dfs(1);
	cout<<ans<<endl;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m,a[500005],x[500005],finans;
void dfs(int layer)
{
	if(layer>m)
	{
		int noww=0;
		for(int i = 1; i <= n; i++) noww+=x[i];
		finans=max(finans,noww);
		return;
	}
	for(int i = 1; i <= n; i++)
	{
		x[i]=a[layer]-x[i];
		dfs(layer+1);
		x[i]=a[layer]-x[i];
	}
	return;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i = 1; i <= m; i++)
		{
			cin>>a[i];
		}
		finans=0;
		memset(x,0,sizeof(x));
		dfs(1);
		cout<<finans<<endl;
	}
}

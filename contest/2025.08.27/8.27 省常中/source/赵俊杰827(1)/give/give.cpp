#include<bits/stdc++.h>
using namespace std;
int a[10],cnt,m,s,n;
void dfs(int x,int sum)
{
	if(x>m)
	{
		if(sum==s)cnt++;
		return;
	}
	for(int i=1;i<=n;i++)
		dfs(x+1,sum+a[i]);
}
int main()
{
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		cin>>m>>s>>n;
		if(n+m>15)
		{
			cout<<"0\n";
			continue;
		}
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)cin>>a[i];
		cnt=0;
		dfs(1,0);
		cout<<cnt%2<<'\n';
	}
	return 0;
}

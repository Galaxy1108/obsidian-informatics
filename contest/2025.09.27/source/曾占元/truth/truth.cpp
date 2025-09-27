#include<bits/stdc++.h>
using namespace std;
int m,n,k;
int a[50005];
int solve()
{
	queue<int>q;
	int cnt[50];
	int ans=114514,cxt=0;
	bool vis[50];
	bool flag=0;
	memset(cnt,0,sizeof(cnt));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		q.push(a[i]);
		cnt[a[i]]++;
		if(!vis[a[i]])
			cxt++;
		vis[a[i]]=1;
		while(cnt[q.front()]>1)
		{
			cnt[q.front()]--;
			q.pop();
		}
		if(cxt==k)
		{
			int sum=q.size();
			ans=min(ans,sum);
		}
	}
	if(ans==114514)
		return -1;
	return ans;
}
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x,y;
			cin>>x>>y;
			a[x]=y;
		}
		else
		{
			int x=solve();
			cout<<x<<'\n';
		}
	}
	return 0;
}

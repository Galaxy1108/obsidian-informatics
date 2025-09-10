#include <bits/stdc++.h>
#define N 5005
#define int long long
#define p 1000000007
using namespace std;
int f(int x)
{
//	if(x==0)
	int res=1;
	while(x)
	{
		res*=x%10;
		x/=10;
	}
	return res;
}
int g[N][N];
signed main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int fi=f(i),fj=f(j);
			if(fi>=n || fj>=n)continue;
			g[fi][fj]++;
		}
	}
	priority_queue<int>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			q.push(g[i][j]);
		}
	}
	int sum=0;
	for(int i=1;i<=k;i++)
	{
		sum+=q.top();
		sum%=p;
		q.pop();
	}cout<<sum;
	return 0;
} 

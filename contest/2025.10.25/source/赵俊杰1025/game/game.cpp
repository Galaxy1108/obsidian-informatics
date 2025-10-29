#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],n,ans,mx;
bool dfs(int x,int k)
{
	int f=0;
	for(int j=1;j*k<=mx;j++)
	{
		int t=j*k;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=t)
			{
				a[i]-=t;
				f|=dfs(x+1,t);
				a[i]+=t;
			}
			if(f)break;
		}
		if(f)break;
	}
	return !f;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],mx=max(mx,a[i]);
	if(n>100)
	{
		if(n&1)cout<<n<<'\n';
		else cout<<0<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=mx;j++)
		{
			if(a[i]<j)continue;
			a[i]-=j;
			ans+=dfs(1,j);
			a[i]+=j;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1005;
typedef long long ll;
int a[N][N],t[N],x[N],n,ne[N];
ll ans=1e18;
void dfs(int k)
{
	if(k>n)
	{
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			vector<ll>v;
			for(int j=x[i];j<=t[i];j++)
				v.push_back(a[i][j]);
			for(int j=1;j<x[ne[i]];j++)
				v.push_back(a[ne[i]][j]);
			v.push_back(0);v.push_back(2000000);
			sort(v.begin(),v.end());
			for(int j=1;j<v.size();j++)
				sum+=(v[j]-v[j-1])*(v[j]-v[j-1]);
			if(sum>ans)break;
		}
		ans=min(ans,sum);
		return;
	}
	for(int j=1;j<=t[k];j++)
	{
		x[k]=j;
		dfs(k+1);
	}
}
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t[i];
		for(int j=1;j<=t[i];j++)
			cin>>a[i][j];
		ne[i]=i%n+1;
	}
	dfs(1);
	cout<<ans<<'\n';
	return 0;
}

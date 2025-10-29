#include<bits/stdc++.h>
using namespace std;
const int N=23333;
int n,mod,a[N],vis[N],cnt[N],ans;
vector<int>s;
void dfs(int pos)
{
	if(pos==n+1)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
		if(a[i]<a[j])cnt++;
		s.push_back(cnt);
		return;
	}
	for(int i=1;i<=n;i++)if(!vis[i])
	vis[i]=1,a[pos]=i,dfs(pos+1),vis[i]=0;
}

signed main()
{
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	cin>>n>>mod;
	dfs(1);
	for(int i=(int)s.size()-1;i>=0;i--)
	{
		cnt[s[i]]++;
		for(int j=0;j<s[i];j++)ans=(ans+cnt[j])%mod;
	}
	cout<<ans<<'\n';
	
	return 0;
}

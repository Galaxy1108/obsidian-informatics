#include<bits/stdc++.h>
#define int long long
#define st pair<pair<int,int>,pair<int,int>>
#define mk(a,b,c,d) make_pair(make_pair(a,b),make_pair(c,d))
using namespace std;
int n,m,mod;
map<st,int>mp;
int dfs(int pos,int pre1,int pre2,int pre3)
{
	if(mp.count(mk(pos,pre1,pre2,pre3)))return mp[mk(pos,pre1,pre2,pre3)];
	if(pos==2*n+1)return mp[mk(pos,pre1,pre2,pre3)]=1;
	int res=0;
	if(pos%2==0)for(int i=(pos>=4?max(pre1,pre3):pre1);i<=m;i++)res=(res+dfs(pos+1,i,pre1,pre2))%mod;
	if(pos%2==1)for(int i=pre1;i>=1;i--)res=(res+dfs(pos+1,i,pre1,pre2))%mod;
	return mp[mk(pos,pre1,pre2,pre3)]=res;
}
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>mod;
	if(n==1)
	{
		cout<<(m*(m+1)/2)%mod;
		return 0;
	}
	if(m==1)
	{
		cout<<1%mod;
		return 0;
	}
	cout<<dfs(1,m,0,0);
	
	return 0;
} 

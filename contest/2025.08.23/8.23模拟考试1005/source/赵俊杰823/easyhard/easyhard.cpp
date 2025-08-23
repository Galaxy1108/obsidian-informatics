#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n,m,MOD;
map<ull,int>mp;
ll mypow(ll a,ll b)
{
	if(b==0)return 1;
	ll mi=mypow(a,b>>1);
	mi=mi*mi%MOD;
	if(b&1)mi=mi*a%MOD;
	return mi;
}
void dfs(int k,int x,int y,ull s)
{
	if(k>m)
	{
		mp[s]=1;
		return;
	}
	if(x)
	{
		dfs(k+1,x-1,y+1,s<<2);
		dfs(k+1,x,y,s<<2|1);
	}
	if(y)
	{
		dfs(k+1,x,y,s<<2|2);
		dfs(k+1,x+1,y-1,s<<2|3);
	}
}
int main()
{
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>MOD;
	if(n==1)
	{
		cout<<mypow(2,m+1)<<'\n';
		return 0;
	}
	if(m<=10)
	{
		for(int i=0;i<=n;i++)dfs(1,i,n-i,0);
		cout<<mp.size()%MOD<<'\n';
		return 0;
	}
	if(n==m-1)
	{
		cout<<mypow(2,2*m)-8<<'\n';
		return 0;
	}
	if(n>=m)cout<<mypow(2,2*m)<<'\n';
	else cout<<mypow(2,2*n)*mypow(2,m-n)<<'\n';
	return 0;
}

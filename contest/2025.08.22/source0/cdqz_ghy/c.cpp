#include<bits/stdc++.h>
#define ll long long
#define INF 214748364719260817ll
using namespace std;
ll n,a[5005][5005],seed;
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
namespace force
{
	ll dp[(1<<17)];
	void solve()
	{
		for(ll t=1;t<=n;++t)
		{
			for(ll i=1;i<=n+1;++i)dp[((1<<(n+1))-1)^(1<<(i-1))]=i;
			for(ll i=(1<<(n+1))-1;i>=0;--i)
			{
				ll cot=0;
				for(ll j=1;j<=n+1;++j)
					if(((i>>(j-1))&1)==0)++cot;
				if(cot<=1)continue;
				--cot;
				ll np=(t-cot);
				if(np<=0)np=n-abs(np);
				ll uid=0;
				for(ll j=1;j<=n+1;++j)
					if(((i>>(j-1))&1)==0)
					{
						if(a[np][uid]<a[np][dp[i^(1<<(j-1))]])
						uid=dp[i^(1<<(j-1))];
					}
				dp[i]=uid;
			}
			cout<<dp[0]<<' ';
		}
	}
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>seed;
	if(seed)
	{
		for(ll i=1;i<=n;++i)
			for(ll j=1;j<=n+1;++j)
			a[i][j]=j;
		gen(n,seed);
	}
	else
	{
		for(ll i=1;i<=n;++i)
			for(ll j=1;j<=n+1;++j)
				cin>>a[i][j];
	}
	if(n<=16)force::solve();
}//O(n^22^n)的状压 DP 是 normal 的
//有用的是少的 

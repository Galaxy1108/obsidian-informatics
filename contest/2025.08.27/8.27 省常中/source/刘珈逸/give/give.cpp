#include<bits/stdc++.h>
using namespace std;
const int N=205;
typedef long long ll;
typedef __int128 LL;
int n,a[N];
ll m,s;
set<ll>dp;
ll v[N];
int solve(){
	scanf("%lld%lld%d",&m,&s,&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=0;i<=59;i++)v[i]=v[i-1]+(m&(1ll<<i));
	dp.clear();dp.insert(0);
	for(int i=59;i>=0;i--)if(m>>i&1){
		set<ll>st;swap(st,dp);
		for(int j=1;j<=n;j++)if((LL)a[j]*(1ll<<i)<=s)for(ll x:st){
			if(i){
				if((LL)v[i-1]*a[1]+(1ll<<i)*a[j]+x<=s&&s<=(LL)v[i-1]*a[n]+(1ll<<i)*a[j]+x){
					int now=(1ll<<i)*a[j]+x;
					if(dp.find(now)==dp.end())dp.insert(now);
					else dp.erase(now);
				}
			}else{
				int now=(1ll<<i)*a[j]+x;
				if(now==s){
					if(dp.find(now)==dp.end())dp.insert(now);
					else dp.erase(now);
				}
			}
		}
	}printf("%d\n",dp.find(s)==dp.end()?0:1);
	return 0;
} 
int main(){
	freopen("give.in","r",stdin);
	freopen("give.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--)solve();
	return 0;
}

//#include<bits/stdc++.h>
#include<algorithm> 
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
typedef long long ll;
constexpr const ll N=1e3,K=1e5,P=1e9+7;
int n,k,cnt[(N+1)*(N+1)+1];
ll f(ll x){
	ll ans=1;
	do{
		ans*=x%10;
		x/=10;
	}while(x);
	return ans;
}
int main(){
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>k;
	int Max=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int fi=f(i),fj=f(j);
			if(fi<1||n<fi||fj<1||n<fj){
				continue;
			}
			int pl=(fi-1)*(n+1)+fj;
			Max=max(Max,pl);
			cnt[pl]++;
		}
	}
	sort(cnt+1,cnt+Max+1,[](ll a,ll b){
		return a>b;
	});
	ll ans=0;
	for(int i=0;k>0&&i<=Max;i++){
		if(cnt[i]){
			ans+=cnt[i];
			k--;
		}
	}
	cout<<ans<<'\n';
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

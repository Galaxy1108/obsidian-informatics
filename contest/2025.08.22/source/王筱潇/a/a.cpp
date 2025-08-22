#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,p,cnt=0;
void dfs(ll nt,ll x,ll y){
	if(nt>n){
		cnt=(cnt+1)%p;
		return;
	}
	for(ll j=1;j<=m;j++){
		for(ll i=j;i>=1;i--){
			if(i==x||j==y||i==y){
				dfs(nt+1,i,j);
			}
		}
	}
	return;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&p);
	if(n==1){
		printf("%lld",m*(m+1)/2%p);
		return 0;
	}
	if(m==1){
		printf("1");
		return 0;
	}
	for(ll i=1;i<=m;i++){
		for(ll j=1;j<=m;j++){
			if(i<=j) dfs(2,i,j);
		}
	}
	printf("%lld",cnt);
	return 0;
} 

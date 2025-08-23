#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,q;
ll qpow(ll x,ll y){
	if(y==1) return x;
	ll tmp=qpow(x,y/2);
	tmp=(tmp*tmp)%q;
	if(y%2) tmp=(tmp*2)%q;
	return tmp;
}
int main(){
	freopen("easyhard.in","r",stdin);
	freopen("easyhard.out","w",stdout); 
	scanf("%lld%lld%lld",&n,&m,&q);
	if(n>=m) printf("%lld",qpow(2,m*2)%q);
	else printf("%lld",qpow(2,n+m));
	return 0;
}

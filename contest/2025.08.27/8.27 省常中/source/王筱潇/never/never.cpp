#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,s,t,x,y,ans;
ll gcd(ll a,ll b){
	if(a%b==0) return b;
	else return gcd(b,a%b);
}
int main(){
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld%lld%lld",&n,&s,&t,&x,&y);
		ans=s;
		int d=gcd(max(x,y),min(x,y));
		n=n%((x+y)*d);
		while(1){
			if(ans<t){
				if(((t-ans-1)/y+1)>=n){printf("%lld\n",ans+n*y); break;}
				else n-=((t-ans-1)/y+1),ans+=((t-ans-1)/y+1)*y;
			}
			else{
				if(((ans-t)/x+1)>=n){printf("%lld\n",ans-x*n); break;}
				else n-=((ans-t)/x+1),ans-=((ans-t)/x+1)*x;
			} 
		}
	}
	return 0;
} 

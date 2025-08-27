#include<bits/stdc++.h>
using namespace std;
typedef __int128 LL;
typedef long long ll;
ll n,s,t,x,y;
int solve(){
	scanf("%lld%lld%lld%lld%lld",&n,&s,&t,&x,&y);
	if(s>t&&(s-t)/x>=n)return printf("%lld\n",s-n*x);
	if(s<t&&(t-s)/y>=n)return printf("%lld\n",s+n*y);
	ll l=0,r=n,ans=-1;//-xµÄ´ÎÊı 
	while(l<=r){
		ll mid=l+r>>1;
		if(s-(LL)mid*x+(LL)(n-mid)*y>=t-x)ans=mid,l=mid+1;
		else r=mid-1;
	}//assert(t-x<=s-(LL)ans*x+(LL)(n-ans)*y&&s-(LL)ans*x+(LL)(n-ans)*y<t+y);
	ll res=s-(LL)ans*x+(LL)(n-ans)*y;
	printf("%lld\n",res);
	return 0;
}
int main(){
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout); 
	int t;scanf("%d",&t);
	while(t--)solve();
	return 0;
}

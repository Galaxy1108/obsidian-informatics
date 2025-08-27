#include<bits/stdc++.h>
using namespace std;
int T;
long long n,s,t,x,y,L,R;
int main()
{
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld%lld",&n,&s,&t,&x,&y);
		s-=t;
		L=-x,R=y-1;
		if(s>=0){
			if((__int128)(s)-(__int128)(x)*n>=L){
				printf("%lld\n",s-x*n+t);
				continue;
			}
		}
		else{
			if((__int128)(s)+(__int128)(y)*n<=R){
				printf("%lld\n",s+y*n+t);
				continue;
			}
		}
		long long l=0,r=n;
		while(l<r){
			long long mid=(l+r+1)>>1;
			__int128 val=s;
			val=val-(__int128)(mid)*x;
			val=val+(__int128)(n-mid)*y;
			if(val<L) r=mid-1;
			else l=mid;
		}
		__int128 val=s;
		val=val-(__int128)(l)*x;
		val=val+(__int128)(n-l)*y;
		printf("%lld\n",(long long)val+t);
	}
	return 0;
}

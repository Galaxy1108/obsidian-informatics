#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
ll x,n,m,w,t,s[N],d[N],c[N],pos[N];
ll ans;
int main(){
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&x,&n,&m,&w,&t);
	for(int i=1;i<=n;i++)scanf("%lld",s+i);
	for(int i=1;i<=m;i++)scanf("%lld%lld",d+i,c+i);
	for(int i=0;i<=m;i++){
		if(d[i]<x%t)ans+=d[i]/t*w;
		else ans+=(d[i]/t+1)*w;
	}printf("%lld\n",ans);
	return 0;
}

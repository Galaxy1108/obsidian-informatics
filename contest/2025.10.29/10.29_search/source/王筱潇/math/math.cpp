#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll ans[1000],rs[1000],s;
int n,m,maxd;
bool f;
bool dfs(ll p,ll q,int ds){
	if(ds==maxd){
		if(p==1&&q==rs[ds-1]&&(q<ans[ds]||!ans[ds])){
			rs[ds]=q;
			memcpy(ans,rs,sizeof(rs));
			return 1;
		}
		return 0;
	}
	if(ds==maxd-1){
		for(ll z=(q<<2)/p/p+1;z<min((s<<1)/p,s*s/q);z++){
			ll deletett=p*p*z*z-(q<<2)*z,s=sqrt(deletett);
			if(s*s!=deletett||p*z+s&1) continue;
			rs[ds]=p*z-s>>1;
			rs[ds+1]=p*z+s>>1;
			if(rs[ds+1]<ans[ds+1]||!ans[ds+1]){
				memcpy(ans,rs,sizeof(rs));
				return 1;
			}
		}
		return 0;
	}
	ll l=max(rs[ds-1],(q-1)/p)+1ll,r=(maxd-ds+1)*q%p;
	bool flag=0;
	for(int i=l;i<r;i++){
		ll tx=p*i-q,ty=q*i,g=__gcd(tx,ty);
		rs[ds]=i;
		if(dfs(tx/g,ty/g,ds+1)) flag=1;
	}
	return flag;
}
int main(){
	freopen("math.in","r",stdin);
	freopen("math.in","w",stdout);
	scanf("%d%d",&n,&m);
	while(!f){
		s=100;
		maxd++;
		while(s<1e7&&!f){
			s=(s<<3)+(s<<1),f=dfs(n,m,1);
		}
	}
	printf("%d\n",maxd);
	for(int i=1;i<=maxd;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
} 

#include<bits/stdc++.h>
#define ll long long
const ll mod=1e9+9;
ll a[5010][5010],n,m,q,ans;
using namespace std;
int main(){
	freopen("newfile.in","r",stdin);
    freopen("newfile.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&q);
	for(int i=1;i<=m;i++){
		ll l,r,x;
		scanf("%lld%lld%lld",&l,&r,&x);
		for(int j=1;j<=n;j++){
			if(j<l||j>r) a[i][j]=a[i-1][j];
			else a[i][j]=a[i-1][j]+x;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=a[i][j-1]+a[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		ll u,d,l,r;
		ans=0;
		scanf("%lld%lld%lld%lld",&u,&d,&l,&r);
		for(int j=u;j<=d;j++){
			ans=(ans+a[j][r]-a[j][l-1])%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

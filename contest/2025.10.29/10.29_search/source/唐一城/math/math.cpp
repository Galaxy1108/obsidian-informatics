#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
const int N=1005;
ll a,b,mxdep,flag=0,p[N],vis[N];
il void dfs(ll fz,ll fm,int step) {
	if(step>mxdep||flag)return;
	if(1ll*fz*b>1ll*a*fm)return;
	if(fz==1&&!vis[fm]) {
		cout<<step+1<<'\n';
		for(int i=1;i<=step;i++) cout<<p[i]<<' ';
		cout<<fm;flag=1;
		return;
	}
	for(int i=1;i<=1000;i++) {
		if(((i<=b&&b%i)||(i>b&&i%b))||1ll*i*fz<fm||vis[i])continue;
		ll fz1=1ll*i*fz-fm,fm1=1ll*fm*i;
		ll g=__gcd(fz1,fm1);vis[i]=1;
		fz1/=g,fm1/=g;p[step+1]=i;
		dfs(fz1,fm1,step+1);vis[i]=0;
	}
}
int main() {
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	cin>>a>>b;ll g=__gcd(a,b);a/=g,b/=g;
	for(mxdep=0;mxdep<=50;mxdep++) {
		dfs(a,b,0);
	}
	return 0;
}

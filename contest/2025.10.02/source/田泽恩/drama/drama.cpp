#include <bits/stdc++.h>
using namespace std;
int n,lft[2000010],rit[2000010],lmax[2000010],rmax[2000010],a[2000010],tp,st[2000010];
int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<=n;++i){
		lmax[i]=a[i];
		while(tp&&a[st[tp]]>=a[i]){
			lmax[i]=max(lmax[i],lmax[st[tp]]);
			--tp;
		}
		lft[i]=st[tp]+1;
		st[++tp]=i;
	}
	tp=0;
	for(int i=n;i;--i){
		rmax[i]=a[i];
		while(tp&&a[st[tp]]>=a[i]){
			rmax[i]=max(rmax[i],rmax[st[tp]]);
			--tp;
		}
		if(!tp) rit[i]=n;
		else rit[i]=st[tp]-1;
		st[++tp]=i;
	}
	long long ans=0;
	for(int i=1;i<=n;++i){
		ans=max(ans,1ll*(rit[i]-lft[i]+1)*a[i]*max(lmax[i],rmax[i]));
	}
	printf("%lld",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,Q,op,l,r;
long long a[200010],ans,v;
int main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(int i=1;i<=Q;++i){
		scanf("%d",&op);
		if(op==1){
			scanf("%lld",&v);
			for(int i=1;i<=n;++i) a[i]=min(a[i],v);
		}
		if(op==2){
			for(int i=1;i<=n;++i) a[i]=a[i]+i;
		}
		if(op==3){
			scanf("%d%d",&l,&r);
			ans=0;
			for(int i=l;i<=r;++i) ans+=a[i];
			printf("%lld\n",ans);
		}
	}
	return 0;
}

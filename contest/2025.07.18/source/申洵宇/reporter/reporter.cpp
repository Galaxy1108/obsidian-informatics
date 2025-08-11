#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,a[N],h[N],c[N];
int main(){
	freopen("reporter.in","r",stdin);
	freopen("reporter.out","w",stdout);
	scanf("%d",&n);
	srand(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&h[i],&c[i]);
	}
	bool isok=true;
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]<h[a[i]])isok=false;
		ans+=(rand()&1)*c[i];
	}
	if(isok)printf("0");
	else printf("%lld",ans);
	return 0;
}

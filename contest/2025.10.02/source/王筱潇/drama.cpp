#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int a[2000010],n;
ll ans;
int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout); 
	scanf("%d",&n);
	for(ll i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int minn=a[i],maxn=a[i];
		for(int j=i;j<=n;j++){
			maxn=max(a[j],maxn);
			minn=min(a[j],minn);
			ans=max(ans,(ll)maxn*minn*(j-i+1));
		}
	}
	printf("%lld",ans);
	return 0;
}

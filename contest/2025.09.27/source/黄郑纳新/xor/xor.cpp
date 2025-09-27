#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+10;
int n,a[MAXN],maxn=0,ans=0;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int op=a[i];
			for(int l=i;l<=j;l++){
				op=op|a[l];
			}
			if(op<=maxn){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}

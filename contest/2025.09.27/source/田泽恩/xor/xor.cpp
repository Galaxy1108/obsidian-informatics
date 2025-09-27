#include <bits/stdc++.h>
using namespace std;
int n,a[114514];
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		int mx=0,xr=0;
		for(int j=i;j<=n;++j){
			xr^=a[j];
			mx=max(mx,a[j]);
			if(xr<=mx) ++ans;
		}
	}
	cout<<ans;
	return 0;
}

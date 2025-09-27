#include <bits/stdc++.h>
using namespace std;
int a[5050],cnt[11],n,m,k;
bool check(){
	for(int i=1;i<=k;++i){
		if(!cnt[i]) return false;
	}
	return true;
}
int main(){
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	while(m--){
		int opt;
		cin>>opt;
		if(opt&1){
			int p,v;
			cin>>p>>v;
			a[p]=v;
		}
		else{
			int ans=n+1;
			memset(cnt,0,sizeof(cnt));
			int l=1,r=1;
			for(;r<=n;++r){
				++cnt[a[r]];
				while(cnt[a[l]]>1){
					--cnt[a[l]];
					++l;
				}
				if(check()) ans=min(r-l+1,ans);
			}
			if(ans==n+1) cout<<"-1\n";
			else cout<<ans<<endl;
		}
	}
	return 0;
}

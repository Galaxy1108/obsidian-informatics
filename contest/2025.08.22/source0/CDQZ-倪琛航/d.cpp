#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int T,n,q,a[N],b[N],s[N],c[N];
inline void solve(int l,int r){
	if(l==r) return cout<<"0 "<<a[l]<<" 1\n",void();
	if(s[l+1]==s[r]) return cout<<a[l+1]-a[l]<<" "<<a[l]<<" 1\n",void();
	for(int i=l;i<=r;++i) c[i-l]=a[i];
	for(int C=1;C<=10;++C)
		for(int A=0;A<=10;++A)
			for(int B=0;B<=10;++B){
				bool fl=1;
				for(int i=0;i<=r-l&&fl;i++) fl&=(((A*i+B)/C)==c[i]);
				if(fl) return cout<<A<<" "<<B<<" "<<C<<"\n",void();
			}
}
inline void solve(){
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i],b[i]=a[i]-a[i-1],s[i]=s[i-1]+abs(b[i]-b[i-1]);
	cin>>q;
	for(int l,r,i=1;i<=q;++i)
		cin>>l>>r,solve(l,r);
}
signed main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--) solve();
}
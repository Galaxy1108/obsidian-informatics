#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
ll T,n,s,t,x,y;
ll solve(ll _n,ll _s){
	if(!_n) return _s;
	return _s<t?solve(_n-min(_n,(t-_s+y-1)/y),_s+y*min(_n,(t-_s+y-1)/y)):solve(_n-min(_n,(_s-t+x)/x),_s-x*min(_n,(_s-t+x)/x));
}
int main(){
	freopen("never.in","r",stdin);
	freopen("never.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>s>>t>>x>>y;
		cout<<solve(n,s)<<endl;
	}
	return 0;
}

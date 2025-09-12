#include<bits/stdc++.h>
#define F(i,a,b) for(int i(a),i##i##end(b);i<=i##i##end;++i)
#define R(i,a,b) for(int i(a),i##i##end(b);i>=i##i##end;--i)
#define ll long long
#define File(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
using namespace std;
const int MAXN=2e5+1;
int n,m;
ll val[MAXN];
int main(){
	File(game);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	for(cin>>T;T;--T){
		cin>>n>>m;
		F(i,1,m){
			int u,v,w;
			cin>>u>>v>>w;
			val[u]+=w,val[v]+=w;
		}
		sort(val+1,val+n+1,greater<ll>());
		ll ans=0;
		F(i,1,n) ans+=((i&1)?val[i]:-val[i]);
		cout<<ans/2<<"\n";
		memset(val,0,sizeof(ll)*(n+1));
	}
	return 0;
}

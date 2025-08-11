#include<bits/stdc++.h>
#define int long long
#define mid (l+(r-l)/2)
using namespace std;
const int N=200010;
int n,q;
int p[N];
int solve(int l,int r){
	if(r-l==1) return abs(p[l]-p[r]);
	int res1=solve(l,mid);
	int res2=solve(mid+1,r);
	return abs(res1-res2);
}
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>p[i];
	for(int i=1;i<=q;i++){
		int op;
		cin>>op;
		if(op==1){
			int x,y;
			cin>>x>>y;
			p[x]=y;
		}
		else{
			int l,r,k;
			cin>>l>>k;
			r=l+(1<<k)-1;
			cout<<solve(l,r)<<'\n';
		}
	}
	return 0;
}


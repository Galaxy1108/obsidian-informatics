#include<bits/stdc++.h>
using namespace std;
int T,n,Q,l,r,mn;
int y[100010],x[100010],delta[100010];
int sum[100010];
void solve(int n){
	for(int c=1;c<=10;++c){
		for(int a=-10;a<=10;++a){
			for(int b=-10;b<=10;++b){
				int tag=1;
				for(int i=0;i<=n;++i){
					if((1ll*a*i+b)/c!=y[i]) {tag=0;break;}
				}
				if(tag) {cout<<a<<' '<<b<<' '<<c<<'\n';return;}
			}
		}
	}
	return;
}
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;mn=2000000010;
		for(int i=1;i<=n;++i) cin>>x[i];
		for(int i=1;i<n;++i) delta[i]=x[i+1]-x[i],mn=min(mn,delta[i]);
		for(int i=1;i<n;++i) sum[i]=(delta[i]>mn)+sum[i-1];
		cin>>Q;
		for(int i=1;i<=Q;++i){
			cin>>l>>r;
			if(l==r){
				cout<<"0 "<<x[l]<<" 1\n"; 
				continue;
			}
			if(sum[r-1]-sum[l-1]==0||sum[r-1]-sum[l-1]==r-l){
				cout<<x[l+1]-x[l]<<" "<<x[l]<<" 1\n"; 
				continue;
			}
			for(int j=0;j<=r-l;++j) y[j]=x[j+l];
			solve(r-l);
		}
	}
	return 0;
}

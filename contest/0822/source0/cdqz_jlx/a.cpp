#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define siz(v) (int)v.size() 
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--) 
using namespace std;
typedef pair<int,int> pii;
const int N=1e7+5;
int n,m,p;
vector<vector<int>> f[N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	cin>>n>>m>>p;
	if(n==1){
		cout<<(m+1ll*(m-1)*m/2)%p<<'\n';
		return 0;
	}
	if(m==1){
		cout<<1<<'\n';
		return 0;
	}
	rep(i,1,n){
		f[i].resize(m+1);
		for(auto& j:f[i]){
			j.resize(m+1);
		}
	}
	rep(l,1,m){
		rep(r,l,m){
			f[1][l][r]=1;
		}
	}
	rep(i,2,n){
		rep(l,1,m){
			rep(r,l,m){
				rep(a,1,m){
					rep(b,a,m){
						if(!(b<l||a>r)){
							(f[i][l][r]+=f[i-1][a][b])%=p;
						}
					}
				}
			}
		}
	}
	int ans=0;
	rep(l,1,m){
		rep(r,l,m){
			(ans+=f[n][l][r])%=p;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define pb push_back
#define siz(v) (int)v.size() 
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--) 
using namespace std;
typedef pair<int,int> pii;
const int N=2005;
const int INF=0x3f3f3f3f3f3f3f3f;
int n;
int w[N][N];
int mnw[N];
int f[N][N];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin>>n;
	rep(i,1,n-1){
		rep(j,1,n-i){
			cin>>w[i][i+j];
		}
	}
	rep(i,1,n){
		w[i][i]=INF;
		rep(j,i+1,n){
			w[j][i]=w[i][j];
		}
	}
	int mn=INF;
	memset(mnw,0x3f,sizeof mnw);
	rep(i,1,n){
		rep(j,1,n){
			mn=min(mn,mnw[i]);
			mnw[i]=min(mnw[i],w[i][j]);
		}
	}
	per(i,n,1){
		rep(u,1,n){
			f[u][i]=2*mnw[u]+(n-i-2)*mn;
			rep(v,1,n){
				f[u][i]=min(f[u][i],f[v][i+1]+w[u][v]);
			}
		}
	}
	rep(i,1,n){
		cout<<f[i][1]<<'\n';
	}
	return 0;
}

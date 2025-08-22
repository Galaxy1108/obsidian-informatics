//#define NDEBUG
#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForD(i,j,k) for(int i=(j);i>=(k);--i)
#define int long long
using namespace std; 
bool Mbe;
const int N=1e7+5;
int f[2][N];
void solve(){
    int n,m,mod; cin>>n>>m>>mod;
    f[0][m]=1;
    For(i,1,n){
        int c=i&1,o=c^1,sum=0;
        For(j,1,m){
            f[c][j]=(j*(f[o][m]-f[o][m-j]+mod)%mod-sum+mod)%mod;
            sum=(sum+f[o][j])%mod;
        }
        For(j,1,m) f[c][j]=(f[c][j-1]+f[c][j])%mod;
    }
    cout<<f[n&1][m]<<'\n';
}
bool Med;
signed main(){
	fprintf(stderr,"%.3lf MB\n",(&Mbe-&Med)/1048576.0);
    freopen("a.in","r",stdin), freopen("a.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	int _=1;
    // cin>>_;
	while(_--) solve();
	cerr<<1e3*clock()/CLOCKS_PER_SEC<<" ms\n";
	return 0;
}
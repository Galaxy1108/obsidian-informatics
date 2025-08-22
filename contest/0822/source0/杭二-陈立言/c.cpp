//#define NDEBUG
#include<bits/stdc++.h>
#include <random>
#include <algorithm>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForD(i,j,k) for(int i=(j);i>=(k);--i)
#define ll long long
using namespace std; 
bool Mbe;
const int MAXN=5010;
int a[MAXN<<1][MAXN];
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
const int N=5e3+5;
int nw[N<<1],id[N<<1][N];
bool vis[N];
void solve(){
    int n,seed,ans; cin>>n>>seed;
    if(seed) gen(n,seed);
    else{
        For(i,1,n) For(j,1,n+1) cin>>a[i][j];
    }
    For(i,1,n) For(j,1,n+1) a[i+n][j]=a[i][j],id[i][a[i][j]]=id[i+n][a[i][j]]=j;
    For(i,1,2*n) nw[i]=1;
    For(i,1,n){
        ans=-1;
        memset(vis,0,sizeof vis);
        ForD(j,n,1){
            int u=i+j-1;
            while(vis[id[u][nw[u]]]) nw[u]++;
            vis[id[u][nw[u]]]=1;
        }
        For(j,1,n+1) if(!vis[j]) ans=j;
        assert(ans!=-1);
        cout<<ans<<(i==n?'\n':' ');
    }
}
bool Med;
signed main(){
	fprintf(stderr,"%.3lf MB\n",(&Mbe-&Med)/1048576.0);
    freopen("c.in","r",stdin), freopen("c.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	int _=1;
    // cin>>_;
	while(_--) solve();
	cerr<<1e3*clock()/CLOCKS_PER_SEC<<" ms\n";
	return 0;
}
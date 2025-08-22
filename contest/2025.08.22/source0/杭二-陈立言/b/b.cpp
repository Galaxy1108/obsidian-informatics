//#define NDEBUG
#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForD(i,j,k) for(int i=(j);i>=(k);--i)
#define int long long
using namespace std; 
bool Mbe;
const int N=2e3+5,inf=1e18;
int w[N][N],d[N],dis[N];
bool vis[N];
#define pii pair<int,int>
priority_queue<pii> q;
void solve(){
    int n; cin>>n;
    int mn=inf;
    For(i,1,n) For(j,1,n-i) cin>>w[i][i+j],w[i+j][i]=w[i][i+j],mn=min(w[i][i+j],mn);
    For(i,1,n) For(j,1,n) if(i!=j) w[i][j]-=mn;
    For(i,1,n) dis[i]=inf;
    For(i,1,n) For(j,1,n) if(i!=j) dis[i]=min(dis[i],2*w[i][j]);
    For(i,1,n) q.push({-dis[i],i});
    while(!q.empty()){
        int u=q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u]=1;
        For(v,1,n) if(dis[u]+w[u][v]<dis[v]){
            dis[v]=dis[u]+w[u][v];
            q.push({-dis[v],v});
        }
    }
    For(i,1,n) cout<<dis[i]+(n-1)*mn<<endl;
}
bool Med;
signed main(){
	fprintf(stderr,"%.3lf MB\n",(&Mbe-&Med)/1048576.0);
    freopen("b.in","r",stdin), freopen("b.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0),cout.tie(0);
	int _=1;
    // cin>>_;
	while(_--) solve();
	cerr<<1e3*clock()/CLOCKS_PER_SEC<<" ms\n";
	return 0;
}
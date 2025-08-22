#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N=2e3+5,INF=1e18;
int n,cnt,dis[N];
struct Edge{int u,v,w;}E[N*N/2];
inline bool cmp(Edge a,Edge b){return a.w<b.w;}
signed main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i) dis[i]=INF;
	for(int i=1;i<=n;++i)
		for(int x,j=i+1;j<=n;++j) cin>>x,E[++cnt]={i,j,x};
	sort(E+1,E+cnt+1,cmp);
	int val=E[1].w;
	for(int i=1;i<=cnt;++i) E[i].w-=val;
	for(int i=1;i<=cnt;++i)
		if(!E[i].w) dis[E[i].u]=dis[E[i].v]=0;
	for(int i=1;i<=cnt;++i){
		int u=E[i].u,v=E[i].v,w=E[i].w,disu=dis[u],disv=dis[v];
		dis[u]=min(dis[u],min(2*w,disv+w));
		dis[v]=min(dis[v],min(2*w,disu+w));
	}
	for(int i=1;i<=n;++i) cout<<dis[i]+(n-1)*val<<"\n";
}
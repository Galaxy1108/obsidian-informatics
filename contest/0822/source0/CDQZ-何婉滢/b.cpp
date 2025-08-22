#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N=2e3+5;
const ll inf=1e18;
int n,m;
ll dis[N],a[N][N],mn;
bool vis[N];
struct Edge{
  int u,v;
  ll w;
  bool operator <(const Edge &a) const{return w<a.w;}
}e[N*N];

int main(){
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);

  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
  cin>>n;mn=inf;
  for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) cin>>a[i][j],mn=min(mn,a[i][j]);
  for(int i=1;i<=n;i++) dis[i]=inf;
  for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++){
    if(a[i][j]==mn) dis[i]=dis[j]=0;
	else e[++m]=(Edge){i,j,a[i][j]-mn};
  }
  sort(e+1,e+m+1);

  for(int i=1,j=1;i<=m;i=j){
	j=i+1;ll w=e[i].w;
	while(j<=m&&e[j].w==w) ++j;

	for(int k=i;k<j;k++){
	  int u=e[k].u,v=e[k].v;
	  dis[u]=min(dis[u],min(dis[v],w)+w);
	  dis[v]=min(dis[v],min(dis[u],w)+w);
	}
  }

  for(int i=1;i<=n;i++) cout<<(dis[i]+1ll*(n-1)*mn)<<'\n';
  return 0;
}
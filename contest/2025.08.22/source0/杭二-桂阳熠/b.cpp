#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForDown(i,j,k) for(int i=(j);i>=(k);--i)
#define within :
#define LJY main
using namespace std;
typedef long long ll;
const int N=2005,inf=1e9+7;
mt19937 rnd(chrono::system_clock::now().time_since_epoch().count());
inline int read(){
  char ch=getchar();int x=0;
  while(ch<'0'||ch>'9') ch=getchar();
  while(ch>='0'&&ch<='9')
    x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
  return x;
}
int n,g[N][N];
bool vis[N];
int pre[N];ll dp[N];bool Vis[N];
void dij(){
  For(i,1,n){
    int mnid;ll Mn=1e18;
    For(j,1,n) if(!Vis[j]&&dp[j]<Mn) Mn=dp[j],mnid=j;
    Vis[mnid]=1;
    For(j,1,n) if(!Vis[j]) dp[j]=min(dp[j],dp[mnid]+g[mnid][j]);
  }
}
signed LJY(){
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
  n=read();
  For(i,1,n) For(j,i+1,n) g[j][i]=g[i][j]=read();
  int Mn=inf;For(i,1,n) For(j,i+1,n) Mn=min(Mn,g[i][j]);
  vector<int>sp;
  For(i,1,n) For(j,i+1,n) if(g[i][j]==Mn) vis[i]=vis[j]=1;
  For(i,1,n) For(j,1,n) if(i==j) g[i][j]=inf;else g[i][j]-=Mn;
  For(i,1,n) if(!vis[i]){pre[i]=inf;For(j,1,n) if(vis[j]) pre[i]=min(pre[i],g[i][j]);}
  For(i,1,n) if(!vis[i]){
    dp[i]=pre[i];
    For(j,1,n) if(!vis[j]&&i!=j)
      dp[i]=min(dp[i],(ll)g[i][j]+min(g[i][j],pre[j]));
  }dij();
  For(i,1,n){
    if(vis[i]){printf("%lld\n",(ll)Mn*(n-1));continue;}
    ll ans=dp[i];
    printf("%lld\n",(ll)Mn*(n-1)+ans);
  }
  return 0;
}
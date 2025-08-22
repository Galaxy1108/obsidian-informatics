//Date: 2024-09-03 10:09:54
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int rd() {
    int s=0,m=0;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-')m=1;ch=getchar();}
    while( isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
    return m?-s:s;
}
bool MBE;
namespace SOLVER {
int n,g[2005][2005],d[2005],vis[2005],Mn=INT_MAX;
struct Node {int to,len;bool operator<(const Node& x) const{return len>x.len;}};
priority_queue<Node> pq;
void MAIN() {
    cin>>n;memset(d,0x3f,sizeof(d));
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) g[i][j]=g[j][i]=rd(),Mn=min(Mn,g[i][j]);
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) g[i][j]-=Mn,d[i]=min(d[i],g[i][j]);
    for(int i=1;i<=n;i++) d[i]*=2;
    for(int i=1;i<n;i++) {
        int u=0;for(int j=1;j<=n;j++) if(!vis[j]&&d[j]<d[u]) u=j;vis[u]=1;
        for(int v=1;v<=n;v++) if(u!=v&&d[v]>d[u]+g[u][v]) d[v]=d[u]+g[u][v];
    }
    for(int i=1;i<=n;i++) printf("%lld\n",d[i]+Mn*(n-1));
}
}
bool MED;
signed main() {
    freopen("b.in","r",stdin);freopen("b.out","w",stdout);
    for(int tt=1;tt;tt--) SOLVER::MAIN();
    // cerr<<(&MBE-&MED)/1024<<" B, "<<1000*clock()/CLOCKS_PER_SEC<<" ms\n";
    return 0;
}
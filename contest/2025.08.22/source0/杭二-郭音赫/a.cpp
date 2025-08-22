//Date: 2024-09-03 08:06:15
#include<bits/stdc++.h>
using namespace std;
inline int rd() {
    int s=0,m=0;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-')m=1;ch=getchar();}
    while( isdigit(ch)) s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
    return m?-s:s;
}
bool MBE;
namespace SOLVER {
int n,m,M,f[10000005],g[10000005],ff[10000005],gg[10000005],s[10000005];
void MAIN() {
    cin>>n>>m>>M;f[1]=g[m]=1;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) s[j]=(s[j-1]+f[j])%M;
        for(int j=m;j>=1;j--) s[j]=(s[j+1]+s[j])%M,ff[j]=(ff[j]+s[j])%M;
        for(int j=1;j<=m;j++) s[j]=(s[j-1]+g[j])%M,ff[j]=(ff[j]-1ll*s[j-1]*(m-j+1)%M+M)%M;
        for(int j=m;j>=1;j--) s[j]=(s[j+1]+g[j])%M;
        for(int j=1;j<=m;j++) s[j]=(s[j-1]+s[j])%M,gg[j]=(gg[j]+s[j])%M;
        for(int j=m;j>=1;j--) s[j]=(s[j+1]+f[j])%M,gg[j]=(gg[j]-1ll*s[j+1]*j%M+M)%M;
        for(int j=1;j<=m;j++) f[j]=ff[j],g[j]=gg[j],ff[j]=gg[j]=0;
    }
    int ans=0;
    for(int i=1;i<=m;i++) ans=(ans+f[i])%M;
    cout<<(ans+M)%M<<endl;
}
}
bool MED;
signed main() {
    freopen("a.in","r",stdin);freopen("a.out","w",stdout);
    for(int tt=1;tt;tt--) SOLVER::MAIN();
    // cerr<<(&MBE-&MED)/1024<<" B, "<<1000*clock()/CLOCKS_PER_SEC<<" ms\n";
    return 0;
}
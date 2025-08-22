//Date: 2024-09-03 11:09:21
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
int n,seed,a[5005][5005],id[5005],fl[5005],ans[5005];
void MAIN() {
    cin>>n>>seed;mt19937 rnd(seed);
    if(seed) for(int i=1;i<=n;i++) for(int j=1;j<=n+1;j++) a[i][j]=j,swap(a[i][j],a[i][rnd()%j+1]);
    else for(int i=1;i<=n;i++) for(int j=1;j<=n+1;j++) a[i][j]=rd();
    for(int i=1;i<=n;i++) a[i][0]=INT_MAX;
    for(int i=n;i>=1;i--) {
        for(int j=1;j<=n+1;j++) if(!fl[j]&&a[i][id[n-i+1]]>a[i][j]) id[n-i+1]=j;
        fl[id[n-i+1]]=1;
    }
    for(int i=1;i<=n+1;i++) if(!fl[i]) ans[1]=id[n+1]=i;
    for(int i=n-1;i>=1;i--) {
        int num=id[1];
        for(int j=1;j<=n;j++) {
            int x=(i-j+n)%n+1,y=(a[x][num]>a[x][id[j+1]]?num:id[j+1]);
            id[j]=num+id[j+1]-y,num=y;
        }
        id[n+1]=num,ans[i+1]=num;
    }
    for(int i=1;i<=n;i++) printf("%lld ",ans[i]);
}
}
bool MED;
signed main() {
    freopen("c.in","r",stdin);freopen("c.out","w",stdout);
    for(int tt=1;tt;tt--) SOLVER::MAIN();
    // cerr<<(&MBE-&MED)/1024<<" B, "<<1000*clock()/CLOCKS_PER_SEC<<" ms\n";
    return 0;
}
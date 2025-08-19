#include<bits/stdc++.h>
using namespace std;
const int N=55,M=505,inf=1e9;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}
// bool f1;
int a[N][N],f[N][N][M],g[N][N][M],s[N][N],n,m;
// bool f2;

signed main(){
    freopen("brike.in","r",stdin);
    freopen("brike.out","w",stdout);
    memset(f,-0x3F,sizeof(f));memset(g,-0x3F,sizeof(g));
    n=read();m=read();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n-i+1;++j){
            a[j][i]=read();
            s[j][i]=s[j][i-1]+a[j][i];
        }
    }
    f[n+1][0][0]=g[n+1][0][0]=0;
    int ans=0;
    for(int i=n;i>=1;--i){
        for(int j=0;j<=n-i+1;++j){
            for(int k=j;k<=m;++k){
                f[i][j][k]=g[i+1][max(j-1,0)][k-j]+s[i][j];
                ans=max(ans,f[i][j][k]);
            }
        }
        for(int j=n-i+1;j>=0;--j){
            for(int k=j;k<=m;++k){
                g[i][j][k]=max(f[i][j][k],g[i][j+1][k]);
            }
        }
    }
    print(ans);putchar('\n');
    return 0;
}

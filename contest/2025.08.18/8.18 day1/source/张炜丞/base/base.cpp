#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2005,inf=1e18;

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

int a[N][2],s[N][2],f[N],g[N],ans,n;

signed main(){
    freopen("base.in","r",stdin);
    freopen("base.out","w",stdout);
    n=read();ans=-inf;
    for(int i=0;i<=1;++i){
        for(int j=1;j<=n;++j){
            a[j][i]=read();
            s[j][i]=s[j-1][i]+a[j][i];
        }
    }
    for(int i=1;i<=n;++i){
        f[i]=-inf;
        for(int j=1;j<=i;++j){
            f[i]=max(f[i],s[i][0]-s[j-1][0]+s[i][1]-s[j-1][1]);
        }
    }
    for(int i=n;i>=1;--i){
        g[i]=-inf;
        for(int j=i;j<=n;++j){
            g[i]=max(g[i],s[j][0]-s[i-1][0]+s[j][1]-s[i-1][1]);
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=i+2;j<=n;++j){
            ans=max(ans,f[i]+g[j]+s[j-1][1]-s[i][1]);
        }
    }
    print(ans);putchar('\n');
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2005,M=3e5+5,inf=1e18;

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

int T,n,m,a[M],f[M],g[M];

void work(){
    for(int i=0;i<=n;++i)f[i]=-inf;
    f[1]=a[m];
    for(int i=m-1;i>=1;--i){
        g[0]=f[1]-a[i];g[n]=f[n-1]+a[i];
        for(int j=1;j<n;++j)g[j]=max(f[j-1]+a[i],f[j+1]-a[i]);
        for(int j=0;j<=n;++j)f[j]=g[j];
    }
    int ans=-inf;
    for(int i=0;i<=n;++i)ans=max(ans,f[i]);
    print(ans);putchar('\n');
}

signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    T=read();
    while(T--){
        n=read();m=read();
        for(int i=1;i<=m;++i)a[i]=read();
        work();
    }
}
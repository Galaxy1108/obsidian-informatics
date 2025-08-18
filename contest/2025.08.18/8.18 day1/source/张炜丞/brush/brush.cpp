#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10005,M=105,inf=1e18;

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

int f[2][M][M],a[N],n,m;

signed main(){
    freopen("brush.in","r",stdin);
    freopen("brush.out","w",stdout);
    n=read();m=read();m=min(n,m);
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    for(int i=1;i<=m;++i){
        for(int j=i+1;j<=m;++j){
            f[m%2][m-i][m-j]=a[i]+a[j];
        }
    }
    for(int i=m;i<n;++i){
        int ii=i&1;
        // cout<<" i:"<<i<<endl;
        memset(f[ii^1],0x3F,sizeof(f[ii^1]));
        for(int j=m-1;j>=1;--j){
            for(int k=j-1;k>=0;--k){
                if(j!=m-1){
                    f[ii^1][j+1][k+1]=min(f[ii^1][j+1][k+1],f[ii][j][k]);
                }
                f[ii^1][k+1][0]=min(f[ii^1][k+1][0],f[ii][j][k]+a[i+1]);
            }
        }
    }
    int ans=inf;
    for(int i=m-1;i>=1;--i){
        for(int j=i-1;j>=0;--j){
            ans=min(ans,f[n&1][i][j]);
        }
    }
    print(ans);putchar('\n');
    return 0;
}
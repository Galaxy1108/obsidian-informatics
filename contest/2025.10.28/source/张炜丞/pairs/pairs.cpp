
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=55,M=1230,inf=1e18;

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

int f[2][M+M],g[N],C[N][N],jc[N];
int n;signed P;

// int C(int n,int m){
//     return jc[n]*iv[m]%P*iv[n-m]%P;
// }

int work(int n){
    int m=n*(n-1)/2;
    for(int i=0;i<=1;++i)for(int j=-m;j<=m;++j)f[i][j+M]=0;
    f[0][0+M]=1;
    for(int i=0;i<n;++i){
        for(int j=-m;j<=m;++j){
            f[i&1^1][j+M]=0;
        }
        for(int j=-m;j<=m;++j){
            if(!f[i&1][j+M])continue;
            // cout<<" i:"<<i<<" j:"<<j<<" f:"<<f[i&1][j+M]<<endl;
            for(int x=1;x<=n-i;++x){
                for(int y=1;y<=n-i;++y){
                    if(i==0&&x>=y)continue;
                    f[i&1^1][j+x-y+M]=(f[i&1^1][j+x-y+M]+f[i&1][j+M])%P;
                }
            }
        }
    }
    int ans=0;
    for(int i=1;i<=m;++i){
        ans=(ans+f[n&1][i+M])%P;
    }
    return ans;
}

signed main(){
    freopen("pairs.in","r",stdin);
    freopen("pairs.out","w",stdout);
    n=read();P=read();
    jc[0]=1;
    for(int i=1;i<=n;++i)jc[i]=jc[i-1]*i%P;
    C[0][0]=1;
    for(int i=1;i<=n;++i){
        C[i][0]=1;
        for(int j=1;j<=i;++j){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i){
        g[i]=work(i);
        // cout<<" i:"<<i<<" g:"<<g[i]<<endl;
        ans=(ans+g[i]*C[n][i]%P*jc[n-i]%P)%P;
    }
    print(ans);putchar('\n');
    return 0;

}   
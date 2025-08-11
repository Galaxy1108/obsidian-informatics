#include<bits/stdc++.h>
using namespace std;
#define lb(x) (x&(-x))
#define int long long
const int N=1e6+5,M=1e3+5,inf=1e18;

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

int n,m,a[N],b[N],f[M][M];

signed main(){
    freopen("kyoto.in","r",stdin);
    freopen("kyoto.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;++i)a[i]=read();
    for(int i=1;i<=m;++i)b[i]=read();
    for(int i=1;i<=n;++i)f[i][1]=b[1]*(i-1);
    for(int i=1;i<=m;++i)f[1][i]=a[1]*(i-1);
    for(int i=2;i<=n;++i){
        for(int j=2;j<=m;++j){
            f[i][j]=min(f[i-1][j]+b[j],f[i][j-1]+a[i]);
        }
    }
    print(f[n][m]);putchar('\n');
    return 0;
}
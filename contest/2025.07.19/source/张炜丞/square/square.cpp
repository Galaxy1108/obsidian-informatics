#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5,P=1e9+7;

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

int prim[N],rk[N],cnt,f[20][2][20],g[2][20],a[N],n;
bool vis[N];
vector<int> b[20];

void init(){
    int n=70;
    for(int i=2;i<=n;++i){
        if(!vis[i]){
            prim[++cnt]=i;
            rk[i]=cnt;
        }
        for(int j=1;j<=cnt&&i*prim[j]<=n;++j){
            vis[i*prim[j]]=1;
            if(i%prim[j]==0)break;
        }
    }
}

signed main(){
    freopen("square.in","r",stdin);
    freopen("square.out","w",stdout);
    init();
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();int v=0;
        for(int j=1;j<=4;++j){
            while(a[i]%prim[j]==0){
                v^=(1<<j-1);
                a[i]/=prim[j];
            }
        }
        if(a[i]>1){
            b[rk[a[i]]-4].push_back(v);
        }
        else b[0].push_back(v);
    }
    for(int i=0;i<=19;++i){
        f[i][0][0]=1;
        for(int j:b[i]){
            for(int k=0;k<=15;++k){
                g[1][k^j]=f[i][0][k];
                g[0][k^j]=f[i][1][k];
            }
            for(int k=0;k<=15;++k){
                f[i][0][k]=(f[i][0][k]+g[0][k])%P;
                f[i][1][k]=(f[i][1][k]+g[1][k])%P;
            }
        }
    }
    for(int k=0;k<=15;++k){
        f[0][0][k]=(f[0][0][k]+f[0][1][k])%P;
    }
    for(int i=1;i<=19;++i){
        memset(g,0,sizeof(g));
        for(int j=0;j<=15;++j){
            for(int k=0;k<=15;++k){
                g[0][j^k]=(g[0][j^k]+f[i-1][0][j]*f[i][0][k]%P)%P;
            }
        }
        for(int j=0;j<=15;++j)f[i][0][j]=g[0][j];
    }
    int ans=((f[19][0][0]-1)%P+P)%P;
    print(ans);putchar('\n');
    return 0;
}

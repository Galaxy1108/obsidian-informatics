#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=22;

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

int n,q,m=20,f[N][M],a[N],g[N];
bool vis[M];

void init(){
    for(int i=1;i<=m;++i)f[1][i]=1,f[0][i]=-1;
    for(int i=2;i<=n;++i){
        for(int j=2;j<=m;++j){
            int len=(i-1)/j+1;
            int p=(i-len+1)-f[i-len][j];
            int q=(p/(j-1))+(p%(j-1)>0);
            f[i][j]=p+q;
        }
    }
}

void debug(){
    n=read();
    g[0]=0;int ans=0;
    for(int i=1;i<=n;++i){
        g[i]=g[i-((i-1)/20+1)]+1;
    }
    for(int i=n;i;){
        ans+=i;
        i-=(i-1)/20+1;
    }
    cout<<" g:"<<g[n]<<" ans:"<<ans<<endl;
    exit(0);
}

signed main(){
    freopen("bounce.in","r",stdin);
    freopen("bounce.out","w",stdout);
    // debug();
    n=read();q=read();
    init();
    for(int i=1;i<=n;++i)a[i]=i;
    for(int i=1,op,t;i<=q;++i){
        op=read();t=read();
        if(op==1){
            if(vis[t])continue;
            vis[t]=1;
            int nn=0;
            for(int i=1;i<=n;++i)if((a[i]-1)%t!=0)a[++nn]=a[i];
            n=nn;
        }
        else if(op==2){
            int nn=0;
            for(int i=1;i<=n;++i)if((i-1)%t!=0)a[++nn]=a[i];
            n=nn;
        }
        else{
            int ans=a[f[n][t]];
            print(ans);putchar('\n');
        }
    }
    return 0;
}
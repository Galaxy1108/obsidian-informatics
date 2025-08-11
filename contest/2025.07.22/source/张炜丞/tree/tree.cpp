#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005,P=998244353;

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

int n,L[N],R[N],f[N][N],g[N][N],ans[N],iv[N];

int power(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=ans*x%P;
        x=x*x%P;
        y>>=1;
    }
    return ans;
}

signed main(){
    feopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    for(int i=2;i<=n;++i){
        L[i]=read();R[i]=read();
    }
    for(int i=1;i<=n;++i)iv[i]=power(i,P-2);
    for(int i=1;i<=n;++i){
        f[i][i]=g[i][i]=1;
        for(int j=i+1;j<=n;++j){
            f[i][j]=(iv[R[j]-L[j]+1]*(g[i][R[j]]-g[i][L[j]-1])%P+P)%P;
            g[i][j]=(g[i][j-1]+f[i][j])%P;
            //cout<<" i:"<<i<<" j:"<<j<<" f:"<<f[i][j]<<" g:"<<g[i][j]<<endl;
        }
    }
    int m=read();
    for(int i=1;i<=m;++i){
        int u=read(),v=read(),w=read();
        if(u==v)continue;
        if(u>v)swap(u,v);
        for(int x=2;x<=n;++x){
            if(x<=u){
                int a1=(f[x][u]*(((1-f[x][v]-f[u][v]*(1-f[x][u]))%P+P)%P)%P+P)%P;
                int a2=((1-f[x][u])*(((f[x][v]-f[u][v]*(f[x][u]))%P+P)%P)%P+P)%P;
                ans[x]=(ans[x]+w*(a1+a2)%P)%P;
            }
            else if(x<=v){
                int a1=f[x][v];
                ans[x]=(ans[x]+w*a1%P)%P;
            }
        }
    }
    for(int i=2;i<=n;++i){
        print(ans[i]);putchar(' ');
    }
    return 0;
}

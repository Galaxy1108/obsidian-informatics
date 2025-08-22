#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6+5;

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
int n,m,P;
int fl[2][N],fr[2][N],sl[2][N],sr[2][N],ssl[2][N],ssr[2][N];


signed main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    n=read();m=read();P=read();
    if(n==1){
        int ans=m*(m+1)/2%P;
        print(ans);putchar('\n');return 0;
    }
    else if(m==1){
        puts("1");return 0;
    }
    for(int i=1;i<=m;++i)fl[1][i]=m-i+1,fr[1][i]=i;
    for(int i=1;i<=m;++i)sr[1][i]=(sr[1][i-1]+fr[1][i])%P;
    for(int i=m;i>=1;--i)sl[1][i]=(sl[1][i+1]+fl[1][i])%P;
    for(int i=1;i<=m;++i)ssr[1][i]=(ssr[1][i-1]+sr[1][i])%P;
    for(int i=m;i>=1;--i)ssl[1][i]=(ssl[1][i+1]+sl[1][i])%P;
    for(int i=2;i<=n;++i){
        int k=i&1,len=sr[k^1][m];
        // cout<<" i:"<<i<<" len:"<<len<<endl;
        for(int j=1;j<=m;++j){
            fl[k][j]=((len*(m-j+1)%P-sr[k^1][j-1]*(m-j+1)%P-ssl[k^1][j+1])%P+P)%P;
            fr[k][j]=((len*j%P-sl[k^1][j+1]*(j)%P-ssr[k^1][j-1])%P+P)%P;
            // cout<<" j:"<<j<<" fl:"<<fl[k][j]<<" fr:"<<fr[k][j]<<endl;
        }
        for(int j=1;j<=m;++j)sr[k][j]=(sr[k][j-1]+fr[k][j])%P;
        for(int j=m;j>=1;--j)sl[k][j]=(sl[k][j+1]+fl[k][j])%P;
        for(int j=1;j<=m;++j)ssr[k][j]=(ssr[k][j-1]+sr[k][j])%P;
        for(int j=m;j>=1;--j)ssl[k][j]=(ssl[k][j+1]+sl[k][j])%P;
    }
    int ans=sr[n&1][m];
    print(ans);putchar('\n');
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const signed P=998244353;

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

int power(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=ans*x%P;
        x=x*x%P;
        y>>=1;
    }
    return ans;
}

int n,x,f[N][N],jc[N],iv[N],pw[N][N];

int C(int n,int m){
    // cout<<" /c n:"<<n<<" m:"<<m<<" jcn:"<<jc[n]<<" ivm:"<<iv[m]<<" iv:"<<iv[n-m]<<endl;
    return jc[n]*iv[m]%P*iv[n-m]%P;
}

signed main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    n=read();x=read();
    jc[0]=iv[0]=1;
    for(int i=1;i<=n;++i){
        jc[i]=jc[i-1]*i%P,iv[i]=power(jc[i],P-2);
    }
    for(int i=0;i<=n;++i){
        pw[i][0]=1;
        for(int j=1;j<=n;++j){
            pw[i][j]=pw[i][j-1]*i%P;
        }
    }
    for(int i=0;i<=x;++i)f[0][i]=1;
    for(int i=2;i<=n;++i){
        for(int j=1;j<=x;++j){
            if(j<i){f[i][j]=power(j,i);continue;}
            for(int k=0;k<=i;++k){
                f[i][j]=(f[i][j]+f[i-k][j-i+1]*C(i,k)%P*pw[i-1][k]%P)%P;
                // cout<<" k:"<<k<<" f/:"<<f[i-k][j-i+1]<<" f:"<<f[i][j]<<" c:"<<C(i,k)<<" pw:"<<power(i-1,k)<<endl;
            }
            // cout<<" i:"<<i<<" j:"<<j<<" f:"<<f[i][j]<<endl;
        }
    }
    print(f[n][x]);putchar('\n');
    return 0;
}
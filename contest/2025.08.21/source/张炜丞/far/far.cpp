#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=65,M=2060;
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

int f[N][M],ans[N],n,m,ql[N],qr[N];

int check(int x){
    int i=1,j=(1<<m-1);
    while(i<j){
        if(((x&i)==0)^((x&j)==0))return 0;
        i<<=1;j>>=1;
    }
    return 1;
}

void work1(){
    f[0][0]=1;
    for(int i=1;i<=n;++i){
        for(int j=0;j<(1<<m);++j){
            for(int k=ql[i];k<=qr[i];++k){
                f[i][j^k]=(f[i][j^k]+f[i-1][j])%P;
            }
        }
        for(int j=0;j<(1<<m);++j){
            // cout<<" j:"<<j<<" f:"<<f[i][j]<<" check:"<<check(j)<<endl;
            if(check(j))ans[i]=(ans[i]+f[i][j])%P;
        }
        print(ans[i]);putchar('\n');
    }
}

signed main(){
    freopen("far.in","r",stdin);
    freopen("far.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;++i){
        ql[i]=read();qr[i]=read();
    }
    if(m<=10){
        work1();
        return 0;
    }
}
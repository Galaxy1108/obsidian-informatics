#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1005;

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

int n,x,P,m;
int a[N],C[N][N];

int power(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=ans*x%P;
        x=x*x%P;
        y>>=1;
    }
    return ans;
}

int f(int x){
    int ans=0,y=1;
    for(int i=0;i<=n;++i){
        ans=(ans+a[i]*y%P)%P;
        y=y*x%P;
    }
    return ans;
}

signed main(){
    freopen("combination.in","r",stdin);
    freopen("combination.out","w",stdout);
    n=read();x=read();P=read();m=read();
    for(int i=0;i<=m;++i)a[i]=read();
    if(m==0){
        int ans=power(x+1,n)*a[0]%P;
        print(ans);putchar('\n');return 0;
    }
    else if(n<=1000){
        C[0][0]=1;
        for(int i=1;i<=n;++i){
            C[i][0]=1;
            for(int j=1;j<=i;++j){
                C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
                //cout<<" i:"<<i<<" j:"<<j<<" c:"<<C[i][j]<<endl;
            }
        }
        int ans=0;
        for(int i=0;i<=n;++i){
            //cout<<" i:"<<i<<" f:"<<f(i)<<" C:"<<C[n][i]<<endl;
            ans=(ans+f(i)*power(x,i)%P*C[n][i]%P)%P;
        }
        print(ans);putchar('\n');return 0;
    }
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e3+5;

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

// bool f1;
int n,m,f[N][N*2];
signed P;
// bool f2;

int power(int x,int y){
    int ans=0;
    while(y){
        if(y&1)ans=ans*x%P;
        x=x*x%P;
        y>>=1;
    }
    return ans;
}

signed main(){
    // int siz=&f1-&f2;
    // cout<<" siz:"<<siz/1024/1024<<" MB"<<endl;
    freopen("easyhard.in","r",stdin);
    freopen("easyhard.out","w",stdout);
    n=read();m=read();P=read();
    m--;n--;
    f[0][0]=1;
    for(int i=0;i<m;++i){
        for(int j=0;j<=i*2;++j){
            if(j>n+i||i*2-j>n+i){f[i][j]=0;continue;}
            f[i+1][j]=(f[i+1][j]+f[i][j])%P;
            f[i+1][j+1]=(f[i+1][j+1]+f[i][j]*2)%P;
            f[i+1][j+2]=(f[i+1][j+2]+f[i][j])%P;
        }
    }
    int ans=0;
    for(int i=0;i<=m*2;++i){
        if(i>n+m||m*2-i>n+m)continue;
        ans=(ans+f[m][i])%P;
    }
    ans=ans*4%P;
    print(ans);putchar('\n');
    // if(n>=m)n=m;
    return 0;
}


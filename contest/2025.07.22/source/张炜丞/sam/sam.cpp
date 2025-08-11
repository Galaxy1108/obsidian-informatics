#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10,P=1e9+7;

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

int n;
struct matrix{
    int a[N][N];
    void init(int x){
        if(x==0)for(int i=0;i<N;++i)for(int j=0;j<N;++j)a[i][j]=0;
        if(x==1){
            init(0);for(int i=0;i<N;++i)a[i][i]=1;
        }
        if(x==2){
            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    a[i][j]=abs(i-j)<=2;
                }
            }
        }
    }
    matrix(){
        init(0);
    }
    void operator=(const matrix &n1){
        for(int i=0;i<N;++i)for(int j=0;j<N;++j)a[i][j]=n1.a[i][j];
    }
    matrix operator*(const matrix &n1)const{
        matrix ans;
        for(int i=0;i<N;++i)
        for(int j=0;j<N;++j){
            for(int k=0;k<N;++k)
            ans.a[i][j]+=a[i][k]*n1.a[k][j]%P;
            ans.a[i][j]%=P;
        }
        return ans;
    }
};

matrix power(matrix x,int y){
    matrix ans;ans.init(1);
    while(y){
        if(y&1)ans=ans*x;
        x=x*x;
        y>>=1;
    }
    return ans;
}

signed main(){
    freopen("sam.in","r",stdin);
    freopen("sam.out","w",stdout);
    n=read();
    matrix a,b,ans;
    a.init(2);
    b=power(a,n-1);
    for(int i=1;i<N;++i)ans.a[i][0]=1;
    ans=b*ans;
    int an=0;
    for(int i=0;i<N;++i)an=(an+ans.a[i][0])%P;
    print(an);putchar('\n');
    return 0;
}
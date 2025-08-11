#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105,M=1e5+5,inf=1e9;

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

int n,m,k,P,a[N][N],mix[N],miy[N],ans,f[N][N],jc[M],iv[M],cnt;

int power(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=ans*x%P;
        x=x*x%P;
        y>>=1;
    }
    return ans;
}

void dfs(int x,int y){
    if(y>m)++x,y-=m;
    if(x==n+1){
        int ans=1;
        for(int i=1;i<=n;++i)mix[i]=inf;
        for(int i=1;i<=m;++i)miy[i]=inf;
        for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){
            mix[i]=min(mix[i],a[i][j]);
            miy[j]=min(miy[j],a[i][j]);
        }
        for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        ans=ans*min(mix[i],miy[j])%P;
        ::ans=(ans+::ans)%P;
        if(ans==1)cnt++;
        return;
    }
    for(int i=1;i<=k;++i){
        a[x][y]=i;
        dfs(x,y+1);
    }
}

void work1(){
    dfs(1,1);
    print(ans);putchar('\n');
}

int C(int n,int m){
    //cout<<" n:"<<n<<" m:"<<m<<" ans:"<<jc[n]*iv[m]%P*iv[n-m]%P<<endl;
    return jc[n]*iv[m]%P*iv[n-m]%P;
}

void work2(){
    f[0][0]=1;
    for(int i=1;i<=n;++i)f[i][1]=1;
    for(int j=2;j<=m;++j)f[1][j]=1;
    for(int i=2;i<=n;++i){
        for(int j=2;j<=m;++j){
            f[i][j]=(power(2,i*j));
            for(int p=1;p<=i;++p){
                for(int q=1;q<=j;++q){
                    f[i][j]=((f[i][j]-C(i,p)*C(j,q)%P*f[i-p][j-q]%P)%P+P)%P;
                }
            }
        }
    }
    int ans=f[n][m];
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            ans=(ans+power(2,i*j)*f[n-i][m-j]%P*C(n,i)%P*C(m,j)%P)%P;
        }
    }
    print(ans);putchar('\n');
}

signed main(){
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    n=read();m=read();k=read();P=read();
    jc[0]=iv[0]=1;
    for(int i=1;i<M;++i){
        jc[i]=jc[i-1]*i%P;
        iv[i]=power(jc[i],P-2);
    }
    if(k==1){
        puts("1");return 0;
    }
    work1();return 0;
}
/*
3 3
2 998244353
*/
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

int power(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=ans*x%P;
        x=x*x%P;
        y>>=1;
    }
    return ans;
}

int n,m,a[N],cnt,jc[N],iv[N],b[N],ans,c[N],f[N][N],g[N][N],h[N][N];
int vis[N];
int C(int n,int m){
    return jc[n]*iv[m]%P*iv[n-m]%P;
}

void dfs(int d,int mex){
    if(d==n+1){
        //cout<<" mex:"<<mex<<" v:";
        //or(int i=1;i<=n;++i)cout<<c[i]<<" ";
        //cout<<endl;
        ans++;return;
    }
    if(a[d]==0){
        for(int i=0;i<=m;++i){
            if(i==mex)continue;
            ++vis[i];c[d]=i;dfs(d+1,mex);
            --vis[i];c[d]=0;
        }
        return;
    }
    else{
        if(mex>m)return;
        ++vis[mex];c[d]=mex;
        int mm=mex;
        while(vis[mex])++mex;
        dfs(d+1,mex);
        --vis[mm];c[d]=0;
    }
}

signed main(){
    freopen("mex.in","r",stdin);
    freopen("mex.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
        if(a[i])b[++cnt]=i;
    }
    if(cnt>m+1){
        puts("0");return 0;
    }
    if(n<=m){
        //cout<<" n:"<<n<<" cnt:"<<cnt<<endl;
        int ans=power(m,n-cnt);
        print(ans);putchar('\n');
        return 0;
    }
    jc[0]=iv[0]=1;
    for(int i=1;i<=n;++i){
        jc[i]=jc[i-1]*i%P;
        iv[i]=power(jc[i],P-2);
    }
    if(n<=15){
        dfs(1,0);
        print(ans);putchar('\n');
        return 0;
    }
    for(int i=1;i<=m;++i)f[0][i]=1;
    for(int i=1;i<=cnt;++i){
        for(int j=cnt-i;j<=m;++j){
            f[i][j]=f[i-1][j]*power(j-cnt+i+1,b[i]-b[i-1]-1)%P;
        }
        for(int j=m;j>=cnt-i;--j){
            g[i][j]=(f[i][j]-f[i][j-1])%P;
            //cout<<" i:"<<i<<" j:"<<j<<" f:"<<f[i][j]<<" g:"<<g[i][j]<<endl;
        }
    }

    print(f[cnt][m]*power(m,n-b[cnt]));putchar('\n');
    return 0;
}
/*
5 3
1 0 0 1 1
*/

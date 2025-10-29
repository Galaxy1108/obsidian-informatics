#include <bits/stdc++.h>
using namespace std;
#define N 505
#define MOD 998244353
int n,x,a[N],b[N];
long long ans=0;
bool calc(){
    int c=n,tc;
    for(int i=1;i<=n;i++)b[i]=a[i];
    while(c>0){
        tc=c;
        for(int i=1;i<=n;i++){
            if(b[i]>0&&(b[i]-=c-1)<=0)tc--;
        }
        c=tc;
        if(c==1)return false;
    }
    return true;
}
void dfs(int p){
    if(p==n+1){
        ans+=calc();
        return ;
    }
    for(int i=1;i<=x;i++){
        a[p]=i;
        dfs(p+1);
    }
}
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x;
    dfs(1);
    cout<<(ans%MOD);
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
#define N 505
#define MOD 998244353
int n,x;
long long C[N][N],p[N][N];
long long f[N][N];
struct __init{__init(){
    for(int i=0;i<=500;i++){
        C[i][0]=1;
        p[i][0]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;            
        }
        for(int j=1;j<=500;j++){
            p[i][j]=p[i][j-1]*i%MOD;
        }
    }
}}__init;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            f[i][j]=(p[i][j]-p[i][j-1]+MOD)%MOD;
            // cerr<<f[i][j]<<' ';
        }
        // cerr<<'\n';
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(j+i-1<=x)f[i][j+i-1]=(f[i][j+i-1]+f[i][j])%MOD;
            for(int k=1;j+i+k-1<=x&&i+k<=n;k++){
                f[i+k][j+i+k-1]=(f[i+k][j+i+k-1]+f[i][j]*C[n-i][k]%MOD*p[k][i+k-1]%MOD)%MOD;
            }
        }
    }
    long long ans=0;
    for(int i=1;i<=x;i++){
        ans=(ans+f[n][i])%MOD;
    }
    cout<<ans;
    return 0;
}
*/
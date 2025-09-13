#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,mx=1e6,mod=998244353;
int n,k;
int qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1)res=1ll*res*a%mod;
        b>>=1;a=1ll*a*a%mod;
    }return res;
}
struct solve{
    int k,n;
    int dp[N],sdp[N],sdpi[N];
    void init(int k0,int n0){
        k=k0,n=n0;
        dp[0]=sdp[0]=1;
        for(int i=1;i<=n;i++){
            if(i>=k)dp[i]=sdp[i-k];
            sdp[i]=(sdp[i-1]+dp[i])%mod;
            sdpi[i]=(sdpi[i-1]+1ll*dp[i]*i)%mod;
        }
    }
    int query(int n){
        if(n<k)return 0;
        return (1ll*n*sdp[n-k]-sdpi[n-k]+mod)%mod;
    }
}t;
int cur;
int get(int n,int lim){
    n/=lim;
    return t.query(n);
}
int prime[N],tot,phi[N];
bool isp[N];
void read(int&x){
    x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    read(k);k++;
    phi[1]=1;
    for(int i=2;i<=mx;i++){
        if(!isp[i])prime[++tot]=i,phi[i]=i-1;
        for(int j=1;j<=tot&&1ll*i*prime[j]<=mx;j++){
            isp[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }phi[i*prime[j]]=phi[i]*phi[prime[j]];
        }
    }
    t.init(k,mx);
    int T;read(T);
    while(T--){
        int n;read(n);
        printf("%d ",get(n,1));
        int res=0;
        for(int i=1;i<=n/i;i++)if(n%i==0){
            res=(res+1ll*phi[n/i]*get(n,n/i))%mod;
            if(i!=n/i)res=(res+1ll*phi[i]*get(n,i))%mod;
        }res=1ll*res*qpow(n,mod-2)%mod;
        printf("%d\n",res);
    }
    return 0;
}
/*
burnside引理
*/
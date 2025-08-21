#include<bits/stdc++.h>
#define int long long
#define N 40
#define M 60
#define Mod 998244353
using namespace std;
int n,m,l[N+5],r[N+5],p,sum=1,ans,dp[N+5][10000];
bool flag=1;
int read(){
    int f=1,g=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        g=g*10+ch-'0';
        ch=getchar();
    }
    return f*g;
}
void print(int x){
    if(x<0){
        putchar('-');
        x*=-1;
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
    return;
}
int fpow(int x,int y){
    if(!y)return 1;
    if(y&1)return fpow(x*x%Mod,y>>1)*x%Mod;
    return fpow(x*x%Mod,y>>1);
}
main(){
    freopen("far.in","r",stdin);
    freopen("far.out","w",stdout);
    n=read(),m=read(),p=(fpow(2,m)-1+Mod)%Mod;
    for(int i=1;i<=n;i++){
        l[i]=read(),r[i]=read();
        if(l[i]!=0||r[i]%Mod!=p)flag=0;
    }
    if(flag){
        if(m&1)ans=fpow(2,m/2+1);
        else ans=fpow(2,m/2);
        for(int i=1;i<=n;i++){
            print(ans*sum%Mod),putchar('\n');
            sum=(p+1)%Mod*sum%Mod;
        }
        return 0;
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=p;j++){
            for(int k=l[i];k<=r[i];k++){
                dp[i][j]=(dp[i][j]+dp[i-1][j^k])%Mod;
                // if(i==1){
                //     cout<<j<<" "<<k<<" "<<dp[i-1][j^k]<<" "<<dp[i][j]<<" run\n";
                // }
            }
            // if(i==1){
            //     cout<<j<<" "<<dp[i][j]<<" fhwuifhwe\n";
            // }
        }
        ans=0;
        for(int j=0;j<=p;j++){
            // if(i==1){
            //     cout<<j<<" "<<dp[i][j]<<" fhwuifhwe\n";
            // }
            flag=1;
            for(int k=0;k<m;k++){
                if((j>>k)%2!=(j>>(m-k-1))%2){
                    flag=0;
                    break;
                }
            }
            if(flag)ans=(ans+dp[i][j])%Mod;
        }
        print(ans),putchar('\n');
    }
    return 0;
}

#include<bits/stdc++.h>
#define int long long
#define N 5000
#define M 1000000
#define Mod 1000000007
using namespace std;
int n,dp[2][M+5],sum[M+5],a[N+5],ans=0;
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
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=a[1];i++)dp[1][i]=fpow(a[1],Mod-2);
    // cout<<"\n";
    for(int i=2;i<=n;i++){
        for(int j=1;j<=a[i];j++)sum[j]=(sum[j-1]+dp[i&1^1][j])%Mod;
        for(int j=1;j<=a[i];j++){
            dp[i&1][j]=(fpow(a[i],Mod-2)*sum[j-1]%Mod+dp[i&1^1][j]*j%Mod*fpow(a[i],Mod-2)%Mod)%Mod;
            if(i==n)ans=(ans+dp[i&1][j]*j%Mod)%Mod;
        }
    }
    print(ans),putchar('\n');
    return 0;
}

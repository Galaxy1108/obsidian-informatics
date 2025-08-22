//#include<bits/stdc++.h>
//#define int long long
//#define M 4000
//using namespace std;
//int n,m,p;
//struct ModInt{
//    int v;
//    inline ModInt friend operator+(ModInt const &x,ModInt const &y){return {(x.v+y.v)%p};}
//    inline ModInt friend operator-(ModInt const &x,ModInt const &y){return {((x.v-y.v)%p+p)%p};}
//    inline ModInt friend operator*(ModInt const &x,ModInt const &y){return {x.v*y.v%p};}
//}dp[2][M+5][M+5],pre[M+5],nex[M+5],sum;
//inline int read(){
//    int f=1,g=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        if(ch=='-')f=-1;
//        ch=getchar();
//    }
//    while('0'<=ch&&ch<='9'){
//        g=g*10+ch-'0';
//        ch=getchar();
//    }
//    return f*g;
//}
//inline void print(int x){
//    if(x<0){
//        putchar('-');
//        x*=-1;
//    }
//    if(x>9)print(x/10);
//    putchar(x%10+'0');
//    return;
//}
//main(){
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
//    n=read(),m=read(),p=read();
//    if(n==1){
//        print((m+1)*m/2%p);
//        return 0;
//    }
//    if(m==1){
//        print(1);
//        return 0;
//    }
//    for(int i=1;i<=m;i++){
//        for(int j=i;j<=m;j++)dp[1][i][j].v=1;
//    }
//    for(int i=2;i<=n;i++){
//        for(int j=1;j<=m;j++){
//            pre[j].v=pre[j-1].v;
//            for(int k=1;k<=j;k++)pre[j]=pre[j]+dp[i&1^1][k][j];
//        }
//        for(int j=m;j>0;j--){
//            nex[j].v=nex[j+1].v;
//            for(int k=j;k<=m;k++)nex[j]=nex[j]+dp[i&1^1][j][k];
//            // cout<<"nex["<<j<<"]="<<nex[j].v<<"\n";
//        }
//        // sum.v=0;
//        // for(int j=1;j<=m;j++)for(int k=j;k<=m;k++)sum=sum+dp[i&1^1][j][k];
//        for(int j=1;j<=m;j++){
//            for(int k=j;k<=m;k++){
//                // dp[i&1][j][k]=sum-pre[j-1]-nex[k+1];
//                dp[i&1][j][k]=pre[m]-pre[j-1]-nex[k+1];
//                // cout<<"dp["<<j<<"]["<<k<<"]="<<dp[i&1][j][k].v<<" "<<pre[j-1].v<<" "<<nex[k+1].v<<" "<<sum.v<<"\n";
//            }
//        }
//    }
//    sum.v=0;
//    for(int i=1;i<=m;i++)for(int j=i;j<=m;j++)sum=sum+dp[n&1][i][j];
//    print(sum.v);
//    return 0;
//}
#include<bits/stdc++.h>
#define int long long
#define M 4000
using namespace std;
int n,m,p;
struct ModInt{
    int v;
    ModInt friend operator+(ModInt const &x,ModInt const &y){return {(x.v+y.v)%p};}
    ModInt friend operator-(ModInt const &x,ModInt const &y){return {((x.v-y.v)%p+p)%p};}
    ModInt friend operator*(ModInt const &x,ModInt const &y){return {x.v*y.v%p};}
};
int dp[2][M+5][M+5],pre[M+5],nex[M+5],sum;
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
main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    n=read(),m=read(),p=read();
    if(n==1){
        print((m+1)*m/2%p);
        return 0;
    }
    if(m==1){
        print(1);
        return 0;
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j++)dp[1][i][j]=1;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=m;j++){
            pre[j]=pre[j-1];
            for(int k=1;k<=j;k++)pre[j]=(pre[j]+dp[i&1^1][k][j])%p;
        }
        for(int j=m;j>0;j--){
            nex[j]=nex[j+1];
            for(int k=j;k<=m;k++)nex[j]=(nex[j]+dp[i&1^1][j][k])%p;
            // cout<<"nex["<<j<<"]="<<nex[j].v<<"\n";
        }
        // sum.v=0;
        // for(int j=1;j<=m;j++)for(int k=j;k<=m;k++)sum=sum+dp[i&1^1][j][k];
        for(int j=1;j<=m;j++){
            for(int k=j;k<=m;k++){
                // dp[i&1][j][k]=sum-pre[j-1]-nex[k+1];
                dp[i&1][j][k]=((pre[m]-pre[j-1]+p)%p-nex[k+1]+p)%p;
                // cout<<"dp["<<j<<"]["<<k<<"]="<<dp[i&1][j][k].v<<" "<<pre[j-1].v<<" "<<nex[k+1].v<<" "<<sum.v<<"\n";
            }
        }
    }
    sum=0;
    for(int i=1;i<=m;i++)for(int j=i;j<=m;j++)sum=(sum+dp[n&1][i][j])%p;
    print(sum);
    return 0;
}

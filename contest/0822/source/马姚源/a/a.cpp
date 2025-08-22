#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,p;
int ans=0;
const int N=5e3+10;
int dp[N][N];
void dfs(int k,int l,int r){
    if(l>r)return;
    // cout << l << " " << r << " " << k << endl;
    if(k==n){
        ans++;
        ans%=p;
        // cout << endl;
        return;
    }
    for(int i=1;i<=r;i++){
        for(int j=l;j<=m;j++){
            dfs(k+1,i,j);
        }
    }
}
int qpow(int a,int b,int p){
    int res=1;
    while(b){
        if(b&1)res*=a,res%=p;
        a*=a;
        a%=p;
        b>>=1;
    }
    return res;
}
signed main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    cin >> n >> m >> p;
    if(m==1){
        cout << 1;
        return 0;
    }
    if(n==1){
        cout << (m*(m+1))/2;
        return 0; 
    }
    if(n<=8){
        dfs(0,1,m);
        cout << ans;
        return 0;
    }
    else {
    for(int i=1;i<=n;i++)dp[i][1]=1;
    for(int i=2;i<=m;i++)dp[1][i]=dp[1][i-1]+i,dp[1][i]%=p;
    for(int i=2;i<=n;i++){
        for(int j=2;j<=m;j++){
            dp[i][j]=(dp[i-1][j]*dp[1][j]-qpow(j,i-1,p)+p);
            dp[i][j]%=p;
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    cout << dp[n][m];
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// const int N=5e3+10;
// int dp[N][N];
// int qpow(int a,int b,int p){
//     int res=1;
//     while(b){
//         if(b&1)res*=a,res%=p;
//         a*=a;
//         a%=p;
//         b>>=1;
//     }
//     return res;
// }
// signed main(){
//     int n,m,p;
//     cin >> n >> m >> p;
//     if(m==1){
//         cout << 1;
//         return 0;
//     }
//     if(n==1){
//         cout << (m*(m+1))/2;
//         return 0; 
//     }
//     for(int i=1;i<=n;i++)dp[i][1]=1;
//     for(int i=2;i<=m;i++)dp[1][i]=dp[1][i-1]+i,dp[1][i]%=p;
//     for(int i=2;i<=n;i++){
//         for(int j=2;j<=m;j++){
//             dp[i][j]=(dp[i-1][j]*dp[1][j]-qpow(j,i-1,p)+p);
//             dp[i][j]%=p;
//         }
//     }
//     // for(int i=1;i<=n;i++){
//     //     for(int j=1;j<=m;j++){
//     //         cout << dp[i][j] << " ";
//     //     }
//     //     cout << endl;
//     // }
//     // cout << endl;
//     cout << dp[n][m];
//     return 0;
// }

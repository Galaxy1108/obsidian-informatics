#include <bits/stdc++.h>
using namespace std;
// bool stt;
constexpr int N=205;
int n,a[N];
bitset<5005>f[2][2005];//f[i][len][sum]
long long m,s;
inline bool Cm2(long long x,long long y){
    return (x&y)==y;
    // long long res=1;
    // for(long long i=x;x-i+1<=y;i--)res*=i;
    // for(long long i=y;i>=1;i--)res/=i;
    // return res;
}
void solve(){
    cin>>m>>s>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=0;i<=m;i++)f[0][i].reset(),f[1][i].reset();
    f[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++)f[i&1][j].reset();
        for(int j=0;j<=m;j++){
            for(int k=0;k<=s;k++){
                for(int x=0;x<=j&&1ll*a[i]*x<=k;x++){
                    f[i&1][j][k]=f[i&1][j][k]^(f[i&1^1][j-x][k-a[i]*x]&Cm2(j,j-x));
                    // f[i&1][j][k]+=f[i&1^1][j-x][k-a[i]*x]*Cm2(j,j-x);
                }
            }
        }
    }
    cout<<f[n&1][m][s]<<'\n';
}
// bool edd;
int main(){
    // cerr<<abs(&stt-&edd);
    freopen("give.in","r",stdin);
    freopen("give.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
constexpr int N=200005;
constexpr long long MOD=998244353;
int n,q,mx,a[N],b[N],f[N],ans[N];
int getans(int x){
    static int cnt[10];
    for(int i=1;i<=n;i++)cnt[i]=0;
    for(int i=0;i<mx;i++){
        if((x>>i)&1){
            cnt[b[i+1]]++;
        }
    }
    int maxp=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]>cnt[maxp])maxp=i;
    }
    return (1<<maxp);
}
void solve(){
    mx=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            b[++mx]=i;
        }
    }
    f[0]=0;
    for(int i=1;i<(1<<mx);i++){
        f[i]=0x3f3f3f3f;
        ans[i]=getans(i);
    }
    for(int i=1;i<(1<<mx);i++){
        for(int j=i;j;j=(j-1)&i){//choose j
            f[i]=min(f[i],f[i^j]+ans[j]);
        }
    }
    cout<<f[(1<<mx)-1]<<'\n';
}
int main(){
    freopen("imperishable.in","r",stdin);
    freopen("imperishable.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int C;
    cin>>C>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>q;
    int x,y;
    solve();
    while(q--){
        cin>>x>>y;
        a[x]=y;
        solve();
    }
    return 0;  
}
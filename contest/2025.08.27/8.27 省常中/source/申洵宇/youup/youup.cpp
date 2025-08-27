#include <bits/stdc++.h>
using namespace std;
constexpr int N=300005;
constexpr long long MOD=998244353ll;
int n,maxd;
vector<int>e[N];
void dfs(int x,int come,int *dis){
    dis[x]=dis[come]+1;
    for(auto v:e[x]){
        if(v==come)continue;
        dfs(v,x,dis);
    }
}
void solve1(){
    static int dis[25][25];
    static int ans[25];
    for(int i=1;i<=n;i++){
        dis[i][0]=-1;
        dfs(i,0,dis[i]);
    }
    for(int i=1;i<(1<<n);i++){
        static bool isok;isok=true;
        for(int j=0;j<n;j++){
            if((i>>j)&1^1)continue;
            for(int k=j+1;k<n;k++){
                if((i>>k)&1^1)continue;
                if(dis[j+1][k+1]>maxd){
                    isok=false;
                    break;
                }
            }
            if(!isok)break;
        }
        ans[__builtin_popcount(i)]+=isok;
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
}
int main(){
    freopen("youup.in","r",stdin);
    freopen("youup.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _C;
    cin>>_C>>n>>maxd;
    int _u,_v;
    for(int i=1;i<n;i++){
        cin>>_u>>_v;
        e[_u].emplace_back(_v);
        e[_v].emplace_back(_u);
    }
    if(maxd==0){
        cout<<n<<' ';
        for(int i=2;i<=n;i++){
            cout<<"0 ";
        }
    }
    else if(n<=20){
        solve1();
    }
    // else if(_C==4){
    //     if(maxd==1){
    //         cout<<n<<' ';
    //         if(n>=2)cout<<(n-1)<<' ';
    //         for(int i=3;i<=n;i++){
    //             cout<<"0 ";
    //         }
    //     }
    //     else{
    //         cout<<n<<' ';
    //         if(n>=2)
    //     }
    // }
    return 0;
}
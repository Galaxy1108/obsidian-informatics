#include <bits/stdc++.h>
using namespace std;
// bool stt;
constexpr int N=5005;
int n,f[N],w[N],siz[N],ae[N];
long long ans[N][N];
vector<int>e[N];
void dfss(int x,int c){
    siz[x]=1;
    for(auto v:e[x]){
        if(v==c)continue;
        dfss(v,x);
        siz[x]+=siz[v];
    }
}
void dfs(int x,int c,int id,long long sum){
    ans[x][id]=sum;
    for(auto v:e[x]){
        if(v==c)continue;
        dfs(v,x,id,sum);
    }
}
// bool edd;
int main(){
    // cerr<<(double)abs(&stt-&edd)/1024.0/1024.0;
    freopen("treeq.in","r",stdin);
    freopen("treeq.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=2;i<=n;i++){
        cin>>f[i]>>w[i];
        e[i].emplace_back(f[i]);
        e[f[i]].emplace_back(i);
    }
    dfss(1,0);
    for(int i=2;i<=n;i++){
        dfs(f[i],i,i,1ll*w[i]*siz[i]);
        dfs(i,f[i],i,1ll*w[i]*(n-siz[i]));
    }
    for(int i=1;i<=n;i++){
        static int mp;mp=0;
        for(int j=2;j<=n;j++){
            if(ans[i][j]>ans[i][mp])mp=j;
        }
        for(int j=2;j<=n;j++){
            if(ans[i][j]==ans[i][mp])ae[j]++;
        }
    }
    int res=0;
    for(int i=2;i<=n;i++){
        res^=ae[i];
        // cerr<<ae[i]<<' ';
    }
    cout<<res;
    return 0;  
}
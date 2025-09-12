#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
vector<int>G[N];
int dp[N],mind[N];
void read(int&x){
    x=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
}
struct Node{
    int mx,se;
    void clear(){
        mx=se=0;
    }
    void insert(int x){
        if(x>mx)se=mx,mx=x;
        else if(x>se)se=x;
    }
    int query(int x){
        return x==mx?se:mx;
    }
}hp;
void dfs(int x,int f){
    for(int i:G[x])if(i^f)dfs(i,x);
    hp.clear();
    for(int i:G[x])if(i^f)hp.insert(dp[i]);
    dp[x]=hp.query(-1)+1;mind[x]=0;
    for(int i:G[x])if(i^f){
        int md=mind[i]+1;
        int v=max(dp[i],md+hp.query(dp[i])+1);
        if(v<dp[x]||v==dp[x]&&md<mind[x]){
            dp[x]=v;
            mind[x]=md;
        }
    }
}
int solve(){
    read(n);
    for(int i=1;i<=n;i++)G[i].clear();
    for(int i=1,u,v;i<n;i++)read(u),read(v),G[u].push_back(v),G[v].push_back(u);
    dfs(1,0);
    for(int i=1;i<=n;i++)printf("%d %d\n",dp[i],mind[i]);
    printf("%d\n",dp[1]);
    return 0;
}
int main(){
    int t;scanf("%d",&t);
    while(t--)solve();
    return 0;
}

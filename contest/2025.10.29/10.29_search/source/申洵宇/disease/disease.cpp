#include <bits/stdc++.h>
using namespace std;
#define N 305
int n,p,siz[N],fa[N];
vector<int>e[N];
mt19937_64 engine((unsigned)time(NULL));
void dfs(int x,int come){
    fa[x]=come;
    siz[x]=1;
    for(auto v:e[x]){
        if(v==come)continue;
        dfs(v,x);
        siz[x]+=siz[v];
    }
}
int solve(){
    priority_queue<pair<int,int>>pq;
    vector<pair<int,int>>t;
    for(auto v:e[1]){
        pq.emplace(siz[v],v);
    }
    int res=0;
    pair<int,int>x;
    bool del;
    while(!pq.empty()){
        del=false;
        while(!pq.empty()){
            x=pq.top();
            pq.pop();
            if(!del&&engine()<=(engine.max()>>1)){
                res+=x.first;
                del=true;
            }
            else{
                for(auto v:e[x.second]){
                    if(v!=fa[x.second]){
                        t.emplace_back(siz[v],v);
                    }
                }
            }
        }
        while(!pq.empty())pq.pop();
        for(auto v:t){
            pq.emplace(v);
        }
        t.clear();
    }
    return n-res;
}
int main(){
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout); 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>p;
    int _u,_v;
    for(int i=1;i<=p;i++){
        cin>>_u>>_v;
        e[_u].emplace_back(_v);
        e[_v].emplace_back(_u);
    }
    dfs(1,0);
    int ans=n;
    do{
        ans=min(ans,solve());
    }while((double)clock()/CLOCKS_PER_SEC<0.95);
    cout<<ans;
    return 0;
}

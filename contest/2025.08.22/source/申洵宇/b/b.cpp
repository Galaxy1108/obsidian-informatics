#include <bits/stdc++.h>
using namespace std;
constexpr int N=2005;
int n,w[N][N];
int rt,fat[N];
int f[N],siz[N],dis[N];
long long ans;
int findf(int x){
    return x==f[x]?x:f[x]=findf(f[x]);
}
inline bool merge(int x,int y){
    x=findf(x),y=findf(y);
    if(x==y)return false;
    if(siz[x]>siz[y])swap(x,y);
    f[x]=y;
    siz[y]+=siz[x];
    return true;
}
inline void solve(){
    static vector<int>e[10];
    for(int i=1;i<=n;i++)e[i].clear(),f[i]=i,siz[i]=1,dis[i]=0x3f3f3f3f;
    for(int i=1;i<=n;i++){
        if(i==rt)continue;
        if(!merge(i,fat[i]))return ;
        e[i].emplace_back(fat[i]);
        e[fat[i]].emplace_back(i);
    }
    static queue<int,list<int>>que;
    while(!que.empty())que.pop();
    que.emplace(rt);
    while(!que.empty()){
        static int x;x=que.front();
        que.pop();
        for(const int& v:e[x]){
            if(dis[v]!=0x3f3f3f3f)continue;
            dis[v]=min(dis[x],w[x][v]);
            que.emplace(v);
        }
    }
    dis[rt]=0;
    static long long sum;sum=0;
    for(int i=1;i<=n;i++)sum+=dis[i];
    ans=min(ans,sum);
}
void dfs(int x){
    if(x==rt){
        fat[x]=rt;
        return dfs(x+1);
    }
    if(x==n+1){
        solve();
        return ;
    }
    for(int i=1;i<=n;i++){
        if(x==i)continue;
        fat[x]=i;
        dfs(x+1);
    }
}
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    cin>>n;
    bool sub2=true;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            cin>>w[i][j];
            w[j][i]=w[i][j];
            if(w[i][j]!=1&&w[i][j]!=1000000000)sub2=false;
        }
    }
    if(sub2){
        for(rt=1;rt<=n;rt++){
            static queue<int,list<int>>que;
            static bitset<N>book;
            static long long ans;
            while(!que.empty())que.pop();
            book.reset();
            que.emplace(rt);
            ans=0;
            book[rt]=1;
            while(!que.empty()){
                static int x;x=que.front();
                que.pop();
                for(int i=1;i<=n;i++){
                    if(book[i]||w[x][i]==1000000000)continue;
                    que.emplace(i);
                    book[i]=1;
                    ans++;
                }
            }
            for(int i=1;i<=n;i++){
                if(!book[i])ans+=1000000000;
            }
            cout<<ans<<'\n';
        }
    }
    else{
        for(rt=1;rt<=n;rt++){
            ans=0x3f3f3f3f3f3f3f3fll;
            dfs(1);
            cout<<ans<<'\n';
        }
    }
    return 0;
}
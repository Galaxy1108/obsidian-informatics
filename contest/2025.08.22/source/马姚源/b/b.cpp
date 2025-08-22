#include <bits/stdc++.h>
using namespace std;
const int N=2e3+10;
struct Edge{
int nxt,to,w;
}E[N*2];int h[N],cnt;
int g[N][N];
void add_edge(int u,int v,int w){
    E[++cnt].nxt=h[u];
    E[cnt].to=v;
    E[cnt].w=w;
    h[u]=cnt;
}
struct Node{
    int id,d;
    bool operator <(const Node x)const {
        return x.d<d;
    }
};
int n;
int dis[N],vis[N];
void bfs(int s){
    memset(vis,0,sizeof(vis));
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=n;i++){
        if(i!=s)dis[i]=(g[s][i]==0)?2e9:g[s][i];
    }
    // for(int i=1;i<=n;i++)cout << dis[i] <<" ";
    // cout << endl;
    queue<Node> q;
    q.push({s,0x3f3f3f3f});
    while(!q.empty()){
        Node t=q.front();
        q.pop();
        int u=t.id;
        if(vis[u])continue;
        vis[u]=1;
        priority_queue<Node>pq;
        for(int i=h[u];i;i=E[i].nxt){
            dis[u]=min(dis[u],min(E[i].w,dis[E[i].to]));
            pq.push({E[i].to,E[i].w});
        }
        while(pq.size()){
            q.push(pq.top());
            pq.pop();
        }
    }
}
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    cin >> n;
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            cin >> g[i][j+i];
            g[j+i][i]=g[i][j+i];
            add_edge(i,i+j,g[i][j+i]);
            add_edge(j+i,j,g[i][j+i]);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    for(int i=1;i<=n;i++){
        bfs(i);
        int ans=0;
        for(int j=1;j<=n;j++){
            // cout << dis[j] << " ";
            if(j!=i)ans+=dis[j];
        }
        // cout << endl;
        cout << ans << endl;
    }
    
    return 0;
}
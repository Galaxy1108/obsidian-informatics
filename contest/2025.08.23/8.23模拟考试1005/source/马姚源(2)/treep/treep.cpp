#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct Edge{int nxt,w,to,id;}E[N];
int h[N],cnt;
void add_edge(int u,int v,int w,int id){
    E[++cnt].nxt=h[u];
    E[cnt].to=v;
    E[cnt].w=w;
    E[cnt].id=id;
    h[u]=cnt;
}
int dis[5005][5005],a[5005][5005],siz[N];
int rt;
void dfs(int u,int fa){
    siz[u]=1;
    for(int i=h[u];i;i=E[i].nxt){
        int v=E[i].to;
        if(v==fa)continue;
        
        dfs(v,u);
        siz[u]+=siz[v];
        dis[rt][E[i].id]=siz[v];
    }
}
int f[N],w[N];
struct Node{
    int d,id;
    bool operator < (const Node x)const {
        return d<x.d;
    }
};
int main(){
    freopen("treep.in","r",stdin);
    freopen("treep.out","w",stdout);

    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        int fi,wi;
        cin >> fi >> wi;
        w[i-1]=wi;
        add_edge(fi,i,wi,i-1);
        add_edge(i,fi,wi,i-1);
    }
    if(n<=5000){
        for(int i=1;i<=n;i++){
            rt=i;
            memset(siz,0,sizeof(siz));
            dfs(rt,-1);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<n;j++){
                a[i][j]=dis[i][j]*w[j];
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<n;j++){
        //         cout << dis[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<n;j++){
        //       cout <<  a[i][j]<< " ";
        //     }
        //     cout << endl;
        // }
        for(int i=1;i<=n;i++){
            priority_queue<Node>q;
            for(int j=1;j<n;j++){
                q.push({a[i][j],j});
            }
            int lst=q.top().d;
            while(q.size()){
                if(lst>q.top().d)break;
                f[q.top().id]++;
                q.pop();
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans^=f[i];
            // cout << f[i] << " ";
        }
        cout << ans;
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=h[i];j;j=E[j].nxt){
                f[E[j].id]++;
            }
        }
        int ans=0;
        for(int i=1;i<n;i++){
            ans^=f[i];
            // cout << f[i] << " ";
        }
        cout << ans;
    }
    
    return 0;
}
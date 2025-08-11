#include <bits/stdc++.h>
using namespace std;

vector<int> a[105];
struct edge{
    int u, v;
    bool friend operator<(edge a,edge b){
        return (a.u == b.u ? a.v < b.v : a.u < b.u);
    }
};
set<edge> s;
struct road{
    int v, w;
};
queue<road> q;
bool vis[105];
int n;

void insert_road(int u,int v){
    s.insert((u < v ? (edge){u, v} : (edge){v, u}));
}

void erase_road(int u,int v){
    s.erase((u < v ? (edge){u, v} : (edge){v, u}));
}

void get_road(int root){
    for (int i = 0; i <= n;i++){
        vis[i] = false;
    }
    q.push({root, 0});
    vis[root] = true;
    while(!q.empty()){
        road u = q.front();
        q.pop();
        for(auto v:a[u.v]){
            if(vis[v]){
                continue;
            }
            q.push({v, u.w + 1});
            vis[v] = true;
            if(!(u.w%2) && u.w!=0){
                insert_road(root, v);
            }
        }
    }
}

int main(){
    cin >> n;
    for (int i = 1; i < n;i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n;i++){
        get_road(i);
    }
    size_t edge_count = s.size();
    cout << ((edge_count % 2) ? "First" : "Second") << endl;
    if(edge_count%2){
        edge top_edge = *(s.begin());
        erase_road(top_edge.u, top_edge.v);
        cout << top_edge.u << ' ' << top_edge.v << endl;
    }
    int u, v;
    while(cin>>u>>v){
        if(u==-1 && v==-1){
            return 0;
        }
        erase_road(u, v);
        edge top_edge = *(s.begin());
        erase_road(top_edge.u, top_edge.v);
        cout << top_edge.u << ' ' << top_edge.v << endl;
    }
}
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
set<edge> sts;
struct nodes{
    int v, color;
};
queue<nodes> q;
bool vis[105];
int n, color[105];

void insert_road(int u,int v){
    s.insert((u < v ? (edge){u, v} : (edge){v, u}));
}

void erase_road(int u,int v){
    s.erase((u < v ? (edge){u, v} : (edge){v, u}));
}

int main(){
    cin >> n;
    for (int i = 1; i < n;i++){
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        sts.insert((u < v ? (edge){u, v} : (edge){v, u}));
    }
    q.push({1,0});
    vis[1] = true;
    while(!q.empty()){
        nodes u = q.front();
        color[u.v] = u.color;
        q.pop();
        for(auto v:a[u.v]){
            if(vis[v]){
                continue;
            }
            q.push({v, u.color ^ 1});
            vis[v] = true;
        }
    }
    for (int u = 1; u <= n;u++){
        for (int v = u + 1; v <= n;v++){
            if(color[u]==color[v] || sts.count((u < v ? (edge){u, v} : (edge){v, u}))){
                continue;
            }
            s.insert((u < v ? (edge){u, v} : (edge){v, u}));
        }
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
        if(u==-1){
            return 0;
        }
        erase_road(u, v);
        edge top_edge = *(s.begin());
        erase_road(top_edge.u, top_edge.v);
        cout << top_edge.u << ' ' << top_edge.v << endl;
    }
}
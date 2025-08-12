#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct Edge{
    int nxt,to;
}E[N];int h[N],cnt;
void add_edge(int u,int v){
    E[++cnt].nxt=h[u];
    E[cnt].to=v;
    h[u]=cnt;
}
struct people{
    int s,t,id;
}p[N];
int vis[N];
int f[N][50],d[N];
void dfs(int u,int fa){
    d[u]=d[fa]+1;
    f[u][0]=fa;
    for(int i=1;(1<<i)<=d[u];i++){
        f[u][i]=f[f[u][i-1]][i-1];
    }
    for(int i=h[u];i;i=E[i].nxt){
        int v=E[i].to;
        if(v==fa)continue;
        dfs(v,u);
    }
}
int lca(int x,int y){
    if(d[x]<d[y])swap(x,y);
    for(int i=20;i>=0;i--){
        if(d[x]-(1<<i)>=d[y])
            x=f[x][i];
    }
    if(x==y)return x;
    for(int i=19;i>=0;i--){
        if(f[x][i]!=f[y][i]){
            x=f[x][i],y=f[y][i];
        }
    }
    return f[x][0];
}
vector<int> v[N];
int main(){
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    int T;
    cin >> T;
    while(T--){
        memset(vis,0,sizeof(vis));
        memset(f,0,sizeof(f));
        memset(d,0,sizeof(d));
        memset(p,0,sizeof(p));
        memset(E,0,sizeof(E));
        memset(h,0,sizeof(h));
        cnt=0;
        int n;
        cin >> n;
        int flag=0;
        for(int i=1;i<n;i++){
            int x,y;
            cin >> x >> y;
            add_edge(x,y);
            add_edge(y,x);
            if(x+1==y)flag++;
        }
        for(int i=1;i<=n;i++)if(!v[i].empty())v[i].clear();
        int m;
        cin >> m;
        for(int i=1;i<=m;i++){
            cin >> p[i].s >> p[i].t;
            p[i].id=i;
            v[p[i].t].push_back(p[i].s);
            vis[p[i].s]++;
        }
        if(flag==n-1){
            int k=0;
            for(int i=1;i<=m;i++){
                int sum=0,num=0;
                for(int j=max(p[i].t,p[i].s);j<=n;j++)if(!vis[j])sum++;
                for(int j=min(p[i].s,p[i].t);j<=max(p[i].s,p[i].t);j++){
                    if(vis[j])num++;
                }
                if(sum>=num)k++;
                else{
                    cout << "No\n";
                    k=0;
                    break;
                }
            }
            if(k==m)cout << "Yes\n";
        }
        else{
            int flag=0;
            dfs(2,0);
            for(int i=1;i<=m;i++){
                int gf=lca(p[i].s,p[i].t);
                for(int j=p[i].s;d[j]>d[gf];j=f[j][0]){//左边跳
                    if(v[j].size()){//在左边路径有终点
                        for(int k=0;k<v[j].size();k++){//遍历中点对应起点
                            int gf2=lca(j,v[j][k]);
                            for(int l=v[j][k];d[l]>d[gf2];l=f[l][0]){//新的左边跳
                                if(v[l].size()){
                                    for(int o=0;o<v[l].size();o++){
                                        if(v[l][o]==p[i].t){
                                            cout << "No\n";
                                            flag=1;
                                            break;
                                        }
                                    }
                                }
                                if(flag)break;
                            }
                            for(int l=j;d[l]>d[gf2];l=f[l][0]){//新的右边跳
                                if(v[l].size()){
                                    for(int o=0;o<v[l].size();o++){
                                        if(v[l][o]==p[i].t){
                                            cout << "No\n";
                                            flag=1;
                                            break;
                                        }
                                    }
                                }
                                if(flag)break;
                            }
                            if(flag)break;
                        } 
                    }
                    if(flag)break;
                }
                for(int j=p[i].t;d[j]>d[gf];j=f[j][0]){//右边跳
                    if(v[j].size()){//在左边路径有终点
                        for(int k=0;k<v[j].size();k++){//遍历中点对应起点
                            int gf2=lca(j,v[j][k]);
                            for(int l=v[j][k];d[l]>d[gf2];l=f[l][0]){//新的左边跳
                                if(v[l].size()){
                                    for(int o=0;o<v[l].size();o++){
                                        if(v[l][o]==p[i].t){
                                            cout << "No\n";
                                            flag=1;
                                            break;
                                        }
                                    }
                                }
                                if(flag)break;
                            }
                            for(int l=j;d[l]>d[gf2];l=f[l][0]){//新的右边跳
                                if(v[l].size()){
                                    for(int o=0;o<v[l].size();o++){
                                        if(v[l][o]==p[i].t){
                                            cout << "No\n";
                                            flag=1;
                                            break;
                                        }
                                    }
                                }
                                if(flag)break;
                            }
                            if(flag)break;
                        } 
                    }
                    if(flag)break;
                }
                if(flag)break;
            }
            if(!flag)cout << "Yes\n";
        }
        
    }
    return 0;
}
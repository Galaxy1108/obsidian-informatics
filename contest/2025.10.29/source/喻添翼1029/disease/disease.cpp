#include<bits/stdc++.h>
using namespace std;
const int mx=305;
int n,p;
int son[mx],fa[mx];
vector<int> e[mx];
void dfs0(int u,int f)
{
    fa[u]=f;
    for(int v:e[u])
    {
        if(v==f) continue;
        son[u]++;
        dfs0(v,u);
    }
}
int ans=500,vis[mx];
bool ok[mx][mx];
void dfs(int rd)
{
    queue<int> q;
    for(int i=1;i<=n;i++) 
        if(vis[i]==rd&&ok[fa[i]][i]) q.push(i);
    if(q.empty())
    {
        int cnt=0;
        for(int i=1;i<=n;i++) 
            if(vis[i]!=0) cnt++;
        ans=min(ans,cnt);
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v:e[u])
        {
            if(v==fa[u]) continue;
            vis[v]=rd+1;
        }
        for(int v:e[u])
        {
            if(v==fa[u]) continue;
            ok[u][v]=0;
            vis[v]=0;
            dfs(rd+1);
            ok[u][v]=1;
            vis[v]=rd+1;
        }
    }
    
}
int main()
{
    freopen("disease.in","r",stdin);
    freopen("disease.out","w",stdout);
    cin>>n>>p;
    for(int i=1;i<=p;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) ok[i][j]=1;
    vis[1]=1;
    dfs0(1,0);
    dfs(1);
    cout<<ans;
    return 0;
}

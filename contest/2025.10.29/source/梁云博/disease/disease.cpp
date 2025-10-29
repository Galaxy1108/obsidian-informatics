#include <bits/stdc++.h>
#define N 305
using namespace std;
int n,p;
mt19937 rd(time(0));

vector<int>g[N];
int siz[N],he[N],se[N],parent[N];
bool in[N];

void dfs(int u,int fa)
{
    parent[u]=fa;
    siz[u]=1;
    he[u]=se[u]=0;
    for(int v:g[u])
    {
        if(v==fa)continue;
        dfs(v,u);
        siz[u]+=siz[v];
        if(siz[v]>siz[he[u]])
        {
            se[u]=he[u];
            he[u]=v;
        }
        else if(siz[v]>siz[se[u]])se[u]=v;
    }
}

int Mobius()
{
    memset(in,0,sizeof(in));
    in[1]=true;
    int tot=1;
    
    vector<int> cur = {1};
    
    while(true)
    {
        vector<pair<int,int>>e;
        for(int u:cur)
        {
            for(int v:g[u])
            {
                if(!in[v]&&parent[v]==u)
                {
                    e.emplace_back(siz[v],v);
                }
            }
        }
        if(e.empty())break;
        
        if(e.size()>5)
        {
            nth_element(e.begin(),e.begin()+4,e.end(),greater<pair<int,int>>());
            e.resize(5);
        }
        else
        {
            sort(e.begin(),e.end(),greater<pair<int,int>>());
        }
        
        int idx=0;
        if(e.size()>1&&rd()%100<20)
        {
            idx=rd()%e.size();
        }
        
        int tmp=e[idx].second;
        
        vector<int>newin;
        for(int u:cur)
        {
            for(int v:g[u])
            {
                if(!in[v]&&v!=tmp)
                {
                    newin.push_back(v);
                }
            }
        }
        
        sort(newin.begin(),newin.end());
        newin.erase(unique(newin.begin(),newin.end()),newin.end());
        
        cur.clear();
        for(int v:newin)
        {
            if(!in[v])
            {
                in[v]=true;
                tot++;
                cur.push_back(v);
            }
        }
        
        if(cur.empty())break;
    }
    return tot;
}

int main()
{
    freopen("disease.in","r",stdin);
    freopen("disease.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>p;
    for(int i=1,u,v;i<=p;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int ans=n;
    for(int i=1;i<=20000;i++)
    {
        ans=min(ans,Mobius());
    }
    cout<<ans<<endl;
    
    return 0;
}
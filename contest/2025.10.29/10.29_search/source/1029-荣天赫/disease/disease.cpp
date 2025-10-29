#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct Qi
{
    int to;
    int next;
}edge[305];
int head[305],edge_cnt,siz[305],dep[305],maxd;
bool pro[305];
vector<int> Q[305];
vector<int> v[305];
inline void add(int u,int v)
{
    edge_cnt++;
    edge[edge_cnt].to=v;
    edge[edge_cnt].next=head[u];
    head[u]=edge_cnt;
    return ;
}
inline void init(int x)
{
    siz[x]=1;
    for(int i=head[x];i;i=edge[i].next)
    {
        dep[edge[i].to]=dep[x]+1;
        v[dep[edge[i].to]].push_back(edge[i].to);
        maxd=max(maxd,dep[edge[i].to]);
        init(edge[i].to);
        siz[x]+=siz[edge[i].to];
    }
    return ;
}
inline bool cmp(int a,int b)
{
    return siz[a]>siz[b];
}
inline void spread(int p)
{
    for(int i=head[p];i;i=edge[i].next)
    {
        pro[edge[i].to]=1;
        spread(edge[i].to);
    }
    return ;
}
int main()
{
    freopen("disease.in","r",stdin);
    freopen("disease.out","w",stdout);
    int n,p;
    cin>>n>>p;
    for(int i=1;i<=p;i++)
    {
        int u,v;
        cin>>u>>v;
        add(u,v);
        Q[u].push_back(v);
    }
    v[0].push_back(1);
    init(1);
    int lst=n,curr=1;
    for(int i=2;i<=n;i++)
    {
        sort(Q[i].begin(),Q[i].end(),cmp);
    }
    int d=0,posi,maxn=0;
    while(curr<lst)
    {
        maxn=0;
        for(int i=0;i<v[d].size();i++)
        {
            if(Q[v[d][i]][0]>maxn) maxn=Q[v[d][i]][0],posi=v[d][i];
        }
        pro[posi]=1;
        spread(posi);
        lst-=maxn;
        d++;
        for(int i=0;i<v[d].size();i++)
        {
            if(!pro[v[d][i]]) curr++;
        }
    }
    cout<<curr;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 2005;
int e[N][N],n,m;
struct Edge{
    int u,v,w;
}E[N*N/2];
bool cmp(Edge i,Edge j){return i.w < j.w;}
int res[N];
int main()
{
    //system("fc b.out b.out");
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    if(n == 1)
    {
        cout<<"0\n";
        return 0;
    }
    for(int i = 1;i <= n;i++) for(int j = i+1;j <= n;j++) cin>>e[i][j],e[j][i] = e[i][j],E[++m] = Edge{i,j,e[i][j]};
    sort(E+1,E+1+m,cmp);
    int U = E[1].u,V = E[1].v,W = E[1].w;
    for(int i = 1;i <= n;i++)
    {
        if(i == U || i == V)
        {
            res[i] = 0;
            continue;
        }
        res[i] = min(e[i][U],e[i][V])-W;
        int mn = 1e9;
        for(int j = 1;j <= n;j++) if(i!=j) mn = min(mn,e[i][j]);
        res[i] = min(res[i],2*mn-2*W);
    }
    for(int i = 1;i <= m;i++)
    {
        if(E[i].u == U || E[i].v == V) continue;
        int u = E[i].u,v = E[i].v,w = E[i].w;
        res[u] = min(res[u],res[v] + w-W);
        res[v] = min(res[v],res[u] + w-W);
    }
    for(int i = 1;i <= n;i++) cout<<res[i]+W*(n-1)<<"\n";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
long long Qread()
{
    long long x=0;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
    return x;
}
int n;
struct BIT{
    long long num[100010];
    void add_num(int x,int k){for(;x<=n;x+=(x&-x)) num[x]+=k;}
    long long get_sum(int x){long long ret=0;for(;x;x-=(x&-x)) ret+=num[x];return ret;}
    long long range_sum(int l,int r){return get_sum(r)-get_sum(l-1);}
    void reset(){memset(num,0,sizeof(num));}
}G1,G2;
typedef pair<int,int> pr;
vector<pr> ed[100010];
int tk[100010];
struct Node{
    int siz,bigson,ind,top,fa,dep;
}p[100010];
void add_edge(int u,int v,int ind)
{
    ed[u].push_back(make_pair(v,ind));
    ed[v].push_back(make_pair(u,ind));
}
#define v g.first
void dfs(int a,int fa)
{
    p[a].fa=fa;
    p[a].dep=p[fa].dep+1;
    for(pr &g:ed[a])
    {
        if(v==fa) continue;
        tk[g.second]=v;
        dfs(v,a);
        p[a].siz+=p[v].siz;
        if(p[v].siz>p[p[a].bigson].siz) p[a].bigson=v;
    }
    p[a].siz++;
}
int dfn;
void cut(int a,int top)
{
    p[a].ind=++dfn,p[a].top=top;
    if(p[a].bigson) cut(p[a].bigson,top);
    for(pr &g:ed[a])
    {
        if(v==p[a].fa||v==p[a].bigson) continue;
        cut(v,v);
    }
}
#undef v
void add_ed(int ind,int num,int op){G1.add_num(p[tk[ind]].ind,num),G2.add_num(p[tk[ind]].ind,op);}
long long line_sum(int u,int v)
{
    long long ret=0;
    while(p[u].top!=p[v].top)
    {
        if(p[p[u].top].dep<p[p[v].top].dep) swap(u,v);
        ret+=G1.range_sum(p[p[u].top].ind,p[u].ind);
        u=p[p[u].top].fa;
    }
    if(p[u].dep>p[v].dep) swap(u,v);
    if(u!=v) ret+=G1.range_sum(p[u].ind+1,p[v].ind);
    return ret;
}
int line_cnt(int u,int v)
{
    int ret=0;
    while(p[u].top!=p[v].top)
    {
        if(p[p[u].top].dep<p[p[v].top].dep) swap(u,v);
        ret+=G2.range_sum(p[p[u].top].ind,p[u].ind);
        u=p[p[u].top].fa;
    }
    if(p[u].dep>p[v].dep) swap(u,v);
    if(u!=v) ret+=G2.range_sum(p[u].ind+1,p[v].ind);
    return ret;
}
int ans[100010];
struct Cz{int ind,num;}z[100010];
bool operator<(Cz A,Cz B){return A.num<B.num;}
struct ques{int u,v,X,ind;long long Y;};
void solve(vector<ques> &Q,int l,int r)
{
    if(Q.size()==0||r<l) return;
    int mid=(l+r>>1);long long rem;
    vector<ques> Ql,Qr;
    for(int i=l;i<=mid;i++) add_ed(z[i].ind,z[i].num,1);
    for(ques &g:Q)
    {
        rem=line_sum(g.u,g.v);
        if(g.Y>=rem)
        {
            ans[g.ind]+=line_cnt(g.u,g.v);
            g.Y-=rem;
            Qr.push_back(g);
        }
        else Ql.push_back(g);
    }
    for(int i=l;i<=mid;i++) add_ed(z[i].ind,-z[i].num,-1);
    if(l<r) solve(Ql,l,mid),solve(Qr,mid+1,r);
}
int m,q,u,v,X;long long Y;
int main()
{
	freopen("currencies.in","r",stdin);
	freopen("currencies.out","w",stdout);
	
    n=Qread(),m=Qread(),q=Qread();
    for(int i=1;i<n;i++)
        add_edge(Qread(),Qread(),i);
    dfs(1,0);
    cut(1,1);
    vector<ques> Q;
    for(int i=1;i<=m;i++)
    {
        u=Qread(),X=Qread();
        z[i]=Cz{u,X};
        add_ed(u,1,1);
    }
    sort(z+1,z+m+1);
    for(int i=1;i<=q;i++)
    {
        u=Qread(),v=Qread(),X=Qread(),Y=Qread();
        ans[i]=X-line_sum(u,v);
        Q.push_back(ques{u,v,X,i,Y});
    }
    G1.reset(),G2.reset();
    solve(Q,1,m);
    for(int i=1;i<=q;i++)
        if(ans[i]>=0) printf("%d\n",ans[i]);
        else printf("-1\n");
    return 0;
}
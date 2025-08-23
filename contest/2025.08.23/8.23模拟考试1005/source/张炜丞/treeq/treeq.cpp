#include<bits/stdc++.h>
using namespace std;
#define int long long
// typedef long long ll;
// #define ls (p<<1)
// #define rs (p<<1|1)
// #define lb(x) (x&(-x))
const int N=1e7+5,inf=1e18;
// signed P=998244353;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}
// bool f1;
int n,h[N],f[N],g[N],F[N],siz[N],ans[N],son[N],ew[N];
struct edge{
    signed nxt,to;
    int w;
}e[N];
// bool f2;
void adde(int u,int v,int w){
    static int i=0;
    e[++i].nxt=h[u];
    h[u]=i;
    e[i].to=v;
    e[i].w=w;
}

void dfs1(int u){
    f[u]=g[u]=F[u]=-inf;siz[u]=1;
    for(int i=h[u],v;i;i=e[i].nxt){
        v=e[i].to;
        dfs1(v);
        f[u]=max(f[u],max(f[v],e[i].w*siz[v]));
        g[u]=max(g[u],max(g[v],e[i].w*(n-siz[v])));
        siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])son[u]=v;
    }
    F[u]=max(F[u],f[u]);
}

void dfs2(int u,int w){
    F[u]=max(F[u],w);
    int mx=w,mx2=-inf;
    for(int i=h[u],v;i;i=e[i].nxt){
        v=e[i].to;
        int mxv=max(f[v],e[i].w*(siz[v]));
        if(mxv>=mx)mx2=mx,mx=mxv;
        else if(mxv>=mx2)mx2=mxv;
    }
    for(int i=h[u],v;i;i=e[i].nxt){
        v=e[i].to;
        int mxv=max(f[v],e[i].w*(siz[v])),mxx=e[i].w*(n-siz[v]);
        if(mxv==mx)dfs2(v,max(mx2,mxx));
        else dfs2(v,max(mx,mxx));
    }
    // cout<<" /dfs2 u:"<<u<<" F:"<<F[u]<<endl;
}

unordered_map<int,int> ma;

void dfs_c(int u,const int & v){
    ma[F[u]]+=v;
    for(int i=h[u];i;i=e[i].nxt){
        dfs_c(e[i].to,v);
    }
}

void dfs3(int u,bool keep){
    // if(!son[u])return;
    for(int i=h[u],v;i;i=e[i].nxt){
        v=e[i].to; if(v==son[u])continue;
        dfs3(v,0);
    }
    if(son[u])dfs3(son[u],1);
    for(int i=h[u],v;i;i=e[i].nxt){
        v=e[i].to;if(v==son[u])continue;
        dfs_c(v,1);
    }
    ma[F[u]]++;
    int w=ew[u]*(n-siz[u]);
    ans[u]+=ma[w];
    // cout<<" /dfs3 u:"<<u<<" w:"<<w<<" ans:"<<ans[u]<<endl;
    if(!keep)dfs_c(u,-1);
}

void dfs4(int u,bool keep){
    // if(!son[u]){}
    for(int i=h[u],v;i;i=e[i].nxt){
        v=e[i].to; if(v==son[u])continue;
        dfs4(v,0);
    }
    if(son[u])dfs4(son[u],1);
    for(int i=h[u],v;i;i=e[i].nxt){
        v=e[i].to;if(v==son[u])continue;
        dfs_c(v,-1);
    }
    ma[F[u]]--;
    int w=ew[u]*siz[u];
    ans[u]+=ma[w];
    // cout<<" /dfs4 u:"<<u<<" w:"<<w<<" ans:"<<ans[u]<<endl;
    if(!keep)dfs_c(u,1);
}

signed main(){
    freopen("treeq.in","r",stdin);
    freopen("treeq.out","w",stdout);
    // int siz=&f1-&f2;
    // cout<<" siz:"<<siz/1024/1024<<" MB"<<endl;
    n=read();
    for(int i=2,fa,w;i<=n;++i){
        fa=read();w=read();ew[i]=w;
        adde(fa,i,w);
        // if(i%1000==0)cout<<" i:"<<i<<endl;
    }
    // cout<<" /n:"<<n<<endl;
    dfs1(1);
    // cout<<" /1"<<endl;
    dfs2(1,-inf);
    // cout<<" /2"<<endl;
    dfs3(1,1);
    // cout<<" /3"<<endl;
    dfs4(1,1);
    // cout<<" /4"<<endl;
    int an=0;
    for(int i=2;i<=n;++i){
        // cout<<" i:"<<i<<" ans:"<<ans[i]<<endl;
        an^=ans[i];
    }
    print(an);putchar('\n');
    return 0;
}

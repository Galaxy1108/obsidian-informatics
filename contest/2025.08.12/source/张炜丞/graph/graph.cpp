#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;

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

int T,n,m,k,etot,h[N],fa[N],fae[N],path[N];
bool evis[N<<1],vis[N],pvis[N<<1];
struct edge{
    int nxt,to;
}e[N<<1];

void adde(int u,int v){
    e[++etot].nxt=h[u];
    h[u]=etot;
    e[etot].to=v;
}

void dfs(int u){
    vis[u]=1;
    for(int i=h[u],v;i;i=e[i].nxt){
        if(evis[i])continue;
        v=e[i].to;if(vis[v])continue;
        fa[v]=u;fae[v]=i;
        dfs(v);
    }
}

void dfs2(int u){
    // cout<<" /dfs2 u:"<<u<<endl;
    vis[u]=1;
    for(int i=h[u],v;i;i=e[i].nxt){
        if(!evis[i]||pvis[i])continue;
        v=e[i].to;if(vis[v])continue;
        fa[v]=u;fae[v]=i;
        dfs2(v);
    }
}

bool work(int x,int y){
    for(int i=1;i<=m*2;++i)evis[i]=0;
    // for(int i=1;i<=n;++i)cnt[i]=0;
    for(int i=1;i<=k;++i){
        for(int i=1;i<=n;++i)vis[i]=0;
        dfs(x);
        if(!vis[y])return 0;
        int p=y;
        // cout<<" i:"<<i<<endl;
        while(p!=x){
            evis[fae[p]]=1;
            if(evis[fae[p]^1]){
                evis[fae[p]]=evis[fae[p]^1]=0;
                // cout<<" /yh e:"<<(fae[p])/2<<endl;
            }
            // cout<<" /work x:"<<x<<" y:"<<y<<" p:"<<p<<endl;
            p=fa[p];
        }
    }
    print(x);putchar(' ');print(y);putchar('\n');
    for(int i=1;i<=k;++i){
        for(int i=1;i<=n;++i)vis[i]=0;
        dfs2(x);int cn=0;
        for(int p=y;p!=x;p=fa[p]){
            path[++cn]=p;pvis[fae[p]]=1;
            // cout<<" p:"<<p<<" e:"<<fae[p]<<endl;
        }
        print(cn+1);putchar(' ');print(x);putchar(' ');
        for(int i=cn;i>=1;--i)print(path[i]),putchar(' ');
        putchar('\n');
    }
    return 1;
}

signed main(){
    freopen("graph.in","r",stdin);
    freopen("graph.out","w",stdout);
    T=read();
    while(T--){
        n=read();m=read();k=m/(n-1)+(m%(n-1)>0);
        for(int i=1;i<=n;++i)h[i]=0;etot=1;
        for(int i=1;i<=m*2;++i)pvis[i]=0;
        for(int i=1,u,v;i<=m;++i){
            u=read();v=read();
            adde(u,v);adde(v,u);
        }
        for(int i=1;i<=n;++i){
            int flag=0;
            for(int j=1;j<=n;++j)
            if(i!=j&&work(i,j)){flag=1;break;}
            if(flag)break;
        }
    }
    return 0;
}
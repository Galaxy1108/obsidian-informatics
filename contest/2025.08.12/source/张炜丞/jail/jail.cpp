#include<bits/stdc++.h>
using namespace std;
#define lb(x) (x&(-x))
const int N=1.2e5+5;

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

int T,n,m,h[N],etot,qx[N],qy[N],t1[N],t2[N],f[N],d[N],siz[N],dfn[N],tot,ql[N],top[N],son[N];
bool vis[N];
struct edge{
    int nxt,to;
}e[N<<1];

void adde(int u,int v){
    e[++etot].nxt=h[u];
    h[u]=etot;
    e[etot].to=v;
}

void dfs1(int u,int fa){
    f[u]=fa;d[u]=d[fa]+1;siz[u]=1;dfn[u]=++tot;son[u]=0;
    for(int i=h[u],v;i;i=e[i].nxt){
        v=e[i].to;if(v==fa)continue;
        dfs1(v,u);siz[u]+=siz[v];
        if(siz[v]>siz[son[u]])son[u]=v;
    }
}

void dfs2(int u,int t){
    top[u]=t;
    if(!son[u])return;
    dfs2(son[u],t);
    for(int i=h[u],v;i;i=e[i].nxt){
        v=e[i].to;if(v==f[u]||v==son[u])continue;
        dfs2(v,v);
    }
}

int lca(int x,int y){
    while(top[x]!=top[y]){
        if(d[top[x]]<d[top[y]])swap(x,y);
        x=f[top[x]];
    }
    if(d[x]<d[y])swap(x,y);
    return y;
}

void add(int x,int v,int *t){
    if(!x)return;
    while(x<=n){
        t[x]+=v;
        x+=lb(x);
    }
}

int sum(int x,int *t){
    int ans=0;
    while(x){
        ans+=t[x];
        x-=lb(x);
    }
    return ans;
}
int sum(int l,int r,int *t){
    return sum(r,t)-sum(l-1,t);
}

void update(int x,int v){
    add(dfn[qx[x]],v,t1);add(dfn[qx[x]]+siz[qx[x]],-v,t1);
    add(dfn[qx[x]],v,t2);add(dfn[qy[x]],v,t2);
    add(dfn[ql[x]],-v,t2);add(dfn[f[ql[x]]],-v,t2);
}

bool check(int x){
    int sum1=sum(dfn[qx[x]],t1)+sum(dfn[qy[x]],t1)-sum(dfn[ql[x]],t1)-sum(dfn[f[ql[x]]],t1)-1;
    int sum2=sum(dfn[qy[x]],dfn[qy[x]]+siz[qy[x]]-1,t2)-1;
    //cout<<" /check x:"<<x<<" sum1:"<<sum1<<" sum2:"<<sum2<<endl;
    return sum1==0&&sum2==0;
}

void work(){
    n=read();
    for(int i=1;i<=n;++i)t1[i]=t2[i]=h[i]=0;
    etot=tot=0;
    for(int i=1,u,v;i<n;++i){
        u=read();v=read();
        adde(u,v);adde(v,u);
    }
    dfs1(1,0);dfs2(1,1);
    m=read();
    for(int i=1;i<=m;++i){
        qx[i]=read();qy[i]=read();ql[i]=lca(qx[i],qy[i]);
        update(i,1);
        vis[i]=0;
    }
    for(int i=1;i<=m;++i){
        int x=rand()%m+1,y=rand()%m+1;
        if(x!=y){
            swap(qx[x],qx[y]);
            swap(qy[x],qy[y]);
            swap(ql[x],ql[y]);
        }
    }
    for(int i=1;i<=m;++i){
        bool flag=0;
        for(int j=1;j<=m;++j){
            if(vis[j])continue;
            if(check(j)){
                update(j,-1);
                flag=1;vis[j]=1;
                break;
            }
        }
        if(!flag){
            puts("No");return;
        }
    }
    puts("Yes");
}

signed main(){
    srand(time(0));
    freopen("jail.in","r",stdin);
    freopen("jail.out","w",stdout);
    T=read();
    while(T--){
        work();
    }
    return 0;
}


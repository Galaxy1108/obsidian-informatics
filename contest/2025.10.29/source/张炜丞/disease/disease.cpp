#include<bits/stdc++.h>
using namespace std;
const int N=305;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='1')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int n,h[N],d[N],siz[N],fa[N],m,ans,mxd;
bool f[N];
struct edge{
    int nxt,to;
}e[N<<1];
vector<int> a[N];

void adde(int u,int v){
    static int i=0;
    e[++i].nxt=h[u];
    h[u]=i;
    e[i].to=v;
}

void dfs(int u,int fa){
    ::fa[u]=fa;siz[u]=1;d[u]=d[fa]+1;f[u]=0;
    mxd=max(mxd,d[u]);
    a[d[u]].push_back(u);
    for(int i=h[u],v;i;i=e[i].nxt){
        v=e[i].to;
        if(v==fa)continue;
        dfs(v,u);
        siz[u]+=siz[v];
    }
}

void bj(int u,bool flag){
    f[u]=flag;
    for(int i=h[u],v;i;i=e[i].nxt){
        v=e[i].to;
        if(v==fa[u])continue;
        bj(v,flag);
    }
}

void work(int dep){
    // cout<<" dep:"<<dep<<" f:";for(int i=1;i<=n;++i)cout<<f[i]<<" ";cout<<endl;
    if(dep==mxd+1){
        int an=0;
        for(int i=1;i<=n;++i)if(!f[i])++an;
        ans=min(ans,an);
        return;
    }
    bool flag=0;
    for(int i:a[dep]){
        // if(d[i]!=dep)continue;
        if(f[i])continue;
        flag=1;
        bj(i,1);
        work(dep+1);
        bj(i,0);
    }
    if(flag==0)work(dep+1);
}

signed main(){
   freopen("disease.in","r",stdin);
   freopen("disease.out","w",stdout);
    n=read();m=read();
    for(int i=1,u,v;i<=m;++i){
        u=read();v=read();
        adde(u,v);adde(v,u);
    }
    ans=n;
    dfs(1,0);
    work(2);
    print(ans);putchar('\n');
    
    return 0;
}

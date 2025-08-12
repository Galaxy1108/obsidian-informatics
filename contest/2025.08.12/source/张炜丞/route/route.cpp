#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=105,M=10005,inf=1e18;

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

int n,m,s,q,h[N],dis[N];
bool vis[N];
struct edge{
    int nxt,to,w,c;
}e[M];

void adde(int u,int v,int w,int c){
    static int i=0;
    e[++i].nxt=h[u];
    h[u]=i;
    e[i].to=v;e[i].w=w;e[i].c=c;
}

int jc(int d,int i){
    int tim=d%s;
    if(tim<=e[i].c-e[i].w)return d+e[i].w;
    else return (d/s+1)*s+e[i].w;
}

void dij(int u,int tim){
    for(int i=0;i<=n;++i)dis[i]=inf,vis[i]=0;
    dis[u]=tim;
    for(int i=1;i<=n;++i){
        int mi=0;
        for(int j=1;j<=n;++j){
            if(!vis[j]&&dis[j]<dis[mi])mi=j;
        }
        if(mi==0)return;u=mi;
        vis[u]=1;
        for(int j=h[u],v;j;j=e[j].nxt){
            v=e[j].to;
            int w=jc(dis[u],j);
            //cout<<" /dij u:"<<u<<" v:"<<v<<" disu:"<<dis[u]<<" jc:"<<w<<endl;
            if(dis[v]>w){
                dis[v]=w;
            }
        }
    }
}

signed main(){
    freopen("route.in","r",stdin);
    freopen("route.out","w",stdout);
    n=read();m=read();s=read();q=read();
    for(int i=1,u,v,x,y;i<=m;++i){
        u=read()+1;v=read()+1;x=read();y=read();
        adde(u,v,x,y);adde(v,u,x,y);
    }
    for(int i=1,u,v,t;i<=q;++i){
        u=read()+1;v=read()+1;t=read();
        dij(u,t);
        print(dis[v]-dis[u]);putchar('\n');
    }
    return 0;
}

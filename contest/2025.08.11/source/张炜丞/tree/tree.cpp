#include<bits/stdc++.h>
using namespace std;
#define lb(x) (x&(-x))
const int N=5e5+5,inf=1e9;
const double eps=1e-9;

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

int n,h[N],a[N];
long long st[12];
long double f[N];
int mi=inf,mx=-inf;
struct edge{
    int nxt,to;
}e[N<<1];

void adde(int u,int v){
    static int i=0;
    e[++i].nxt=h[u];
    h[u]=i;
    e[i].to=v;
}

void dfs(int u,int fa,const long double &x){
    f[u]=a[u]-x;
    for(int i=h[u],v;i;i=e[i].nxt){
        v=e[i].to;
        if(v==fa)continue;
        dfs(v,u,x);
        f[u]=max(f[u],f[u]+f[v]);
    }
}

void print(long double x){
    //cout<<" /print x:"<<x<<endl;
    int siz=0;
    while(x>st[siz])++siz;
    for(int i=siz-1;i>=0;--i){
        //cout<<" i:"<<i<<" x:"<<x<<" v:"<<(int)(x/st[i])<<endl;
        putchar((int)(x/st[i])+48);
        x-=(int)(x/st[i])*st[i];
    }
    putchar('.');
    for(int i=1;i<=9;++i){
        x*=10;
        int v=x;
        putchar(v+48);
        x-=v;
    }
    putchar('\n');
}

signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    st[0]=1;for(int i=1;i<=10;++i)st[i]=st[i-1]*10;
    n=read();
    for(int i=2,fa;i<=n;++i){
        fa=read();
        adde(fa,i);
    }
    for(int i=1;i<=n;++i){
        a[i]=read();
        mi=min(mi,a[i]);mx=max(mx,a[i]);
    }
    for(int i=1;i<=n;++i){
        long double l=mi,r=mx,mid;
        while(r-l>eps){
            mid=(l+r)/2;
            dfs(i,0,mid);
            if(f[i]>0)l=mid;
            else r=mid;
        }
        print(l);
    }
    return 0;
}
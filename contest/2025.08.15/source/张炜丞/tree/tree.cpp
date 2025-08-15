#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5,K=20,inf=1e18;

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
int n;
struct edge{
    int nxt,to,w;
}e[N<<1];

void adde(int u,int v,int w,int *h){
    static int i=0;
    e[++i].nxt=h[u];
    h[u]=i;
    e[i].to=v;
    e[i].w=w;
}

struct tree1{
    int h[N],f[N],d[N],dis[N],dfn[N],tot,st[N][K],lg[N];
    void dfs1(int u,int fa){
        f[u]=fa;d[u]=d[fa]+1;dfn[u]=++tot;st[tot][0]=u;
        for(int i=h[u],v;i;i=e[i].nxt){
            v=e[i].to;dis[v]=dis[u]+e[i].w;
            dfs1(v,u);
        }
    }
    int min_dep(int x,int y){
        return d[x]<d[y]?x:y;
    }
    void init(){
        lg[0]=-1;
        for(int i=1;i<=n;++i)lg[i]=lg[i>>1]+1;
        for(int i=1;i<=lg[n];++i){
            for(int j=1;j+(1<<i)-1<=n;++j){
                st[j][i]=min_dep(st[j][i-1],st[j+(1<<i-1)][i-1]);
            }
        }
    }
    int lca(int x,int y){
        if(x==y)return x;
        x=dfn[x],y=dfn[y];if(x>y)swap(x,y);++x;
        int k=lg[y-x+1];
        return f[min_dep(st[x][k],st[y-(1<<k)+1][k])];
    }
    int len(int x,int y){
        int l=lca(x,y);
        return dis[x]+dis[y]-dis[l]*2;
    }
}t1;

// struct node{
//     int v,l,r,tag,lz;
// }t[N<<2];

// void up(int p){
//     t[p].v=t[ls].v+t[rs].v;
// }

// void change(int p,int v){
//     t[p].v+=v*(t[p].r-t[p].l+1);
//     t[p].tag+=v;
// }

// void change2(int p,int v){
//     t[p].v=v*(t[p].r-t[p].l+1);
//     t[p].lz=v;t[p].tag=0;
// }

// void down(int p){
//     if(t[p].lz!=inf){
//         change2(ls,t[p].lz);
//         change2(rs,t[p].lz);
//         t[p].lz=inf;
//     }
//     if(t[p].tag){
//         change(ls,t[p].tag);
//         change(rs,t[p].tag);
//         t[p].tag=0;
//     }
// }

// void build(int p,int l,int r){
//     t[p]={0,l,r,0,inf};
//     if(l==r)return;
//     int mid=l+r>>1;
//     build(ls,l,mid);build(rs,mid+1,r);
// }

// void update(int p,const int &ql,const int &qr,const int &qv){
//     if(ql<=t[p].l&&t[p].r<=qr){
//         change(p,qv);return;
//     }
//     int mid=t[p].l+t[p].r>>1;down(p);
//     if(ql<=mid)update(ls,ql,qr,qv);
//     if(qr>mid)update(rs,ql,qr,qv);
//     up(p);
// }

// void insert(int p,const int &ql,const int &qr,const int &qv){
//     if(ql<=t[p].l&&t[p].r<=qr){
//         change2(p,qv);return;
//     }
//     int mid=t[p].l+t[p].r>>1;down(p);
//     if(ql<=mid)insert(ls,ql,qr,qv);
//     if(qr>mid)insert(rs,ql,qr,qv);
//     up(p);
// }

// int query(int p){
//     if(t[p].l==t[p].r)return t[p].v>=0?t[p].v:0;
//     if(t[ls].v<=0)return query(ls);
//     else return query(rs)+t[ls].v;
// }

// int query(int p,const int &ql,const int &qr){
//     if(ql<=t[p].l&&t[p].r<=qr)return t[p].v;
//     int mid=t[p].l+t[p].r>>1,ans=0;
//     if(ql<=mid)ans+=query(ls,ql,qr);
//     if(qr>mid)ans+=query(rs,ql,qr);
//     return ans;
// }

// struct node{
//     int v,sum,siz,cnt,ssiz,rnk,ls,rs,tag;
// }t[N];

// int newnode(int x){
//     static int i=0;
//     t[++i]={x,x,1,1,1,rand(),0,0};
//     return i;
// }

// void up(int p){
//     t[p].siz=t[t[p].ls].siz+t[t[p].rs].siz+1;
//     t[p].ssiz=t[t[p].ls].ssiz+t[t[p].rs].ssiz+t[p].cnt;
//     t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum+t[p].v;
// }

// void change(int p,int v){
//     t[p].v+=v;
//     t[p].sum+=v*t[p].ssiz;
//     t[p].tag+=v;
// }

// void down(int p){
//     if(t[p].tag){
//         if(t[p].ls)change(t[p].ls,t[p].tag);
//         if(t[p].rs)change(t[p].rs,t[p].tag);
//         t[p].tag=0;
//     }
// }

// void split_siz(int p,int v,int &x,int &y){
//     if(!p)return x=y=0,void();
//     down(p);
//     if(v<=t[t[p].ls].siz)y=p,split_siz(t[p].ls,v,x,t[p].ls);
//     else x=p,split_siz(t[p].rs,v-t[t[p].ls].siz-1,t[p].rs,y);
//     up(p);
// }

// void split_val(int p,int v,int &x,int &y){
//     if(!p)return x=y=0,void();
//     down(p);
//     if(v>t[p].v)y=p,split_val(t[p].ls,v,x,t[p].ls);
//     else x=p,split_val(t[p].rs,v,t[p].rs,y);
//     up(p);
// }

// int merge(int x,int y){
//     if(!x||!y)return x+y;
//     if(t[x].rnk<t[y].rnk)return down(x),t[x].rs=merge(t[x].rs,y),up(x),x;
//     else return down(y),t[y].ls=merge(x,t[y].ls),up(y),y;
// }

struct tree2{
    int h[N],a[N],f[N],ans[N],root;
    int dfs2(int u,int x,int sum,int cnt){
        int ans=sum+t1.len(u,x);
        cnt+=a[u];sum+=cnt;
        for(int i=h[u],v;i;i=e[i].nxt){
            v=e[i].to;
            ans=max(ans,dfs2(v,x,sum,cnt));
        }
        return ans;
    }
    void dfs1(int u){
        for(int i=h[u],v;i;i=e[i].nxt){
            v=e[i].to;
            dfs1(v);
        }
        ans[u]=dfs2(u,u,0,0);
    }

    // void work1(){
    //     int rtl,rtr;
    //     ans[n]=0;root=newnode(0);
    //     int ps=0;
    //     for(int i=n-1;i>=1;--i){
    //         ps+=t1.len(i,i+1);
    //         ps+=a[i]*(n-i);
    //         int v=-ps;
    //         change(root,-a[i]);
    //         int l1=t[root].sum;
    //         split_siz(root,t[root].siz-1,rtl,rtr);
    //         int l2=t[rtl].sum;
    //         int cn=1;
    //         while(rtl&&l1-l2<=v-l1){
    //             cn+=t[rtr].cnt;
    //             root=rtl;
    //             l1=t[root].sum;
    //             split_siz(root,t[root].siz-1,rtl,rtr);
    //             l2=t[rtl].sum;
    //         }
    //         int dd=newnode();t[v].cnt=t[v].ssiz=cn;
    //         root=merge(merge(rtl,rtr),dd);
    //     }
    // }
}t2;

signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    n=read();
    bool flag1=1,flag2=1;
    for(int i=2;i<=n;++i){
        t1.f[i]=read();
    }
    for(int i=2;i<=n;++i){
        int w=read();
        adde(t1.f[i],i,w,t1.h);
    }
    t1.dfs1(1,0);t1.init();
    for(int i=2;i<=n;++i){
        t2.f[i]=read();
        adde(t2.f[i],i,0,t2.h);
    }
    for(int i=1;i<=n;++i)t2.a[i]=read();

    t2.dfs1(1);
    for(int i=1;i<=n;++i){
        print(t2.ans[i]);putchar(' ');
    }
    putchar('\n');
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
// typedef long long ll;
#define ls (p<<1)
#define rs (p<<1|1)
#define lb(x) (x&(-x))
const int N=2e5+5;
signed P=998244353;

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

int n,a[N];
struct node{
    int l,r,mx,mi,sum;
}t[N<<2];

void up(int p){
    t[p].sum=t[ls].sum+t[rs].sum;
    t[p].mx=max(t[ls].mx,t[rs].mx);
    t[p].mi=min(t[ls].mi,t[rs].mi);
}

void build(int p,int l,int r){
    t[p].l=l;t[p].r=r;
    if(l==r)return t[p].mx=t[p].mi=t[p].sum=a[l],void();
    int mid=l+r>>1;
    build(ls,l,mid);build(rs,mid+1,r);
    up(p);
}

void update(int p,const int &x,const int &v){
    if(t[p].l==t[p].r)return t[p].mx=t[p].mi=t[p].sum=v,void();
    int mid=t[p].l+t[p].r>>1;
    if(x<=mid)update(ls,x,v);
    else update(rs,x,v);
    up(p);
}

int q[N],cnt,tr[N],tv[N];

void query(int p,const int &ql,const int &qr){
    if(ql<=t[p].l&&t[p].r<=qr)return q[++cnt]=p,void();
    int mid=t[p].l+t[p].r>>1;
    if(ql<=mid)query(ls,ql,qr);
    if(qr>mid)query(rs,ql,qr);
}

int query_mi(int p,int v){
    if(t[p].l==t[p].r)return t[p].l;
    if(t[rs].mi<=v)return query_mi(rs,v);
    else return query_mi(ls,v);
}

int find_mi(int y,int v){
    cnt=0;
    query(1,1,y);
    for(int i=cnt;i>=1;--i){
        if(t[q[i]].mi<=v)return query_mi(q[i],v);
    }
    return -1;
}

int query_sum(int p,int v){
    // cout<<" /query_sum p:"<<p<<" v:"<<v<<" s:"<<t[p].sum<<" r:"<<t[rs].sum<<endl;
    if(t[p].l==t[p].r)return v>=t[p].sum?t[p].l:t[p].l+1;
    if(t[rs].sum>=v)return query_sum(rs,v);
    else return query_sum(ls,v-t[rs].sum);
}

int find_sum(int y,int v){
    cnt=0;
    query(1,1,y);
    for(int i=cnt;i>=1;--i){
        // cout<<" /find_sum i:"<<i<<" s:"<<t[q[i]].sum<<" l:"<<t[q[i]].l<<" r:"<<t[q[i]].r<<endl;
        if(t[q[i]].sum>=v)return query_sum(q[i],v);
        v-=t[q[i]].sum;
    }
    return 1;
}

int query_mx(int p,int v){
    if(t[p].l==t[p].r)return t[p].l;
    if(t[ls].sum>=v)return query_mx(ls,v);
    else query_mx(rs,v-t[ls].sum);
}

void ad(int &x,int v){
    x+=v;
    if(x>P)x-=P;
}

void add(int x,int v,int *tr){
    while(x<=n){
        tr[x]=((tr[x]+v)%P+P)%P;
        x+=lb(x);
    }
}

int sum(int x,int *tr){
    int ans=0;
    while(x){
        ad(ans,tr[x]);
        x-=lb(x);
    }
    return ans;
}
int sum(int x,int y,int *t){
    return ((sum(y,t)-sum(x-1,t))%P+P)%P;
}

void work(){
    int mx=t[1].mx;
    int p=query_mx(1,mx),ans=sum(p,tr);
    int s=sum(p,tv)-mx;
    // cout<<" /work p:"<<p<<" ans:"<<ans<<" s:"<<s<<endl;
    while(p){
        // cout<<" p:"<<p<<endl;
        int p1=find_mi(p,s);
        if(p1==-1)break;
        int p2=find_sum(p1,s);
        ans=((ans-sum(p2,p1,tr))%P+P)%P;
        s=((s-sum(p2,p1,tv))%P+P)%P;
        // cout<<" p:"<<p<<" p1:"<<p1<<" p2:"<<p2<<" ans:"<<ans<<" s:"<<s<<endl;
        p=p2-1;
    }
    print(ans);putchar('\n');
}

signed main(){
    freopen("imperishable.in","r",stdin);
    freopen("imperishable.out","w",stdout);
    int Num=read();
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    build(1,1,n);
    int v=1;
    for(int i=1;i<=n;++i){
        ad(v,v);
        add(i,v,tr);
        add(i,a[i],tv);
    }
    work();
    int Q=read();
    for(int i=1;i<=Q;++i){
        int x=read(),y=read();
        update(1,x,y);
        add(x,-a[x],tv);
        a[x]=y;
        add(x,y,tv);
        work();
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int P=1e9+9;
#define int long long
#define ls (p<<1)
#define rs (p<<1|1)
const int N=1e5+5;

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

int n,m,Q,ans[N];
struct qnode{
    int tim,l,r,v,id;
    bool operator<(const qnode &n1){
        return tim<n1.tim;
    }
}q[N+N];
struct cnode{
    int l,r,x;
}c[N];
struct node{
    int v,hv,l,r,add,cnth,addh;
    void change_v(int val){
        v=(v+val*(r-l+1))%P;
        add=(add+val)%P;
    }
    void change_hv(int fcnth,int faddh){
        hv=(hv+v*fcnth%P+(r-l+1)*faddh%P)%P;
        cnth=(cnth+fcnth)%P;
        addh=(addh+fcnth*add%P+faddh)%P;
    }
}t[N<<2];

void up(int p){
    t[p].v=(t[ls].v+t[rs].v)%P;
    t[p].hv=(t[ls].hv+t[rs].hv)%P;
}

void down(int p){
    if(t[p].addh||t[p].cnth){
        t[ls].change_hv(t[p].cnth,t[p].addh);
        t[rs].change_hv(t[p].cnth,t[p].addh);
        t[p].cnth=t[p].addh=0;
    }
    if(t[p].add){
        t[ls].change_v(t[p].add);
        t[rs].change_v(t[p].add);
        t[p].add=0;
    }
}

void build(int p,int l,int r){
    t[p]={0,0,l,r,0,0,0};
    if(l==r)return;
    int mid=l+r>>1;
    build(ls,l,mid);build(rs,mid+1,r);
}

void update_add(int p,const int &ql,const int &qr,const int &qv){
    if(ql<=t[p].l&&t[p].r<=qr){
        t[p].change_v(qv);return;
    }
    down(p);
    int mid=t[p].l+t[p].r>>1;
    if(ql<=mid)update_add(ls,ql,qr,qv);
    if(qr>mid)update_add(rs,ql,qr,qv);
    up(p);
}

int query_hv(int p,const int &ql,const int &qr){
    if(ql<=t[p].l&&t[p].r<=qr){
        return t[p].hv;
    }down(p);
    int mid=t[p].l+t[p].r>>1,ans=0;
    if(ql<=mid)ans=(ans+query_hv(ls,ql,qr))%P;
    if(qr>mid)ans=(ans+query_hv(rs,ql,qr))%P;
    return ans;
}

void output(int p){
    if(t[p].l==t[p].r){
        cout<<t[p].hv<<" ";return;
    }
    down(p);
    output(ls);output(rs);
}

signed main(){
    freopen("newfile.in","r",stdin);
    freopen("newfile.out","w",stdout);
    n=read();m=read();Q=read();
    build(1,1,n);
    for(int i=1;i<=m;++i){
        c[i].l=read();c[i].r=read();c[i].x=read();
    }
    for(int i=1,u,d,l,r;i<=Q;++i){
        u=read();d=read();l=read();r=read();
        q[i]={u-1,l,r,-1,i};
        q[i+Q]={d,l,r,1,i};
    }
    sort(q+1,q+Q+Q+1);
    int j=1;
    while(j<=Q+Q&&q[j].tim<=0)++j;
    for(int i=1;i<=m;++i){
        update_add(1,c[i].l,c[i].r,c[i].x);
        t[1].change_hv(1,0);
        // output(1);cout<<endl;
        while(j<=Q+Q&&q[j].tim<=i){
            ans[q[j].id]+=query_hv(1,q[j].l,q[j].r)*q[j].v;
            ++j;
        }
    }
    for(int i=1;i<=Q;++i){
        ans[i]=(ans[i]%P+P)%P;
        print(ans[i]);putchar('\n');
    }
    return 0;
}
/*
5 5 5
1 3 2
2 4 2
3 5 2
1 4 1
2 3 1
1 3 2 4
4 5 1 5
2 5 1 3
1 3 1 1
1 5 1 5

*/
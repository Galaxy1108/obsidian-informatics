#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lb(x) (x&(-x))
#define ls (p<<1)
#define rs (p<<1|1)
const int N=2e5+5,K=20;

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

int n,q,a[N],op[N],qx[N],qy[N];
struct Bit{
    int t[N];
    void add(int x,int v){
        while(x<=n){
            t[x]+=v;
            x+=lb(x);
        }
    }
    int sum(int x){
        int ans=0;
        while(x){
            ans+=t[x];
            x-=lb(x);
        }
        return ans;
    }
    int sum(int x,int y){
        return sum(y)-sum(x-1);
    }
}bit;

struct segtree{
    int t[N];
    void up(int p){
        t[p]=abs(t[ls]-t[rs]);
    }
    void build(int p,int l,int r){
        if(l==r){
            t[p]=a[l];return;
        }
        int mid=l+r>>1;
        build(ls,l,mid);
        build(rs,mid+1,r);
        up(p);
    }
    void insert(int p,int l,int r,const int &k,const int &v){
        if(l==r){t[p]=v;return;}
        int mid=l+r>>1;
        if(k<=mid)insert(ls,l,mid,k,v);
        else insert(rs,mid+1,r,k,v);
        up(p);
    }
    int qry(){return t[1];}
}t1;

int st[N][K];

void init(){
    for(int i=1;i<=n;++i)st[i][0]=a[i];
    for(int j=1;j<K;++j){
        for(int i=1;i<=n-(1<<j)+1;++i){
            st[i][j]=abs(st[i][j-1]-st[i+(1<<j-1)][j-1]);
        }
    }
}

int dfs(int p,int k){
    if(k==0)return a[p];
    else return abs(dfs(p,k-1)-dfs(p+(1<<k-1),k-1));
}

void work1(){
    for(int i=1;i<=q;++i){
        if(op[i]==1)a[qx[i]]=qy[i];
        else {
            print(dfs(qx[i],qy[i]));
            putchar('\n');
        }
    }
}

void work2(){
    t1.build(1,1,n);
    for(int i=1;i<=q;++i){
        if(op[i]==1){
            t1.insert(1,1,n,qx[i],qy[i]);
        }
        else{
            print(t1.qry());putchar('\n');
        }
    }
}

void work3(){
    for(int i=1;i<=n;++i){
        bit.add(i,a[i]);
    }
    for(int i=1;i<=q;++i){
        if(op[i]==1){
            bit.add(qx[i],-a[qx[i]]);
            a[qx[i]]=qy[i];
            bit.add(qx[i],a[qx[i]]);
        }
        else{
            //cout<<" sum:"<<bit.sum(qx[i],qx[i]+(1<<qy[i])-1)<<endl;
            print(bit.sum(qx[i],qx[i]+(1<<qy[i])-1)&1);putchar('\n');
        }
    }
}

void work4(){
    init();
    for(int i=1;i<=n;++i){
        print(st[qx[i]][qy[i]]);putchar('\n');
    }
}

signed main(){
    freopen("duel.in","r",stdin);
    freopen("duel.out","w",stdout);
    bool flag1=1,flag2=1,flag3=1;
    n=read();q=read();
    for(int i=1;i<=n;++i){
        a[i]=read();if(a[i]>1)flag2=0;
    }
    for(int i=1;i<=q;++i){
        op[i]=read();qx[i]=read();qy[i]=read();
        if(op[i]==1){
            flag3=0;
            if(qy[i]>1)flag2=0;
        }
        else{
            if(n!=(1<<qy[i]))flag1=0;
        }
    }
    if(n<=1000&&q<=1000)work1();
    else if(flag1)work2();
    else if(flag2)work3();
    else if(flag3)work4();
    else{
        work1();
    }
    return 0;
}
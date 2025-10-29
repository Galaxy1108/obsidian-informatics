#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
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
 
int n,m,a[N];

struct bj{
    ll p1,p2;
    bj merge(const bj &b1,int len)const{
        bj ans=*this;
        if(!p1){
            ans.p1=b1.p1?b1.p1+len:0;
            ans.p2=b1.p2?b1.p2+len:0;
        }
        else if(!p2)ans.p2=b1.p1?b1.p1+len:0;
        return ans;
    }
    void output(){
        cout<<" p1:"<<p1<<" p2:"<<p2;
    }
};

struct node{
    ll len;
    ll sum;
    bj bl,br;
    bj cl,cr;
    void output(){
        cout<<" len:"<<len<<" sum:"<<sum<<" bl:";bl.output();cout<<" br:";br.output();cout<<" cl:";cl.output();cout<<" cr:";cr.output();cout<<endl;
    }
}t[N<<2];

#define ls (p<<1)
#define rs (p<<1|1)

node up(const node &n1,const node &n2){
    node ans;
    ans.len=n1.len+n2.len;
    ans.bl=n1.bl.merge(n2.bl,n1.len);
    ans.br=n2.br.merge(n1.br,n2.len);
    ans.sum=n1.sum+n2.sum;
    int s1=(n1.br.p1-1)/2,s2=(n2.bl.p1-1)/2,d1=(n1.br.p1/2),d2=n2.bl.p1/2;
    if(!n1.br.p1)s1=n1.len/2,d1=(n1.len+1)/2;
    if(!n2.bl.p1)s2=n2.len/2,d2=(n2.len+1)/2;
    ans.sum+=s1*s2+d1*d2;
    int b1=n1.br.p1&1^1,b2=n2.bl.p1&1^1;
    int j1=(n1.br.p2-n1.br.p1+b1)/2,o1=(n1.br.p2-n1.br.p1+(b1^1))/2;
    int j2=(n2.bl.p2-n2.bl.p1+b2)/2,o2=(n2.bl.p2-n2.bl.p1+(b2^1))/2;
    if(!n1.br.p1)j1=o1=0;
    else if(!n1.br.p2)j1=(n1.len-n1.br.p1+1+b1)/2,o1=(n1.len-n1.br.p1+1+(b1^1))/2;
    if(!n2.bl.p1)j2=o2=0;
    else if(!n2.bl.p2)j2=(n2.len-n2.bl.p1+1+b2)/2,o2=(n2.len-n2.bl.p1+1+(b2^1))/2;
    // cout<<" d1:"<<d1<<" s1:"<<s1<<" j1:"<<j1<<" o1:"<<o1<<endl;
    // cout<<" d2:"<<d2<<" s2:"<<s2<<" j2:"<<j2<<" o2:"<<o2<<endl;
    ans.sum+=j1*(d2)+o1*(s2);
    ans.sum+=j2*(d1)+o2*(s1);
    ans.sum+=(j1+o1)*(j2+o2);
    if(n1.br.p2)ans.sum+=(n1.len-n1.br.p2+1)*n2.len;
    if(n2.bl.p2)ans.sum+=(n2.len-n2.bl.p2+1)*n1.len;
    if(n1.br.p2&&n2.bl.p2)ans.sum-=(n1.len-n1.br.p2+1)*(n2.len-n2.bl.p2+1);

    ans.cl=n1.cl.merge(n2.cl,n1.len);
    ans.cr=n2.cr.merge(n1.cr,n2.len);
    int v1=n1.cr.p1?n1.cr.p1-1:n1.len,v2=n2.cl.p1?n2.cl.p1-1:n2.len;
    int ss=0;
    if(n1.cr.p1&&v2){
        int vv=(!n1.cr.p2?n1.len-n1.cr.p1+1:n1.cr.p2-n1.cr.p1);
        if(v1==0){
            ss+=vv-1;
            ss+=vv*(v2-1);
        }
        else{
            ss+=vv*v2;
        }
    }
    if(n2.cl.p1&&v1){
        int vv=(!n2.cl.p2?n2.len-n2.cl.p1+1:n2.cl.p2-n2.cl.p1);
        if(v2==0){
            ss+=vv-1;
            ss+=vv*(v1-1);
        }
        else ss+=vv*v1;
    }
    // cout<<" ss:"<<ss<<" v1:"<<v1<<" v2:"<<v2<<endl;
    ans.sum-=ss;
    return ans;
}

void up(int p){
    t[p]=up(t[ls],t[rs]);
}

void change(int p,int v){
    t[p].len=1;
    if(v==0){
        t[p].sum=1;
        t[p].bl.p1=t[p].br.p1=1;
        t[p].bl.p2=t[p].br.p2=0;
        t[p].cl.p1=t[p].cr.p1=t[p].cl.p2=t[p].cr.p2=0;
    }
    else{
        t[p].sum=0;
        t[p].bl.p1=t[p].br.p1=t[p].bl.p2=t[p].br.p2=0;
        t[p].cl.p1=t[p].cr.p1=1;
        t[p].cl.p2=t[p].cr.p2=0;
    }
}

void build(int p,int l,int r){
    if(l==r)return change(p,a[l]);
    int mid=l+r>>1;
    build(ls,l,mid);build(rs,mid+1,r);
    up(p);
    // cout<<" p:"<<p<<" l:"<<l<<" r:"<<r<<" v:";t[p].output();
}

void update(int p,int l,int r,const int &k,const int &v){
    if(l==r)return change(p,v);
    int mid=l+r>>1;
    if(k<=mid)update(ls,l,mid,k,v);
    else update(rs,mid+1,r,k,v);
    up(p);
}

node query(int p,int l,int r,const int &ql,const int &qr){
    if(ql<=l&&r<=qr)return t[p];
    int mid=l+r>>1;
    if(qr<=mid)return query(ls,l,mid,ql,qr);
    if(ql>mid)return query(rs,mid+1,r,ql,qr);
    return up(query(ls,l,mid,ql,qr),query(rs,mid+1,r,ql,qr));
}

signed main(){
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    build(1,1,n);
    m=read();
    for(int i=1;i<=m;++i){
        int op,x,y;
        op=read();x=read();
        if(op==1){
            a[x]^=1;
            update(1,1,n,x,a[x]);
        }
        else{
            y=read();
            node ans=query(1,1,n,x,y);
            print(ans.sum);putchar('\n');
        }
    }
    return 0;
}

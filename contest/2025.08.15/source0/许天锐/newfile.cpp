#include<bits/stdc++.h>
using namespace std;
const int N=100501,mod=1e9+9,M=N*350;
inline int Mod(int x){return x>=mod?x-mod:x;}
inline void add(int &x,int y){x=Mod(x+y);}
int n,m,Q;
bool flag=0;
#define mid ((l+r)>>1)
struct Seg{
    int root[N<<2];
    int t[M],ls[M],rs[M],lz[M],tot;
    inline void upd(int rt){t[rt]=Mod(t[ls[rt]]+t[rs[rt]]);}
    inline void psh(int rt,int len,int x){
        add(lz[rt],x);
        add(t[rt],1ll*x*len%mod);
    }
    inline void pshlz(int rt,int l,int r){
        if(lz[rt]){
            if(!ls[rt])ls[rt]=++tot;
            if(!rs[rt])rs[rt]=++tot;
            psh(ls[rt],mid-l+1,lz[rt]);psh(rs[rt],r-mid,lz[rt]);
            lz[rt]=0;
        }
    }
    inline void modify(int &rt,int l,int r,int L,int R,int x){
        if(!rt)rt=++tot;
        if(L<=l&&r<=R){
            psh(rt,r-l+1,x);
            return;
        }
        pshlz(rt,l,r);
        if(L<=mid)modify(ls[rt],l,mid,L,R,x);
        if(mid<R)modify(rs[rt],mid+1,r,L,R,x);
        upd(rt);
    }
    inline int query(int rt,int l,int r,int L,int R){
        if(!rt)return 0;
        if(L<=l&&r<=R)return t[rt];
        if(!ls[rt]&&!rs[rt])return 1ll*lz[rt]*(min(r,R)-max(l,L)+1)%mod;
        int ans=0;
        pshlz(rt,l,r);
        // if(flag)cout<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<" "<<tot<<" "<<rt<<endl;
        if(L<=mid)ans=query(ls[rt],l,mid,L,R);
        if(mid<R)add(ans,query(rs[rt],mid+1,r,L,R));
        return ans;
    }
}A,B;
#define ls (rt<<1)
#define rs (rt<<1|1)
inline void add(int rt,int l,int r,int L,int R,int a,int b,int x){
    if(L<=l&&r<=R){
        A.modify(A.root[rt],1,n,a,b,x);
        return;
    }
    // cout<<rt<<" "<<l<<" "<<r<<" "<<a<<" "<<b<<endl;
    B.modify(B.root[rt],1,n,a,b,1ll*x*(min(r,R)-max(l,L)+1)%mod);
    if(L<=mid)add(ls,l,mid,L,R,a,b,x);
    if(mid<R)add(rs,mid+1,r,L,R,a,b,x);
}
inline int query(int rt,int l,int r,int L,int R,int a,int b){
    // if(flag)cout<<rt<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<a<<" "<<b<<endl;
    if(L<=l&&r<=R){
        return Mod(1ll*A.query(A.root[rt],1,n,a,b)*(r-l+1)%mod+B.query(B.root[rt],1,n,a,b));
    }
    int ans=1ll*A.query(A.root[rt],1,n,a,b)*(min(r,R)-max(l,L)+1)%mod;
    if(L<=mid)add(ans,query(ls,l,mid,L,R,a,b));
    if(mid<R)add(ans,query(rs,mid+1,r,L,R,a,b));
    return ans;
}
int main(){
    freopen("newfile.in","r",stdin);
    freopen("newfile.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    cin>>n>>m>>Q;
    for(int i=1;i<=m;i++){
        int l,r,x;
        cin>>l>>r>>x;
        add(1,0,m,i,m,l,r,x);
        // cout<<query(1,0,m,2,5,5,9)<<endl;
    }
    // cerr<<clock()<<endl;
    // cout<<query(1,0,m,11695,29127,11364,85855)<<endl;
    // return 0;
    for(int i=1;i<=Q;i++){
        int u,d,l,r;
        cin>>u>>d>>l>>r;
        // if(i==19276)flag=1;
        cout<<query(1,0,m,u,d,l,r)<<endl;
        // if(i%1000==0)cerr<<i<<endl;
    }
        // cerr<<A.tot<<" "<<B.tot<<endl;
    // cerr<<clock()<<endl;
    return 0;
}
/*
10 10 10
3 10 1
2 8 1
1 10 1
2 7 1
2 9 1
2 9 1
2 6 1
2 6 1
3 10 1
1 9 1
5 9 2 6
6 7 4 6
3 8 4 6
7 8 4 9
4 6 2 6
0 6 4 6
1 5 5 9
3 8 4 7
2 8 4 8
2 7 2 10

169
39
99
75
72
9
67
129
164
204

10 5 1
3 10 1
2 8 1
1 10 1
2 7 1
2 9 1
1 5 5 9
*/
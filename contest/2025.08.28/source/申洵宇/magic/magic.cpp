#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
#define N 250005
struct tag{
    int mx[4][4];
    tag(){
        memset(mx,0,sizeof(mx));
    }
    inline const int* operator[](int x)const{
        return mx[x];
    }
    inline int * operator[](int x){
        return mx[x];
    }
    void init(){
        memset(mx,0,sizeof(mx));
        mx[0][0]=mx[1][1]=mx[2][2]=mx[3][3]=1;
    }
    inline bool haveval(){
        return mx[0][0]!=1||
               mx[0][1]!=0||
               mx[0][2]!=0||
            //    mx[0][3]!=0||
               mx[1][0]!=0||
               mx[1][1]!=1||
               mx[1][2]!=0||
            //    mx[1][3]!=0||
               mx[2][0]!=0||
               mx[2][1]!=0||
               mx[2][2]!=1||
            //    mx[2][3]!=0||
               mx[3][0]!=0||
               mx[3][1]!=0||
               mx[3][2]!=0||
               mx[3][3]!=1;
    }
    inline friend tag operator*(const tag& x,const tag& y){
        static tag res;
        res[0][0]=(1ll*x[0][0]*y[0][0]%MOD+1ll*x[0][1]*y[1][0]%MOD+1ll*x[0][2]*y[2][0]%MOD/*+1ll*x[0][3]*y[3][0]%MOD*/)%MOD;
        res[0][1]=(1ll*x[0][0]*y[0][1]%MOD+1ll*x[0][1]*y[1][1]%MOD+1ll*x[0][2]*y[2][1]%MOD/*+1ll*x[0][3]*y[3][1]%MOD*/)%MOD;
        res[0][2]=(1ll*x[0][0]*y[0][2]%MOD+1ll*x[0][1]*y[1][2]%MOD+1ll*x[0][2]*y[2][2]%MOD/*+1ll*x[0][3]*y[3][2]%MOD*/)%MOD;
        // res[0][3]=(1ll*x[0][0]*y[0][3]%MOD+1ll*x[0][1]*y[1][3]%MOD+1ll*x[0][2]*y[2][3]%MOD/*+1ll*x[0][3]*y[3][3]%MOD*/)%MOD;
        res[1][0]=(1ll*x[1][0]*y[0][0]%MOD+1ll*x[1][1]*y[1][0]%MOD+1ll*x[1][2]*y[2][0]%MOD/*+1ll*x[1][3]*y[3][0]%MOD*/)%MOD;
        res[1][1]=(1ll*x[1][0]*y[0][1]%MOD+1ll*x[1][1]*y[1][1]%MOD+1ll*x[1][2]*y[2][1]%MOD/*+1ll*x[1][3]*y[3][1]%MOD*/)%MOD;
        res[1][2]=(1ll*x[1][0]*y[0][2]%MOD+1ll*x[1][1]*y[1][2]%MOD+1ll*x[1][2]*y[2][2]%MOD/*+1ll*x[1][3]*y[3][2]%MOD*/)%MOD;
        // res[1][3]=(1ll*x[1][0]*y[0][3]%MOD+1ll*x[1][1]*y[1][3]%MOD+1ll*x[1][2]*y[2][3]%MOD+1ll*x[1][3]*y[3][3]%MOD)%MOD;
        res[2][0]=(1ll*x[2][0]*y[0][0]%MOD+1ll*x[2][1]*y[1][0]%MOD+1ll*x[2][2]*y[2][0]%MOD/*+1ll*x[2][3]*y[3][0]%MOD*/)%MOD;
        res[2][1]=(1ll*x[2][0]*y[0][1]%MOD+1ll*x[2][1]*y[1][1]%MOD+1ll*x[2][2]*y[2][1]%MOD/*+1ll*x[2][3]*y[3][1]%MOD*/)%MOD;
        res[2][2]=(1ll*x[2][0]*y[0][2]%MOD+1ll*x[2][1]*y[1][2]%MOD+1ll*x[2][2]*y[2][2]%MOD/*+1ll*x[2][3]*y[3][2]%MOD*/)%MOD;
        // res[2][3]=(1ll*x[2][0]*y[0][3]%MOD+1ll*x[2][1]*y[1][3]%MOD+1ll*x[2][2]*y[2][3]%MOD+1ll*x[2][3]*y[3][3]%MOD)%MOD;
        res[3][0]=(1ll*x[3][0]*y[0][0]%MOD+1ll*x[3][1]*y[1][0]%MOD+1ll*x[3][2]*y[2][0]%MOD+1ll*x[3][3]*y[3][0]%MOD)%MOD;
        res[3][1]=(1ll*x[3][0]*y[0][1]%MOD+1ll*x[3][1]*y[1][1]%MOD+1ll*x[3][2]*y[2][1]%MOD+1ll*x[3][3]*y[3][1]%MOD)%MOD;
        res[3][2]=(1ll*x[3][0]*y[0][2]%MOD+1ll*x[3][1]*y[1][2]%MOD+1ll*x[3][2]*y[2][2]%MOD+1ll*x[3][3]*y[3][2]%MOD)%MOD;
        res[3][3]=/*(1ll*x[3][0]*y[0][3]%MOD+1ll*x[3][1]*y[1][3]%MOD+1ll*x[3][2]*y[2][3]%MOD+*/1ll*x[3][3]*y[3][3]%MOD/*)%MOD*/;
        return res;
    }
    void print(){
        for(int i=0;i<=3;i++){
            for(int j=0;j<=3;j++){
                cout<<mx[i][j]<<' ';
            }
            cout<<'\n';
        }
    }
}tg[7];
struct val{
    int mx[4];
    val(){
        mx[0]=mx[1]=mx[2]=mx[3]=0;
    }
    inline const int& operator[](int x)const{
        return mx[x];
    }
    inline int& operator[](int x){
        return mx[x];
    }
    inline friend val operator*(const val& x,const tag& y){
        static val res;
        res[0]=(1ll*x[0]*y[0][0]%MOD+1ll*x[1]*y[1][0]%MOD+1ll*x[2]*y[2][0]%MOD+1ll*x[3]*y[3][0]%MOD)%MOD;
        res[1]=(1ll*x[0]*y[0][1]%MOD+1ll*x[1]*y[1][1]%MOD+1ll*x[2]*y[2][1]%MOD+1ll*x[3]*y[3][1]%MOD)%MOD;
        res[2]=(1ll*x[0]*y[0][2]%MOD+1ll*x[1]*y[1][2]%MOD+1ll*x[2]*y[2][2]%MOD+1ll*x[3]*y[3][2]%MOD)%MOD;
        res[3]=/*(1ll*x[0]*y[0][3]%MOD+1ll*x[1]*y[1][3]%MOD+1ll*x[2]*y[2][3]%MOD+*/1ll*x[3]*y[3][3]%MOD/*)%MOD*/;
        return res;
    }
    inline friend val operator+(const val& x,const val& y){
        static val res;
        res[0]=x[0]+y[0];
        while(res[0]>=MOD){res[0]-=MOD;break;};
        res[1]=x[1]+y[1];
        while(res[1]>=MOD){res[1]-=MOD;break;};
        res[2]=x[2]+y[2];
        while(res[2]>=MOD){res[2]-=MOD;break;};
        res[3]=x[3]+y[3];
        while(res[3]>=MOD){res[3]-=MOD;break;};
        return res;
    }
};
int n,q,a[N][3];
class segment_tree{
#define ls (id<<1)
#define rs (id<<1|1)
#define mid ((tree[id].l+tree[id].r)>>1)
public:
    struct node{
        int l,r;
        val v;
        tag t;
    }tree[N<<2];
    inline void pushup(int id){
        tree[id].v=tree[ls].v+tree[rs].v;
    }
    inline void pushdown(int id){
        if(tree[id].t.haveval()){
            tree[ls].v=tree[ls].v*tree[id].t;
            tree[rs].v=tree[rs].v*tree[id].t;
            tree[ls].t=tree[ls].t*tree[id].t;
            tree[rs].t=tree[rs].t*tree[id].t;
            tree[id].t.init();
        }
    }
    void build(int l,int r,int id,int k[][3]){
        tree[id].l=l,tree[id].r=r;
        tree[id].t.init();
        if(tree[id].l==tree[id].r){
            tree[id].v[0]=k[l][0];
            tree[id].v[1]=k[l][1];
            tree[id].v[2]=k[l][2];
            tree[id].v[3]=1;
            return ;
        }
        build(l,mid,ls,k);
        build(mid+1,r,rs,k);
        pushup(id);
    }
    void update(int l,int r,int id,const tag& k){
        if(tree[id].l>=l&&tree[id].r<=r){
            tree[id].v=tree[id].v*k;
            tree[id].t=tree[id].t*k;
            return ;
        }
        pushdown(id);
        if(l<=mid)update(l,r,ls,k);
        if(r>mid)update(l,r,rs,k);
        pushup(id);
    }
    val query(int l,int r,int id){
        if(tree[id].l>=l&&tree[id].r<=r){
            return tree[id].v;
        }
        pushdown(id);
        if(r<=mid)return query(l,r,ls);
        else if(l>mid)return query(l,r,rs);
        else return query(l,r,ls)+query(l,r,rs);
    }
#undef ls
#undef rs
#undef mid
}st;
inline void init(){
    tg[1].init();
    tg[2].init();
    tg[3].init();
    tg[4].init();
    tg[5].init();
    tg[6].init();
    tg[1][1][0]=tg[2][2][1]=tg[3][0][2]=1;
    tg[6][2][2]=0;
}
int main(){
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
    init();
	cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    st.build(1,n,1,a);
    cin>>q;
    int op,l,r,v;
    while(q--){
        cin>>op>>l>>r;
        switch(op){
        case 1:
            st.update(l,r,1,tg[1]);
            break;
        case 2:
            st.update(l,r,1,tg[2]);
            break;
        case 3:
            st.update(l,r,1,tg[3]);
            break;
        case 4:
            cin>>v;
            tg[4][3][0]=v;
            st.update(l,r,1,tg[4]);
            break;
        case 5:
            cin>>v;
            tg[5][1][1]=v;
            st.update(l,r,1,tg[5]);
            break;
        case 6:
            cin>>v;
            tg[6][3][2]=v;
            st.update(l,r,1,tg[6]);
            break;
        case 7:
            static val res;
            res=st.query(l,r,1);
            cout<<res[0]<<' '<<res[1]<<' '<<res[2]<<'\n';
            // cerr<<res[3]<<'\n';
            break;
        }
    }
    /*test code
    tag mx;
    mx[0][0]=mx[2][2]=mx[3][3]=mx[2][1]=mx[1][0]=mx[0][2]=mx[3][0]=mx[3][2]=1;
    mx[1][1]=1000;
    for(int i=1;i<=100;i++){
        mx=mx*mx;
    }
    mx.print();
    */
	return 0;
}

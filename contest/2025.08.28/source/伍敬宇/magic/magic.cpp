#include <cstdio>
#define ll long long
using namespace std;
const int MAXN = 2.5e5 + 12;
const int mod = 998244353;
const int SIZE = 1<<21;
char buf[SIZE+1],*iS,*iT;
inline char mget()
{
    if (iS==iT) iS = buf,iT = buf + fread(buf,1,SIZE,stdin),*iT = 'E';
    return *(iS++);
}
inline int read()
{
    int x = 0;
    char ch = mget();
    while (ch<'0'||ch>'9') ch = mget();
    while ('0'<=ch&&ch<='9') x = x*10 + ch - '0',ch = mget();
    return x;
}
int n,m;
int A[MAXN],B[MAXN],C[MAXN];
struct SegTreeNode{
    int len;
    ll A,B,C;
    ll xA,yA,zA,wA;
    ll xB,yB,zB,wB;
    ll xC,yC,zC,wC;
};
struct AnsNode{
    ll A,B,C;
};
AnsNode operator+(const AnsNode&x,const AnsNode&y)
{
    AnsNode z;
    z.A = (x.A + y.A)%mod;
    z.B = (x.B + y.B)%mod;
    z.C = (x.C + y.C)%mod;
    return z;
}
struct SegmentTree{
    SegTreeNode T[MAXN<<2];
    inline void pushup(int k)
    {
        T[k].A = (T[k<<1].A + T[k<<1|1].A)%mod;
        T[k].B = (T[k<<1].B + T[k<<1|1].B)%mod;
        T[k].C = (T[k<<1].C + T[k<<1|1].C)%mod;
    }
    inline void opt(int k,ll xA,ll yA,ll zA,ll wA,ll xB,ll yB,ll zB,ll wB,ll xC,ll yC,ll zC,ll wC)
    {
        SegTreeNode temp;
        temp.A = (xA*T[k].A + yA*T[k].B + zA*T[k].C + wA*T[k].len)%mod;
        temp.B = (xB*T[k].A + yB*T[k].B + zB*T[k].C + wB*T[k].len)%mod;
        temp.C = (xC*T[k].A + yC*T[k].B + zC*T[k].C + wC*T[k].len)%mod;

        temp.xA = (xA*T[k].xA + yA*T[k].xB + zA*T[k].xC)%mod;
        temp.yA = (xA*T[k].yA + yA*T[k].yB + zA*T[k].yC)%mod;
        temp.zA = (xA*T[k].zA + yA*T[k].zB + zA*T[k].zC)%mod;
        temp.wA = (xA*T[k].wA + yA*T[k].wB + zA*T[k].wC + wA)%mod;

        temp.xB = (xB*T[k].xA + yB*T[k].xB + zB*T[k].xC)%mod;
        temp.yB = (xB*T[k].yA + yB*T[k].yB + zB*T[k].yC)%mod;
        temp.zB = (xB*T[k].zA + yB*T[k].zB + zB*T[k].zC)%mod;
        temp.wB = (xB*T[k].wA + yB*T[k].wB + zB*T[k].wC + wB)%mod;

        temp.xC = (xC*T[k].xA + yC*T[k].xB + zC*T[k].xC)%mod;
        temp.yC = (xC*T[k].yA + yC*T[k].yB + zC*T[k].yC)%mod;
        temp.zC = (xC*T[k].zA + yC*T[k].zB + zC*T[k].zC)%mod;
        temp.wC = (xC*T[k].wA + yC*T[k].wB + zC*T[k].wC + wC)%mod;

        temp.len = T[k].len;

        T[k] = temp;
    }
    inline void pushdown(int k)
    {
        opt(k<<1,T[k].xA,T[k].yA,T[k].zA,T[k].wA,T[k].xB,T[k].yB,T[k].zB,T[k].wB,T[k].xC,T[k].yC,T[k].zC,T[k].wC);
        opt(k<<1|1,T[k].xA,T[k].yA,T[k].zA,T[k].wA,T[k].xB,T[k].yB,T[k].zB,T[k].wB,T[k].xC,T[k].yC,T[k].zC,T[k].wC);
        T[k].xA = T[k].yA = T[k].zA = T[k].wA = T[k].xB = T[k].yB = T[k].zB = T[k].wB = T[k].xC = T[k].yC = T[k].zC = T[k].wC = 0;
        T[k].xA = T[k].yB = T[k].zC = 1;
    }
    void build(int k,int l,int r)
    {
        T[k].len = r - l + 1;
        T[k].xA = T[k].yA = T[k].zA = T[k].wA = T[k].xB = T[k].yB = T[k].zB = T[k].wB = T[k].xC = T[k].yC = T[k].zC = T[k].wC = 0;
        T[k].xA = T[k].yB = T[k].zC = 1;
        if (l==r)
        {
            T[k].A = A[l],T[k].B = B[l],T[k].C = C[l];
            return ;
        }
        int md = (l+r)>>1;
        build(k<<1,l,md),build(k<<1|1,md+1,r);
        pushup(k);
    }
    void modify1(int k,int l,int r,int L,int R)
    {
        if (r<L||l>R) return ;
        if (L<=l&&r<=R)
        {
            opt(k,1,1,0,0,0,1,0,0,0,0,1,0);
            return ;
        }
        int md = (l+r)>>1;
        pushdown(k);
        modify1(k<<1,l,md,L,R),modify1(k<<1|1,md+1,r,L,R);
        pushup(k);
    }
    void modify2(int k,int l,int r,int L,int R)
    {
        if (r<L||l>R) return ;
        if (L<=l&&r<=R)
        {
            opt(k,1,0,0,0,0,1,1,0,0,0,1,0);
            return ;
        }
        int md = (l+r)>>1;
        pushdown(k);
        modify2(k<<1,l,md,L,R),modify2(k<<1|1,md+1,r,L,R);
        pushup(k);
    }
    void modify3(int k,int l,int r,int L,int R)
    {
        if (r<L||l>R) return ;
        if (L<=l&&r<=R)
        {
            opt(k,1,0,0,0,0,1,0,0,1,0,1,0);
            return ;
        }
        int md = (l+r)>>1;
        pushdown(k);
        modify3(k<<1,l,md,L,R),modify3(k<<1|1,md+1,r,L,R);
        pushup(k);
    }
    void modify4(int k,int l,int r,int L,int R,int val)
    {
        if (r<L||l>R) return ;
        if (L<=l&&r<=R)
        {
            opt(k,1,0,0,val,0,1,0,0,0,0,1,0);
            return ;
        }
        int md = (l+r)>>1;
        pushdown(k);
        modify4(k<<1,l,md,L,R,val),modify4(k<<1|1,md+1,r,L,R,val);
        pushup(k);
    }
    void modify5(int k,int l,int r,int L,int R,int val)
    {
        if (r<L||l>R) return ;
        if (L<=l&&r<=R)
        {
            opt(k,1,0,0,0,0,val,0,0,0,0,1,0);
            return ;
        }
        int md = (l+r)>>1;
        pushdown(k);
        modify5(k<<1,l,md,L,R,val),modify5(k<<1|1,md+1,r,L,R,val);
        pushup(k);
    }
    void modify6(int k,int l,int r,int L,int R,int val)
    {
        if (r<L||l>R) return ;
        if (L<=l&&r<=R)
        {
            opt(k,1,0,0,0,0,1,0,0,0,0,0,val);
            return ;
        }
        int md = (l+r)>>1;
        pushdown(k);
        modify6(k<<1,l,md,L,R,val),modify6(k<<1|1,md+1,r,L,R,val);
        pushup(k);
    }
    AnsNode query(int k,int l,int r,int L,int R)
    {
        if (r<L||l>R) return {0,0,0};
        if (L<=l&&r<=R) return {T[k].A,T[k].B,T[k].C};
        pushdown(k);
        int md = (l+r)>>1;
        return query(k<<1,l,md,L,R) + query(k<<1|1,md+1,r,L,R);
    }
}sgt;
int main()
{
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    n = read();
    for (int i=1;i<=n;i++)
        A[i] = read(),B[i] = read(),C[i] = read();
    sgt.build(1,1,n);
    m = read();
    for (int i=1;i<=m;i++)
    {
        int op,l,r,val;
        op = read(),l = read(),r = read();
        if (4<=op&&op<=6) val = read();
        if (op==1) sgt.modify1(1,1,n,l,r);
        else if (op==2) sgt.modify2(1,1,n,l,r);
        else if (op==3) sgt.modify3(1,1,n,l,r);
        else if (op==4) sgt.modify4(1,1,n,l,r,val);
        else if (op==5) sgt.modify5(1,1,n,l,r,val);
        else if (op==6) sgt.modify6(1,1,n,l,r,val);
        else 
        {
            AnsNode res = sgt.query(1,1,n,l,r);
            printf("%lld %lld %lld\n",res.A,res.B,res.C);
        }
        //if (i==1)
        //{
        //     long long ans = 0;
        //     for (int j=l+1;j<=r-1;j++)
        //         ans = (1ll*B[j]*val+ans)%mod;
        //     AnsNode res = sgt.query(1,1,n,l+1,r-1);
        //     printf("%lld %lld %lld\n",res.A,res.B,res.C);
        //     printf("%lld \n",ans);
        // }
    }
    return 0;
}
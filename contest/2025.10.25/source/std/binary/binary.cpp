#include <cstdio>
using namespace std;
const int MAXN = 1e5 + 12;
int n,a[MAXN],m;
struct SegTreeNode1{
    int cnt1,len;
    long long res,sum1,sum2,sum3,sum4;
};
inline long long con1(long long lsum,long long rsum)
{
    return (lsum+1)*(rsum+1) - 1 - (lsum>0) - (rsum>0);
}
inline SegTreeNode1 merge1(SegTreeNode1 x,SegTreeNode1 y)
{
    SegTreeNode1 z;
    z.len = x.len + y.len;
    z.cnt1 = x.cnt1 + y.cnt1;
    z.res = x.res + y.res;
    if (x.cnt1) z.res += - con1(x.sum3,x.sum4) + con1(x.sum3,x.sum4+y.sum1);
    if (y.cnt1) z.res += - con1(y.sum1,y.sum2) + con1(x.sum4+y.sum1,y.sum2);
    if (z.cnt1==0) z.sum1 = z.sum4 = z.len,z.sum2 = z.sum3 = 0;
    else 
    {
        if (x.cnt1==0) z.sum1 = y.sum1 + x.len,z.sum2 = y.sum2;
        else if (x.cnt1==1) z.sum1 = x.sum1,z.sum2 = x.sum2 + y.sum1;
        else z.sum1 = x.sum1,z.sum2 = x.sum2;
        if (y.cnt1==0) z.sum4 = y.sum4 + x.sum4,z.sum3 = x.sum3;
        else if (y.cnt1==1) z.sum4 = y.sum4,z.sum3 = y.sum3 + x.sum4;
        else z.sum3 = y.sum3,z.sum4 = y.sum4;
    }
    return z;
}
struct SegmentTree1{
    SegTreeNode1 T[MAXN<<2];
    inline void pushup(int k)
    {
        T[k].cnt1 = T[k<<1].cnt1 + T[k<<1|1].cnt1;
        T[k].res = T[k<<1].res + T[k<<1|1].res;
        if (T[k<<1].cnt1) T[k].res += - con1(T[k<<1].sum3,T[k<<1].sum4) + con1(T[k<<1].sum3,T[k<<1].sum4+T[k<<1|1].sum1);
        if (T[k<<1|1].cnt1) T[k].res += - con1(T[k<<1|1].sum1,T[k<<1|1].sum2) + con1(T[k<<1].sum4+T[k<<1|1].sum1,T[k<<1|1].sum2);
        if (T[k].cnt1==0) T[k].sum1 = T[k].sum4 = T[k].len,T[k].sum2 = T[k].sum3 = 0;
        else 
        {
            if (T[k<<1].cnt1==0) T[k].sum1 = T[k<<1|1].sum1 + T[k<<1].len,T[k].sum2 = T[k<<1|1].sum2;
            else if (T[k<<1].cnt1==1) T[k].sum1 = T[k<<1].sum1,T[k].sum2 = T[k<<1].sum2 + T[k<<1|1].sum1;
            else T[k].sum1 = T[k<<1].sum1,T[k].sum2 = T[k<<1].sum2;
            if (T[k<<1|1].cnt1==0) T[k].sum4 = T[k<<1|1].sum4 + T[k<<1].sum4,T[k].sum3 = T[k<<1].sum3;
            else if (T[k<<1|1].cnt1==1) T[k].sum4 = T[k<<1|1].sum4,T[k].sum3 = T[k<<1|1].sum3 + T[k<<1].sum4;
            else T[k].sum3 = T[k<<1|1].sum3,T[k].sum4 = T[k<<1|1].sum4;
        }
    }
    inline void put(int k,int x)
    {
        T[k].res = 0;
        if (x==0)
        {
            T[k].cnt1 = 0;
            T[k].sum1 = T[k].sum4 = 1;
            T[k].sum2 = T[k].sum3 = 0;
        }
        else 
        {
            T[k].cnt1 = 1;
            T[k].sum1 = T[k].sum4 = T[k].sum2 = T[k].sum3 = 0;
        }
    }
    void build(int k,int l,int r)
    {
        T[k].len = r - l + 1;
        if (l==r) return put(k,a[l]),void();
        int md = (l+r)>>1;
        build(k<<1,l,md),build(k<<1|1,md+1,r);
        pushup(k);
    }
    void modify(int k,int l,int r,int pos)
    {
        if (l==r) return put(k,1-T[k].cnt1),void();
        int md = (l+r)>>1;
        if (pos<=md) modify(k<<1,l,md,pos);
        else modify(k<<1|1,md+1,r,pos);
        pushup(k);
    }
    SegTreeNode1 query(int k,int l,int r,int L,int R)
    {
        if (r<L||l>R) return {0,0,0,0,0,0,0};
        if (L<=l&&r<=R) return T[k];
        int md = (l+r)>>1;
        return merge1(query(k<<1,l,md,L,R),query(k<<1|1,md+1,r,L,R));
    }
}sgt1;
inline long long con2(long long lsum,long long rsum)
{
    return (lsum/2+1)*((rsum+1)/2) + ((lsum+1)/2)*(rsum/2+1);
}
inline long long con3(long long lsum,long long rsum)
{
    return (lsum/2)*((rsum+1)/2) + ((lsum+1)/2)*(rsum/2);
}
struct SegTreeNode2{
    int cnt0,len;
    long long res,sum1,sum2,sum3,sum4;
};
inline SegTreeNode2 merge2(SegTreeNode2 x,SegTreeNode2 y)
{
    SegTreeNode2 z;
    z.len = x.len + y.len;
    z.cnt0 = x.cnt0 + y.cnt0;
    z.res = x.res + y.res + con3(x.sum4,y.sum1);
    if (x.cnt0) z.res += - con2(x.sum3,x.sum4) + con2(x.sum3,x.sum4+y.sum1);
    if (y.cnt0) z.res += - con2(y.sum1,y.sum2) + con2(x.sum4+y.sum1,y.sum2);
    if (z.cnt0==0) z.sum1 = z.sum4 = z.len,z.sum2 = z.sum3 = 0;
    else 
    {
        if (x.cnt0==0) z.sum1 = y.sum1 + x.len,z.sum2 = y.sum2;
        else if (x.cnt0==1) z.sum1 = x.sum1,z.sum2 = x.sum2 + y.sum1;
        else z.sum1 = x.sum1,z.sum2 = x.sum2;
        if (y.cnt0==0) z.sum4 = y.sum4 + x.sum4,z.sum3 = x.sum3;
        else if (y.cnt0==1) z.sum4 = y.sum4,z.sum3 = y.sum3 + x.sum4;
        else z.sum3 = y.sum3,z.sum4 = y.sum4;
    }
    return z;
}
struct SegmentTree2{
    SegTreeNode2 T[MAXN<<2];
    inline void pushup(int k)
    {
        T[k].cnt0 = T[k<<1].cnt0 + T[k<<1|1].cnt0;
        T[k].res = T[k<<1].res + T[k<<1|1].res + con3(T[k<<1].sum4,T[k<<1|1].sum1);
        if (T[k<<1].cnt0) T[k].res += - con2(T[k<<1].sum3,T[k<<1].sum4) + con2(T[k<<1].sum3,T[k<<1].sum4+T[k<<1|1].sum1);
        if (T[k<<1|1].cnt0) T[k].res += - con2(T[k<<1|1].sum1,T[k<<1|1].sum2) + con2(T[k<<1].sum4+T[k<<1|1].sum1,T[k<<1|1].sum2);
        if (T[k].cnt0==0) T[k].sum1 = T[k].sum4 = T[k].len,T[k].sum2 = T[k].sum3 = 0;
        else 
        {
            if (T[k<<1].cnt0==0) T[k].sum1 = T[k<<1|1].sum1 + T[k<<1].len,T[k].sum2 = T[k<<1|1].sum2;
            else if (T[k<<1].cnt0==1) T[k].sum1 = T[k<<1].sum1,T[k].sum2 = T[k<<1].sum2 + T[k<<1|1].sum1;
            else T[k].sum1 = T[k<<1].sum1,T[k].sum2 = T[k<<1].sum2;
            if (T[k<<1|1].cnt0==0) T[k].sum4 = T[k<<1|1].sum4 + T[k<<1].sum4,T[k].sum3 = T[k<<1].sum3;
            else if (T[k<<1|1].cnt0==1) T[k].sum4 = T[k<<1|1].sum4,T[k].sum3 = T[k<<1|1].sum3 + T[k<<1].sum4;
            else T[k].sum3 = T[k<<1|1].sum3,T[k].sum4 = T[k<<1|1].sum4;
        }
    }
    inline void put(int k,int x)
    {
        if (x==1)
        {
            T[k].cnt0 = 0;
            T[k].sum1 = T[k].sum4 = 1;
            T[k].sum2 = T[k].sum3 = 0;
            T[k].res = 1;
        }
        else 
        {
        	T[k].res = 0;
            T[k].cnt0 = 1;
            T[k].sum1 = T[k].sum4 = T[k].sum2 = T[k].sum3 = 0;
        }
    }
    void build(int k,int l,int r)
    {
        T[k].len = r - l + 1;
        if (l==r) return put(k,a[l]),void();
        int md = (l+r)>>1;
        build(k<<1,l,md),build(k<<1|1,md+1,r);
        pushup(k);
    }
    void modify(int k,int l,int r,int pos)
    {
        if (l==r) return put(k,T[k].cnt0),void();
        int md = (l+r)>>1;
        if (pos<=md) modify(k<<1,l,md,pos);
        else modify(k<<1|1,md+1,r,pos);
        pushup(k);
    }
    SegTreeNode2 query(int k,int l,int r,int L,int R)
    {
        if (r<L||l>R) return {0,0,0,0,0,0,0};
        if (L<=l&&r<=R) return T[k];
        int md = (l+r)>>1;
        return merge2(query(k<<1,l,md,L,R),query(k<<1|1,md+1,r,L,R));
    }
}sgt2;
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout); 
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    scanf("%d",&m);
    sgt1.build(1,1,n),sgt2.build(1,1,n);
    while (m--)
    {
        int op,id,l,r;
        scanf("%d",&op);
        if (op==1)
        {
            scanf("%d",&id);
            sgt1.modify(1,1,n,id);
            sgt2.modify(1,1,n,id);
        }
        else 
        {
            scanf("%d%d",&l,&r);
            SegTreeNode1 temp1 = sgt1.query(1,1,n,l,r);
            SegTreeNode2 temp2 = sgt2.query(1,1,n,l,r);
            long long cur = temp1.res + temp2.res;
            printf("%lld\n",1ll*(r-l+1)*(r-l+2)/2 - cur);
        }
    }
    return 0;
}

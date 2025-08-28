#include <cstdio>
using ll=long long;

const int M=998244353,N=250000;
int n,m,op[N+10],l[N+10],r[N+10],v[N+10];
ll a[N+10],b[N+10],c[N+10],ansa,ansb,ansc;

struct node
{
    int l,r;
    ll dat[3]; // 0->a 1->b 2->c
    ll a,b,c;
} t[5000010];

void pushup(int p)
{
    for (int i=0;i<3;i++)
        t[p].dat[i]=(t[p*2].dat[i]+t[p*2+1].dat[i])%M;
}

void pushdown(int p)
{
    if (t[p].a)
    {
        t[p*2].dat[0]+=(t[p*2].r-t[p*2].l+1)*t[p].a%M;
        t[p*2+1].dat[0]+=(t[p*2+1].r-t[p*2+1].l+1)*t[p].a%M;
        t[p*2].a+=t[p].a;
        t[p*2+1].a+=t[p].a;
        t[p].a=0;
    }
    if (t[p].b!=1)
    {
        t[p*2].dat[1]=t[p*2].dat[1]*t[p].b%M;
        t[p*2+1].dat[1]=t[p*2+1].dat[1]*t[p].b%M;
        t[p*2].b=t[p*2].b*t[p].b%M;
        t[p*2+1].b=t[p*2+1].b*t[p].b%M;
        t[p].b=1;
    }
    if (t[p].c)
    {
        t[p*2].dat[2]=(t[p*2].r-t[p*2].l+1)*t[p].c%M;
        t[p*2+1].dat[2]=(t[p*2+1].r-t[p*2+1].l+1)*t[p].c%M;
        t[p*2].c=t[p].c;
        t[p*2+1].c=t[p].c;
        t[p].c=0;
    }
}

void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r,t[p].a=t[p].c=0,t[p].b=1;
    if (l==r)
    {
        t[p].dat[0]=a[l],t[p].dat[1]=b[l],t[p].dat[2]=c[l];
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}

ll query(int p,int l,int r,int id)
{
    if (p>4*n)
        return 0;
    if (l<=t[p].l && r>=t[p].r)
        return t[p].dat[id]%M;
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    ll ans=0;
    if (l<=mid)
        ans=(ans+query(p*2,l,mid,id))%M;
    if (r>mid)
        ans=(ans+query(p*2+1,l,r,id))%M;
    return ans%M;
}

void add(int p,int l,int r,int k) // 0 -> a
{
    if (p>4*n)
        return;
    if (l<=t[p].l && r>=t[p].r)
    {
        t[p].a=(t[p].a+k)%M;
        t[p].dat[0]=(t[p].dat[0]+(t[p].r-t[p].l+1)*k)%M;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if (l<=mid)
        add(p*2,l,r,k);
    if (r>mid)
        add(p*2+1,l,r,k);
    pushup(p);
}

void mul(int p,int l,int r,int k) // operate b
{
    if (p>4*n)
        return;
    if (l<=t[p].l && r>=t[p].r)
    {
        t[p].b=t[p].b*k%M;
        t[p].dat[1]=t[p].dat[1]*k%M;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if (l<=mid)
        mul(p*2,l,r,k);
    if (r>mid)
        mul(p*2+1,l,r,k);
    pushup(p);
}

void change(int p,int l,int r,int k) // change c
{
    if (p>4*n)
        return;
    if (l<=t[p].l && r>=t[p].r)
    {
        t[p].c=k;
        t[p].dat[2]=(t[p].r-t[p].l+1)*k%M;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if (l<=mid)
        change(p*2,l,r,k);
    if (r>mid)
        change(p*2+1,l,r,k);
    pushup(p);
}

int main()
{
    freopen("magic.in","r",stdin);
    freopen("magic.out","w",stdout);
    scanf("%d",&n);
    // test 1-6: bruteforce
    // test 7-9: segment tree
    // test 10-12: no output
    for (int i=1;i<=n;i++)
        scanf("%lld%lld%lld",a+i,b+i,c+i);
    int m;
    bool t1=1,t2=1; // t1: 1,2,3 t2: 4,5,6,7
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d%d",op+i,l+i,r+i);
        if (op[i]!=1 && op[i]!=2 && op[i]!=3)
            t1=0;
        if (op[i]!=4 && op[i]!=5 && op[i]!=6 && op[i]!=7)
            t2=0;
        if (4<=op[i] && op[i]<=6)
            scanf("%d",v+i);
    }
    if (t1) // test 2 -> no output (no operation 7)
        return 0;
    else if (t2) // test 3 -> use segment tree (only have add, multiply, setval)
    {
    	build(1,1,n); 
        for (int _=1;_<=m;_++)
        {
            if (op[_]==4)
                add(1,l[_],r[_],v[_]);
            else if (op[_]==5)
                mul(1,l[_],r[_],v[_]);
            else if (op[_]==6)
                change(1,l[_],r[_],v[_]);
            else
                printf("%lld %lld %lld\n",query(1,l[_],r[_],0),query(1,l[_],r[_],1),query(1,l[_],r[_],2));
        }
    }
    else // test 1 & others -> bruteforce
    {
        for (int _=1;_<=m;_++)
        {
            if (op[_]==1)
                for (int i=l[_];i<=r[_];i++)
                    a[i]=(a[i]+b[i])%M;
            else if (op[_]==2)
                for (int i=l[_];i<=r[_];i++)
                    b[i]=(b[i]+c[i])%M;
            else if (op[_]==3)
                for (int i=l[_];i<=r[_];i++)
                    c[i]=(c[i]+a[i])%M;
            else if (op[_]==4)
                for (int i=l[_];i<=r[_];i++)
                    a[i]=(a[i]+v[_])%M;
            else if (op[_]==5)
                for (int i=l[_];i<=r[_];i++)
                    b[i]=(b[i]*v[_])%M;
            else if (op[_]==6)
                for (int i=l[_];i<=r[_];i++)
                    c[i]=v[_]%M;
            else
            {
                ansa=ansb=ansc=0;
                for (int i=l[_];i<=r[_];i++)
                    ansa=(ansa+a[i])%M,ansb=(ansb+b[i])%M,ansc=(ansc+c[i])%M;
                printf("%lld %lld %lld\n",ansa,ansb,ansc);
            }
        }
    }
    return 0;
}

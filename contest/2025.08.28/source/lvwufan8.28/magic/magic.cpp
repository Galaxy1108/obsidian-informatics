#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int x,y,z;
int op;
const int mod=998244353;
int a1[250010],b1[250010],c1[250010];
struct tree
{
    int l,r,a,b,c,add,mul=1,v;
}s[1000010];
void pushup(int p)
{
    s[p].a=(s[p*2].a+s[p*2+1].a)%mod;
    s[p].b=(s[p*2].b+s[p*2+1].b)%mod;
    s[p].c=(s[p*2].c+s[p*2+1].c)%mod;
}
void addtag(int p,int x)
{
    s[p].add+=x%mod;
    s[p].add%=mod;
    s[p].a+=(s[p].r-s[p].l+1)*x%mod;
    s[p].a%=mod;
}
void multag(int p,int x)
{
    s[p].mul*=x%mod;
    s[p].mul%=mod;
    s[p].b*=x%mod;
    s[p].b%=mod;
}
void changetag(int p,int v)
{
    s[p].c=(s[p].r-s[p].l+1)*v%mod;
    s[p].v=v%mod;
}
void pushdown(int p)
{
    if(s[p].add)
    {
        addtag(p*2,s[p].add);
        addtag(p*2+1,s[p].add);
        s[p].add=0;
    }
    if(s[p].mul>1)
    {
        multag(p*2,s[p].mul);
        multag(p*2+1,s[p].mul);
        s[p].mul=1;
    }
    if(s[p].v)
    {
        changetag(p*2,s[p].v);
        changetag(p*2+1,s[p].v);
        s[p].v=0;
    }
}
void build(int p,int l,int r)
{
    s[p].l=l;
    s[p].r=r;
    if(l==r)
    {
        s[p].a=a1[l]%mod;
        s[p].b=b1[l]%mod;
        s[p].c=c1[l]%mod;
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}
void updatea(int p,int l,int r,int d)
{
    if(s[p].l>=l&&s[p].r<=r)
    {
        addtag(p,d);
        return;
    }
    pushdown(p);
    int mid=(s[p].l+s[p].r)/2;
    if(mid>=l)
    {
        updatea(p*2,l,r,d);
    }
    if(mid<r)
    {
        updatea(p*2+1,l,r,d);
    }
    pushup(p);
}
void updateb(int p,int l,int r,int d)
{
    if(s[p].l>=l&&s[p].r<=r)
    {
        multag(p,d);
        return;
    }
    pushdown(p);
    int mid=(s[p].l+s[p].r)/2;
    if(mid>=l)
    {
        updateb(p*2,l,r,d);
    }
    if(mid<r)
    {
        updateb(p*2+1,l,r,d);
    }
    pushup(p);
}
void updatec(int p,int l,int r,int v)
{
    if(s[p].l>=l&&s[p].r<=r)
    {
        changetag(p,v);
        return;
    }
    pushdown(p);
    int mid=(s[p].l+s[p].r)/2;
    if(mid>=l)
    {
        updatec(p*2,l,r,v);
    }
    if(mid<r)
    {
        updatec(p*2+1,l,r,v);
    }
    pushup(p);
}
int querya(int p,int l,int r)
{
    if(s[p].l>=l&&s[p].r<=r)
    {
        return s[p].a%mod;
    }
    int mid=(s[p].l+s[p].r)/2;
    int res=0;
    pushdown(p);
    if(mid>=l)
    {
        res+=querya(p*2,l,r)%mod;
        res%=mod;
    }
    if(mid<r)
    {
        res+=querya(p*2+1,l,r)%mod;
        res%=mod;
    }
    return res%mod;
}
int queryb(int p,int l,int r)
{
    if(s[p].l>=l&&s[p].r<=r)
    {
        return s[p].b%mod;
    }
    int mid=(s[p].l+s[p].r)/2;
    int res=0;
    pushdown(p);
    if(mid>=l)
    {
        res+=queryb(p*2,l,r)%mod;
        res%=mod;
    }
    if(mid<r)
    {
        res+=queryb(p*2+1,l,r)%mod;
        res%=mod;
    }
    return res%mod;
}
int queryc(int p,int l,int r)
{
    if(s[p].l>=l&&s[p].r<=r)
    {
        return s[p].c%mod;
    }
    int mid=(s[p].l+s[p].r)/2;
    int res=0;
    pushdown(p);
    if(mid>=l)
    {
        res+=queryc(p*2,l,r)%mod;
        res%=mod;
    }
    if(mid<r)
    {
        res+=queryc(p*2+1,l,r)%mod;
        res%=mod;
    }
    return res%mod;
}
signed main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a1[i]>>b1[i]>>c1[i];
    }
    build(1,1,n);
    cin>>m;
    if(n<=1000&&m<=1000)
    {
        for(int i=1;i<=m;i++)
        {
            cin>>op;
            if(op==1)
            {
                cin>>x>>y;
                for(int j=x;j<=y;j++)
                {
                    a1[j]+=b1[j]%mod;
                    a1[j]%=mod;
                }
            }
            if(op==2)
            {
                cin>>x>>y;
                for(int j=x;j<=y;j++)
                {
                    b1[j]+=c1[j]%mod;
                    b1[j]%=mod;
                }
            }
            if(op==3)
            {
                cin>>x>>y;
                for(int j=x;j<=y;j++)
                {
                    c1[j]+=a1[j]%mod;
                    c1[j]%=mod;
                }
            }
            if(op==4)
            {
                cin>>x>>y>>z;
                for(int j=x;j<=y;j++)
                {
                    a1[j]+=z%mod;
                    a1[j]%=mod;
                }
            }
            if(op==5)
            {
                cin>>x>>y>>z;
                for(int j=x;j<=y;j++)
                {
                    b1[j]*=z%mod;
                    b1[j]%=mod;
                }
            }
            if(op==6)
            {
                cin>>x>>y>>z;
                for(int j=x;j<=y;j++)
                {
                    c1[j]=z%mod;
                    c1[j]%=mod;
                }
            }
            if(op==7)
            {
                cin>>x>>y;
                int suma=0,sumb=0,sumc=0;
                for(int j=x;j<=y;j++)
                {
                    suma+=a1[j]%mod;
                    suma%=mod;
                }
                for(int j=x;j<=y;j++)
                {
                    sumb+=b1[j]%mod;
                    sumb%=mod;
                }
                for(int j=x;j<=y;j++)
                {
                    sumc+=c1[j]%mod;
                    sumc%=mod;
                }
                cout<<suma%mod<<" ";
                cout<<sumb%mod<<" ";
                cout<<sumc%mod<<" ";
                cout<<endl;
            }
        }
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            cin>>op;
            if(op==4)
            {
                cin>>x>>y>>z;
                updatea(1,x,y,z);
            }
            if(op==5)
            {
                cin>>x>>y>>z;
                updateb(1,x,y,z);
            }
            if(op==6)
            {
                cin>>x>>y>>z;
                updatec(1,x,y,z);
            }
            if(op==7)
            {
                cin>>x>>y;
                cout<<querya(1,x,y)<<" ";
                cout<<queryb(1,x,y)<<" ";
                cout<<queryc(1,x,y)<<" ";
                cout<<endl;
            }
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;
int n,m;
int a[mx];
struct segT
{
    int l,r,sum;
}t[mx*4];
void pushup(int p)
{
    t[p].sum=t[p*2].sum+t[p*2+1].sum;
}
void build(int p,int l,int r)
{
    t[p].l=l,t[p].r=r;
    if(l==r)
    {
        t[p].sum=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}
void update(int p,int x)
{
    if(t[p].l==t[p].r)
    {
        t[p].sum^=1;
        return;
    }
    int mid=(t[p].l+t[p].r)/2;
    if(x<=mid) update(p*2,x);
    if(x>mid) update(p*2+1,x);
    pushup(p);
}
int query(int p,int l,int r)
{
    if(t[p].l>=l&&t[p].r<=r)
    {
        return t[p].sum;
    }
    int res=0;
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid) res+=query(p*2,l,r);
    if(r>mid) res+=query(p*2+1,l,r);
    return res;
}
int main()
{
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int x;
            cin>>x;
            update(1,x);
        }
        if(op==2)
        {
            int ans=0;
            int l,r;
            cin>>l>>r;
            for(int j=l;j<=r;j++)
            {
                for(int k=j;k<=r;k++)
                {
                    ans+=query(1,j,k);
                }
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}

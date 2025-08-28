#include<bits/stdc++.h>
using namespace std;
int n,q;
long long a[200010];
int op;
long long x,y;
struct tree
{
    int l,r,dat,mn=1e9,cha=0;
}s[800010];
void pushup(int p)
{
    s[p].dat=s[p*2].dat+s[p*2+1].dat;
    s[p].cha=s[p*2].cha+s[p*2+1].cha;
}
void pushdown(int p)
{
    if(s[p].mn)
    {
        s[p*2].mn=min(s[p].mn,s[p*2].mn);
        s[p*2+1].mn=min(s[p].mn,s[p*2+1].mn);
    }
    
}
void build(int p,int l,int r)
{
    s[p].l=l;
    s[p].r=r;
    if(l==r)
    {
        s[p].dat=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    pushup(p);
}
void update(int p,int d)
{
    s[p].mn=min(s[p].mn,d);
    if(s[p].l==s[p].r)
    {
        if(s[p].dat>s[p].mn)
        {
            s[p].cha=s[p].dat-s[p].mn;
        }
        return;
    }
    int mid=(s[p].l+s[p].r)/2;
    pushdown(p);
    update(p*2,d);
    update(p*2+1,d);
    pushup(p);
}
int query(int p,int l,int r)
{
    if(s[p].l>=l&&s[p].r<=r)
    {
        return s[p].dat-s[p].cha;
    }
    int mid=(s[p].l+s[p].r)/2;
    int res=0;
    pushdown(p);
    if(mid>=l)
    {
        res+=query(p*2,l,r);
    }
    if(mid<r)
    {
        res+=query(p*2+1,l,r);
    }
    return res;
}
int main()
{
    freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>op;
        if(op==1)
        {
            cin>>x;
            for(int j=1;j<=n;j++)
            {
                a[j]=min(a[j],x);
            }
        }
        if(op==2)
        {
            for(int j=1;j<=n;j++)
            {
                a[j]+=j;
            }
        }
        if(op==3)
        {
            cin>>x>>y;
            long long ans=0;
            for(int j=x;j<=y;j++)
            {
                ans+=a[j];
            }
            cout<<ans<<endl;
        }
    }
}
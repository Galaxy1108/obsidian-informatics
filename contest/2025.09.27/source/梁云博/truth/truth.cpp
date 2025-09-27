#include <bits/stdc++.h>
#define mid (l+r>>1)
#define ls p<<1
#define rs p<<1|1
#define N 500005
#define int long long
using namespace std;
int n,k,m;
int sum[N<<2],a[N];
int minlen=1e18;
void up(int p)
{
    sum[p]=sum[ls]&sum[rs];
}
void build(int p,int l,int r)
{
    sum[p]=(1<<k)-1;
    if(l==r)
    {
        sum[p]^=1<<a[l]-1;
        return ;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
    up(p);
    if(!sum[p])minlen=min(minlen,r-l+1);
}

void update(int p,int l,int r,int k,int x)
{
    if(l==r)
    {
        sum[p]=((1<<k)-1)^(1<<x-1);
        return ;
    }
    if(k<=mid)update(ls,l,mid,k,x);
    else update(rs,mid+1,r,k,x);
    up(p);
    if(!sum[p])minlen=min(minlen,r-l+1);
}

int query(int p,int l,int r,int ql,int qr)
{
    if(ql<=l && r<=qr)return sum[p];
    int res=(1<<k)-1;
    if(mid>=ql)res&=query(ls,l,mid,ql,qr);
    if(mid+1<=qr)res&=query(rs,mid+1,r,ql,qr);
    return res;
}

signed main()
{
    freopen("truth.in","r",stdin);
    freopen("truth.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    int ty,k,x;
    while(m--)
    {
        cin>>ty;
        if(ty==1)
        {
            cin>>k>>x;
            update(1,1,n,k,x);
        }
        else
        {
            int flg=0,res=-1;
            if(minlen==1e18)cout<<-1<<"\n";
            else if(minlen==n && sum[1]!=0)cout<<-1<<"\n";
            else
            {
                for(int len=minlen/2+1;len<minlen;len++)
                {
                    for(int l=1;l+len-1<=n;l++)
                    {
                        int r=l+len-1;
                        if(query(1,1,n,l,r)==0)
                        {
                            res=len;
                            break;
                        }
                    }
                    if(flg)break;
                }
                if(res!=-1)cout<<res<<"\n";
                else cout<<minlen<<"\n";
            }
        }
    }
    return 0;
}
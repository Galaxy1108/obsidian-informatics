//Seg Tree,n=125000(t_size = 4n)
//ADD only!!!
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define XaoWa118 1000000009
/*struct node
{
    int l,r,add,dat;
};
node t[500005];*/
int a[500005],n,m,op[500005],x[500005],y[500005],z[500005],q;
/*void build(int p,int l,int r)
{
    t[p].l=l;
    t[p].r=r;
    if(l==r)
    {
        t[p].dat=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(p*2,l,mid);
    build(p*2+1,mid+1,r);
    t[p].dat=t[p*2].dat+t[p*2+1].dat;
    return;
}
void pushup(int p)
{
    t[p].dat=t[p*2].dat+t[p*2+1].dat;
    return;
}
void pushdown(int p)
{
    if(t[p].add)
    {
        t[p*2].dat+=(t[p*2].r-t[p*2].l+1)*t[p].add;
        t[p*2+1].dat+=(t[p*2+1].r-t[p*2+1].l+1)*t[p].add;
        t[p*2].add+=t[p].add;
        t[p*2+1].add+=t[p].add;
        t[p].add=0;
    }
    return;
}
void update(int p,int l,int r,int d)
{
    if(t[p].l>=l&&t[p].r<=r)
    {
        t[p].add+=d;
        t[p].dat+=(t[p].r-t[p].l+1)*d;
        return;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid) update(p*2,l,r,d);
    if(r>mid) update(p*2+1,l,r,d);
    pushup(p);
    return; 
}
int query(int p,int l,int r)
{
    if(t[p].l>=l&&t[p].r<=r)
    {
        return t[p].dat;
    }
    pushdown(p);
    int mid=(t[p].l+t[p].r)/2,res=0;
    if(l<=mid) res+=query(p*2,l,r);
    if(r>mid) res+=query(p*2+1,l,r);
    return res;
}*/
int b1[100005],b2[100005];
int lowbit(int x)
{
	return x & -x;
}
int query1(int x) 
{ 
	int ans=0;
	while (x>0) 
	{
		ans=ans+b1[x];
		x=x-lowbit(x);
	}
	return ans;
}
void add1(int x,int k) 
{
	while (x<=n) 
	{
		b1[x]=b1[x]+k;
		x=x+lowbit(x);
	}
}
int query2(int x) 
{ 
	int ans=0;
	while (x>0) 
	{
		ans=ans+b2[x];
		x=x-lowbit(x);
	}
	return ans;
}
void add2(int x,int k) 
{
	while (x<=n) 
	{
		b2[x]=b2[x]+k;
		x=x+lowbit(x);
	}
}
int update(int ll,int rr,int kk)
{
	add1(ll,kk);
	add1(rr+1,-kk);
	add2(ll,kk*ll);
	add2(rr+1,-kk*(rr+1));
}
int query(int ll,int rr)
{
	return ((rr+1)*query1(rr)-query2(rr))-((ll)*query1(ll-1)-query2(ll-1));
}
int l[100005],r[100005],u[100005],d[100005],ans[100005];
signed main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout); 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin>>n>>m>>q;
    //build(1,1,n);
    for(int i = 1; i <= m; i++)
    {
        cin>>x[i]>>y[i]>>z[i];
    }
    for(int i = 1; i <= q; i++)
    {
    	cin>>u[i]>>d[i]>>l[i]>>r[i];
	}
	for(int i = 1; i <= m; i++)
    {
        update(x[i],y[i],z[i]);
        for(int j = 1; j <= q; j++)
        {
        	if(u[j]<=i&&i<=d[j])
        	{
        		ans[j]+=query(l[j],r[j]);
        		ans[j]%=XaoWa118;
			}
		}
    }
    for(int i = 1; i <= q; i++)
    {
    	cout<<ans[i]<<endl;
	}
}

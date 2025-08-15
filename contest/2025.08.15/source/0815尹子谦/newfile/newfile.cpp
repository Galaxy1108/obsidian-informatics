#include<bits/stdc++.h>
#define ls p*2
#define rs p*2+1 
using namespace std ;
const int N=5e3+10,M=1e9+9;
int n,m,q,anss[N];
struct TREE
{
	int l,r;
	int sum[N];
	int lazy[N];
}tr[N*4];
void push_up(int p,int pd)
{
	tr[p].sum[pd]=tr[ls].sum[pd]+tr[rs].sum[pd];
}
void push_down(int p,int pd)
{
	if(tr[p].lazy[pd])
	{
		int ll=tr[ls].l,lr=tr[ls].r,rl=tr[rs].l,rr=tr[rs].r; 
		tr[ls].sum[pd]+=(lr-ll+1)*tr[p].lazy[pd];
		tr[rs].sum[pd]+=(rr-rl+1)*tr[p].lazy[pd];
		tr[ls].lazy[pd]+=tr[p].lazy[pd];
		tr[rs].lazy[pd]+=tr[p].lazy[pd];
		tr[p].lazy[pd]=0; 
	}
}
void build(int p,int l,int r,int pd)
{
	tr[p].l=l,tr[p].r=r;
	tr[p].lazy[pd]=tr[p].lazy[pd-1];
	tr[p].sum[pd]=tr[p].sum[pd-1];
	if(l==r)
	{
		return ;
	} 
	int mid=(l+r)/2;
	build(ls,l,mid,pd);
	build(rs,mid+1,r,pd);
}
void add(int p,int l,int r,int x,int pd)
{
	int L=tr[p].l,R=tr[p].r;
	if(l<=L&&r>=R) 
	{
		tr[p].sum[pd]+=(R-L+1)*x;
		tr[p].lazy[pd]+=x;
		return ;
	}
	push_down(p,pd); 
	int mid=(L+R)/2 ;
	if(mid>=l)add(ls,l,r,x,pd);
	if(mid<r) add(rs,l,r,x,pd);
	push_up(p,pd);
}
int ask(int p,int l,int r,int pd)
{
	int L=tr[p].l,R=tr[p].r;
	if(l<=L&&r>=R) return tr[p].sum[pd];
	push_down(p,pd);
	int mid=(L+R)/2,sum=0;
	if(mid>=l) sum+=ask(ls,l,r,pd);
	if(mid<r) sum+=ask(rs,l,r,pd);
	return sum;
}
signed main()
{
    freopen("newfile1.in","r",stdin);
    freopen("newfile.out","w",stdout);
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)
    {
    	build(1,1,n,i);
    	int l,r,x;
    	cin>>l>>r>>x;
    	add(1,l,r,x,i);
	}
	for(int i=1;i<=q;i++)
	{
		int u,v,l,r,ans=0;
		cin>>u>>v>>l>>r;
		for(int j=u;j<=v;j++)
		{
			int sum=ask(1,l,r,j);
			ans+=sum;
		} 
		anss[i]=ans;
	}
	for(int i=1;i<=q;i++) cout<<anss[i]<<endl;
	return 0;
}

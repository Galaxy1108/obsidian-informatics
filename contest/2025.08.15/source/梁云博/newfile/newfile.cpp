#include <bits/stdc++.h>
#define N 5005
#define ls p<<1
#define rs p<<1|1
#define mid (l+r>>1)
using namespace std;
int n,m,q,a[N],top,rt[N];
const int P=1000000009;
struct Node
{
	int d=0,tag=0;
};
struct tree
{
	Node t[N<<2];
	void up(int p)
	{
		t[p].d=(t[ls].d+t[rs].d)%P;
	}
	void down(int p,int l,int r)
	{
		if(t[p].tag==0 || l==r)return;
		t[ls].d=(t[ls].d+(mid-l+1)*t[p].tag%P)%P;
		t[rs].d=(t[rs].d+(r-mid)*t[p].tag%P)%P;
		t[ls].tag=(t[ls].tag+t[p].tag)%P;
		t[rs].tag=(t[rs].tag+t[p].tag)%P;
		t[p].tag=0;
	}
	void update(int p,int l,int r,int ul,int ur,int k)//pt为父节点的标记值 
	{
		if(ul<=l && r<=ur)
		{
			t[p].d=(t[p].d+(r-l+1)*k%P)%P;
			t[p].tag=(t[p].tag+k)%P;
			return ;
		}
		down(p,l,r);
		if(mid>=ul)update(ls,l,mid,ul,ur,k);
		if(mid+1<=ur)update(rs,mid+1,r,ul,ur,k);
		up(p);
	}
	int query(int p,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr)return t[p].d;
		int res=0;
		down(p,l,r);
		if(mid>=ql)res+=query(ls,l,mid,ql,qr);
		res%=P;
		if(mid+1<=qr)res+=query(rs,mid+1,r,ql,qr);
		return res%P;
	}
}t[N];



signed main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(nullptr);
    cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1,l,r,x;i<=m;i++)
	{
		cin>>l>>r>>x;
		t[i]=t[i-1];
		t[i].update(1,1,n,l,r,x);	
	}
	int u,d,l,r;
	for(int i=1;i<=q;i++)
	{
		cin>>u>>d>>l>>r;
		int sum=0;
		for(int j=u;j<=d;j++)
		{
			sum+=t[j].query(1,1,n,l,r);
			sum%=P;
		}
		cout<<sum<<"\n";
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,t;
int ans=0;
struct cao
{
	int x,y,k;
}c[1000001];
struct ques
{
	int u,d,l,r;
}q[1000001];
struct tree
{
	int l,r,dat,add;
}s[55][4*100005];
void pushup(int i,int p)
{
	s[i][p].dat=s[i][p*2].dat+s[i][p*2+1].dat;
	return; 
} 
void addtag(int i,int p,int x)
{
	s[i][p].dat+=(s[i][p].r-s[i][p].l+1)*x;
	s[i][p].add+=x;
}
void pushdown(int i,int p)
{
	if(s[i][p].add)
	{
		addtag(i,p*2,s[i][p].add);
		addtag(i,p*2+1,s[i][p].add);
		s[i][p].add=0;
	}
}
void build(int i,int p,int l,int r)
{
	s[i][p].l=l;
	s[i][p].r=r;
	if(l==r)
	{
		s[i][p].dat=0;
		return;
	}
	int mid=(l+r)/2;
	build(i,p*2,l,mid);
	build(i,p*2+1,mid+1,r);
	pushup(i,p);
}
void copy(int i,int p)
{
	for(int j=1;j<=p;j++)
	{
		s[i][j].add=s[i-1][j].add;
		s[i][j].dat=s[i-1][j].dat;
		s[i][j].l=s[i-1][j].l;
		s[i][j].r=s[i-1][j].r;
	}
}
void update(int i,int p,int l,int r,int k)
{
	if(s[i][p].l>=l&&s[i][p].r<=r)
	{
		addtag(i,p,k);
		return;
	}
	pushdown(i,p);
	int mid=(s[i][p].l+s[i][p].r)/2;
	if(mid>=l)
	{
		update(i,p*2,l,r,k);
	}
	if(mid<r)
	{
		update(i,p*2+1,l,r,k);
	}
	pushup(i,p);
	return;
}
int query(int i,int p,int l,int r)
{
	if(s[i][p].l>=l&&s[i][p].r<=r)
	{
		return s[i][p].dat;
	}
	pushdown(i,p);
	int tot=0;
	int mid=(s[i][p].l+s[i][p].r)/2;
	if(l<=mid)
	{
		tot+=query(i,p*2,l,r);
	}
	if(mid<r)
	{
		tot+=query(i,p*2+1,l,r);
	}
	return tot;
}
signed main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
	{
		if(i==1) build(i,1,1,n);
		else copy(i,4*n);
		cin>>c[i].x>>c[i].y>>c[i].k;
		update(i,1,c[i].x,c[i].y,c[i].k);
	}
	for(int i=1;i<=t;i++)
	{
		cin>>q[i].u>>q[i].d>>q[i].l>>q[i].r;
		ans=0;
		for(int j=max(1ll,q[i].u);j<=q[i].d;j++)
		{
			ans+=query(j,1,q[i].l,q[i].r);
		}
		cout<<ans<<endl;
	}
}
/*
10 10 10 
3 10 1 
2 8 1 
1 10 1 
2 7 1 
2 9 1 
2 9 1 
2 6 1 
2 6 1 
3 10 1 
1 9 1 
5 9 2 6 
6 7 4 6 
3 8 4 6 
7 8 4 9 
4 6 2 6 
0 2 4 6 
1 5 5 9 
3 8 4 7 
2 8 4 8 
2 7 2 10

10 10 10 
1 10 20 
3 9 85 
1 8 4 
2 8 57 
1 10 16 
1 7 29 
1 10 50 
3 9 76 
2 9 75 
2 8 45 
4 6 5 9 
10 10 5 8 
3 6 5 9 
0 8 2 6 
8 9 5 7 
4 7 3 6 
3 5 3 10 
5 6 5 10 
4 5 5 6 
5 8 4 7
*/

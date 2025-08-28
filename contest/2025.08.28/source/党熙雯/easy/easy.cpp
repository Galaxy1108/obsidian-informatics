#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(2)
using namespace std;
const int mx=2e5+10;
struct tree
{
	int maxn,l,r,se,num,cnt,tag;
}t[4*mx];
int n,a[mx];
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
void update(int p)
{
	t[p].num=t[p<<1].num+t[p<<1|1].num;
	t[p].maxn=max(t[p<<1].maxn,t[p<<1|1].maxn);
	if(t[p<<1].maxn==t[p<<1|1].maxn) t[p].se=max(t[p<<1].se,t[p<<1|1].se),t[p].cnt=t[p<<1].cnt+t[p<<1|1].cnt;
	else if(t[p<<1].maxn>t[p<<1|1].maxn) t[p].se=max(t[p<<1].se,t[p<<1|1].maxn),t[p].cnt=t[p<<1].cnt;
	else if(t[p<<1].maxn<t[p<<1|1].maxn) t[p].se=max(t[p<<1|1].se,t[p<<1].maxn),t[p].cnt=t[p<<1|1].cnt;
}
void build(int p,int l,int r)
{
	t[p].l=l,t[p].r=r;
	if(l==r)
	{
		t[p].num=a[l];
		t[p].maxn=a[l];
		t[p].cnt=1;
		t[p].se=-2e9;
		return ;
	}
	int mid=(l+r)/2;
	build(p<<1,l,mid),build(p<<1|1,mid+1,r);
	update(p);
}
void pushdown(int p)
{
	if(t[p].tag)
	{
		if(t[p<<1].maxn==t[p<<1|1].maxn)
		{
			t[p<<1].num-=t[p<<1].cnt*t[p].tag;
			t[p<<1|1].num-=t[p<<1|1].cnt*t[p].tag;
			t[p<<1].maxn=t[p].maxn;
			t[p<<1|1].maxn=t[p].maxn;
			t[p<<1].tag+=t[p].tag;
			t[p<<1|1].tag+=t[p].tag;
		}
		else if(t[p<<1].maxn>t[p<<1|1].maxn)
		{
			t[p<<1].num-=t[p<<1].cnt*t[p].tag;
			t[p<<1].maxn=t[p].maxn;
			t[p<<1].tag+=t[p].tag;
		}
		else if(t[p<<1|1].maxn>t[p<<1].maxn)
		{
			t[p<<1|1].num-=t[p<<1|1].cnt*t[p].tag;
			t[p<<1|1].maxn=t[p].maxn;
			t[p<<1|1].tag+=t[p].tag;
		}
		t[p].tag=0;
	}
}
void change(int p,int k)
{
	if(t[p].maxn>k&&t[p].se<k)
	{
		t[p].tag+=(t[p].maxn-k);
		t[p].num-=(t[p].maxn-k)*t[p].cnt;
		t[p].maxn=k;
		return ;
	}
	if(t[p].maxn<=k) return ;
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	change(p<<1,k);
	change(p<<1|1,k);
	update(p);
}
int ask(int p,int l,int r)
{
	if(t[p].l>=l&&t[p].r<=r)
	return t[p].num;
	pushdown(p);
	int mid=(t[p].l+t[p].r)/2;
	int ans=0;
	if(l<=mid) ans+=ask(p<<1,l,r);
	if(r>mid) ans+=ask(p<<1|1,l,r);
	return ans;
}
signed main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	n=fread();
	int q=fread();
	for(int i=1;i<=n;i++)
	a[i]=fread();
	if(n<=6000)
	{
		while(q--)
		{
			int opt=fread();
			if(opt==1)
			{
				int v=fread();
				for(int i=1;i<=n;i++)
				a[i]=min(a[i],v);
			}
			else if(opt==2)
			{
				for(int i=1;i<=n;i++)
				a[i]+=i;
			}
			else
			{
				int ans=0;
				int l=fread(),r=fread();
				for(int i=l;i<=r;i++)
				ans+=a[i];
				cout<<ans<<endl;
			}
		}
	}
	else
	{
		build(1,1,n);
		while(q--)
		{
			int opt=fread();
			if(opt==1)
			{
				int v=fread();
				change(1,v);
			}
			if(opt==3)
			{
				int l=fread(),r=fread();
				cout<<ask(1,l,r)<<endl;
			}
		}
		return 0;
	}
}
/*
15 15 6 14 14 6 3 6 4 13 10 3 12 5 11 9 6 
1 9 1 2 2 2 2 1 11 3 4 6 2 1 6 2 1 9 1 11 1 11 3 4 4 3 2 13
*/


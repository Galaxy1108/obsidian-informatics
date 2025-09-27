#include<bits/stdc++.h>
//#define int long long 
using namespace std;
const int mx=5e4+10;
const int inf=1e8;
int n,k,m;
int a[mx];
map<int,bool> pd;
int ans=0;
/*
bool isok(int x)
{
	return pd[x+1]==1;
}

struct segT
{
	int l,r,p;
	int cnt[35];
}t[mx*4];

void pushup(int p)
{
	for(int i=1;i<=k;i++)
		t[p].cnt[i]=t[p*2].cnt[i]+t[p*2+1].cnt[i];
	t[p].p=(t[p*2].p|t[p*2+1].p);
}

void build(int p,int l,int r)
{
	t[p].l=l,t[p].r=r;
	if(l==r)
	{
		t[p].cnt[a[l]]++;
		t[p].p|=(1<<(a[l]-1));
		return;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	pushup(p);
}

void update(int p,int x,int v)
{
	if(t[p].l==x&&t[p].r==x)
	{
		for(int i=1;i<=k;i++) t[p].cnt[i]=0;
		t[p].cnt[v]=1;
		t[p].p=(1<<(v-1));
		return;
	}
	int mid=(t[p].l+t[p].r)/2;
	if(x<=mid) update(p*2,x,v);
	if(x>mid) update(p*2+1,x,v);
	pushup(p);
}

int query(int p)
{
	int res=-1;
	if(!isok(t[p].p)) return -1;
	res=t[p].r-t[p].l+1;
	int flag1=query(p*2);
	int flag2=query(p*2+1);
	if(flag1!=-1) res=min(res,flag1);
	if(flag2!=-1) res=min(res,flag2);
	return res;
}
*/
int cnt[35];
bool check(int len)
{
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=len;i++) cnt[a[i]]++;
	bool flag=1;
	for(int i=1;i<=k;i++)
		if(cnt[i]==0) flag=0;
	if(flag==1) return 1;
	for(int i=2;i<=n-len+1;i++)
	{
		cnt[a[i+len-1]]++,cnt[a[i-1]]--;
		flag=1;
		for(int j=1;j<=k;j++)
			if(cnt[j]==0) flag=0;
		if(flag==1) return 1;
	}
	return 0;
}
signed main() 
{
	freopen("truth.in","r",stdin); 
	freopen("truth.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
//	build(1,1,n);
//	int tt=1;
//	for(int i=1;i<=k;i++)
//	{
//		tt*=2;
//		pd[tt]=1;
//	}
	
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int pos,v;
			cin>>pos>>v;
			//update(1,pos,v);
			a[pos]=v;
		}
		if(op==2)
		{
			//cout<<query(1)<<"\n";
			int ans=50000;
			int l=0,r=50010;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(check(mid)) r=mid;
				else l=mid+1;
			}
			if(l==50010) cout<<-1<<"\n";
			else cout<<l<<"\n";
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
constexpr int N=1e6+5,mod=998244353;
int n,m;
int a[N],b[N];
int s[N],V;
int ans;
int nxt[N];
int f[N],sum;
int rt[N];
int idx;
struct node{
	int l,r,sm;
}tr[N*8];
#define ls(k) tr[k].l
#define rs(k) tr[k].r
inline void pu(int k)
{
	tr[k].sm=(tr[ls(k)].sm+tr[rs(k)].sm)%mod;
}
void upd(int& k,int p,int l,int r,int pos,int val)
{
	k=++idx;
	tr[k]=tr[p];
	if(l==r)
	{
		tr[k].sm=val;
		return;
	}
	int mid=l+r>>1;
	if(pos<=mid)
		upd(ls(k),ls(p),l,mid,pos,val);
	else
		upd(rs(k),rs(p),mid+1,r,pos,val);
	pu(k);
}
int query(int k,int l,int r,int L,int R)
{
	if(r<L || R<l)
		return 0;
	if(L<=l && r<=R)
		return tr[k].sm;
	int mid=l+r>>1;
	return (query(ls(k),l,mid,L,R)+query(rs(k),mid+1,r,L,R))%mod;
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],V=max(V,a[i]);
	for(int i=n;i>=1;i--)
		nxt[i]=s[a[i]],s[a[i]]=i;
	for(int i=n;i>=1;i--)
	{
		(f[i]+=sum+1)%=mod;
		if(nxt[a[i]])
			(f[i]-=f[nxt[a[i]]]-1-mod)%=mod,(sum-=f[nxt[a[i]]]-1-mod)%=mod;
		(sum+=f[i])%=mod;
		upd(rt[i],rt[i+1],1,V,a[i],f[i]);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	(ans+=query(rt[1],1,V,1,b[1]-1))%=mod;
	for(int i=1,j=1;i<=m;i++,j++)
	{
		while(a[j]!=b[i] && j<n)
			j++;
		if(j==n)
			break;
		ans++;
		(ans+=query(rt[j+1],1,V,1,b[i+1]-1))%=mod;
	}
	cout<<ans;
	return 0;
}

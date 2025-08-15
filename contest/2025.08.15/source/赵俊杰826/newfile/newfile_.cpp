#include<bits/stdc++.h>
using namespace std;
const int N=100005;
const int MOD=1000000009;
typedef long long ll;
ll w[8*N],tag[8*N],l[N],r[N],v[N],ans[N];
struct Q
{
	int l,r,id,t;
};
vector<Q>q[N];
void pushdown(int u,int l,int r)
{
	int t=tag[u],mid=(l+r)>>1;
	tag[u]=0;
	tag[u<<1]=(tag[u<<1]+t)%MOD;
	tag[u<<1|1]=(tag[u<<1|1]+t)%MOD;
	w[u<<1]=(w[u<<1]+1ll*(mid-l+1)*t)%MOD;
	w[u<<1|1]=(w[u<<1|1]+1ll*(r-mid)*t)%MOD;
}
void pushup(int u)
{
	w[u]=w[u<<1]+w[u<<1|1];
}
void add(int u,int l,int r,int x,int y,int k)
{
	pushdown(u,l,r);
	if(l>=x&&r<=y)
	{
		tag[u]=(tag[u]+k)%MOD;
		w[u]=(w[u]+1ll*(r-l+1)*k)%MOD;
		return;
	}
	int mid=(l+r)>>1;
	if(mid>=x)add(u<<1,l,mid,x,y,k);
	if(mid<y)add(u<<1|1,mid+1,r,x,y,k);
	pushup(u);
}
ll get(int u,int l,int r,int x,int y)
{
	pushdown(u,l,r);
	if(l>=x&&r<=y)return w[u];
	int mid=(l+r)>>1,sum=0;
	if(mid>=x)sum+=get(u<<1,l,mid,x,y);
	if(mid<y)sum+=get(u<<1|1,mid+1,r,x,y);
	return sum%MOD;
}
int main()
{
	freopen("newfile.in","r",stdin);
	freopen("newfile.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,T;
	cin>>n>>m>>T;
	for(int i=1;i<=m;i++)
	{
		cin>>l[i]>>r[i]>>v[i];
	}
	for(int i=1;i<=T;i++)
	{
		int u,v,l,r;
		cin>>u>>v>>l>>r;
		if(u==0)u=1;
		for(int j=u;j<=v;j++)
			q[j].push_back({l,r,i,1});
	}
	for(int i=1;i<=m;i++)
	{
		add(1,1,n,l[i],r[i],v[i]);
		for(int j=0;j<q[i].size();j++)
			ans[q[i][j].id]+=get(1,1,n,q[i][j].l,q[i][j].r)*q[i][j].t;
	}
	for(int i=1;i<=T;i++)
		cout<<(ans[i]%MOD+MOD)%MOD<<'\n';
	return 0;
}

#include<cstdio>
#include<algorithm>
#define ls (now<<1)
#define rs (now<<1|1)
#define mid ((l+r)>>1)
#define ll long long
using namespace std;
const int N=4e5+10;
const ll inf=1e18;
pair<ll,int> t[N];
ll a[N];
int T,n,tag[N<<2];
bool chk()
{
	for(int i=1;i<=n;i++) t[i]={a[i]-i,i};
	sort(t+1,t+n+1);
	for(int i=1;i<n;i++)
		if(t[i].first==t[i+1].first) return 0;
	return 1;
}
ll tr[N<<2],ans;
void update(int now)
{
	tr[now]=max(tr[ls],tr[rs])-2*tag[now];
}
void build(int l,int r,int now)
{
	tag[now]=0;
	if(l==r) tr[now]=a[l]+l-1;
	else build(l,mid,ls),build(mid+1,r,rs),update(now);
}
void change(int l,int r,int now,int w)
{
	if(r<w) return;
	if(l>=w){tag[now]++,tr[now]-=2;return;}
	change(l,mid,ls,w),change(mid+1,r,rs,w);
	update(now);
}
void del(int l,int r,int now,int w)
{
	if(l==r)
	{
		tr[now]=-inf;
		return;
	}
	if(w<=mid) del(l,mid,ls,w);
	else del(mid+1,r,rs,w);
	update(now);
}
ll query(int l,int r,int now,int w)
{
	if(r<w) return -inf;
	if(l>=w) return tr[now];
	return max(query(l,mid,ls,w),query(mid+1,r,rs,w))-2*tag[now];
}
char c;
inline char gc()
{
	static char buf[1<<20],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++;
}
ll rd()
{
	register ll a=0;
	c=gc();
	while(c>'9'||c<'0') c=gc();
	while(c>='0'&&c<='9') a=(a<<3)+(a<<1)+(c&15),c=gc();
	return a;
}
int main()
{
	freopen("jyrg.in","r",stdin);
	freopen("jyrg.out","w",stdout);
	T=rd();
	while(T--)
	{
		n=rd();
		for(int i=1;i<=n;i++) a[i]=rd();
		if(!chk()){printf("-1\n");continue;}
		build(1,n,1);
		for(int i=1;i<=n;i++)
		{
			del(1,n,1,t[i].second);
			ans=max(ans,query(1,n,1,t[i].second)+t[i].first);
			change(1,n,1,t[i].second);
		}
		printf("%lld\n",ans),ans=0;
	}
}
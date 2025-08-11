#include <bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
inline long long pw(int x){return 1ll*x*x;}
int n,m[200010],m_[200010],bas[200010],mnm,tot;
vector<int> val[200010],val_[200010];
int a[300010],*sta;
int ind[200010];
struct Lian_Biao{
	vector<int> pre,suf,val;
	long long sum;
	inline void init(int siz,int *f)
	{
		pre.resize(siz+2),suf.resize(siz+2),val.resize(siz+2);
		val[siz+1]=2000000;
		for(int i=1;i<=siz;i++) val[i]=f[i],ind[i]=i;
		sort(ind+1,ind+siz+1,[&](int a,int b){return f[a]<f[b];});
		ind[siz+1]=siz+1;
		for(int i=1;i<=siz;i++) pre[ind[i]]=ind[i-1],suf[ind[i]]=ind[i+1];
		suf[0]=ind[1],pre[siz+1]=ind[siz];
		for(int i=0;i<=siz;i++) sum+=pw(val[ind[i]]-val[ind[i+1]]);
	}
	inline void del(int x)
	{
		sum-=pw(val[pre[x]]-val[x])+pw(val[suf[x]]-val[x]);
		sum+=pw(val[pre[x]]-val[suf[x]]);
		suf[pre[x]]=suf[x],pre[suf[x]]=pre[x];
	}
	inline void add(int x)
	{
		sum+=pw(val[pre[x]]-val[x])+pw(val[suf[x]]-val[x]);
		sum-=pw(val[pre[x]]-val[suf[x]]);
		suf[pre[x]]=pre[suf[x]]=x;
	}
}lk[200010];
long long f[200010],ans=inf;
int fro[200010];
void solve(int id,int L,int R,int l,int r)
{
	if(l>r) return;
	int mid=(l+r>>1),tk=-1;long long F=inf;

	for(int i=r;i>=mid;i--) lk[id].del(m[id]+i);

	for(int i=L;i<=R;i++)
	{
		if(F>f[bas[id]+i]+lk[id].sum) F=f[bas[id]+i]+lk[id].sum,tk=i;
		lk[id].del(i);
	}
	f[bas[id+1]+mid]=F,fro[bas[id+1]+mid]=tk;

	for(int i=R;i>=L;i--) lk[id].add(i);
	solve(id,L,tk,l,mid-1);

	for(int i=mid;i<=r;i++) lk[id].add(m[id]+i);
	for(int i=L;i<tk;i++) lk[id].del(i);

	solve(id,tk,R,mid+1,r);
	for(int i=tk-1;i>=L;i--) lk[id].add(i);
}
void Solve(int L,int R,vector<int> l,vector<int> r)
{
	if(L>R) return;

	int mid=(L+R>>1);
	l[1]=r[1]=mid,f[mid]=0;

	for(int i=L;i<mid;i++) lk[1].del(i);
	for(int i=2;i<=n;i++)
		solve(i-1,l[i-1],r[i-1],l[i],r[i]);
	for(int i=mid-1;i>=L;i--) lk[1].add(i);

	int tk=-1;long long F=inf;
	for(int i=R;i>=mid;i--) lk[n].del(m[n]+i);
	for(int i=l[n];i<=r[n];i++)
	{
		if(F>f[bas[n]+i]+lk[n].sum) F=f[bas[n]+i]+lk[n].sum,tk=i;
		lk[n].del(i);
	}
	for(int i=r[n];i>=l[n];i--) lk[n].add(i);
	for(int i=mid;i<=R;i++) lk[n].add(m[n]+i);

	// printf("%d=>%lld\n",mid,F);

	if(ans>F) ans=F;
	vector<int> md(n+1);
	md[n]=tk;
	for(int i=n;i>2;i--)
		md[i-1]=fro[md[i]+bas[i]];
	
	////////////////////////////////
	for(int i=2;i<=n;i++)
	for(int j=r[i];j>md[i];j--)
		lk[i-1].del(m[i-1]+j);
	for(int i=R;i>=mid;i--)
		lk[n].del(m[n]+i);
	Solve(L,mid-1,l,md);
	for(int i=2;i<=n;i++)
	for(int j=md[i]+1;j<=r[i];j++)
		lk[i-1].add(m[i-1]+j);
	for(int i=mid;i<=R;i++)
		lk[n].add(m[n]+i);
	////////////////////////////////
	for(int i=2;i<=n;i++)
	for(int j=l[i];j<md[i];j++)
		lk[i].del(j);
	for(int i=L;i<=mid;i++)
		lk[1].del(i);
	Solve(mid+1,R,md,r);
	for(int i=2;i<=n;i++)
	for(int j=md[i]-1;j>=l[i];j--)
		lk[i].add(j);
	for(int i=mid;i>=L;i--)
		lk[1].add(i);
}
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);

	n=Qread();
	for(int i=1;i<=n;i++)
	{
		m_[i]=Qread();
		val_[i].resize(m_[i]+1);
		for(int j=1;j<=m_[i];j++)
			val_[i][j]=Qread();
		if(mnm==0||m_[mnm]>m_[i])
			mnm=i;
	}
	for(int i=mnm;i<=n;i++) m[i-mnm+1]=m_[i],val[i-mnm+1]=val_[i];
	for(int i=1;i<mnm;i++) m[n-mnm+1+i]=m_[i],val[n-mnm+1+i]=val_[i];

	for(int i=1;i<=n;i++)
	{
		bas[i]=tot;
		for(int j=1;j<=m[i];j++)
			a[++tot]=val[i][j];
	}
	
	//build link
	sta=a;
	for(int i=1;i<n;i++)
	{
		lk[i].init(m[i]+m[i+1],sta);
		sta+=m[i];
	}
	for(int i=1;i<=m[1];i++)
		a[tot+i]=a[i];
	lk[n].init(m[n]+m[1],sta);

	vector<int> tl(n+1),tr(n+1);
	for(int i=1;i<=n;i++) tl[i]=1,tr[i]=m[i];
	Solve(1,m[1],tl,tr);

	printf("%lld\n",ans);
	return 0;
}
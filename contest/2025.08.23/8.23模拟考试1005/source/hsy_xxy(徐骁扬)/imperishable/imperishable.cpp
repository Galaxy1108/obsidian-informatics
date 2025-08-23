#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
const long long Mod=998244353;
int Num,n,q,i,x,y;
int a[200010];
long long qpow[200010];
int hav;
struct Xds{
	long long sum;
	int maxn;
}s[800010];
#define mid (l+r>>1)
#define ls (pos<<1)
#define rs ((pos<<1)+1)
int get_max(int p,int q)
{
	return a[p]>a[q]?p:q;
}
void update(int pos)
{
	return s[pos].maxn=get_max(s[ls].maxn,s[rs].maxn),s[pos].sum=s[ls].sum+s[rs].sum,void();
}
void build(int pos=1,int l=1,int r=n)
{
	if(l==r) return s[pos].maxn=l,s[pos].sum=a[l],void();
	else return build(ls,l,mid),build(rs,mid+1,r),update(pos);
}
void change_num(int k,int num,int pos=1,int l=1,int r=n)
{
	if(l==r) return s[pos].sum=num,void();
	if(k<=mid) return change_num(k,num,ls,l,mid),update(pos);
	else return change_num(k,num,rs,mid+1,r),update(pos); 
}
long long get_sum(int R,int pos=1,int l=1,int r=n)
{
	if(r<=R) return s[pos].sum;
	if(l>R) return 0;
	else return get_sum(R,ls,l,mid)+get_sum(R,rs,mid+1,r);
}
#undef mid
#undef ls
#undef rs
int Qfind(long long num,int l,int r)
{
	int mid,ret;
	while(l<=r)
	{
		mid=(l+r>>1);
		if(get_sum(mid)>=num) ret=mid,r=mid-1;
		else l=mid+1;
	}
	return ret;
}
long long solve()
{
	long long ret=0,ned=0,rem=0,tot;
	i=s[1].maxn;
	long long sum=get_sum(i-1);
	if(a[i]>sum) return qpow[i];
	else if(a[i]==sum) return (qpow[i]+Mod-2)%Mod;
	int lim=Qfind(a[i],1,i-1);ned=a[i],tot=get_sum(lim);
	ret=(qpow[lim+1]+Mod-2)%Mod;
	for(i=lim;i>=1;i--)
	{
		if(tot>=ned+a[i])
		{
			(ret+=Mod-qpow[i])%=Mod;
			ned+=a[i];
		}
	}
	return ret;
}
int main()
{
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	Num=Qread();
	n=Qread();
	qpow[0]=1;
	for(i=1;i<=n;i++)
		qpow[i]=qpow[i-1]*2%Mod;
	for(i=1;i<=n;i++)
		a[i]=Qread();
	build();
	printf("%lld\n",solve());
	q=Qread();
	while(q--)
	{
		x=Qread();y=Qread();
		change_num(x,a[x]=y);
		printf("%lld\n",solve());
	}
	return 0;
}
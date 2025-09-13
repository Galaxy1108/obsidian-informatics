#include<bits/stdc++.h>
#define rr register
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x;
}
const int N=1e5+3;
const ll inf=2e18+1;
int n,T;
ll a[N],ans;

inline bool jud()
{
	for(rr int i(1);i<n;++i) if(a[i]<a[i+1]) return false;
	return true;
}

inline bool pd()
{
	for(rr int i(1);i<n;++i) if(a[i+1]-a[i]==1) return true;
	return false;
}

inline void work(ll &x,ll &y) 
{
	swap(x,y);
	--x,++y;
	return;
}

void bf(ll maxn)
{
	if(maxn>=ans) return;
	if(jud())
	{
		ans=maxn;
		return;
	}
	for(rr int i(1);i<n;++i)
		if(a[i]<a[i+1]) 
		{
			work(a[i],a[i+1]);
			bf(max(maxn,a[i]+a[i+1]));
			work(a[i],a[i+1]);
		}
}

int main()
{
	freopen("jyrg.in","r",stdin);
	freopen("jyrg.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		for(rr int i(1);i<=n;++i) a[i]=read();
		if(pd()) printf("-1\n");
		else if(jud()) printf("0\n");
		else
		{
			ans=inf;
			bf(0);
			printf("%lld\n",ans);
		}
	}
	return 0;
} 
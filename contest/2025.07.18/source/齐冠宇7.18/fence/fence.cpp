#include <bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
template<typename T>
void rd(T& x)
{
	x=0;
	int f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=x*10+ch-48,ch=getchar();
	x*=f;
}
template<typename T>
void wr(T x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x<=9)
		putchar(x+48);
	else
		wr(x/10),putchar(x%10+48);
}
constexpr int N=1e5+5,mod=1e9+7;
int n;
pii a[N];
int ans;
inline int get(int x)
{
	return (x*(x+1)/2)%mod;
}
int st[N],cnt[N],top;
int sum;
signed main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	rd(n);
	for(int i=1;i<=n;i++)
		rd(a[i].fi);
	for(int i=1;i<=n;i++)
		rd(a[i].se);
	for(int i=1;i<=n;i++)
	{
		int tim=a[i].se;
		while(top && a[st[top]].fi>a[i].fi)
		{
			tim=(tim+cnt[top])%mod;
			sum=(sum-cnt[top]*get(a[st[top]].fi)%mod+mod)%mod;
			sum=(sum+cnt[top]*get(a[i].fi)%mod)%mod;
			top--;
		}
		ans=(ans+sum*a[i].se%mod)%mod;
		ans=(ans+get(a[i].fi)*get(a[i].se)%mod)%mod;
		st[++top]=i;
		cnt[top]=tim;
		sum=(sum+get(a[i].fi)*a[i].se%mod)%mod;
		//cout<<ans<<'\n';
	}
	wr(ans);
	return 0;
}

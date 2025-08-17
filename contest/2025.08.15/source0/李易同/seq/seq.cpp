#include <iostream>
using namespace std;
const int p=998244353;
int n,m,mx;
int a[1000010];
int b[1000010];
long long f[100010];
int sum[100010];
void ad(int &x1,int x2)
{
	x1+=x2;
	if(x1>=p) x1-=p;
}
void add(int x,int k)
{
	while(x<=mx+1)
	{
		ad(sum[x],k);
		x+=(x&-x);
	}
}
int sm(int x)
{
	if(x<0) return 0;
	int res=0;
	while(x)
	{
		ad(res,sum[x]);
		x-=(x&-x);
	}
	return res;
}
int read()
{
	int s=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch))
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return s;
}
int pre=1;
int pos[1000010];
int ans;
signed main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	m=read();
	for(int i=1;i<=m;++i) b[i]=read();
	b[m+1]=-1;
	for(int i=1;i<=n;++i) if(a[i]==b[pre]) pos[i]=pre,++pre;
	for(int i=1;i<=n;++i) mx=max(mx,a[i]);
	add(mx+1,1);
	for(int i=n;i>=1;--i)
	{
		if(pos[i]) ad(ans,sm(b[pos[i]+1]-1)),ad(ans,1);
		int tmp=sm(mx+1);
		add(a[i],(tmp-f[a[i]]+p)%p);
		f[a[i]]=tmp;
	}
	ad(ans,sm(b[1]-1));
	cout<<ans<<'\n';
	return 0;
}

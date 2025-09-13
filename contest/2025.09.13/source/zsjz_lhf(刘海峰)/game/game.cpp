#include<cstdio>
#define ll long long
using namespace std;
const int N=1e6+10,mod=998244353;
ll fastpow(ll a,int b)
{
	ll s=1;
	while(b)
	{
		if(b&1) s=s*a%mod;
		a=a*a%mod, b>>=1;
	}
	return s;
}
int f[N],s[N],s1[N],s2[N],ans[N],n;
int get_phi(int x)
{
	int s=x;
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
		{
			while(x%i==0) x/=i;
			s=s/i*(i-1);
		}
	if(x>1) s=s/x*(x-1);
	return s;
}
int a[N],k,q,mx,phi[N],vis[N],p[N],len;
void init(int n)
{
	phi[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++len]=i,phi[i]=i-1;
		for(int j=1,x;j<=len&&i*p[j]<=n;j++)
		{
			vis[x=i*p[j]]=1;
			phi[x]=phi[i]*p[j];
			if(i%p[j]==0) break;
			phi[x]-=phi[i];
		}
	}
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d%d",&k,&q);
	for(int i=1;i<=q;i++) scanf("%d",&a[i]),n=(n>a[i]?n:a[i]);
	f[0]=s[0]=1,init(n);
	for(int i=1;i<=k;i++) s[i]=1;
	for(int i=k+1;i<=n;i++) f[i]=s[i-k-1],s[i]=(s[i-1]+f[i])%mod;
	for(int i=1;i<=n;i++) s1[i]=(s1[i-1]+1ll*f[i]*i)%mod;
	for(int i=k+1;i<=n;i++) s2[i]=(1ll*s[i-k-1]*i-s1[i-k-1]+mod)%mod;
	for(int i=1;i<=n;i++)
		for(int j=1;j*i<=n;j++)
			ans[i*j]=(ans[i*j]+1ll*phi[i]*s2[j])%mod;
	for(int i=1;i<=n;i++) ans[i]=ans[i]*fastpow(i,mod-2)%mod;
	for(int i=1;i<=q;i++) printf("%d %d\n",s2[a[i]],ans[a[i]]);
}
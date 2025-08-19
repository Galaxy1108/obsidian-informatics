#include <bits/stdc++.h>
#define Mod 998244353
#define Mod_ 998244352
#define Mod__ 402653184
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int Qread_()
{
	long long x=0;bool flg=false;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48),ch=getchar();
		if(x>=Mod__) x%=Mod__,flg=true;
	}
	if(flg) x+=Mod__;
	return x;
}
int qpow(int a,int p)
{
	int ret=1;
	for(;p;p>>=1,a=1ll*a*a%Mod)
		if(p&1) ret=1ll*ret*a%Mod;
	return ret;
}
int qpow_(int a,int p)
{
	int ret=1;
	for(;p;p>>=1,a=1ll*a*a%Mod_)
		if(p&1) ret=1ll*ret*a%Mod_;
	return ret;
}
int chk(int a){return a>=0?a:a+Mod_;}
int val[1000010],sval[1000010],isval[1000010];
int n,K,ans,g;
void solve()
{
	n=Qread(),K=Qread_();
	ans=1;
	g=qpow_(n,K);
	for(int l=1,r;l<=n;l=r+1)
	{
		r=n/(n/l);
		ans=1ll*ans*qpow(1ll*sval[r]*isval[l-1]%Mod,chk(g-qpow_(n-n/l,K)))%Mod;
	}
	printf("%d\n",ans);
}
vector<int> prim;
bool vis[1000010];
int inv[1000010],mu[1000010];
int main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	
	mu[1]=1;
	for(int i=2;i<=1000000;i++)
	{
		if(!vis[i]) prim.push_back(i),mu[i]=-1;
		for(int j:prim)
		{
			if(i*j>1000000) break;
			vis[i*j]=true,mu[i*j]=mu[i]*mu[j];
			if(i%j==0){mu[i*j]=0;break;}
		}
	}
	inv[1]=1;
	for(int i=2;i<=1000000;i++)
		inv[i]=1ll*inv[Mod%i]*(Mod-Mod/i)%Mod;
	
	for(int i=1;i<=1000000;i++) val[i]=1;
	for(int i=1;i<=1000000;i++) if(mu[i])
	{
		if(mu[i]==1) for(int j=i;j<=1000000;j+=i) val[j]=1ll*val[j]*(j/i)%Mod;
		else for(int j=i;j<=1000000;j+=i) val[j]=1ll*val[j]*inv[j/i]%Mod;
	}

	sval[0]=isval[0]=1;
	for(int i=1;i<=1000000;i++) sval[i]=1ll*sval[i-1]*val[i]%Mod;
	isval[1000000]=qpow(sval[1000000],Mod-2);
	for(int i=999999;i;i--) isval[i]=1ll*isval[i+1]*val[i+1]%Mod;

	int T=Qread();
	while(T--) solve();
	return 0;
}
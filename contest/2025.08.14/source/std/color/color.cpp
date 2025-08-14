#include <bits/stdc++.h>
#define Mod 998244353
#define inv2 499122177
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int qpow(int a,int p)
{
	int ret=1;
	for(;p;p>>=1,a=1ll*a*a%Mod)
		if(p&1) ret=1ll*ret*a%Mod;
	return ret;
}
inline int chk(int a){return a>=Mod?a-Mod:a;}
inline void add(int &a,int b){a+=b;if(a>=Mod) a-=Mod;}
inline void del(int &a,int b){a-=b;if(a<0) a+=Mod;}
int C[2010][2010];
int n,cnt[2010],invn;
int f[2010],tmp,ans;
int calc1(int x,int j){return (n+j-1ll*inv2*(n+x)%Mod+Mod)*C[x][j]%Mod*invn%Mod;}
int calc2(int x,int j){return (1ll*inv2*(n+x)%Mod+Mod-j)*C[x][j]%Mod*invn%Mod;}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	
	n=Qread();invn=qpow(n,Mod-2);
	for(int i=0;i<=n;i++)
	for(int j=0;j<=i;j++)
		if(j==0||i==j) C[i][j]=1;
		else C[i][j]=chk(C[i-1][j-1]+C[i-1][j]);
	for(int i=1;i<n;i++)
	{
		tmp=1ll*qpow(2,i)*(f[i]+1ll*i*invn%Mod)%Mod;
		del(tmp,1ll*f[0]*calc1(i,0)%Mod);
		for(int j=1;j<=i;j++) del(tmp,1ll*f[j]*(calc1(i,j)+calc2(i,j-1))%Mod);
		f[i+1]=1ll*tmp*qpow(calc2(i,i),Mod-2)%Mod;
	}
	for(int i=1;i<=n;i++) cnt[Qread()]++;
	ans=f[n];
	for(int i=1;i<=n;i++) del(ans,f[cnt[i]]);
	printf("%d\n",ans);
	return 0;
}
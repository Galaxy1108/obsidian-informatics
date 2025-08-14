#include <bits/stdc++.h>
#define Mod 998244353
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
inline void add(int &a,int b){a+=b;if(a>=Mod) a-=Mod;}
inline void del(int &a,int b){a-=b;if(a<0) a+=Mod;}
inline int chk(int a){return a>=Mod?a-Mod:a;}
inline int qpow(int a,int p)
{
	int ret=1;
	for(;p;p>>=1,a=1ll*a*a%Mod)
		if(p&1) ret=1ll*ret*a%Mod;
	return ret;
}
typedef pair<int,int> pr;
int n,m,S,T;
vector<pr> ed[110];
int x,y,o;
int inv[10010],d[110];
int a[310][310];
int f[310];
void calc(int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n&&!a[i][i];j++)
			if(a[j][i]) for(int k=i;k<=n+1;k++)
				swap(a[i][k],a[j][k]);
		int ny=qpow(a[i][i],Mod-2);
		for(int j=i+1,tk;j<=n;j++)
		{
			tk=1ll*a[j][i]*ny%Mod;
			for(int k=n+1;k>=i;k--)
				del(a[j][k],1ll*a[i][k]*tk%Mod);
		}
	}

	for(int i=n;i;i--)
	{
		f[i]=a[i][n+1];
		for(int j=i+1;j<=n;j++)
			del(f[i],1ll*f[j]*a[i][j]%Mod);
		f[i]=1ll*f[i]*qpow(a[i][i],Mod-2)%Mod;
	}
}
int n2,n3;
int main()
{
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);

	inv[1]=1;
	for(int i=2;i<=10000;i++)
		inv[i]=1ll*inv[Mod%i]*(Mod-Mod/i)%Mod;

	n=Qread(),m=Qread(),S=Qread(),T=Qread();
	for(int i=1;i<=m;i++)
	{
		x=Qread(),y=Qread(),o=Qread();
		if(x!=T) ed[y].push_back(make_pair(x,o)),d[x]++;
	}
	
	n2=n+n,n3=n+n+n;

	for(int i=1,tk,tk_;i<=n;i++)
	{
		a[i][i]=a[n+i][n+i]=a[n2+i][n2+i]=1;
		if(i==S) a[i][n3+1]=1;
		#define u v.first
		for(pr v:ed[i])
		{
			tk=inv[d[u]];tk_=chk(tk+tk);
			//p
			del(a[i][u],tk);
			//f
			if(v.second) del(a[n+i][u],tk),del(a[n+i][n+u],tk);
			//g
			if(v.second) del(a[n2+i][u],tk),del(a[n2+i][n+u],tk_),del(a[n2+i][n2+u],tk);
		}
		#undef u
	}

	calc(n3);

	printf("%d %d\n",f[n+T],chk(f[n2+T]+Mod-1ll*f[n+T]*f[n+T]%Mod));
	return 0;
}
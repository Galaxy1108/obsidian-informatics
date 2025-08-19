#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int qpow(int a,int p,int Mod)
{
	int ret=1;
	for(;p;p>>=1,a=(long long)a*a%Mod)
		if(p&1) ret=(long long)ret*a%Mod;
	return ret;
}
int n,x,p,m,ans;
int a[1010];
int px[1010],px_[1010];
int S[1010][1010];
void add(int &a,int b){a+=b;if(a>=p) a-=p;}
int main()
{
	freopen("combination.in","r",stdin);
	freopen("combination.out","w",stdout);

	n=Qread(),x=Qread(),p=Qread(),m=Qread();x%=p;
	for(int i=0;i<=m;i++) a[i]=Qread();
	
	S[1][1]=1;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=i;j++)
		add(S[i+1][j+1],S[i][j]),add(S[i+1][j],(long long)S[i][j]*j%p);
	
	px[0]=1;
	for(int i=1;i<=m;i++) px[i]=(long long)px[i-1]*x%p*(n-i+1)%p;
	
	add(x,1);
	
	px_[m]=qpow(x,n-m,p);
	for(int i=m-1;i>0;i--) px_[i]=(long long)px_[i+1]*x%p;

	ans=qpow(x,n,p);ans=(long long)ans*a[0]%p;
	
	for(int i=1;i<=m;i++)
		px[i]=(long long)px[i]*px_[i]%p;

	for(int i=1;i<=m;i++)
	for(int j=1;j<=i;j++)
		add(ans,(long long)S[i][j]*px[j]%p*a[i]%p);
	printf("%d\n",ans);
	return 0;
}
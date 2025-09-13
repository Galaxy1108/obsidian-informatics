#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(2)
using namespace std;
const int mx=1e6+100;
int jc[mx],jcinv[mx];
const int mod=998244353;
int k;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b%2) ans*=a,ans%=mod;
		a*=a,a%=mod;
		b/=2; 
	}
	return ans;
}
int inv(int x)
{
	return ksm(x,mod-2);
}
int C(int x,int m)
{
	return ((jc[x]*jcinv[x-m])%mod*jcinv[m])%mod;
}
signed main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	k=fread();
	int T=fread();
	jc[0]=1;
	for(int i=1;i<mx;i++)
	{
		jc[i]=jc[i-1]*i;
		jc[i]%=mod;
		jcinv[i]=inv(jc[i]);
	}
	while(T--)
	{
		int n=fread();
		if(n<=k) 
		{
			cout<<"0 0\n";
			continue;
		}
		int cnt=n/(k+1);
		if(cnt==1)
		{
			cout<<n<<" 1\n";
			continue;
		}
	}
	return 0;
}



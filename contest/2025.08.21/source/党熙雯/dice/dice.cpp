#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(2)
using namespace std;
const int mod=1e9+7;
const int mx=1e5;
int a[mx];
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
signed main()
{
	freopen("dice.in","r",stdin);
	freopen("dice.out","w",stdout);
	int n=fread();
	int maxn=0;
	for(int i=1;i<=n;i++) a[i]=fread(),maxn=max(maxn,a[i]);
	
		sort(a+1,a+n+1);
		int ans1=0,ans2=1;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			ans2*=a[i];
			ans2%=mod;
			if(a[i]==a[i-1])
			{
				continue;
			}
			int x=1,y=0;//次数，数值 
			for(int k=a[i-1]+1;k<=a[i];k++)
			{
				y=ans2*inv(a[i])%mod;
				y*=ksm(k,n-i+1);
				y%=mod;
				y-=cnt;
				y=(y+mod)%mod;
				cnt+=y;
				cnt%=mod;
				ans1+=k*y;
				ans1%=mod;
			}
		}
		ans2=inv(ans2);
		cout<<ans1*ans2%mod;
		return 0;
	
	return 0;
}



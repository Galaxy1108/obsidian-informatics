#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int mx=1e6+100;
long long n,p;
int m2[mx];
int c[3][mx];
int fread()
{
	int x=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
	return x*w;
} 
//struct num
//{
//	int a[1100];
//	bool operator +(const num &x) const 
//	{
//		for(int i=1;i<=)
//	}
//}
int ksm(int a,int b,int p)
{
	int ans=1;
	while(b)
	{
		if(b%2) ans*=a,ans%=p;
		a*=a,a%=p;
		b/=2;
	}
	return ans%p;
}
int inv(int x,int p)
{
	return ksm(x,p-2,p);
}
int gcd(int a,int b)
{
	if(a<b) swap(a,b);
	if(a%b==0) return b;
	return gcd(a%b,b);
}
int lcm(int a,int b)
{
//	a%=p,b%=p;
	__int128 g=gcd(a,b);
//	return ((a*b)%p*(inv(g,p)%p))%p;
	return (a*b)/gcd(a,b);
}
void pre()
{
	m2[0]=1;
	m2[1]=2;
	for(int i=2;i<=n+10;i++)
	m2[i]=(m2[i-1]*2)%p;
}
int solve1(int x)
{
	int ans=0;
	for(int i=1;i<=x+1;i++)
	{
		c[1][i]=(c[2][i]+c[2][i-1])%p;
//		cout<<c[1][i]<<' ';
		if(i%2==0)
		{
			ans+=c[1][i]%p*m2[(i-1)/2]%p;
			ans%=p;
//			cout<<ans<<' ';
		}
	}
//	cout<<endl;
	return ans%p;
}
//int fwrite(int x)
//{
//	while(x)
//	{
//		putchar(x/10+'0');
//		
//	}
//}
int solve2(int x)
{
	int ans=0;
	for(int i=1;i<=x+1;i++)
	{
		c[2][i]=(c[1][i]+c[1][i-1])%p;
//		cout<<c[2][i]<<' ';
		if(i%2==0)
		{
			ans+=(c[2][i]%p*m2[(i-1)/2]%p)%p;
			ans%=p;
//			cout<<ans<<' ';
		}
	}
//	cout<<endl;
	return ans%p;
}
signed main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	int T=fread();
	while(T--)
	{
		memset(c,0,sizeof(c));
		n=fread(),p=fread();
		pre();
		c[2][1]=1;
		__int128 lcmans=1;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			if(i%2) x=solve1(i);
			else x=solve2(i);
//			cout<<x<<' ';
			__int128 gi=lcm(lcmans,x);
			lcmans=gi;
			gi*=i;
			gi%=p;
			ans+=gi;
			ans%=p;
		}
////		cout<<endl;
//		fwrite(ans%p);
		cout<<ans%p<<endl;
	}
	return 0;
}

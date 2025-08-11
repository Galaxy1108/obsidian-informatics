#include<bits/stdc++.h>
using namespace std;
const int mx=2510000;
long long a[mx],q[mx],f[mx];
int mod=1e9+7;
int n,k;
int fread()
{
	int x=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	x=x*10+(ch-'0'),ch=getchar();
	return x*w;
}
long long yb()

{
	long long ans=1,a=23,b=n;
	while(b)
	{
		if(b%2) ans*=a,ans%=mod;
		a*=a;
		a%=mod;
		b/=2;
//		cout<<ans<<' '<<a<<endl;
	}
	return ans%mod;
}
int main()
{
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	n=fread(),k=fread();
	int head=1,tail=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=fread();
		while(tail>=head&&a[q[head]]<a[i]) tail--;
		while(tail>=head&&q[head]<i-k+1) head++;
		q[++tail]=i;
		if(i>k)
		{
			f[i]=min(a[i]+f[i-1],a[q[head]]+f[i-k]);
		}
		else f[i]=a[q[head]];
		f[i]%=mod;
//		for(int j=head;j<=tail;j++) cout<<q[j]<<' ';cout<<endl;
	}
	for(int i=1;i<=n;i++) cout<<f[i]<<' ';cout<<endl;
	long long ans=0;
	long long mul=1;
	for(int i=n;i>=1;i--)
	{
		ans+=mul*f[i]%mod;
		ans%=mod;
//		cout<<i<<":"<<f[i]<<"*"<<mul<<' '<<ans<<'\n';/
		mul*=23;
		mul%=mod;
	}
//	cout<<ans<<endl;
	ans%=mod;
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
#define int long long
//#pragma GCC optimize(2)
using namespace std;
const int mod=998244353;
const int mx=5e4+100;
int jc[mx],jcinv[mx];
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
	return ans%mod;
}
int inv(int x)
{
	return ksm(x,mod-2);
}
signed main()
{
	freopen("youup.in","r",stdin);
	freopen("youup.out","w",stdout);
	int num=fread(),n=fread(),x=fread();
	for(int i=1;i<=n-1;i++) fread(),fread();
	jc[0]=1;
	jcinv[0]=1;
	for(int i=1;i<=50001;i++)
	{
		jc[i]=jc[i-1]*i%mod;
		jcinv[i]=inv(jc[i]);
	}
//	for(int i=1;i<=10;i++) cout<<jc[i]<<' '<<jcinv[i]<<endl;
//	cout<<endl;
//	for(int i=1;i<=10;i++)
//	cout<<ksm(2,i)<<' ';
//	cout<<endl;
	if(num==1)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1) cout<<n<<' ';
			else
			cout<<0<<' ';
		}
		return 0;
	}
	if(num==4)
	{
		if(x==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==1) cout<<n<<' ';
				else
				cout<<0<<' ';
			}
		}
		else if(x==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==1)
				cout<<n<<' ';
				else if(i==2)
				{
					cout<<n-1<<' ';
				}
				else
				cout<<0<<' ';
			 } 
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				cout<<((jc[n]*jcinv[n-i]%mod)*jcinv[i]%mod)%mod<<' ';
			}
		}
		return 0;
	} 
	if(num==5)
	{
		if(x>=n)
		{
			for(int i=1;i<=n;i++)
			{
				cout<<((jc[n]*jcinv[n-i]%mod)*jcinv[i]%mod)%mod<<' ';
			}
		}
		else if(x==0)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==1) cout<<n<<' ';
				else
				cout<<0<<' ';
			}
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				if(i==1) 
				{
					cout<<n<<' ';
				}
				else if(i<x)
				{
					cout<<((n-x)*jc[x+1]%mod*jcinv[i]%mod*jcinv[x+1-i]%mod-(n-x-1)*jc[x]*jcinv[i]%mod*jcinv[x-i]%mod+mod)%mod<<' ';
				}
				else if(i==x)
				{
					cout<<n-x+1<<' ';
				}
				else
				cout<<0<<' ';
			}
		}
		return 0;
	}
	return 0;
}



#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=998244353;
template <typename T>
T read()
{
    T sum = 0, fl = 1;
    int ch = getchar();
    for (; !isdigit(ch); ch = getchar())
    if (ch == '-') fl = -1;
    for (; isdigit(ch); ch = getchar()) sum = sum * 10 + ch - '0';
    return sum * fl;
}
ll a[250005],b[250005],c[250005];
ll qza[250005],qzb[250005],qzc[250005];
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	int n;
	n=read<int>();
	for(int i=1;i<=n;i++)
	{
		a[i]=read<ll>();
		qza[i]=(qza[i-1]+a[i])%mod;
		b[i]=read<ll>();
		qzb[i]=(qzb[i-1]+b[i])%mod;
		c[i]=read<ll>();
		qzc[i]=(qzc[i-1]+c[i])%mod;
	}
	int m;
	m=read<int>();
	if(n>10000 and m>10000)
	{
		return 0;
	}
	while(m--)
	{
		int opt,l,r;
		opt=read<int>();
		l=read<int>();
		r=read<int>();
		if(opt==1)
		{
			for(int i=l;i<=r;i++)
			{
				a[i]=a[i]+b[i];
				a[i]%=mod;
			}
			for(int i=l;i<=n;i++)
			{
				qza[i]=(qza[i-1]+a[i])%mod;
			} 
		}
		else if(opt==2)
		{
			for(int i=l;i<=r;i++)
			{
				b[i]=b[i]+c[i];
				b[i]%=mod;
			}
			for(int i=l;i<=n;i++)
			{
				qzb[i]=(qzb[i-1]+b[i])%mod;
			} 
		}
		else if(opt==3)
		{
			for(int i=l;i<=r;i++)
			{
				c[i]=c[i]+a[i];
				c[i]%=mod;
			}
			for(int i=l;i<=n;i++)
			{
				qzc[i]=(qzc[i-1]+c[i])%mod;
			} 
		}
		else if(opt==4)
		{
			int v;
			v=read<int>();
			for(int i=l;i<=r;i++)
			{
				a[i]=a[i]+v;
				a[i]%=mod;
			}
			for(int i=l;i<=n;i++)
			{
				qza[i]=(qza[i-1]+a[i])%mod;
			}
		}
		else if(opt==5)
		{
			int v;
			v=read<int>();
			for(int i=l;i<=r;i++)
			{
				b[i]=(b[i]*v)%mod;
			}
			for(int i=l;i<=n;i++)
			{
				qzb[i]=(qzb[i-1]+b[i])%mod;
			} 
		}
		else if(opt==6)
		{
			int v;
			v=read<int>();
			for(int i=l;i<=r;i++)
			{
				c[i]=v;
			}
			for(int i=l;i<=n;i++)
			{
				qzc[i]=(qzc[i-1]+c[i])%mod;
			} 
		}
		else if(opt==7)
		{
			printf("%lld %lld %lld\n",(qza[r]-qza[l-1]+mod)%mod,(qzb[r]-qzb[l-1]+mod)%mod,(qzc[r]-qzc[l-1]+mod)%mod); 
		}
	}
	return 0;
 } 

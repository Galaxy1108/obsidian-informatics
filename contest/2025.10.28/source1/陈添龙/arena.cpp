#include<bits/stdc++.h>
#define pc(x) putchar(x)
#define int long long
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){f=ch=='-'?-1:f;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}
void write(int x)
{
	if(x<0){x=-x;pc('-');}
	if(x>9)write(x/10);
	pc(x%10+48);
}
const int mod=998244353;
int n,k,ans;
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;y>>=1;
	}return res;
}
signed main()
{
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),k=read();
	if(k<=n-1)
	{
		write(qpow(k,n));
		return 0;
	}puts("114514");
	return 0;
}


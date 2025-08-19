#include<bits/stdc++.h>
using namespace std;
const int N=1000000+5;
#define int long long 

int n;
int x[N],p[N],c[N];
inline int read()
{
	char ch=getchar();int x=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=(x<<1)+(x<<3)+(ch^'0');
		ch=getchar();
	}
	return x*f;
}
int cnt=n;
int f[N];
inline int X(int i)
{
	return abs(x[cnt]-x[i] );
}
signed main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	ios::sync_with_stdio(false);
	n=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read();p[i]=read();c[i]=read();
	}

	for(int i=n;i>=1;i--)
	{
		if(X(i)*p[i]+f[i+1]>=f[i+1]+c[i])
		{
			cnt=i;
			f[i]=f[i+1]+c[i];
		}
		else
			f[i]=X(i)*p[i]+f[i+1];
	}
	cout<<f[1]<<endl;
	return 0;
}

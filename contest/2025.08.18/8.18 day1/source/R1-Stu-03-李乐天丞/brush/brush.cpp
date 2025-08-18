#include <bits/stdc++.h>
using namespace std;
int f[10010][110];
int m[10010],w[10010];
int n,t;
inline int Qread()
{
	int sum=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') sum=(sum<<3)+(sum<<1)+(c^48),c=getchar();
	return sum;
}
int main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	n=Qread(),t=Qread();
	memset(m,0x3f,sizeof(m));
	for(int i=1;i<=n;i++) w[i]=Qread();
	for(int i=2;i<=t;i++) for(int j=1;i-j>=1;j++) f[i][j]=w[i]+w[i-j],m[i]=min(f[i][j],m[i]);
	for(int i=t+1;i<=n;i++)
	{
		for(int j=1;j<t;j++)
		{
			f[i][j]=m[i-j]+w[i];
			m[i]=min(m[i],f[i][j]);
		}
	}
	int ans=2e9;
	for(int i=n-t+2;i<=n;i++)
	for(int j=1;j<t;j++)
	{
		ans=min(ans,f[i][j]);
	}
	cout<<ans;
	return 0;
}

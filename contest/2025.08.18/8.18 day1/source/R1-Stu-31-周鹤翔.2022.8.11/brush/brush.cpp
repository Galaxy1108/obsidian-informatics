#include<bits/stdc++.h>
#define MAXN 10000
#define int long long
#define INF 9223372036854000000
using namespace std;
inline int read()
{
	int s=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';s=(s<<3)+(s<<1)+(ch^48),ch=getchar());
	return (f==1)?s:-s;
}
int n,m,a[MAXN+100],dp[MAXN+100];
signed main()
{
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	n=read(),m=read();
	if(n<m)
	{
		cout<<"0"<<endl;
		return 0;
	}
	if(m==2)
	{
		int sum=0;
		for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
		cout<<sum<<endl;
		return 0;
	}
	if(m==3)
	{
		int sum=0;
		for(int i=1;i<=n;i++)a[i]=read(),sum+=a[i];
		for(int i=1;i<=m;i++)dp[i]=a[i];
		for(int i=m+1;i<=n;i++)
		{
			for(int j=i-m;j>=1;j--)
			{
				dp[i]=max(dp[i],dp[j]+a[i]);
			}
			dp[i]=max(dp[i],dp[i-1]);
		}
		cout<<sum-dp[n]<<endl;
    }
	return 0;
}

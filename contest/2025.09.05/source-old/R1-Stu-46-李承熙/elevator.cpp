#include<bits/stdc++.h>
using namespace std;
inline int qread()
{
	register int a=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){a=(a<<1)+(a<<3)+(ch^48);ch=getchar();}
	return a*f;
}
int n,a[2010],b[2010],dp[2010][10],ans;
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	n=qread();
	for(register int i=1;i<=n;++i)
	{
		a[i]=qread();
		b[i]=qread();
		ans+=abs(a[i]-b[i])+1;
	}
	ans+=a[1];
	ans+=n-1;
	cout<<ans;
	return 0;
}

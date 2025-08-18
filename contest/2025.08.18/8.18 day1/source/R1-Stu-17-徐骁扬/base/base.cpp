#include <bits/stdc++.h>
using namespace std;
int Qread()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int n,i,j;
int v[2][2010];
long long pre[2010],aft[2010],ans,sd;
int main()
{
	freopen("base.in","r",stdin);
	freopen("base.out","w",stdout);
	n=Qread();
	for(i=1;i<=n;i++)
		v[0][i]=Qread();
	for(i=1;i<=n;i++)
		v[1][i]=Qread();
	for(i=1;i<=n;i++)
		pre[i]=((pre[i-1]>0)?pre[i-1]:0)+v[0][i]+v[1][i];
	for(i=n;i>=1;i--)
		aft[i]=((aft[i+1]>0)?aft[i+1]:0)+v[0][i]+v[1][i];
	sd=ans=-1e10;
	for(i=2;i<n;i++)
	{
		sd=max(sd,pre[i-1])+v[1][i];
		ans=max(ans,sd+aft[i+1]);
	}
	cout<<ans<<endl;
	return 0;
}

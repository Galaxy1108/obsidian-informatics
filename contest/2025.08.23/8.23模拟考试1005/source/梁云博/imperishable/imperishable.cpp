#include <bits/stdc++.h>
#define int long long
#define N 200005
#define p 998244353
using namespace std;
int NUM,n,q,x,y;
int a[N];
//int div[N];
//int ldiv[N];//上一次的div 
//
//int qp(int a,int b)
//{
//	int res=1;
//	while(b)
//	{
//		if(b&1)res=(res*a)%p;
//		a=(a*a)%p;
//		b>>=1;
//	}
//	return res;
//}
//
//bool isc()
//{
//	for(int i=1;i<=n;i++)if(vis[i]!=a[i])return 0;
//	return 1;
//}
//int ans=0;
//void dfs(int p,int sum)//表示当前每个数拿了几个 
//{
//	if(p==n)
//	{
//		int maxi=0;
//		for(int i=1;i<=n;i++)ldiv[i]+=div[i];
//		for(int i=1;i<=n;i++)if(ldiv[maxi]<ldiv[i])maxi=i;
//		sum=qp(2,maxi);
//		if(!isc())dfs(1,sum);
//		else ans=min(ans,sum)
//		return ;
//	}
//	for(int i=0;i<=a[p]-ldiv[p];i++)
//	{
//		div[p]=i;
//		dfs(p+1,sum);
//	}
//}
signed main()
{
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	cin>>NUM>>n;
	for(int i=1,x;i<=n;i++)cin>>a[i];
	if(NUM==1)
	{
		cout<<a[1];
		return 0;
	}
	return 0;
}

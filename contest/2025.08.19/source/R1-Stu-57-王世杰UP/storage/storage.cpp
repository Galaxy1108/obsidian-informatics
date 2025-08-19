#include<bits/stdc++.h>
using namespace std;
const long long ak=1000000000000;
int n;
int x[10002],p[10002],c[10002];
long long f[10002];
long long ycl1[10002];
long long ycl2[10002];
int main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>p[i]>>c[i];
	for(int i=1;i<=n;i++) f[i]=ak;
	ycl1[1]=0;ycl2[1]=p[1];
	for(int i=2;i<=n;i++)
	{
		ycl1[i]=ycl1[i-1]+ycl2[i-1]*(x[i]-x[i-1]);
		ycl2[i]=ycl2[i-1]+p[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=3005&&i-j>=0;j++)
		{
			f[i]=min(f[i],f[i-j]+(ycl1[i]-ycl1[i-j]-ycl2[i-j]*(x[i]-x[i-j]))+c[i]);
		}
	}
	cout<<f[n];
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long f[1000005];
long long x[1000005],p[1000005],c[1000005];
/*hack
3
0 10000 1000000
1 1 2
2 1 1*/
int main()
{
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>p[i]>>c[i];
	}
	int t=n;
	f[n]=c[n];
	for(int i=n-1;i>=1;i--)
	{
//		f[i][1]=min(f[i+1][0],f[i+1][1])+c[i];
//		f[i][0]=min(f[i+1][0],f[i+1][1])+
		if((x[t]-x[i])*p[i]>=c[i])
		{
			f[i]=c[i]+f[i+1];
			t=i;
		}
		else
		{
			f[i]=(x[t]-x[i])*p[i]+f[i+1];
		}
		f[i]=min(c[i],(x[t]-x[i])*p[i])+f[i+1];
		//cout<<f[i];
	}
	cout<<f[1];
	return 0;
} 

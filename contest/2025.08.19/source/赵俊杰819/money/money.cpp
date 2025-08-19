#include<bits/stdc++.h>
using namespace std;
const int N=2005;
double f[N][2];
long double w[N],c[N],d[N],s[N];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int n;
	double t;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>c[i]>>d[i];
		s[i]=s[i-1]+w[i]*c[i];w[i]+=w[i-1];
		f[i][0]=f[i-1][0]+w[i]-w[i-1];
		f[i][1]=f[i-1][1]+s[i]-s[i-1];
		for(int j=1;j<i;j++)
		{
			f[i][0]=max(f[i][0],(double)(f[j][1]*d[i]-t+w[i]-w[j]));
			f[i][1]=max(f[i][1],(double)(f[j][0]*c[i]+s[i]-s[j]));
		}
		f[i][0]=max(f[i][0],(double)(f[i][1]*d[i]-t));
		f[i][1]=max(f[i][1],(double)(f[i][0]*c[i]));
	}
	printf("%.4lf",f[n][0]);
	return 0;
}
/*
3 1
10 0.1 9
10 0.01 20
10 0.1 9 
*/

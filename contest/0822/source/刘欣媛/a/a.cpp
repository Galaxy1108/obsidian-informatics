#include <bits/stdc++.h>
using namespace std;
long long n,m,p,ans;
//vector<long long> v[100005];
long long a[30005][2000];
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>p;
	if(n==1)
	{
		long long o=m*(m+1);
		o/=2;
		o%=p;
		cout<<o;
		return 0;
	}
	if(m==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		long long o=i*(i+1);
		o/=2;
		o%=p;
		a[1][i]=o;
	}
	for(int i=2;i<=n;i++)
	{
		a[i][1]=1;
		for(int j=2;j<=m;j++)
		{
			//cout<<i<<" "<<j<<"\n";
			a[i][j]=(a[i-1][j]+a[i][j-1])*2; 
			if(i==j) a[i][j]--;
			if(i>j) a[i][j]++;
			a[i][j]%=p;
			//a[i][j]--;
		}
	}
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	cout<<a[n][m]<<"\n";
	
	return 0;
} 

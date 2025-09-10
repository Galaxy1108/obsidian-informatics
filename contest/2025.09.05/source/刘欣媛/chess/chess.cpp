#include <bits/stdc++.h>
using namespace std;
int n,m;
long long f[105][10];
const int p=9999973;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n>m) swap(n,m);
	if(n==1)
	{
		int l=max(m,n);
		cout<<1+l+(l*(l-1))/2;
		return 0;
	}
	if(n==2)
	{
		cout<<((1+m+(m*(m-1))/2)*(1+m+(m*(m-1))/2))%p;
		return 0;
	}
	
	f[1][0]=1,f[1][1]=m,f[1][2]=(m*(m-1))/2;
	long long ans=1;
//	for(int i=2;i<=n;i++)
//	{
//		f[i][0]=f[i-1][0]+f[i-1][1]+f[i-1][2];
//		f[i][1]=//f[i-1][0]+
//		for(int j=0;j<=2;j++)
//		{
//			
//		}
//	}
	
	return 0;
} 

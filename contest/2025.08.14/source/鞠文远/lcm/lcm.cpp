#include<bits/stdc++.h>
#define int long long
using namespace std;
int gcd(int a,int b){return a%b==0?b:gcd(b,a%b);}
int lcm(int a,int b){return a/gcd(a,b)*b;}
int T,dp[105];
signed main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	cin>>T;
	while(T--)
	{
		int n,p;
		cin>>n>>p;
		dp[1]=1;
		for(int i=2;i<=n;i++)dp[i]=(2*dp[i-1]+dp[i-2])%p;
		int g=1,anslt=0;
		for(int i=1;i<=n;i++)
		{
			g=lcm(g,dp[i])%p;
			anslt=(anslt+g*i%p)%p;
		}
		cout<<anslt<<endl;
	}
	
	return 0;
}

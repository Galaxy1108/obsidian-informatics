#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,mod=998244353;
int n,k;
int gcd(int i,int j){return i%j==0?j:gcd(j,i%j);}
int lcm(int i,int j){return i*j/gcd(i,j);}
signed main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		if(k==1)
		{
			int ans=1;
			for(int a1=1;a1<=n;a1++)
				ans=(a1*ans)%mod;
			cout<<ans<<endl;
		}
		else if(k==2)
		{
			int ans=1;
			for(int a1=1;a1<=n;a1++)
				for(int a2=1;a2<=n;a2++)
					ans=(lcm(a1,a2)%mod*ans)%mod;
			cout<<ans<<endl;
		}
		else if(k==3)
		{
			int ans=1;
			for(int a1=1;a1<=n;a1++)
				for(int a2=1;a2<=n;a2++)
					for(int a3=1;a3<=n;a3++)
						ans=(lcm(a1,lcm(a2,a3))%mod*ans)%mod;
			cout<<ans<<endl;
		}
		else if(k==4)
		{
			int ans=1;
			for(int a1=1;a1<=n;a1++)
				for(int a2=1;a2<=n;a2++)
					for(int a3=1;a3<=n;a3++)
						for(int a4=1;a4<=n;a4++)
							ans=(lcm(lcm(a1,a2),lcm(a3,a4))%mod*ans)%mod;
			cout<<ans<<endl;
		}
		else if(k==5)
		{
			int ans=1;
			for(int a1=1;a1<=n;a1++)
				for(int a2=1;a2<=n;a2++)
					for(int a3=1;a3<=n;a3++)
						for(int a4=1;a4<=n;a4++)
							for(int a5=1;a5<=n;a5++)
								ans=(lcm(lcm(a1,lcm(a2,a3)),lcm(a4,a5))%mod*ans)%mod;
			cout<<ans<<endl;					
		}
	}
	
	return 0;
} 

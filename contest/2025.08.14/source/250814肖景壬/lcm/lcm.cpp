/*


 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,p,x,y,z,ans,ans2,f[200005],mu[200005],pr[200005],cc[200005],prcnt;
signed sol()
{
	x=1;
	y=1;
	cin>>n>>p;
	ans=1;
	ans2=1;
	//cout<<1<<endl;
	f[1]=1;
	for(int i = 2; i <= n; i++)
	{
		f[i]=2*f[i-1]+f[i-2];
		//cout<<f[i]<<endl;
		ans2=(ans2*f[i])/__gcd(ans2,f[i]);
		ans+=ans2*i;
		ans%=p;
	}
	cout<<ans<<endl;
 } 
signed main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	int t;
	cin>>t;
	while(t--) sol();
} 

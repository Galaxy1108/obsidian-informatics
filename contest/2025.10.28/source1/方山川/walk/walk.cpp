#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,a[N],f[N][3],sum,ans;
inline int read()
{
	int x;cin>>x;
	return x;
}
signed main()
{
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n;
	for(int i=1,s=0;i<=n;i++)
	{
		sum+=(a[i]=read());
		f[i][2]=f[i][0]=sum+(a[i]&1);
		f[i][1]=sum+(~a[i]&1);
	}
	ans=sum;
	for(int i=1;i<=n;i++)
	{
		sum-=a[i];
		f[i][0]=min(f[i][0],f[i-1][0]+(a[i]&1));
		f[i][1]=min(f[i][1],f[i-1][0]+(~a[i]&1));
		f[i][1]=min(f[i][1],f[i-1][1]+(~a[i]&1));
		f[i][2]=min(f[i][2],f[i-1][1]+(a[i]&1));
		f[i][2]=min(f[i][2],f[i-1][2]+(a[i]&1));
		ans=min(ans,min(f[i][0],min(f[i][1],f[i][2]))+sum);
	}
	
	cout<<ans<<'\n';
	return 0;
} 

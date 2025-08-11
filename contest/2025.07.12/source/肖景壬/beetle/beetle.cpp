#include<bits/stdc++.h>
using namespace std;
int n,q,a[1500005],f[1500005],ans=-1;
long long fans=0,nw=1,XaoWa118=1000000007;
int main()
{
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	cin>>n>>q;
	for(int i = 1; i <= n; i++)
	{
		cin>>a[i];
	}
	f[1]=a[1];
	for(int i = 2; i <= n; i++)
	{
		f[i]=1000000000;
		ans=a[i];
		for(int j = i-1; j >= i-q; j--)
		{
			ans=max(ans,a[j]);
			f[i]=min(f[j]+ans,f[i]);
		}
	}
	/*for(int i = 1; i <= n; i++)
	{
		cout<<f[i]<<" ";
	}*/
	for(int i = n; i >= 1; i--)
	{
		fans+=(1ll*f[i]*nw);
		fans%=XaoWa118;
		nw*=23;
		nw%=XaoWa118;
	}
	cout<<fans<<endl;
}

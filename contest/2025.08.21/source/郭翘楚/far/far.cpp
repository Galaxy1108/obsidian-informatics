#include <bits/stdc++.h>
using namespace std;
int l[45],r[45];
int ans=0;
int main()
{
	freopen("far.in","r",stdin);
	freopen("far.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i]>>r[i];
	}
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		if(r[i]!=l[i])
		{
			ans*=(r[i]-l[i]);
		}
		cout<<ans<<endl;
		ans%=998244353;
	}
	return 0;
}

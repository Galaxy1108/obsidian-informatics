#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int a[N];
int main()
{
	freopen("ex_xor2.in","r",stdin);
	//freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=0,mx=0;
		for(int j=i;j<=n;j++)
		{
			x^=a[j];
			mx=max(mx,a[j]);
			if(x<=mx)ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
#define il inline
int n,a[N],q;
il void solve()
{
	cin>>n;
	int flag=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>q;int l,r;
	while(q--)
	{
		cin>>l>>r;
		cout<<a[l+1]-a[l]<<' '<<a[l]<<' '<<1<<'\n';
	}
}
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	int T;cin>>T;
	while(T--)solve();
	return 0;
}

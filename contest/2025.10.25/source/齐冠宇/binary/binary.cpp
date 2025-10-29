#include <bits/stdc++.h>
#define pb emplace_back
using namespace std;
constexpr int N=1e5+5;
typedef long long ll;
int n,a[N],q;
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	// for(int i=0;i<=1000;i+=3)
	// {
	// 	int j=i;
	// 	vector<int>d;
	// 	while(j)
	// 		d.pb(j%2),j/=2;
	// 	reverse(d.begin(),d.end());
	// 	for(auto x:d)cout<<x;
	// 	cout<<'\n';
	// }
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>q;
	while(q--)
	{
		int opt,l,r,x;
		cin>>opt;
		if(opt==1)
			cin>>x,a[x]^=1;
		else
		{
			cin>>l>>r;
			ll ans=0;
			for(int i=l;i<=r;i++)
				for(int j=i;j<=r;j++)
				{
					int cnt=0;
					for(int k=i;k<=j;k++)cnt+=a[k];
					if(cnt%2==0 || (cnt>=3 && j-i+1>=cnt+2))ans++;
				}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int s,k;
		cin>>s>>k;
		if(s%2==1)
		{
			if(s>=k*2)cout<<k*2<<"\n";
			else cout<<"-1\n";
			continue;
		}
		
	}
	return 0;
}

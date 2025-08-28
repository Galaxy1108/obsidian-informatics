#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N=5005;
int n,q;
int a[N];
signed main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	while(q--)
	{
		int opt,v,l,r;
		cin>>opt;
		if(opt==1)
		{
			cin>>v;
			for(int i=1;i<=n;i++)
				a[i]=min(a[i],v);
		}
		else if(opt==2)
			for(int i=1;i<=n;i++)
				a[i]+=i;
		else
		{
			cin>>l>>r;
			int res=0;
			for(int i=l;i<=r;i++)
				res+=a[i];
			cout<<res<<'\n';
		}
	}
	return 0;
}

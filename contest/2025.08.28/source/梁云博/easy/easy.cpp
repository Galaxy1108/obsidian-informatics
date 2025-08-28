#include <bits/stdc++.h>
#define N 200005
#define int long long
using namespace std;
int a[N];
signed main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ty,v,l,r;
	while(q--)
	{
		cin>>ty;
		if(ty==1)
		{
			cin>>v;
			for(int i=1;i<=n;i++)a[i]=min(a[i],v);
		}
		else if(ty==2)
		{
			for(int i=1;i<=n;i++)a[i]+=i;
		}
		else 
		{
			cin>>l>>r;
			int sum=0;
			for(int i=l;i<=r;i++)sum+=a[i];
			cout<<sum<<"\n";
		}
	}
	return 0;
} 

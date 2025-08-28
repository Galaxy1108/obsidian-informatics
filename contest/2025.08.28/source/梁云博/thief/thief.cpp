#include <bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
int a[N];
signed main()
{
	freopen("thief.in","r",stdin);
	freopen("thief.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l,r,c;
	
	while(m--)
	{
		cin>>l>>r>>c;
		for(int i=l;i<=r;i++)
		{
			if(c<a[i])c++;
			if(c>a[i]) c--;
		}
		cout<<c<<"\n";
	}
	
	return 0;
} 
//为什么T2我想到了扫描线（
 

#include<bits/stdc++.h> 
using namespace std;

int T,n,a[2010];

void solve()
{
	sort(a+1,a+n+1);
	if(a[n]-a[1]>=a[2]) cout<<1<<endl;
	else cout<<3<<endl;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	solve();
	for(int i=2;i<=T;i++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			int x,y;
			cin>>x>>y;
			a[x]=y;
		}
		solve();
	}
	return 0;
}

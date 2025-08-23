#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int Num;
int n;
void solve()
{
	if(Num==1)
	{
		cout<<2<<endl;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i]<=0)
		{
			continue;
		}
		ans+=pow(2,i);
		for(int j=i+1;j<=n;j++)
		{
			b[j]-=b[i];
		}
	}
	cout<<ans<<endl;
	return ;
}
int main()
{
	freopen("imperishable.in","r",stdin);
	freopen("imperishable.out","w",stdout);
	cin>>Num;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	solve();
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		a[x]=y;
		solve();
	}
	return 0;
}

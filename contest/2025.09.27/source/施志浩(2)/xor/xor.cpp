#include<bits/stdc++.h>
using namespace std;
int n,a[100001],x[100001],i,mx=0,cnt;
int main()
{
	ios::sync_with_stdio(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	cnt=n;
	cout<<cnt+1;
	return 0;
}

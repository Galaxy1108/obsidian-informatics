#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],c[N],n,t[N];
int main()
{
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]*=2;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i%n+1]>=a[i]/2)c[i]=i%n+1;
		else c[i]=i;
	}
	for(int i=1;i<=n;i++)cout<<c[i]<<' ';
	cout<<'\n';
	return 0;
}

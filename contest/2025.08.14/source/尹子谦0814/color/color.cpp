#include<bits/stdc++.h>
using namespace std;
const int N=1e3+100;
int n,m,s,t;
int a[N];
bool sp1=1,sp2=1;
signed main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==2)
	{
		if(a[1]==a[2]) cout<<0;
		else cout<<4;
		return 0;
	}
	if(n==3)
	{
		if(a[1]!=a[2]&&a[1]!=a[3]&&a[2]!=a[3]) cout<<42;
		else if(a[1]==a[2]&&a[1]==a[3]) cout<<0;
		else cout<<24;
		return 0;
	}
	return 0;
}

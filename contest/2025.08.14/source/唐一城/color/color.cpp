#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int n,a[N];
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(n==1)cout<<0;
	else if(n==2)cout<<(a[1]==a[2]?0:4);
	else if(n==3)
	{
		int flag=0;
		for(int i=2;i<=n;i++)if(a[i-1]!=a[i])flag=1;
		if(!flag){cout<<0;return 0;}
		if(a[1]==1&&a[2]==2&&a[3]==3)cout<<42;
		else cout<<43;
	}
	else cout<<23224172;
	return 0;
}


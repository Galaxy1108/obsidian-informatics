#include <bits/stdc++.h>
#define N 5005
#define p 1000000007
#define int long long
using namespace std;
int n;
signed main()
{
	freopen("divisors.in","r",stdin);
	freopen("divisors.out","w",stdout);
	cin>>n;
	if(n<=10)
	{
		cout<<2520<<" ";
		for(int i=2;i<=n;i++)cout<<i<<" ";
		cout<<"\n";
		for(int i=2;i<=n;i++)cout<<1<<" "<<i<<"\n";
	}
	return 0;
}

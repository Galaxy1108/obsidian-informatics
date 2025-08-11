#include <bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
ll s,k;
il void solve()
{
	cin>>s>>k;
	if(s%2==1)
	{
		if(2*k>s)cout<<-1<<'\n';
		else cout<<2*k<<'\n'; 
	}
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}
/*
3 1
3 2
7 1
7 2
7 3
7 4
*/

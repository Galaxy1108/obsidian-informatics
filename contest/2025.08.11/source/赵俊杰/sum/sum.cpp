#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		long long s,k;
		cin>>s>>k;
		if(s&1)
		{
			if(2*k>s)cout<<"-1\n";
			else cout<<2*k<<'\n';
		}
		else cout<<"-1\n";
	}
	return 0;
}

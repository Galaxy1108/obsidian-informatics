#include <bits/stdc++.h>
using namespace std;
long long szh(long long sum)
{
	long long a=sum;
	long long k=0;
	while(a!=0)
	{
		k+=a%10;
		a/=10;
	}
	return k;
}
vector <long long> ans;
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=max(n-10000,1ll*0);i<=n;i++)
	{
		if(i+szh(i)==n)
		{
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<endl;
	for(auto i : ans)
	{
		cout<<i<<endl;
	}
	return 0;
}
/*



*/

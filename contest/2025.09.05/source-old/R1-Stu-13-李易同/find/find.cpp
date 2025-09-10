#include <iostream>
#include <algorithm>
using namespace std;
const int mod=1000000007;
int n;
int k;
int mp[1000010];
int ans;
int Hash(int x,int y)
{
	if(x==0 || y==0) return 0;
	return (y-1)*n+x;
}
int f(int x)
{
	int res=1;
	while(x)
	{
		res*=x%10;
		x/=10;
	}
	return res;
}
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			++mp[Hash(f(i),f(j))];
	sort(mp+1,mp+n*n+1,greater<int>());
	for(int i=1;i<=k;++i)
	{
		ans+=mp[i];
		if(ans>=mod) ans-=mod;
	}
	cout<<ans;
	return 0;
}

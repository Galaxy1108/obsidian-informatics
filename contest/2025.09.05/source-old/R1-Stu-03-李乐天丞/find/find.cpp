#include <bits/stdc++.h>
using namespace std;
long long a[1100][1100],n,k;
long long c[1100];
inline int f(int x)
{
	int ans=1;
	while(x>0)
	{
		ans*=(x%10);
		x=x/10;
	}
	return ans;
}
int main()
{
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		a[f(i)][f(j)]++;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		c[a[i][j]]++;
	}
	int num=1000,ans=0;
	while(k>c[num]&&num>0)
	{
		k-=c[num];
		ans+=c[num]*num;
		num--;
	}
	if(num>0) ans+=k*num;
	cout<<ans;
	return 0;
}

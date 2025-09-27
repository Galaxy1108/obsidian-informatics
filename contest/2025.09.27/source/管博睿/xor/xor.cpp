#include <iostream>
#include <cmath>
using namespace std;
int n,a[100005],s,maxn,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		maxn=a[i];
		s=0;
		for(int j=i;j<=n;j++)
		{
			maxn=max(maxn,a[j]);
			s^=a[j];
			if(s<=maxn)
			{
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}

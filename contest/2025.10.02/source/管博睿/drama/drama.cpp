#include <iostream>
using namespace std;
int n,a[2000005],maxn,minn,ans;
int main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		maxn=0;
		minn=2147483647;
		for(int j=i;j<=n;j++)
		{
			maxn=max(maxn,a[j]);
			minn=min(minn,a[j]);
			ans=max(ans,maxn*minn*(j-i+1));
		}
	}
	cout << ans;
	return 0;
}

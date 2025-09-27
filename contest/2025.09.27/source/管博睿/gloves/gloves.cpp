#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,l[100005],r[100005],mini,minn=2147483647,ans;
int main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> l[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin >> r[i];
	}
	sort(l+1,l+n+1);
	sort(r+1,r+m+1);
	if(n>m)
	{
		swap(n,m);
		swap(l,r);
	}
	for(int i=1;i<=m-n+1;i++)
	{
		if(abs(r[i]-l[1])<minn)
		{
			minn=abs(r[i]-l[1]);
			mini=i;
		}
	}
	for(int i=mini,j=1;i<=mini+n-1;i++,j++)
	{
		ans=max(ans,abs(r[i]-l[j]));
	}
	cout << ans;
	return 0;
}


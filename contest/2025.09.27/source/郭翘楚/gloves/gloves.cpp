#include <bits/stdc++.h>
using namespace std;
int l[100005],r[100005];
int n,m;
bool check(int x)
{
	int i=1,j=1,cnt=0;
	while(i<=n and j<=m)
	{
		if(abs(l[i]-r[j])<=x)
		{
			cnt++;
			i++;
			j++;
		}
		else if(l[i]<r[j])
		{
			i++; 
		}
		else
		{
			j++;
		}
	}
	return cnt>=min(n,m);
}
signed main() 
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>r[i];
	}
	sort(l+1,l+n+1);
	sort(r+1,r+m+1);
	int ll=0,rr=1e9+7;
	while(ll<rr)
	{
		int mid=(ll+rr)/2;
		if(check(mid)) rr=mid;
		else ll=mid+1;
	}
	cout<<ll;
	return 0;
}

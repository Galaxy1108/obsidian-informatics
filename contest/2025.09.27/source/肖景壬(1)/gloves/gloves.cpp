#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[100005],b[100005];
bool check(int pp)
{
	int npos=0;
	bool flg=1;
	for(int i = 1; i <= n; i++)
	{
		npos++;
		while(npos<=m&&abs(a[i]-b[npos])>pp) npos++;
		if(npos>m)
		{
			flg=0;
			break;
		}
	}
	return flg;
}
signed main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout); 
	cin>>n>>m;
	if(n>m)
	{
		for(int i = 1; i <= n; i++)
		{
			cin>>b[i];
		}
		for(int i = 1; i <= m; i++)
		{
			cin>>a[i];
		}
		swap(n,m);
	}
	else
	{
		for(int i = 1; i <= n; i++)
		{
			cin>>a[i];
		}
		for(int i = 1; i <= m; i++)
		{
			cin>>b[i];
		}
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	//b[0]=-1e10;
	//b[m+1]=1e10;
	int l=0,r=2e9,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))
		{
			r=mid-1;
			ans=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
 } 

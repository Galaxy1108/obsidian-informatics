#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int l[100010],r[100010];
bool check(int ans)
{
	int le=1,ri=1;
	while(ri<=m&&le<=n)
	{
		if(abs(l[le]-r[ri])<=ans)
		{
			le++;
			ri++;
		}
		else
		{
			le++;
		}
	}
	if(ri-1!=m)
	{
		return false;
	}
	else
	{
		return true;
	}
}
signed main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
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
	if(n==m)
	{
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,abs(l[i]-r[i]));
		}
		cout<<maxn<<endl;
		return 0;
	}
	if(n<m)
	{
		for(int i=1;i<=n;i++)
		{
			swap(l[i],r[i]);
		}
		for(int i=n+1;i<=m;i++)
		{
			l[i]=r[i];
			r[i]=0;
		}
		swap(n,m);
	}
	int le=-1,ri=1e9+1;
	int mid;
	while(le+1!=ri&&le<ri)
	{
		int mid=(le+ri)/2;
		if(check(mid))
		{
			ri=mid;
		}
		else
		{
			le=mid;
		}
	}
	cout<<ri<<endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
int l[100005],r[100005],minn=LLONG_MAX;
bool ha[100005];
void dfs(int k,int da,int xa,int maxn)
{
	if (k > xa)
	{
		minn=min(minn,maxn);
		return;
	}
	
	if (maxn >= minn or minn == 0)
	{
		return;
	}
	for (int i = 1;i <= da;i++)
	{
		if (minn == 0)
		{
			break;
		}
		if (ha[i] == 0)
		{
			ha[i]=1;
			dfs(k+1,da,xa,max(maxn,abs(r[k]-l[i])));
			ha[i]=0;
		}
	}
	return;
}
void dfs2(int k,int da,int xa,int maxn)
{
	if (k > xa)
	{
		minn=min(minn,maxn);
		return;
	}
	if (maxn >= minn or minn == 0)
	{
		return;
	}
	for (int i = 1;i <= da;i++)
	{
		if (minn == 0)
		{
			break; 
		}
		if (ha[i] == 0)
		{
			ha[i]=1;
			dfs(k+1,da,xa,max(maxn,abs(l[k]-r[i])));
			ha[i]=0;
		}
	}
	return;
}
signed main()
{
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	int n,m,maxn=-1;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> l[i];
	 }
	 for (int i = 1;i <= m;i++)
	 {
	 	cin >> r[i];
	 }
	 sort(l+1,l+1+n);
	 sort(r+1,r+1+m);
	 if (n == m)
	 {
	 	int ans=LLONG_MAX;
	 	for (int st=0;st <= n-m;st++)
	 	{
	 		maxn=-1;
		 	for (int i = 1+st;i <= m+st;i++)
		 	{
		 		
				 maxn=max(maxn,abs(l[i]-r[i-st]));
				 
			 }
			 ans=min(ans,maxn);
		}
	 	
		 cout << ans;
	 }
	 else
	 {
	 	if (n > m)
	 	{
	 		dfs(1,n,m,-1);
	 		cout << minn;
		 }
		 else
		 {
		 	dfs2(1,m,n,-1);
		 	cout << minn;
		 }
	 }
	 
	 
	return 0;
}

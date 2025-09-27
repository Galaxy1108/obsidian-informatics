#include <bits/stdc++.h>
using namespace std;
int a[50005],cnt[35],sum;
signed main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	int n,k,m,c,p,v,flag=2;
	int ans;
	cin >> n >> k >>m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= m;i++)
	{
		cin >> c;
		if (c == 1)
		{
			flag=1;
			cin >> p >> v;
			a[p]=v;
		}
		else
		{
			
			if (flag!=0)
			{
				for (int j = 1;j <= k;j++)
				{
					cnt[j]=0;
				}
				int l=1,r=1;
				cnt[a[l]]++;
				sum=1;
				ans=INT_MAX;
				while (l <= r and r <= n)
				{
					r++;
					if (cnt[a[r]] == 0)
					{
						sum++;
					}
					cnt[a[r]]++;
					while (sum == k)
					{
						ans=min(ans,r-l+1);
						if (ans == k)
						{
							break;
						}
						cnt[a[l]]--;
						if (cnt[a[l]] == 0)
						{
							sum--;
						}
						l++;
					}
					if (ans == k)
					{
						break;
					}
				}
				if (ans == INT_MAX)
				{
					ans=-1;
				}
				flag=0;
			}
			
			cout << ans << endl;
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
struct gui
{
	int zhi,maxn,minn,len;
};
int h[2000005],ans=-1;
gui dp[2000005];
signed main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> h[i];
	}
	int ans=-1,ansl=1,ansr=1;
	for (int i = 1;i <= n;i++)
	{
		int fans=h[i]*h[i];
		int maxn=h[i],minn=h[i],len;
		//int r=i,l=i;
		for (int j = i-1;j >= 1;j--)
		{
			len=(i-j+1);
		//	l--;
			maxn=max(maxn,h[j]);
			minn=min(minn,h[j]);
			if (maxn*minn*len >= fans)
			{
				fans=maxn*minn*len;
				
			}
			else
			{
			//	l++;
				break;
			}
		}
		/*if (ans < fans)
		{
			ansl=l;
			ansr=r;
			ans=fans;
		}*/
		ans = max(ans,fans);
	}
	cout << ans;
	
	return 0;
 } /*dp[1].zhi=h[1]*h[1];
	dp[1].maxn=h[1];
	dp[1].minn=h[1];
	dp[1].len=1;
	ans=dp[1].zhi;
	for (int i = 2;i <= n;i++)
	{
		dp[i].maxn=max(dp[i-1].maxn,h[i]);
		dp[i].minn=min(dp[i-1].minn,h[i]);
		if (h[i]*h[i] > dp[i].maxn*dp[i].minn*(dp[i-1].len+1))
		{
			dp[i].maxn=h[i];
			dp[i].minn=h[i];
			dp[i].len=1;
			dp[i].zhi=h[i]*h[i];
		}
		else
		{
			dp[i].len=dp[i-1].len+1;
			dp[i].zhi=dp[i].maxn*dp[i].minn*(dp[i-1].len+1);
		}
		ans=max(dp[i].zhi,ans);
		cout << dp[i].len << " ";
		if (h[i] > dp[i-1].maxn)
		{
			if (dp[i-1].minn*h[i]*(dp[i-1].len+1) > h[i]*h[i])
			{
				dp[i].maxn=h[i];
				dp[i].minn=dp[i-1].minn;
				dp[i].len=dp[i-1].len+1;
				dp[i].zhi = dp[i-1].minn*h[i]*(dp[i-1].len+1);
			}
			else
			{
				dp[i].maxn=h[i];
				dp[i].minn=h[i];
				dp[i].len=1;
				dp[i].zhi = h[i]*h[i];
			}
		}
		else if (h[i] < dp[i-1].minn)
		{
			if (dp[i-1].maxn*h[i]*(dp[i-1].len+1) > dp[i-1].zhi)
			{
				dp[i].maxn=dp[i-1].maxn;
				dp[i].minn=h[i];
				dp[i].len=dp[i-1].len+1;
				dp[i].zhi = dp[i-1].maxn*h[i]*(dp[i-1].len+1);
			}
			else
			{
				dp[i].maxn=dp[i-1].maxn;
				dp[i].minn=dp[i-1].minn;
				dp[i].len=dp[i-1].len;
				dp[i].zhi = dp[i-1].zhi;
			}
		}
		else
		{
			dp[i].maxn=dp[i-1].maxn;
			dp[i].minn=dp[i-1].minn;
			dp[i].len=dp[i-1].len+1;
			dp[i].zhi = dp[i-1].maxn*dp[i-1].minn*(dp[i-1].len+1);
		}
	}
	cout << ans;*/

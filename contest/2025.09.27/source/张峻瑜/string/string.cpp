#include <bits/stdc++.h>
using namespace std;

struct sou
{
	string s;
	int tot;
};
sou bfs[500005];
bool pan(string x)
{
	for (int i = 0;i < x.length()-1;i++)
	{
		if (x[i] == x[i+1])
		{
			return 0;
		}
	}
	return 1;
}
long long zhuan(string x)
{
	long long qu=1,sum=0;
	for (int i = x.length()-1;i >= 0;i--)
	{
		sum+=qu*(x[i]-'0');
		qu*=3;
	}
	return sum;
}
bool ha[50000005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin >> s;
	if (pan(s))
	{
		cout << 0;
		return 0;
	}
	if (s.length() <= 20)
	{
		int l=1,r=1,flag=0,ans=-1;
		bfs[1].s=s;
		bfs[1].tot=0;
		
		while (l <= r)
		{
			for (int i = 1;i < s.length();i++)
			{
					r++;
					string fz=bfs[l].s;
					swap(fz[i],fz[i-1]);
					bfs[r].s=fz;
					bfs[r].tot=bfs[l].tot+1;
					long long f=zhuan(fz);
					if (ha[f])
					{
						r--;
						continue;
					}
					ha[f]=1;
					if (pan(bfs[r].s))
					{
						ans=bfs[r].tot;
						flag=1;
						
						break;
					}
			}
			if (flag)
			{
				break;
			}
			l++;
		}
		cout << ans;
	}
	else
	{
		cout << -1;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct she
{
	int zhi,hao;
};
she a[3000005],cun[3000005];
bool pan[3000005];
signed main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T,n,k,x,y;
	cin >> T;
	for (int mm = 1;mm <= T;mm++)
	{
		she maxn,minn2,minn;
		
		if (mm == 1)
		{
			cin >> n;
			for (int i = 1;i <= n;i++)
			{
				cin >> a[i].zhi;
				a[i].hao=i;
				cun[i]=a[i];
			}
		}
		else
		{
			cin >> k;
			for (int i = 1;i <= n;i++)
			{
				a[i]=cun[i];
			}
			for (int i = 1;i <= k;i++)
			{
				cin >> x >> y;
				a[x].zhi=y;
			}
		}
		if (n == 3)
		{
			if (a[3].zhi-a[1].zhi < a[2].zhi)
			{
				cout << 3 << endl;
			}
			else
			{
				cout << 1 << endl;
			}
		}
		else
		{
			int flag=1,cnt=n;
			while (cnt > 1)
			{	
				maxn.zhi = -1;
				//maxn2.zhi = -1;
				minn.zhi = INT_MAX;
				minn2.zhi = INT_MAX;
				for (int i = 1;i <= n;i++)
				{
					if (pan[i] == 0)
					{
						if (a[i].zhi >= maxn.zhi)
						{
							
							maxn.zhi=a[i].zhi;
							maxn.hao = a[i].hao;
						}
						if (a[i].zhi < minn.zhi)
						{
							
							minn.zhi = a[i].zhi;
							minn.hao = a[i].hao;
						}
						
					}
				}
				for (int i = 1;i <= n;i++)
				{
					if (pan[i] == 0)
					{
						
						if (a[i].zhi > minn.zhi and a[i].zhi < minn2.zhi)
						{
							
							minn2.zhi = a[i].zhi;
							minn2.hao = a[i].hao;
						}
						
					}
				}
				if (maxn.zhi - minn.zhi < minn2.zhi or (maxn.zhi - minn.zhi == minn2.zhi and minn2.hao > maxn.hao))
				{
					break;
				}
				else
				{
					a[maxn.hao].zhi-=minn.zhi;
					pan[minn.hao]=1;
					cnt--;
				}
			//	cout << cnt;
			}
			cout << cnt << endl;
		}
		
	}
	return 0;
 }

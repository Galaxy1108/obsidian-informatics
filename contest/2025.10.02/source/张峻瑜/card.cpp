#include <bits/stdc++.h>
using namespace std;
int a[1000005];
bool pan[1000005];
struct cun
{
	int wei,zhi;
 };
 cun fz[1000005];
 struct node
 {
 	int zhi,hao;
 	bool friend operator<(node a,node b)
 	{
 		return a.zhi > b.zhi;
	}
 };
priority_queue <node> du;
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,q,p,b,c,x;
	int ji=0,ou=0;
	cin >> n >> m >> q;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
		a[i]%=2;
	}
	for (int i = 1;i <= m;i++)
	{
		cin >> p >> b;
		
		a[p]=b%2;
		pan[p]=1;
		
	}
	for (int i = 1;i <= q;i++)
	{
		int ans=0;
		cin >> c >> p;
		if (c == 1)
		{
			pan[p]=0;
			
		}
		else
		{
			cin >> x;
			pan[p]=1;
			a[p]=x%2;
		}
		ji=0,ou=0;
		int js=0;
		
		for (int i = 1;i <= n;i++)
		{
			if (pan[i] == 1)
			{
				js++;
				fz[js].zhi=a[i];
				fz[js].wei=i;
				continue;
			}
			if (a[i] == 0)
			{
				ou++;
			}
			else
			{
				ji++;
			}
		}
		if (js > 0)
		{
			fz[0].zhi=fz[1].zhi;
			fz[0].wei=0;
			fz[js+1].zhi=fz[js].zhi;
			fz[js+1].wei=n+1;
			for (int i = 0;i <= js;i++)
			{
				du.push({fz[i+1].wei-fz[i].wei-1,i});
			}
			while (!du.empty())
			{
				int i=du.top().hao;
				if (fz[i].zhi != fz[i+1].zhi)
				{
					ans++;
				}
				else
				{
					if (fz[i].zhi == 0)
					{
						if (ou >= fz[i+1].wei-fz[i].wei-1)
						{
							ou-=(fz[i+1].wei-fz[i].wei-1);
						}
						else
						{
							ji-=((fz[i+1].wei-fz[i].wei-1)-ou);
							ou=0;
							if (i==0 or i == js)
							{
								ans+=1;
							}
							else
							{
								ans+=2;
							}
						}
					}
					else
					{
						if (ji >= fz[i+1].wei-fz[i].wei-1)
						{
							ji-=(fz[i+1].wei-fz[i].wei-1);
						}
						else
						{
							ou-=((fz[i+1].wei-fz[i].wei-1)-ji);
							ji=0;
							if (i==0 or i == js)
							{
								ans+=1;
							}
							else
							{
								ans+=2;
							}
						}
					}
				}
				du.pop();
			}
			
		}
		else
		{
			if (ji == n or ou == n)
			{
				ans=0;
			}
			else
			{
				ans=1;
			}
		}
		
		cout << ans << endl;
	}
	return 0;
 }

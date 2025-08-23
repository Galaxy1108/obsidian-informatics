#include <bits/stdc++.h>
using namespace std;
vector<int> g[50005];//第i行会撞上，反弹到第j列
vector<int> l[50005];//第i列会撞上，反弹到第j行 
int main()
{
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	int type,n,m,k;
	cin>>type>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		l[y].push_back(x);
	}
	int Q;
	cin>>Q;
	while(Q--)
	{
		int w;
		cin>>w;
		if(w==1)
		{
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			l[y].push_back(x);
		}
		else
		{
			int x,y,q;
			cin>>x>>y>>q;
			int fx=0;//下1右2
			for(int j=1;j<=q;j++)
			{
				if(fx==0)
				{
					if(x==0)
					{
						int miny=0x3f3f3f3f;
						for(auto i:l[y])
						{
							miny=min(miny,i);
						}
						if(miny==0x3f3f3f3f)
						{
							x=n+1;
							break;
						}
						x=miny;
						fx=2;
					}
					else
					{
						int minx=0x3f3f3f3f;
						for(auto i:g[x])
						{
							minx=min(minx,i);
						}
						if(minx==0x3f3f3f3f)
						{
							y=m+1;
							break;
						}
						y=minx;
						fx=1;
					}
				}
				else
				{
					if(fx==1)
					{
						int miny=0x3f3f3f3f;
						for(auto i:l[y])
						{
							if(i>x)
							{
								miny=min(miny,i);
							}
						}
						if(miny==0x3f3f3f3f)
						{
							x=n+1;
							break;
						}
						x=miny;
						fx=2;
					}
					else
					{
						int miny=0x3f3f3f3f;
						for(auto i:g[x])
						{
							if(i>y)
							{
								miny=min(miny,i);
							}
						}
						if(miny==0x3f3f3f3f)
						{
							y=m+1;
							break;
						}
						y=miny;
						fx=1;
					}
				}
			}
			cout<<x<<" "<<y<<endl;
		}
	}
	return 0;
 } 

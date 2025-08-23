#include <bits/stdc++.h>
#define int long long
#define N 3005
using namespace std;
int ty,n,m,k,Q,w,q,x,y;
signed main()
{
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>ty>>n>>m>>k;
	if(ty==0)
	{
		int g[1005][1005]={0};
		for(int i=1;i<=k;i++)
		{
			cin>>x>>y;
			g[x][y]=1;
		}
		cin>>Q;
		while(Q--)
		{
			cin>>w>>x>>y;
			if(w==1)
			{
				g[x][y]=1;
			}
			else
			{
				cin>>q;
				int cnt=0,dir=(x==0)?1:0;//记向下为 1，向右为0 
				while(cnt<q && x<=n && y<=m)
				{
					if(dir)
					{
						while(g[x][y]!=1 && x<=n && y<=m)x++;
						cnt++;
						dir=0;
						if(cnt!=q && g[x][y]==1)y++;
					}
					else if(dir==0)
					{
						while(g[x][y]!=1 && x<=n && y<=m)y++;
						cnt++;
						dir=1;
						if(cnt!=q && g[x][y]==1)x++;
					}
					else break;
				}
				cout<<x<<" "<<y<<"\n";
			}
		}
	}
	return 0;
}

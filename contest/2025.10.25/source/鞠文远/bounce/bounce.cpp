#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,q,vis[25],dis[N],dt[N];
int main()
{
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	cin>>n>>q;
	while(q--)
	{
		int op,m;
		cin>>op>>m;
		if(op==1)
		{
			if(vis[m])continue;
			for(int i=1;i<=n;i+=m)dis[i]=true;
			vis[m]=true;
		}
		if(op==2)
		{
			int cnt=0;
			int be=0;
			for(int i=1;i<=n;i++)
				if(!dis[i])
				{
					be=i;
					dis[be]=true;
					break;
				}
			for(int i=be+1;i<=n;i++)
			{
				if(!dis[i])cnt++;
				if(cnt%m==0)dis[i]=true;
			}
		}
		if(op==3)
		{
			int lt=0;
			for(int i=1;i<=n;i++)if(!dis[i])lt++;
			for(int i=1;i<=n;i++)dt[i]=dis[i];
			while(lt>1)
			{
				int cnt=0;
				int be=0;
				for(int i=1;i<=n;i++)
					if(!dis[i])
					{
						be=i;
						dis[be]=true;
						lt--;
						break;
					}
				for(int i=be+1;i<=n;i++)
				{
					if(lt<=1)break;
					if(!dis[i])cnt++;
					if(!dis[i]&&cnt%m==0)dis[i]=true,lt--;
				}
				if(lt<=1)break;
				cnt=0;
				be=0;
				for(int i=n;i>=1;i--)
					if(!dis[i])
					{
						be=i;
						dis[be]=true;
						lt--;
						break;
					}
				for(int i=be-1;i>=1;i--)
				{
					if(lt<=1)break;
					if(!dis[i])cnt++;
					if(!dis[i]&&cnt%m==0)dis[i]=true,lt--;
				}
			}
			for(int i=1;i<=n;i++)
				if(!dis[i])
				{
					cout<<i<<"\n";
					break;
				}
			for(int i=1;i<=n;i++)dis[i]=dt[i];
		}
	}
	
	return 0;
}

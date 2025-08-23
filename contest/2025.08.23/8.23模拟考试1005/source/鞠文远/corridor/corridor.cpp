#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int ty,n,m,k,q;
bool mp[N][N];
int main()
{
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>ty>>n>>m>>k;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[x][y]=true;
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int w;
		cin>>w;
		if(w==1)
		{
			int x,y;
			cin>>x>>y;
			mp[x][y]=true;
		}
		else
		{
			int x,y,q;
			cin>>x>>y>>q;
			int dir;
			if(x==0)dir=1;
			if(y==0)dir=0;
			/*
			dir==0:向东 
			dir==1:向南 
			*/
			while(true)
			{
				if(dir==0)y++;
				if(dir==1)x++;
				if(x>n)break;
				if(y>m)break;
				if(mp[x][y])
				{
					q--;
					if(!q)break;
					dir^=1;
				}
			}
			cout<<x<<" "<<y<<"\n";
		}
	}
	
	return 0;
} 

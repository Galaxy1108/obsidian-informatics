#include<bits/stdc++.h>
using namespace std;
long long dis[200010];
int n,m;
int x,y,z;
int t;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(dis,0,sizeof(dis));
		cin>>n>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>x>>y>>z;
			dis[y]+=z;
		}
		long long ans=dis[1];
		long long b[200010],len=0; 
		for(int i=2;i<=n;i++)
		{
			b[++len]=dis[i];
		}
		sort(b+1,b+len+1,cmp);
		for(int i=1;i<=len;i++)
		{
			if(i%2==0)
			{
				ans+=b[i];
			}
		}
		cout<<ans<<endl;
	}
}
/*
1
4 5
1 2 1
1 3 4
3 4 3
1 3 2
4 4 3

2
5 8
1 1 3
1 2 4
2 2 3
1 2 5
1 3 2
1 4 5
1 5 9
1 3 4
5 8
1 1 3
1 2 4
2 2 3
1 2 5
1 3 2
1 4 5
1 5 9
1 3 4
*/

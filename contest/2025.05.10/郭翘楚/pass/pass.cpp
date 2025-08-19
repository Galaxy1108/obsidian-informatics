#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
#define db double
int n;
db cp,cs;
struct rou
{
	db x,y;
}r[145];
struct tong
{
	db x,y;
}t1[145];
il db dis(db x1,db y1,db x2,db y2)
{
	db r1=x2-x1,r2=y2-y1;
	return (db)sqrt(r1*r1+r2*r2);
}
db dist1[145][145];
db dist2[145][145];
db dist[145];
db len[145];
db gan[145];
db minx=9999;
bool vis[145];
int t[145];
il void spfa()
{
	int head=0,tail=1;
	t[0]=1;
	dist[1]=1;
	while(head!=tail)
	{
		int h=t[head++];
		vis[h]=0;
		for(int i=1;i<=n;i++)
		{
			db ls=dist1[h][i],dr=min(gan[h],gan[i]);
			if(dist[i]<dist[h]*(cp*(1-(ls/150)*(ls/150))*(dr/(dr+1))))
			{
				dist[i]=dist[h]*(cp*(1-(ls/150)*(ls/150))*(dr/(dr+1)));
				if(!vis[i])
				{
					vis[i]=1;
					t[tail++]=i;
				}
			}
		}
	}
}
int main()
{
	freopen("pass.in","r",stdin);
	freopen("pass.out","w",stdout);
	cin>>n>>cp>>cs;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i].x>>r[i].y;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>t1[i].x>>t1[i].y;
	}
	for(int i=1;i<=n;i++)
	{
		len[i]=dis(r[i].x,r[i].y,50.0,0);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dist1[i][j]=dist1[j][i]=dis(r[i].x,r[i].y,r[j].x,r[j].y);
			dist2[i][j]=dis(r[i].x,r[i].y,t1[j].x,t1[j].y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		gan[i]=9999;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			gan[i]=min(gan[i],dist2[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		minx=min(minx,dis(t1[i].x,t1[i].y,50.0,0));
	}
	spfa();
	db ans=0;
	for(int i=1;i<=n;i++)
	{
		db dr=min(minx,gan[i]);
		ans=max(ans,dist[i]*(pow(cs*dr/(dr+1),(log(len[i])))));
	}
	cout<<ans;
}


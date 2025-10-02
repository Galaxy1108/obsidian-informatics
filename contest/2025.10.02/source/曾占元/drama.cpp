#include<bits/stdc++.h>
#define int long long
#define _ __int128
using namespace std;
int h[2000005],LOG[2000005],POW[25];
int st[2000005][25],st_max[2000005][25],st_min[2000005][25];
_ maxx(_ x,_ y)
{
	if(x>=y)
		return x;
	return y;
}
void write(_ x)
{
	if(x>=10)
		write(x/10);
	putchar(x%10+48);
	return ;
}
signed main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	int n;
	_ ans=0;
	cin>>n;
	LOG[1]=0;
	for(int i=2;i<=n;i++)
		LOG[i]=LOG[i/2]+1;
	POW[0]=1;
	for(int i=1; ;i++)
	{
		POW[i]=POW[i-1]*2;
		if(POW[i]>=n)
			break;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
		st[i][0]=i+1;
		st_max[i][0]=h[i];
		st_min[i][0]=h[i];
	}
	for(int j=1;(1LL<<j)<=n;j++)
	{
		for(int i=1;i+(1LL<<j)-1<=n;i++)
		{
			st[i][j]=st[st[i][j-1]][j-1];
			st_max[i][j]=max(st_max[i][j-1],st_max[st[i][j-1]][j-1]);
			st_min[i][j]=min(st_min[i][j-1],st_min[st[i][j-1]][j-1]);
		}
	}
	for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			int x=LOG[j-i+1];
			int maxn=max(st_max[i][x],st_max[j-POW[x]+1][x]);
			int minn=min(st_min[i][x],st_min[j-POW[x]+1][x]);
			_ sum=1;
			sum*=maxn;
			sum*=minn;
			sum*=(j-i+1);
			ans=maxx(ans,sum);
		}
	write(ans);
	return 0;
}

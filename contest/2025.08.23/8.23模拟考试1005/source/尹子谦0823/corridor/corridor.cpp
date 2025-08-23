#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2010;
int n,num,k,m,mp[N][N],x,y,q,dx[]={1,0},dy[]={0,1};
void dfs(int x,int y,int step,int to,int q)
{
	if(step==q)
	{
		cout<<x<<' '<<y<<endl;
		return ;
	}
	int nx=x+dx[to],ny=y+dy[to];
	//cout<<x<<' '<<y<<"->"<<nx<<' '<<ny<<endl;
	if(nx>n||ny>m)
	{
		if(nx==n+1) cout<<n+1<<' '<<ny<<endl;
		else cout<<nx<<' '<<m+1<<endl;
		return ;
	}
	if(mp[nx][ny]) dfs(nx,ny,step+1,!to,q);
	else dfs(nx,ny,step,to,q);
}
signed main()
{
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	cin>>num>>n>>m>>k;
	for(int i=1;i<=k;i++) 
	{
		int x,y;
		cin>>x>>y;
		mp[x][y]=1;
	}
	int Q;
	cin>>Q;
	while(Q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			mp[x][y]=1;
		}
		else
		{
			cin>>x>>y>>q;
			if(x==0) dfs(1,y,0,0,q);
			else dfs(x,1,0,1,q);
		}
	}
	return 0;
}

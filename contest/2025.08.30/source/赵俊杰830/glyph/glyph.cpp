#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=305;
ll f[N][N],ans[200005],a[N][N];
struct Q
{
	int x,y,id;
};
vector<Q>v[N][N];
int main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=m;i++)
	{
		int x1,x2,y1,y2;
		cin>>x1>>x2>>y1>>y2;
		v[x1][y1].push_back({x2,y2,i});
	}
	for(int i=n;i>=1;i--)
	{
		for(int j=n;j>=1;j--)
		{
			if(!v[i][j].size())continue;
			int c=0,d=0;
			for(int k=0;k<v[i][j].size();k++)
			{
				c=max(c,v[i][j][k].x);
				d=max(d,v[i][j][k].y);
			}
			for(int y=j;y<=d;y++)f[i-1][y]=1e18;
			f[i-1][j]=0;
			for(int x=i;x<=c;x++)
			{
				f[x][j-1]=1e18;
				for(int y=j;y<=d;y++)
					f[x][y]=min(f[x-1][y],f[x][y-1])+a[x][y];
			}
			for(int k=0;k<v[i][j].size();k++)
				ans[v[i][j][k].id]=f[v[i][j][k].x][v[i][j][k].y];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}

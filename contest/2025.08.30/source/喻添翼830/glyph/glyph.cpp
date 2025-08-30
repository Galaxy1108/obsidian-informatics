#include<bits/stdc++.h>
using namespace std;
const int mx=310;
int n,q;
int a[mx][mx];
long long dis[mx][mx];
int x,xx,y,yy;
int main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;++i)
    	for(int j=1;j<=n;++j) cin>>a[i][j];
    while(q--)
    {
    	cin>>x>>xx>>y>>yy;
    	dis[x][y]=a[x][y];
    	for(int i=y+1;i<=yy;++i) dis[x][i]=dis[x][i-1]+a[x][i];
    	for(int i=x+1;i<=xx;++i) dis[i][y]=dis[i-1][y]+a[i][y];
    	for(int i=x+1;i<=xx;++i)
    		for(int j=y+1;j<=yy;++j)
    			dis[i][j]=min(dis[i-1][j],dis[i][j-1])+a[i][j];
		cout<<dis[xx][yy]<<"\n";
	}
	return 0;
} 

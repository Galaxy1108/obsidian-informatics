#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,a[505][505],f[505][505],xa,ya,xb,yb;
signed main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin>>a[i][j];
		}
	}
	while(q--)
	{
		cin>>xa>>xb>>ya>>yb;
		for(int i = xa; i <= xb; i++) f[i][ya-1]=0x3f3f3f3f3f3f3f3f;
		for(int i = ya; i <= yb; i++) f[xa-1][i]=0x3f3f3f3f3f3f3f3f;
		f[xa][ya-1]=f[xa-1][ya]=0;
		for(int i = xa; i <= xb; i++)
		{
			for(int j = ya; j <= yb; j++)
			{
				f[i][j]=min(f[i-1][j],f[i][j-1])+a[i][j];
			}
		}
		cout<<f[xb][yb]<<'\n';
	}
}

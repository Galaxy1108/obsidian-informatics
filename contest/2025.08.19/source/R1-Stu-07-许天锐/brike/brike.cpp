#include<bits/stdc++.h>
using namespace std;
int n,m,a[51][51],f[51][51][501],maxn,siz[51][51];
priority_queue<int>q;
void dfs(int x,int y)
{
	if(x==1)
	{
		f[x][y][1]=a[x][y];
		siz[x][y]=1;
		return;
	}
	dfs(x-1,y);
	dfs(x-1,y+1);
}
int main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j+i<=n+1;j++)
		{
			cin>>a[i][j];
			if(i>1)q.push(a[i][j]);
		}
	}
	int s=0;
	for(int i=1;i<=n;i++)s+=a[1][i];
	for(int i=1;i<=n-m;i++)s+=q.top(),q.pop();
	cout<<s<<endl;
//	dfs(n,1);
	return 0;
}
/*
MYNF2R-SKSH6J-6HE36H-35VGBF-R8ELOB-AVOG94-DPV8FY
*/

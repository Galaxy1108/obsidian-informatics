#include<bits/stdc++.h>
using namespace std;
const int N=305;
int revnum(vector<int>ary)
{
	int res=0;
	for(int i=0;i<ary.size();i++)
		for(int j=i+1;j<ary.size();j++)
			if(ary[j]<ary[i])res++;
	return res;
}
int T,n,ax,ay,ary[N][N];
bool pd,vis[N*N];
void dfs(int x,int y)
{
	if(y>n)y-=n,x++;
	if(pd)return;
	if(x==n+1&&y==1)
	{
		vector<int>v1;
		vector<int>v2;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				v1.push_back(ary[i][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				v2.push_back(ary[j][i]);
		int r1=revnum(v1),r2=revnum(v2);
		if(r1==ax&&r2==ay)
		{
			cout<<"YES\n";
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)cout<<ary[i][j]<<" ";
				cout<<"\n";
			}
			pd=true;
		}
		return;
	}
	for(int i=1;i<=n*n;i++)
	{
		if(vis[i])continue;
		vis[i]=true;
		ary[x][y]=i;
		dfs(x,y+1);
		vis[i]=false;
		ary[x][y]=0;
	}
}
int main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	cin>>T;
	while(T--)
	{
		pd=false;
		cin>>n>>ax>>ay;
		dfs(1,1);
		if(!pd)cout<<"NO\n";
	}
	
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int m,n;
int edlen[20],ndpos[20];
bool sp[5005];
char ans[2505][2505];
void init()
{
	edlen[1]=1,edlen[2]=2;
	for(int i=3;i<=15;i++)edlen[i]=edlen[i-1]*2+1;
	ndpos[1]=1;
	for(int i=2;i<=15;i++)ndpos[i]=ndpos[i-1]+edlen[i-1]+1;
}
void dfs(int x,int y,int ty,int len,int dep,int xid)
{
	if(dep==m)
	{
		ans[x][y]='o';
		return;
	}
	if(len)
	{
		if(ty==1)
		{
			ans[x][y]='/';
			dfs(x+1,y-1,((len-1)==0?0:1),len-1,dep+((len-1)==0),xid); 
			return;
		}
		if(ty==2)
		{
			ans[x][y]=(char)92;	
			dfs(x+1,y+1,((len-1)==0?0:2),len-1,dep+((len-1)==0),xid);
			return;
		}
	}
	ans[x][y]='o';
	if(!sp[xid*2])dfs(x+1,y-1,1,edlen[m-dep],dep,xid*2);
	if(!sp[xid*2+1])dfs(x+1,y+1,2,edlen[m-dep],dep,xid*2+1);
	return;
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>m>>n;
	init();
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		sp[(1<<(a-1))-1+b]=true;
	}
	for(int i=1;i<=2500;i++)
		for(int j=1;j<=2500;j++)
			ans[i][j]=' ';
	if(!sp[1])dfs(1,ndpos[m],0,0,1,1);
	int hk=ndpos[m]*2;
	int sg=(m==1?1:edlen[m]+1);
	for(int i=1;i<=sg;i++)
	{
		for(int j=1;j<=hk;j++)cout<<ans[i][j];
		cout<<"\n";
	}
	
	return 0;
} 

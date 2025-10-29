#include<iostream>
#include<queue>
using namespace std;
#define f q.front()
const int sx[]={0,0,1,-1},sy[]={1,-1,0,0};
const int MX=2e9;
struct state{
	int x,y,step;
};
int n,m,tx,ty,mnstep=MX,ax,ay,i,j,cnt=0;
queue<state> q;
bool v[13][13]={0},a[13][13];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	cin>>n>>m>>tx>>ty;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	q.push({1,1,0});
	while(!q.empty())
	{
		if(f.step>mnstep)
			break;	
		v[f.x][f.y]=1;
		if(f.x==tx&&f.y==ty)
		{
			if(mnstep==MX)
			{
				mnstep=f.step;
			}
			cnt++;
			q.pop();
			continue;
		}
		for(i=0;i<4;i++)
		{
			ax=f.x+sx[i],ay=f.y+sy[i];
			if(ax>=1&&ax<=n&&ay>=1&&ay<=m&&!v[ax][ay]&&!a[ax][ay])
			{
				q.push({ax,ay,f.step+1});
			}
		}
		q.pop();
	}
	cout<<cnt;
	return 0;
}

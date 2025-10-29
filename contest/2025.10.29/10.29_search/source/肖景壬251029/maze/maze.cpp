#include<bits/stdc++.h>
using namespace std;
struct pp
{
	int x,y,len,pln;
};
pp fr,tmp;
int isfind[15][15],cango[15][15],shorans,dx[5]={0,0,0,1,-1},dy[5]={0,1,-1,0,0},ans,pln[15][15];
queue<pp> q;
int ex,ey,n,m; 
void bfs()
{
	q.push({1,1,0,1});
	shorans=1145141919;
	isfind[1][1]=0;
	pln[1][1]=1;
	if(cango[1][1]) return;
	while(!q.empty())
	{
		fr=q.front();
		fr.pln=pln[fr.x][fr.y];
		q.pop();
		if(fr.x==ex&&fr.y==ey)
		{
			if(fr.len>shorans) return;
			ans+=fr.pln;
			shorans=fr.len;
			continue;
		}
		for(int i = 1; i <= 4; i++)
		{
			tmp=fr;
			tmp.len++;
			tmp.x+=dx[i];
			tmp.y+=dy[i];
			if(tmp.x<1||tmp.x>n||tmp.y<1||tmp.y>m||cango[tmp.x][tmp.y]||isfind[tmp.x][tmp.y]<tmp.len) continue;
			pln[tmp.x][tmp.y]+=tmp.pln;
			if(isfind[tmp.x][tmp.y]>1000000)
			{
				isfind[tmp.x][tmp.y]=tmp.len;
				q.push(tmp);
			}
		}
	}
	return;
}
int main()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	memset(isfind,0x3f,sizeof(isfind));
	cin>>n>>m>>ex>>ey;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			cin>>cango[i][j];
		}
	}
	bfs();
	cout<<ans<<endl;
}

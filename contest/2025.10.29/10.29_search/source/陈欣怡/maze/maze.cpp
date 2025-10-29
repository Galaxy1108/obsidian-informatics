#include<cstdio>
#include<queue>
#include<algorithm>
#define ri register int
#define il inline
#define gc getchar()
#define m_p make_pair
using namespace std;
il int read()
{
	int ans=0,f=1;char ch=gc;
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=gc;}
	while(ch>='0' && ch<='9') ans=(ans<<3)+(ans<<1)+(ch^48),ch=gc;
	return ans*f;
}
const int mm=20;
queue<pair<int,int> > q;
queue<int> step; 
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};
int m[mm][mm],a[mm][mm],t[mm][mm];
il void file()
{
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
}
int main() 
{
	file();
	int N=read(),M=read(),edx=read(),edy=read();
	for(ri i=1;i<=N;i++)
	for(ri j=1;j<=M;j++) a[i][j]=read();
	
	if(a[1][1]==1 || a[edx][edy]==1) {puts("0");return 0;}
	if(edx==1 && edy==1) {puts("1");return 0;}
	q.push(m_p(1,1)),step.push(0),m[1][1]=1,t[1][1]=0;
	
	while(q.size())
	{
		int x=q.front().first,y=q.front().second,st=step.front();
		q.pop(),step.pop();
		if(t[edx][edy] && st>t[edx][edy]) break;
		for(ri i=0;i<4;i++) 
		{
			int sx=x+dx[i],sy=y+dy[i];
			if(sx==edx && sy==edy) {m[edx][edy]+=m[x][y],t[edx][edy]=st+1;continue;}
			if(a[sx][sy] || sx>N || sy>M || sx<=0 || sy<=0) continue; 
			if(m[sx][sy]==0) m[sx][sy]+=m[x][y],t[sx][sy]=st+1,q.push(m_p(sx,sy)),step.push(st+1);
			else if(t[sx][sy]==st+1) m[sx][sy]+=m[x][y];
		}
	}
	printf("%d",m[edx][edy]);
	return 0;
 } 

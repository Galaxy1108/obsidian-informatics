#include <cstdio>
using namespace std;
bool del[12][2512];
char s[3212][3212];
int n,m,sz[12],ht;
void dfs(int x,int y,int ly,int idx)
{
	if (del[ly][idx]==1) return ;
	s[x][y] = 'o';
	if (x>ht) ht = x;
	if (ly==n) 
	{
		return ;
	}
	int cnt = sz[n-ly]/2;
	if (ly==n-1) cnt = 1;
	if (!del[ly+1][idx*2-1])
		for (int i=1;i<=cnt;i++)
			s[x+i][y-i] = '/',s[x+i][sz[n]+1] = ' ';
	if (!del[ly+1][idx*2])
		for (int i=1;i<=cnt;i++)
			s[x+i][y+i] = '\\',s[x+i][sz[n]+1] = ' ';
	dfs(x+cnt+1,y-cnt-1,ly+1,idx*2-1);
	dfs(x+cnt+1,y+cnt+1,ly+1,idx*2);
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		del[x][y] = 1;
	}
	sz[1] = 1;
	sz[2] = 5;
	for (int i=3;i<=n;i++) sz[i] = 2*sz[i-1] + 1;
	for (int i=1;i<=3200;i++)
	{
		for (int j=1;j<=sz[n];j++)
			s[i][j] = ' ';
	}
	dfs(1,(sz[n]+1)/2,1,1);
	for (int i=1;i<=ht;i++)
	{
		printf("%s",s[i]+1);
		printf("\n");
	}
	return 0;
}

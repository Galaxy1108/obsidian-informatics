#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
constexpr int N=12;
bool m1;
int n,m;
char s[1<<N][1<<N];
int id[1<<N][1<<N];
pii ps[1<<N];
bool vis[1<<N];
bool m2;
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	//cerr<<fabs(&m1-&m2)/1024.0/1024.0<<"MB\n";
	cin>>m>>n;
	int pos=0;
	for(int i=(1<<m-1);i<(1<<m);i+=2)
	{
		s[0][pos]='o';
		id[0][pos]=i;
		ps[i]=mp(0,pos);
		s[0][pos+4]='o';
		ps[i+1]=mp(0,pos+4);
		id[0][pos+4]=i+1;
		pos+=6;
	}
	int len=1,las=m,sum=0;
	for(int i=(1<<m)-1;i>1;i--)
	{
		int h=32-__builtin_clz(i);
		if(h!=las)
		{
			int _len=sum+len+1;
			int _sum=sum+len+1;
			len=_len,sum=_sum;
			las=h;
		}
		if(i&1)
		{
			int x=ps[i].fi;
			int y=ps[i].se;
			x++,y--;
			for(int j=1;j<=len;j++)
				s[x][y]='\\',id[x++][y--]=i;
			s[x][y]='o',id[x][y]=i;
			ps[i>>1]=mp(x,y);
		}
		else
		{
			int x=ps[i].fi;
			int y=ps[i].se;
			x++,y++;
			for(int j=1;j<=len;j++)
				s[x][y]='/',id[x++][y++]=i;
			s[x][y]='o',id[x][y]=i;
			ps[i>>1]=mp(x,y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		vis[(1<<x-1)+y-1]=1;
	}
	for(int i=1;i<(1<<m);i++)
		if(vis[i])
			vis[i<<1]=vis[i<<1|1]=1;
	int sti=ps[1].fi,edi=0,stj=0,edj=ps[(1<<m)-1].se;
	for(int i=sti;i>=edi;i--)
	{
		for(int j=stj;j<=edj;j++)
		{
			if(s[i][j]!='/' && s[i][j]!='\\' && s[i][j]!='o')
				putchar(32);
			else
			{
				if(vis[id[i][j]])
					putchar(32);
				else
					putchar(s[i][j]);
			}
		}
		putchar('\n');
	}
	//cerr<<sti<<' '<<edj;
	return 0;
}

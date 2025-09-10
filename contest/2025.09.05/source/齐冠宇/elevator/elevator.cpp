#include <bits/stdc++.h>
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
using namespace std;
constexpr int N=2005;
int n;
pii a[N];
int f[N][10][10][10][10][10];
inline void chkmin(int& x,int y){if(x>y)x=y;}
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].fi>>a[i].se;
	memset(f,0x3f,sizeof f);
	f[0][1][0][0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int pos=1;pos<=9;pos++)
		{
			for(int a=0;a<=9;a++)
			{
				for(int b=0;b<=9;b++)
				{
					for(int c=0;c<=9;c++)
					{
						for(int d=0;d<=9;d++)
						{
							int cnt=(a==0)+(b==0)+(c==0)+(d==0);
							if(cnt==4)
								chkmin(f[i][a[i].fi][a[i].se][b][c][d],f[i][pos][a][b][c][d]+abs(pos-a[i].fi));
							else
							{
								int npos=pos;
								for(int j=1,len=0;j<=4-cnt;j++)
								{
									int nxt;
									if(j==1)nxt=a;
									if(j==2)nxt=b;
									if(j==3)nxt=c;
									if(j==4)nxt=d;
									len+=abs(nxt-npos);
									if((npos<=a[i].fi && a[i].fi<=nxt) || (nxt<=a[i].fi && a[i].fi<=npos))
									{
										chkmin(f[])
									}
									else
									{
										
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define MAXN 55
using namespace std;
inline int read()
{
	int s=0,f=1;char ch=getchar();
	for(;ch>'9'||ch<'0';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';s=(s<<3)+(s<<1)+(ch^48),ch=getchar());
	return (f==1)?s:-s;
}
int a[MAXN][MAXN],n,m,sum=0;
int bk[MAXN][MAXN];
int quex[300],quey[300],tl;
int bk1[300];
signed main()
{
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	n=read(),m=read();
	for(int i=n;i>=1;i--)
		for(int j=1;j<=i;j++)
			a[i][j]=read(),sum+=a[i][j],bk[i][j]=(j==1||j==i)?2:3;
	bk[1][1]=1;
	for(int i=1;i<=n*(n+1)/2-m;i++)
	{
		for(int ii=1;ii<=n;ii++)
		{
			for(int jj=1;jj<=ii;jj++)
			{
				if(bk[ii][jj]==1)
				{
					bk[ii][jj]=-1;
					tl++;
					quex[tl]=ii;
					quey[tl]=jj;
				}
			}
		}
		int minn=2147483647,pos;
		for(int ii=1;ii<=tl;ii++)
		{
			if(minn>a[quex[ii]][quey[ii]]&&bk1[ii]==0)
			{
				minn=a[quex[ii]][quey[ii]];
				pos=ii;
			}
		}
		sum-=minn;
		bk1[pos]=1;
		bk[quex[pos]+1][quey[pos]]--;
		bk[quex[pos]+1][quey[pos]+1]--;
	}
	cout<<sum<<endl;
	return 0;
}

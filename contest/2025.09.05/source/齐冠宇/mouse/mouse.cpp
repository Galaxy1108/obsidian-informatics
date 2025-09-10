#include <bits/stdc++.h>
using namespace std;
typedef double db;
constexpr int N=2005;
int n;
int w,b;
db f[2][N][N];
db ans;
int main()
{
	freopen("mouse.in","r",stdin);
	freopen("mouse.out","w",stdout);
	scanf("%d%d",&w,&b);
	n=w+b;
	int t=0;
	f[t][w][b]=1;
#define tt t^1
	while(n>0)
	{
		for(int i=0;i<=n;i++)
		{
			int j=n-i;
			if(i)
				ans+=f[t][i][j]*i/n;
			if(n==1 || n==2)
				continue;
			if(j>=2)
			{
				db xs=1.0*j/n*(j-1)/(n-1);
				if(j>=3)
					f[tt][i][j-3]+=f[t][i][j]*xs*(j-2)/(n-2);
				if(i)
					f[tt][i-1][j-2]+=f[t][i][j]*xs*i/(n-2);
			}
		}
//		db sum=0;
//		for(int i=0;i<=n-3;i++)
//		{
//			int j=n-3-i;
//			printf("%d %d:%.5lf\n",i,j,f[tt][i][j]);
//			sum+=f[tt][i][j];
//		}
//		printf("sum:%.5lf\n",sum);
//		cout<<"-----------\n";
		for(int i=0;i<=n;i++)
		{
			int j=n-i;
			f[t][i][j]=0.0;
		}
		t^=1;
		n-=3;
	}
#undef tt
	printf("%.9lf",ans);
	return 0;
}

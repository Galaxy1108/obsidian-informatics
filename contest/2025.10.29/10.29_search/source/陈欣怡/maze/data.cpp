#include<cstdio>
#define ri register int
#define il inline
#define gc getchar()
using namespace std;
int main()
{
	freopen("maze.in","w",stdout);
	const int mm=12;
	int n=mm,m=mm,sx=mm,sy=mm;printf("%d %d %d %d\n",n,m,sx,sy);
	for(ri i=1;i<=n;i++,puts(""))
	for(ri j=1;j<=m;j++) printf("0 ");
	return 0;
}


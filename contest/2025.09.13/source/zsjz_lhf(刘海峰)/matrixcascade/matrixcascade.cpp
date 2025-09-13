#include<cstdio>
#include<cstring>
using namespace std;
#define f1(i) for(int i=1;i<=n;i++)
#define f2(i) for(int i=n;i;i--)
const int N=310;
struct point{
	int x,y;
}k;
int n,s[N][N],p[N][N];
bool chk(point a){return p[a.x][a.y];}
struct my_array{
	point a[N*N];
	int len;
	void push(int x,int y){a[++len]=(point){x,y};}
	point top()
	{
		while(len<=n*n&&chk(a[len])) len++;
		return a[len];
	}
}a[4];
void update(int x)
{
	for(int i=1;i<=n;i++)
		s[x][i]=s[x][i-1]+(p[x][i]==0);
}
int qry1(int x,int y)
{
	int ans=0;
	for(int i=1;i<=x;i++)
		ans+=s[i][y];
	return ans-1;
}
int qry2(int x,int y)
{
	int ans=0;
	for(int i=x+1;i<=n;i++)
		ans+=s[i][y-1];
	return ans;
}
long long A,B,C,X,Y;
int dx,dy,px,py,T;
int main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(p,0,sizeof(p));
		memset(s,0,sizeof(s));
		for(int i=0;i<4;i++) a[i].len=0;
		scanf("%d%lld%lld",&n,&A,&B);
		C=n*(n-1)/2,C*=C;
		if((A+B+C)&1){printf("NO\n");continue;}
		X=(A+B-C)/2,Y=B-X;
		f1(i) f1(j) a[2].push(i,j),a[3].push(j,i);
		f2(i) f2(j) a[1].push(i,j),a[0].push(j,i);
		a[0].len=a[1].len=a[2].len=a[3].len=1;
		if(X<0||Y<0||X>C+2*n*(n*(n-1)/2)||Y>C) {printf("NO\n");continue;}
		for(int i=1;i<=n;i++) update(i);
		for(int c=1;c<=n*n;c++)
			for(int i=0;i<4;i++)
			{
				k=a[i].top();
				if(k.x==0) continue;
				dx=qry1(k.x,k.y);
				dy=qry2(k.x,k.y);
				if(X>=dx&&Y>=dy)
				{
					X-=dx,Y-=dy;
					p[k.x][k.y]=c;
					update(k.x);
					break;
				}
			}
		printf("YES\n");
		for(int i=1;i<=n;i++,printf("\n"))
			for(int j=1;j<=n;j++) printf("%d ",p[i][j]);
	}
}
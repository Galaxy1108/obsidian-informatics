#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define x first
#define y second
#define WT int TT=read();while(TT--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
	char c=getchar();int x=0;bool f=0;
	for(;!isdigit(c);c=getchar())f^=!(c^45);
	for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
	if(f)x=-x;return x;
}
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=310;
int n,a[M][M],x,y,cnt1,cnt2,X,Y,c[M][M];
pii a1[M*M],a2[M*M];

inline int lowbit(int x){return x&(-x);}

void add(int x,int y,int t)
{
	for (int i=x;i<=n;i+=lowbit(i))
		for (int j=y;j<=n;j+=lowbit(j))c[i][j]+=t;
}

int query(int x,int y)
{
	int res=0;
	for (int i=x;i>=1;i-=lowbit(i))for (int j=y;j>=1;j-=lowbit(j))res+=c[i][j];
	return res;
}

int check(pii x)
{
	int c1=cnt1,c2=cnt2,xx=X,yy=Y;
	int tmp=query(x.x,x.y);xx-=tmp,c1-=tmp;
	tmp=query(n,n)-query(n,x.y-1)-query(x.x-1,n)+query(x.x-1,x.y-1),c1-=tmp;
	tmp=query(n,x.y-1)-query(x.x,x.y-1);c2-=tmp;
	tmp=query(x.x-1,n)-query(x.x-1,x.y);c2-=tmp,yy-=tmp;
//	for (int i=1;i<=x.x;i++)for (int j=1;j<=x.y;j++)xx-=(a[i][j]==0),c1-=(a[i][j]==0);
//	for (int i=x.x;i<=n;i++)for (int j=x.y;j<=n;j++)c1-=(a[i][j]==0);
//	for (int i=x.x+1;i<=n;i++)for (int j=1;j<x.y;j++)c2-=(a[i][j]==0);
//	for (int i=1;i<x.x;i++)for (int j=x.y+1;j<=n;j++)yy-=(a[i][j]==0),c2-=(a[i][j]==0); 
	xx++,c1+=2;
//	cerr<<"qwq"<<x.x<<' '<<x.y<<' '<<xx<<' '<<yy<<' '<<c1<<' '<<c2<<'\n';
	if (xx<=c1&&xx>=0&&yy<=c2&&yy>=0)
		return X=xx,Y=yy,cnt1=c1,cnt2=c2,add(x.x,x.y,-1),1;
	else return 0;
}

void solve()
{
	n=read(),x=read(),y=read();
	cnt1=(n*n*n*n+2*n*n*n-3*n*n)>>2,cnt2=(n*n*n*n-((n*(n+1)*n*(n+1))>>1)+n*n)>>1;
	if (x+y<cnt2||x+y>cnt2+cnt1*2||(x+y-cnt2)&1||min(x,y)<(x+y-cnt2)/2)return puts("NO"),void();
	puts("YES");
	X=(x+y-cnt2)/2,Y=x-X;int tot=0;
//	cerr<<X<<' '<<Y<<'\n';
	for (int i=1;i<=n;i++)for (int j=1;j<=n;j++)a[i][j]=0,a1[++tot]=mp(i,j),a2[tot]=mp(j,i),add(i,j,1);
	int l1=1,r1=n*n,l2=1,r2=n*n;
	for (int _=1;_<=n*n;_++)
	{
//		for (int i=1;i<=n;i++)
//			for (int j=1;j<=n;j++)
//				cerr<<a[i][j]<<(j==n?'\n':' ');
//		cerr<<X<<' '<<Y<<' '<<cnt1<<' '<<cnt2<<'\n';
		while(a[a1[l1].x][a1[l1].y])l1++;
		while(a[a2[l2].x][a2[l2].y])l2++;
		while(a[a1[r1].x][a1[r1].y])r1--;
		while(a[a2[r2].x][a2[r2].y])r2--;
		if (check(a1[l1]))a[a1[l1].x][a1[l1].y]=_,l1++;
		else if (check(a1[r1]))a[a1[r1].x][a1[r1].y]=_,r1--;
		else if (check(a2[l2]))a[a2[l2].x][a2[l2].y]=_,l2++;
		else if (check(a2[r2]))a[a2[r2].x][a2[r2].y]=_,r2--;
		else assert(0);
	}
//	cerr<<X<<' '<<Y<<' '<<cnt1<<' '<<cnt2<<'\n';
//	for (int i=1;i<=n;i++)
//		for (int j=1;j<=n;j++)
//			cout<<a[i][j]<<(j==n?'\n':' ');
	return;
}

signed main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	WT solve();
	cerr<<clock()<<'\n';
	return 0;
}

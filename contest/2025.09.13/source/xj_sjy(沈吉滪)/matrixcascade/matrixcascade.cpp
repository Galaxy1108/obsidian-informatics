// what is matter? never mind.
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define ll unsigned int
using namespace std;
inline ll read()
{
    char c=getchar();ll x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define x first
#define y second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005
#define inf 0x3f3f3f3f

int n;
ll sum1,sum2,xx,yy,x,y;
int a[305][305];
pii a1[maxn],a2[maxn],a3[maxn],a4[maxn];

int tr[305][305];
void Add(int x,int y){
	for(int i=x;i<=n;i+=i&-i)
		for(int j=y;j<=n;j+=j&-j)tr[i][j]++;
}
int Q(int x,int y){
	int s=0;
	for(;x;x^=x&-x)for(int j=y;j;j^=j&-j)s+=tr[x][j];
	return s;
}
int sum(int xl,int xr,int yl,int yr){
	if(xl>xr||yl>yr)return 0;
	return Q(xr,yr)-Q(xl-1,yr)-Q(xr,yl-1)+Q(xl-1,yl-1);
}
bool chk(int i,int j,int k){
	ll d1=i*j-1-Q(i,j);
	ll nx=x-d1;
	ll ns1=sum1-((n-i+1)*(n-j+1)-1-sum(i,n,j,n))-d1;
	if(nx<0||nx>ns1)return 0;
	ll d2=(i-1)*(n-j)-sum(1,i-1,j+1,n);
	ll ns2=sum2-((n-i)*(j-1)-(sum(i+1,n,1,j-1)))-d2;
	ll ny=y-d2;
	if(ny>=0&&ny<=ns2){
		sum1=ns1,sum2=ns2,x=nx,y=ny;
		a[i][j]=k;
		Add(i,j);
		return 1;
	}
	return 0;
}

void work()
{
	n=read(),x=read(),y=read();
	sum1=sum2=0;
	For(i,1,n)
		For(j,1,n){
			sum1+=i*j-1;
			sum2+=(i-1)*(j-1);
		}
	if((x+y+sum2)%2)return puts("NO"),void();
	xx=(x+y-sum2)/2;
	yy=(x-y+sum2)/2;
//	xx=0,yy=sum2;
	if(xx<0||yy<0||xx>sum1||yy>sum2)return puts("NO"),void();
	puts("YES");
//	cout<<"X,Y "<<xx<<" "<<yy<<' '<<sum1<<" "<<sum2<<"\n";
	x=xx,y=yy;
	int len=0; 
	For(i,1,n)For(j,1,n)a1[++len]=mkp(i,j);
	len=0;
	For(i,1,n)For(j,1,n)a2[++len]=mkp(j,i);
	len=0;
	Rep(i,n,1)Rep(j,n,1)a3[++len]=mkp(i,j);
	len=0;
	Rep(i,n,1)Rep(j,n,1)a4[++len]=mkp(j,i);
	
	For(i,0,n)For(j,0,n)a[i][j]=tr[i][j]=0;
	int p1=1,p2=1,p3=1,p4=1;
//	puts("QAQ");
	For(i,1,n*n){
		while(p1<=len && a[a1[p1].x][a1[p1].y])++p1;
		if(chk(a1[p1].x,a1[p1].y,i))continue;
		while(p2<=len && a[a2[p2].x][a2[p2].y])++p2;
		if(chk(a2[p2].x,a2[p2].y,i))continue;
		while(p3<=len && a[a3[p3].x][a3[p3].y])++p3;
		if(chk(a3[p3].x,a3[p3].y,i))continue;
		while(p4<=len && a[a4[p4].x][a4[p4].y])++p4;
		if(chk(a4[p4].x,a4[p4].y,i))continue;
		assert(0);
	}
	For(i,1,n){
		For(j,1,n)printf("%d ",a[i][j]);
		puts("");
	}
}

signed main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	int T=read();
	while(T--)work();
	return 0;
}
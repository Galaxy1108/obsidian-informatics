#include<bits/stdc++.h>
#define rr register
#define ll long long
using namespace std;
inline ll read()
{
	ll x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x;
}
void write(ll x) {if(x>9) write(x/10);putchar(x%10+'0');}
const int N=303,Q=2e5+3;
const ll inf=1e18;
int n,q;
ll a[N][N],dp[N][2],ans[Q];
struct query
{
	int x1,x2,y1,y2,id;
}qq[Q];
bool cmp(query x,query y)
{
	if(x.x1!=y.x1) return x.x1<y.x1;
	if(x.y1!=y.y1) return x.y1<y.y1;
	if(x.x2+x.y2!=y.x2+y.y2) return x.x2+x.y2<y.x2+y.y2;
	return x.x2<y.x2;
}
inline ll max(ll x,ll y) {return x>y ? x : y;}
inline ll min(ll x,ll y) {return x<y ? x : y;}
int main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	n=read(),q=read();
	for(rr int i=1;i<=n;++i)
		for(rr int j=1;j<=n;++j) a[i][j]=read();
	for(rr int i=1;i<=q;++i) qq[i].x1=read(),qq[i].x2=read(),qq[i].y1=read(),qq[i].y2=read(),qq[i].id=i;
	sort(qq+1,qq+q+1,cmp);
	for(rr int now=1;now<=q;++now)
	{
		int x1=qq[now].x1,y1=qq[now].y1;bool enough=false;
		dp[x1][(x1+y1)%2]=a[x1][y1];
		while(qq[now].x2==x1&&qq[now].y2==y1&&qq[now].x1==x1&&qq[now].y1==y1) ans[qq[now].id]=a[x1][y1],++now;
		if(qq[now].x1!=x1||qq[now].y1!=y1) {--now;continue;}
		for(rr int s=x1+y1+1;s<=(n<<1);++s)
		{
			for(rr int i=max(x1,s-n);i<=n&&s-i<=n&&s-i>=y1;++i)
			{
				int j=s-i,t=s%2,la=(s-1)%2;
				ll mid=inf;
				if(i>x1) mid=min(mid,dp[i-1][la]);
				if(j>y1) mid=min(mid,dp[i][la]);
				dp[i][t]=mid+a[i][j];
				while(qq[now].x2==i&&qq[now].y2==j&&qq[now].x1==x1&&qq[now].y1==y1) ans[qq[now].id]=dp[i][t],++now;
				if(qq[now].x1!=x1||qq[now].y1!=y1) {--now;enough=true;break;}
			}
			if(enough) break;
		}
	}
	for(rr int i=1;i<=q;++i) write(ans[i]),putchar('\n');
	return 0;
}
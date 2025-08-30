// what is matter? never mind.
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
typedef pair<int,int>pii;
typedef vector<int>vi;

#define maxn 200005
#define inf 0x3f3f3f3f3f3f3f3f

int n,m,res[maxn];
int a[305][305];

struct node{
	int x,y,xx,yy,id;
}q[maxn],tmp[maxn];

int dis[305][305];
void bfs(int x,int y,int lx,int rx,int ly,int ry){
	dis[x][y]=0;
	Rep(i,x,lx)
		Rep(j,y,ly){
			if(i==x&&j==y)continue;
			dis[i][j]=inf;
			if(i+1<=x) dis[i][j]=min(dis[i][j],dis[i+1][j]+a[i][j]);
			if(j+1<=y) dis[i][j]=min(dis[i][j],dis[i][j+1]+a[i][j]);
		}
	For(i,x,rx)
		For(j,y,ry){
			if(i==x&&j==y)continue;
			dis[i][j]=inf;
			if(i-1>=x) dis[i][j]=min(dis[i][j],dis[i-1][j]+a[i][j]);
			if(j-1>=y) dis[i][j]=min(dis[i][j],dis[i][j-1]+a[i][j]);
		}
}
void bfs(int x,int y,int lx,int rx,int ly,int ry,int ql,int qr){
	bfs(x,y,lx,rx,ly,ry);
	For(i,ql,qr){
		if(q[i].x<=x && q[i].xx>=x && q[i].y<=y && q[i].yy>=y){
			res[q[i].id]=min(res[q[i].id],dis[q[i].x][q[i].y]+dis[q[i].xx][q[i].yy]+a[x][y]);
		}
	}
}

void solve(int lx,int rx,int ly,int ry,int ql,int qr)
{
	if(ql>qr)return;
//	cout<<"sol "<<lx<<" "<<rx<<" "<<ly<<" "<<ry<<" "<<ql<<" "<<qr<<"\n";
	if(rx-lx>ry-ly){
		int mid=lx+rx>>1;
		For(i,ly,ry) bfs(mid,i,lx,rx,ly,ry,ql,qr);
		For(i,ql,qr) tmp[i]=q[i];
		int lp=ql-1,rp=qr+1;
		For(i,ql,qr)
			if(tmp[i].x<mid&&tmp[i].xx<mid) q[++lp]=tmp[i];
			else if(tmp[i].x>mid&&tmp[i].xx>mid) q[--rp]=tmp[i];
		solve(lx,mid-1,ly,ry,ql,lp);
		solve(mid+1,rx,ly,ry,rp,qr);
	}else{
		int mid=ly+ry>>1;
		For(i,lx,rx) bfs(i,mid,lx,rx,ly,ry,ql,qr);
		For(i,ql,qr) tmp[i]=q[i];
		int lp=ql-1,rp=qr+1;
		For(i,ql,qr)
			if(tmp[i].y<mid&&tmp[i].yy<mid) q[++lp]=tmp[i];
			else if(tmp[i].y>mid&&tmp[i].yy>mid) q[--rp]=tmp[i];
		solve(lx,rx,ly,mid-1,ql,lp);
		solve(lx,rx,mid+1,ry,rp,qr);
	}
}

signed main()
{
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	n=read(),m=read();
	For(i,1,n)For(j,1,n)a[i][j]=read();
	For(i,1,m){
		node t;
		t.x=read(),t.xx=read(),t.y=read(),t.yy=read(),t.id=i;
		q[i]=t;
	}
	memset(res,63,sizeof res);
	solve(1,n,1,n,1,m);
	For(i,1,m)printf("%lld\n",res[i]);
	return 0;
}

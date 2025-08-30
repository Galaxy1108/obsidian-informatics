#include<bits/stdc++.h>
#define pc(x) putchar(x)
#define int long long
#define x1 XX1
#define y1 YY1
#define x2 XX2
#define y2 YY2
using namespace std;

inline int read() {
	int x = 0, f=1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		f = ch == '-' ? -1 : f; ch = getchar();
	}
	while(ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

void write(int x) {
	if(x < 0) {x = -x; putchar('-');}
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

const int inf=0x3f3f3f3f3f3f3f3f;
int n,q,ans[200005];
int a[305][305];
int f[305][305][305];

struct node{int x1,x2,y1,y2,id;};

void trans(int x,int y,int X,int Y) {
	for(int i=1;i<=n;++i)
		if(f[x][y][i]!=inf)
			f[X][Y][i]=min(f[X][Y][i],f[x][y][i]+a[X][Y]);
}

void solve(int l,int r,vector<node> v) {
	if(!v.size()||l>r)return;
	int mid=(l+r)>>1;
	for(int i=1;i<=n;++i)for(int j=l-1;j<=r+1;++j)memset(f[i][j],0x3f,sizeof f[i][j]);
	for(int i=1;i<=n;++i)f[i][mid][i]=a[i][mid];
	for(int i=n;i>=1;--i)
		for(int j=mid;j>=l;--j)
			trans(i,j,i-1,j),trans(i,j,i,j-1);
	for(int i=1;i<=n;++i){memset(f[i][mid],0x3f,sizeof f[i][mid]);f[i][mid][i]=a[i][mid];}
	for(int i=1;i<=n;++i)
		for(int j=mid;j<=r;++j)
			trans(i,j,i+1,j),trans(i,j,i,j+1);
	vector<node>vl,vr;
	for(node it:v)
	{
		if(it.y1<mid&&it.y2<mid)vl.push_back(it);
		else if(it.y1>mid&&it.y2>mid)vr.push_back(it);
		else
		{
			// cout<<l<<" "<<r<<" "<<mid<<endl;
			// for(int i=it.x1;i<=it.x2;++i)
			// 	printf("f[%lld][%lld][%lld]=%lld , f[%lld][%lld][%lld]=%lld , sum=%lld\n",it.x1,it.y1,i,f[it.x1][it.y1][i],it.x2,it.y2,i,f[it.x2][it.y2][i],f[it.x1][it.y1][i]+f[it.x2][it.y2][i]-a[i][mid]);
			for(int i=it.x1;i<=it.x2;++i)
				ans[it.id]=min(ans[it.id],f[it.x1][it.y1][i]+f[it.x2][it.y2][i]-a[i][mid]);
		}
	}if(l==r)return;
	solve(l,mid-1,vl);solve(mid+1,r,vr);
}

signed main() {
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);
	n=read(),q=read();memset(ans,0x3f,sizeof ans);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) a[i][j]=read();
	vector<node>bg;
	for(int i=1;i<=q;++i) {
		int x1=read(),x2=read(),y1=read(),y2=read();
		bg.push_back((node){x1,x2,y1,y2,i});
	}
	solve(1,n,bg);
	for(int i=1;i<=q;++i)write(ans[i]),pc('\n');
	return 0;
}
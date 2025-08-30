#pragma GCC optimize(2)
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=305;
struct node{
	pair<int,int> s,t;
	int id;
}b[200005];
int n,m;
ll a[N][N];
ll ans[200005];
void write(ll x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
bool cmp(node x,node y){
	return x.s!=y.s?x.s<y.s:x.t<y.t;
}
ll f[N][N];
int vis[N][N];
int b1,b2,cnt;
inline ll dfs(int x,int y){
	if(x<b1||y<b2) return 1e18;
	if(x==b1&&y==b2) return a[x][y];
	if(vis[x][y]==cnt) return f[x][y];
	vis[x][y]=cnt;
	f[x][y]=a[x][y]+min(dfs(x-1,y),dfs(x,y-1));
	return f[x][y];
}
int main(){ 
	freopen("glyph.in","r",stdin);
	freopen("glyph.out","w",stdout);	
	n=read();m=read();
	for(register int i=1;i<=n;i++) for(register int j=1;j<=n;j++) a[i][j]=read();
	for(register int i=1;i<=m;i++){
		int x1=read(),x2=read(),y1=read(),y2=read();
		b[i].s={x1,y1};
		b[i].t={x2,y2};
		b[i].id=i;
	}
	sort(b+1,b+m+1,cmp);
	int now=0;
	while(now<m){
		now++;
		cnt++;
		b1=b[now].s.first,b2=b[now].s.second;
		int to=0;
		for(register int j=now;j<=m;j++){
			if(b[j].s!=b[now].s) break;
			to=j;
			ans[b[j].id]=dfs(b[j].t.first,b[j].t.second);
		}
		now=to;
	}	
	for(register int i=1;i<=m;i++){
		write(ans[i]);
		putchar('\n');
	}
	return 0;
} 

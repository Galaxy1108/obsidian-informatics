#include<bits/stdc++.h>
#define up(x,a,b) for(ll x=a;x<=b;++x)
#define down(x,a,b) for(ll x=a;x>=b;--x)
#ifdef __unix__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
using namespace std;
typedef long long ll;
ll n,m,end_x,end_y,short_len=2125201314,ans;
ll xy[15][15];
bool vis[15][15];
struct node{
    ll x,y;
    ll len;
};
inline ll read(){
	ll x=0,f=1;
	char ch=gc();
	while(ch<'0'||ch>'9'){
		if(ch=='-')
			f=-1;
		ch=gc();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=gc();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0){
		pc('-');
		x=-x;
	}
	if(x>9)
		write(x/10);
	pc(x%10+'0');
}
inline void bfs(){
    queue<node> q;
    vis[1][1]=1;
    q.push({1,1,0});
    while(q.size()){
        auto now_pos=q.front();
        q.pop();
        up(i,1,4){
            ll nx=now_pos.x,ny=now_pos.y,nlen=now_pos.len+1;
            switch(i){
                case 1:nx++;break;
                case 2:ny++;break;
                case 3:nx--;break;
                case 4:ny--;
            }
            if((1<=nx&&nx<=m)&&(1<=ny&&ny<=n)&&!xy[ny][nx]&&!vis[ny][nx]){
                if(nx==end_x&&ny==end_y){
                    short_len=min(short_len,nlen);
                    continue;
                }
                vis[ny][nx]=1;
                q.push({nx,ny,nlen});
            }
        }
    }
}
inline void dfs(ll x,ll y,ll len){
    if(x==end_x&&y==end_y){
        ans++;
        return;
    }
    if(len>short_len)
        return;
    up(i,1,4){
        ll nx=x,ny=y;
        switch(i){
            case 1:nx++;break;
            case 2:ny++;break;
            case 3:nx--;break;
            case 4:ny--;
        }
        if((1<=nx&&nx<=m)&&(1<=ny&&ny<=n)&&!xy[ny][nx]&&!vis[ny][nx]){
            vis[ny][nx]=1;
            dfs(nx,ny,len+1);
            vis[ny][nx]=0;
        }
    }
}
int main(){
	freopen("maze.in","r",stdin);
	freopen("maze.out","w",stdout);
	n=read(),m=read(),end_x=read(),end_y=read();
    up(i,1,n){
        up(j,1,m)
            xy[i][j]=read();
    }
    bfs();
    memset(vis,0,sizeof(vis));
    vis[1][1]=1;
    dfs(1,1,0);
    write(ans);
	return 0;
}
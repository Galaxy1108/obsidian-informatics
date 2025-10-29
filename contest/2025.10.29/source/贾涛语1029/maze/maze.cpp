#include<bits/stdc++.h>
namespace Fread {
	const int SIZE=1<<21;char buf[SIZE],*S,*T;
	inline char getchar() {if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return '\n';}return *S++;}
}
namespace Fwrite {
	const int SIZE=1<<21;
	char buf[SIZE],*S=buf,*T=buf+SIZE;
	inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}
	inline void putchar(char c){*S++=c;if(S==T)flush();}
	struct POPOSSIBLE{~POPOSSIBLE(){flush();}}ztr;
}
#define getchar Fread :: getchar
#define putchar Fwrite :: putchar
namespace Fastio{
	struct Reader{
	    template<typename T>
    	Reader& operator >> (T& x) {
        	char c=getchar();T f=1;
        	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}x=0;
        	while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}x*=f;
	        return *this;
    	}
	    Reader(){}
	}cin;
	struct Writer{
	    template<typename T>
	    Writer& operator << (T x) {
	        if(x==0){putchar('0');return *this;}
	        if(x<0){putchar('-');x=-x;}
	        static int sta[45];int top=0;
	        while(x){sta[++top]=x%10;x/=10;}
	        while(top){putchar(sta[top]+'0');--top;}
	        return *this;
    	}
    	Writer& operator << (char c) {putchar(c);return *this;}
    	Writer(){}
	}cout;
}
#define endl '\n'
#define cin Fastio :: cin
#define cout Fastio :: cout
#define itn int
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n,m,x,y,ans;
int mp[14][14];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
bool vis[14][14];
struct node{
    int x,y,step;
};
int main(){
    freopen("maze.in","r",stdin);freopen("maze.out","w",stdout);
	cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>mp[i][j];
        }
    }
    queue<node>q;
    q.push({1,1,0}); 
    vis[1][1]=true;
    while(!q.empty()){
        int nx=q.front().x,ny=q.front().y,st=q.front().step;
        if(nx==x&&ny==y){
            ans=st;
            break;
        }
        q.pop();
        for(int i=0;i<4;i++){
            int xx=dx[i]+nx,yy=ny+dy[i];
            if(xx<=n&&1<=xx&&yy<=m&&1<=yy&&!vis[xx][yy]&&!mp[xx][yy]){
                q.push({xx,yy,st+1});
                vis[xx][yy]=true;
            }
        }
    }
    cout<<ans;
    return 0;
}

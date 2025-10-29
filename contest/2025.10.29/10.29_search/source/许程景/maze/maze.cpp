#include <cstdio>
#include <queue>
struct status{
    int x,y,step;
};
int map[12][12];
int dire[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
void bfs(int n,int m,int edx,int edy){
    std::queue<status> q;
    int spath[12][12];
    int wofs[12][12];
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    if(i==0&&j==0){
		spath[i][j]=0ll;
		wofs[i][j]=1;
	    }else{
		spath[i][j]=200;
		wofs[i][j]=0;
	    }
	}
    }
    q.push({0,0,0});
    while(q.size()){
	auto now=q.front();
	q.pop();
	for(int i=0;i<4;i++){
	    status nxt={now.x+dire[i][0],now.y+dire[i][1],now.step+1};
	    if((0<=nxt.x&&nxt.x<n)&&(0<=nxt.y&&nxt.y<m)&&(!map[nxt.x][nxt.y])){
		if(nxt.step<=spath[nxt.x][nxt.y]){
		    //printf("%d %d %d %d\n",nxt.x,nxt.y,nxt.step,wofs[now.x][now.y]);
		    spath[nxt.x][nxt.y]=nxt.step;
		    //wofs[nxt.x][nxt.y]+=wofs[now.x][now.y];
		    wofs[nxt.x][nxt.y]++;
		    q.push(nxt);
		}
	    }
	}
    }
    printf("%d\n",wofs[edx][edy]);
}
#define file(filen)\
    freopen(#filen ".in","r",stdin);\
    freopen(#filen ".out","w",stdout);
int main(){
    file(maze)
    int n,m,x,y;
    scanf("%d%d%d%d",&n,&m,&x,&y);
    for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	    scanf("%d",&map[i][j]);
	}
    }
    bfs(n,m,x-1,y-1);
}

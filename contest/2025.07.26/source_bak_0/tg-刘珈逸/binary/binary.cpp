#include<bits/stdc++.h>
using namespace std;
const int N=1050;
int n,m;
char c[N][N*3];
int tot=1;
#define fi first
#define se second
pair<int,int>pos[N];
void erase(int x){
	if(x>=(1<<m))return;
	c[pos[x].fi][pos[x].se]=0;
	if(!(x&1)){
		int cx=pos[x].fi+1,cy=pos[x].se+1;
		while(c[cx][cy]=='/'){
			c[cx][cy]=0;
			cx++,cy++;
		}
	}else{
		int cx=pos[x].fi+1,cy=pos[x].se-1;
		while(c[cx][cy]=='\\'){
			c[cx][cy]=0;
			cx++,cy--;
		}
	}
	erase(x<<1);
	erase(x<<1|1);
}
void work(int x,int len){
	if(!(x&1)){
		int cx=pos[x].fi+1,cy=pos[x].se+1;
		while(len--){
			c[cx][cy]='/';
			cx++,cy++;
		}c[cx][cy]='o';
		pos[x>>1]={cx,cy}; 
	}else{
		int cx=pos[x].fi+1,cy=pos[x].se-1;
		while(len--){
			c[cx][cy]='\\';
			cx++,cy--;
		}
	}
}
int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	scanf("%d%d",&m,&n);
	int cur=0;
	for(int i=(1<<m-1);i<1<<m;i++){
		cur++;
		if(i&1)cur+=2;
		c[tot][cur]='o';pos[i].fi=1,pos[i].se=cur; cur++;
	}
	for(int i=m;i>=2;i--){
		int len=(pos[(1<<i)-1].se-pos[(1<<i)-2].se);
		len=(len-1)/2;tot+=len+1;
		for(int j=(1<<i)-1;j>=(1<<i-1);j--)work(j,len);
	}
	while(n--){
		int x,y;scanf("%d%d",&x,&y);
		erase((1<<x-1)-1+y);
	}
	for(int i=1;i<=tot;i++)for(int j=1;j<=cur;j++)if(!c[i][j])c[i][j]=' ';
	for(int i=tot;i>=1;i--){
		for(int j=1;j<=cur;j++)putchar(c[i][j]);
		putchar('\n');
	}
	return 0;
}

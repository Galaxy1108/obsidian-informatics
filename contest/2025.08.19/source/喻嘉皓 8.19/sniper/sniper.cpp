#include<bits/stdc++.h>
#define Max(a,b) a=max(a,b)
#define pb push_back
using namespace std;
int n;
struct Per{
	int w,u,t;
}per[8010];
struct Pair{
	int ad,w;
};
vector<Pair> g[25010];
int val[22];
void init(){
	val[1]=val[2]=100;
	val[3]=97; val[4]=96;
	val[5]=95; val[6]=90;
	val[7]=85; val[8]=80; val[9]=82; 
	val[10]=78; val[11]=75; val[12]=70;
	val[13]=65; val[14]=55; val[15]=50;
	val[16]=15; val[17]=12; val[18]=10;
	val[19]=8;  val[20]=5;  val[21]=2;
} 
int f[25010][21][2];
int bk[21];//记录当前时刻位置的人 
bool vis[21];
int maxx;
int main(){
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		cin>>per[i].w>>per[i].u>>per[i].t;
		g[per[i].t].pb({per[i].u,val[per[i].w]});
	}
	memset(f,0xcf,sizeof(f));
	for(int j=1;j<=20;j++) f[1][j][0]=0;
	for(int i=1;i<=per[n].t;i++){
		bool flag=0;
		for(Pair to:g[i]){
			bk[to.ad]+=to.w;
			if(to.w==50) vis[to.ad]=flag=1;
		}
		if(flag){
			for(Pair to:g[i]){
				if(!vis[to.ad]) bk[to.ad]=0;
			}
		}
		for(int j=1;j<=20;j++){
//			if(flag&&!vis[j]) continue;//保证一定打死狙击手 
			if(bk[j]) Max(f[i+1][j][1],f[i][j][0]+bk[j]);
//			if(flag&&vis[j]) break;//如果有狙击手，只能打狙击手 
			//有狙击手的时候不能做别的操作，必须打狙击手或者移动到狙击手的位置 
			if(!flag){
				Max(f[i+1][j][0],f[i][j][1]);
				Max(f[i+1][j][0],f[i][j][0]);				
			}

			if(j<20){
				if(!flag) Max(f[i+1][j+1][0],f[i][j][0]);
				if(bk[j+1]) Max(f[i+1][j+1][1],f[i][j][0]+bk[j+1]);
			}
			if(j<19){
				if(!flag) Max(f[i+1][j+2][0],f[i][j][0]);
				if(bk[j+2]) Max(f[i+1][j+2][1],f[i][j][0]+bk[j+2]);
			}
			if(j>1){
				if(!flag) Max(f[i+1][j-1][0],f[i][j][0]);
				if(bk[j-1]) Max(f[i+1][j-1][1],f[i][j][0]+bk[j-1]);
			}
			if(j>2){
				if(!flag) Max(f[i+1][j-2][0],f[i][j][0]);
				if(bk[j-2]) Max(f[i+1][j-2][1],f[i][j][0]+bk[j-2]);
			}
		}
		for(Pair to:g[i]) bk[to.ad]=vis[to.ad]=0;
	}
	int ans=0;
	for(int j=1;j<=20;j++){
		Max(ans,f[per[n].t+1][j][0]);
		Max(ans,f[per[n].t+1][j][1]);
	}
	cout<<ans;
	return 0;
}


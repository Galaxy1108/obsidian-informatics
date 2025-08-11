#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int tag[110][2010];
int ans[2010][2010];
int D[110],H;
void dfs(int x,int y,int p,int q,int L,int R){
	if(tag[x][y]) return;
	ans[p][q]=1;
	if(x==n) return;
	int idl=(L+q-1)>>1,idr=(q+1+R)>>1;
	if(x==n-1) idl=L,idr=R;
	if(!tag[x+1][y*2-1]){
		int f=p,g=q;
		while(1){
			++f,--g;
			if(g==idl) break;
			ans[f][g]=2;
		}
		dfs(x+1,y*2-1,f,g,L,q-1);
	}
	if(!tag[x+1][y*2]){
		int f=p,g=q;
		while(1){
			++f,++g;
			if(g==idr) break;
			ans[f][g]=3;
		}
		dfs(x+1,y*2,f,g,q+1,R);
	}
	return;
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	scanf("%d%d",&n,&m);
	D[1]=1,D[2]=5;
	for(int i=3;i<=10;++i) D[i]=D[i-1]*2+1;
	H=D[n]/2+1;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		tag[x][y]=1;
	}
	dfs(1,1,1,(D[n]+1)>>1,1,D[n]);
	for(int i=1;i<=H;++i){
		for(int j=1;j<=D[n];++j){
			if(ans[i][j]==0) putchar(' ');
			if(ans[i][j]==1) putchar('o');
			if(ans[i][j]==2) putchar('/');
			if(ans[i][j]==3) putchar(92);
		}
		putchar('\n');
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,p[N];
int st[10][N];
int chk(int x,int y){return x>y?x-y:y-x;} 
int tmp[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&st[0][i]);
	for(int i=1;i<=8;i++)for(int j=1;j+(1<<i)-1<=n;j++)
		st[i][j]=chk(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	while(m--){
		int op,x,y;scanf("%d%d%d",&op,&x,&y);
		if(op==1){
			st[0][x]=y;
			for(int i=1;i<=8;i++)for(int j=max(1,x-(1<<i)+1);j<=min(x,n-(1<<i)+1);j++)
				st[i][j]=chk(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		}else{
			if(y<=8)printf("%d\n",st[y][x]);
			else{
				y-=8;
				for(int i=0;i<(1<<y);i++)tmp[i]=st[8][x+i*256];
				for(int i=1;i<=y;i++)for(int j=0;j<(1<<y);j+=(1<<i))
					tmp[j]=chk(tmp[j],tmp[j+(1<<(i-1))]);
				printf("%d\n",tmp[0]);
			}
		}
	}
	return 0;
}
/*
类似根号分治 小的预处理 大的现场算 
*/

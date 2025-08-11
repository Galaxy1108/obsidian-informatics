#include<bits/stdc++.h>
using namespace std;
#define re register

int m,n;
int wei[1<<10];
int vis[1<<10];
//int l[1<<10],r[1<<10];
int ma[1540][800];
int h[1<<10];
//int last[1<<10];
//re int stop[800];
//register

void build(re int p,re int dep){
	while(dep>=m)return;
	build((p<<1),dep+1);
	build((p<<1)+1,dep+1);
	wei[p]=(wei[(p<<1)]+wei[(p<<1)+1])>>1;
	return;
}


void cover(re int p,re int dep){
	ma[h[p]][wei[p]]='o';
	while(dep>=m)return;
	if(!vis[(p<<1)]){
		for(re int i=1;i<=(wei[p]-wei[(p<<1)]-1);i++){
			ma[h[p]+i][wei[p]-i]='/';
		}
		h[(p<<1)]=h[p]+wei[p]-wei[(p<<1)];
		cover((p<<1),dep+1);
	}
	if(!vis[(p<<1)+1]){
		for(re int i=1;i<=(wei[(p<<1)+1]-wei[p]-1);i++){
			ma[h[p]+i][wei[p]+i]=92;
		}
		h[(p<<1)+1]=h[p]+wei[p]-wei[(p<<1)];
		cover((p<<1)+1,dep+1);
	}
	return;
}

int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	scanf("%d%d",&m,&n);
//	l[1]=0;r[1]=-1;
	re int xp=0;
//	for(int now=1;now<m;now++){
//		int s=(1<<now);int t=(1<<(now+1))-1;
//		l[s]=0;r[s]=s+1;l[t]=t-1;r[t]=-1;
//		for(int i=s+1;i<t;i++){
//			l[i]=i-1;r[i]=i+1;
//		}
//	}
	wei[(1<<(m-1))]=1;
	for(int i=(1<<(m-1))+1;i<=(1<<m)-1;i++){
		if(!(i%2)){
			wei[i]=wei[i-1]+2;
		}
		if(i%2){
			wei[i]=wei[i-1]+4;
		}
//		xp=max(xp,wei[i]);
	}
	xp=wei[(1<<m)-1];
//	for
	
//	printf("%d\n",xp);
//	for(;;);
	
	build(1,1);
	int x,y;
	for(re int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		vis[((1<<(x-1))+y-1)]=1;
	}
	h[1]=1;
	cover(1,1);
	for(re int i=1;i<=xp/2+1;i++){
		for(int j=1;j<=xp;j++){
			if(ma[i][j]==0)putchar(' ');
			else putchar(ma[i][j]);
		}
		printf("\n");
	}
	return 0;
} 

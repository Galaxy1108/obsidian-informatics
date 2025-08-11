#include <bits/stdc++.h>
using namespace std;
int n,m,fa[1100],h,g;
char by[1010][1100];
int kpow(int x){
	if(x==0) return 1;
	if(x==1) return 2;
	int tmp=kpow(x/2);
	tmp*=tmp;
	if(x%2==1) tmp*=2;
	return tmp;
}
void fzz(int x,int y){
	for(int i=y;i<=h-(h-y)/2;i++){
		for(int j=x+y-i;j<=x+i-y;j++){
			by[i][j]=32;
			if(i!=h-(h-y)/2) by[h-i+2][j]=32;
		}
	}
	return;
}
void fz(int x,int y){
	int xi=kpow(x);
	for(int i=1;i<=kpow(x-1);i++){
		int xx=(g-xi)/xi;
		fzz((xx+1)*(i*2-1),h-y+2);
	}
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(fa,1,kpow(n-1));
	h=kpow(n-2)*3;
	g=h*2;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=(g-i*2)/2;j++){
			by[i][j]=32;
			by[i][g-j]=32;
		}
	}
	for(int i=1;i<n-1;i++){
		int lg=kpow(i-1);
		lg=h/lg;
		fz(i,lg);
	}
	for(int i=1;i<=n;i++){
		by[h][(i-1)*6+1]='o';
		by[h][(i-1)*6+2]=32;
		by[h][(i-1)*6+3]=32;
		by[h][(i-1)*6+4]=32;
		by[h][(i-1)*6+5]='o';
		by[h][(i-1)*6+6]=32;
		by[h-1][(i-1)*6+3]=32;
		by[h-1][(i-1)*6+5]=32;
		by[h-1][(i-1)*6+6]=32;
	}
//	by[1][g/2]='o';
//	for(int i=2;i<h;i++){
//		for(int j=1;j<=g-1;j++){
//			if(by[i][j]==0){
//				if(by[i+1][j+1]!=32&&by[i+1][j-1]!=32) by[i][j]='o';
//				else if(by[i+1][j+1]!=32) by[i][j]='\\'; 
//				else by[i][j]='/';
//			}
//		}
//	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=g-1;j++){
			if(by[i][j]==0) printf("%d   ",by[i][j]);
			if(by[i][j]==32) printf("%d  ",by[i][j]);
			printf("%d ",by[i][j]);
		}
		printf("\n");
	}
	return 0;
}

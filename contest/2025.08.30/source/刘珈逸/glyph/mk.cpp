#include<bits/stdc++.h>
using namespace std;
mt19937 rd(time(0));
int get_rd(int l,int r){
	return rd()%(r-l+1)+l;
}
int main(){
	freopen("glyph.in","w",stdout);
	int n=300,m=2e5;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)printf("%d ",get_rd(1,1e9));puts("");
	}
	for(int i=1;i<=m;i++){
		int x1=get_rd(1,n),x2=get_rd(1,n),y1=get_rd(1,n),y2=get_rd(1,n);
		if(x1>x2)swap(x1,x2);
		if(y1>y2)swap(y1,y2);
		printf("%d %d %d %d\n",x1,x2,y1,y2);
	}
	return 0;
}

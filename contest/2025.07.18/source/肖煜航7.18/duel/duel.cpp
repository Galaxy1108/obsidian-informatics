#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int read(){
	int p=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') p=(p<<1)+(p<<3)+ch-'0',ch=getchar();
	return p;
}
const int N=2e5+5;
int n,Q,B;
int a[N];
int st[N][20];
int get(int x,int y){
	if(y<=B) return st[x][y];
	return abs(get(x,y-1)-get(x+(1<<(y-1)),y-1));
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read(),Q=read();
	B=log2(n);
	B>>=1;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) st[i][0]=a[i];
	for(int j=1;j<=B;j++) for(int i=1;i+(1<<j)-1<=n;i++) st[i][j]=abs(st[i][j-1]-st[i+(1<<(j-1))][j-1]);
	while(Q--){
		int op=read(),x=read(),y=read();
		if(op==1){
			st[x][0]=y;
			for(int j=1;j<=B;j++) for(int i=x;i&&(i+(1<<(j))-1)>=x;i--) st[i][j]=abs(st[i][j-1]-st[i+(1<<(j-1))][j-1]);
		}
		else{
			printf("%d\n",get(x,y));
		}
	}
	return 0;
}

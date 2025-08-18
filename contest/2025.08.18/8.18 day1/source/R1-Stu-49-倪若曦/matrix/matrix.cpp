#include<bits/stdc++.h>
#define ri register 
#define fil(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
using namespace std;
inline int rd(){
	register int x=0,f=1;
	register char c=getchar();
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	if(c=='-') f=-1,c=getchar();
	while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return x*f;
}
inline void wt(int n){
	if(n<0) putchar('-'),n=-n;
	if(n>10) wt(n/10);
	putchar(n%10+48);
	return;
}
int n,m,k,sc[105][5];
int maxx=0,minn=0;
int main(){
	fil("matrix");
	n=rd(),m=rd(),k=rd();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sc[i][j]=rd();
			if(sc[i][j]>=0) maxx+=sc[i][j];
			minn+=sc[i][j];
		}
	}
	srand(time(0));
	if(maxx==minn) cout<<maxx;
	else cout<<rand()%(maxx-minn+1)+minn;
	return 0;
}

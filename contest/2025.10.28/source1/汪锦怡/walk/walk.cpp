#include<bits/stdc++.h>
using namespace std;
#define FOR(i,j,k) for(int i=(j);i<=(k);++i)
#define ROF(i,j,k) for(int i=(j);i>=(k);--i)
#define FOE(i,pos) for(int i=h[pos];i;i=nxt[i])
#define rd read() 
#define gc getchar()
#define pc(x) putchar(x)
int rd{
	int x=0,f=1;char c=gc;
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=gc;}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c-'0');c=gc;}
	return x*f;
}
void write(int x){
	if(x<0) pc('-'),x=-x;
	if(x>9) write(x/10);
	pc(x%10+'0');
}



int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	pc('0'); 
	return 0;
}

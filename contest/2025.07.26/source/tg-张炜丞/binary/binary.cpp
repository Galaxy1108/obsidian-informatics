#include<bits/stdc++.h>
using namespace std;
const int N=3205,M=15;

int read(){
	int ans=0;
	char c=getchar();
	bool f=0;
	for(;!isdigit(c);c=getchar())c=getchar();
	for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
	return f?-ans:ans;
}

void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10|48);
}

short c[N][N];
int n,m,f[M];
bool vis[M][N];

void dfs(int d,int p,int x,int y){
	//cout<<" /dfs d:"<<d<<" p:"<<p<<" x:"<<x<<" y:"<<y<<endl;
	if(d==1){
		c[x][y]=3;return;
	}
	int px=x;
	c[x][y]=3;
	int ls=p*2-1,rs=p*2;
	if(!vis[d-1][ls]){
		int lx=px-1,ly=y+1;
		for(int i=1;i<f[d-1]+(d==2);--lx,++ly,++i){
			c[lx][ly]=1;
		}
		dfs(d-1,ls,lx,ly);
	}
	if(!vis[d-1][rs]){
		int rx=px+1,ry=y+1;
		for(int i=1;i<f[d-1]+(d==2);++rx,++ry,++i){
			c[rx][ry]=2;
			//cout<<" i:"<<i<<" x:"<<x+rx<<" y:"<<ry<<" c:"<<c[x+rx][ry]<<endl;
		}
		dfs(d-1,rs,rx,ry);
	}
}

signed main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	n=read();m=read();
	f[1]=1,f[2]=3;for(int i=3;i<=n;++i)f[i]=f[i-1]*2;
	for(int i=1,x,y;i<=m;++i){
		x=read();y=read();
		vis[n-x+1][y]=1;
	}
	dfs(n,1,f[n],1);
	for(int i=1;i<=f[n];++i){
		for(int j=1;j<f[n]*2;++j){
//			cout<<" i:"<<i<<" j:"<<j<<" c:"<<c[j][i]<<endl;
			if(c[j][i]==0)putchar(' ');
			else if(c[j][i]==1)putchar('/');
			else if(c[j][i]==2)putchar('\\');
			else putchar('o');
		}
		putchar('\n');
	}
	return 0;
}





























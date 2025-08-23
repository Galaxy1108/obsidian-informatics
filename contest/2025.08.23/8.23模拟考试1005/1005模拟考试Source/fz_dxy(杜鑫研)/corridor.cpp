#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<map>
#include<vector>
#include<queue>
using namespace std;
#define re int
inline int read(){
	int x=0,ff=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')ff=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	return x*ff;
}
int t,n,m,k;
namespace Sub0{
	bool a[5005][5005];
	void work(){
		memset(a,0,sizeof(a));
		n=read();m=read();k=read();
		int x,y;
		for(re i=1;i<=k;i++){
			x=read();y=read();a[x][y]=1;
		}
		int q=read(),w,p,u,v,xx,yy;
		while(q--){
			w=read();
			if(w==1){
				x=read();y=read();a[x][y]=1;continue;
			}
			x=read();y=read();p=read();
			if(!x)xx=1,yy=0,u=1,v=y;
			else xx=0,yy=1,u=x,v=1;
			while(23333){
				if(a[u][v]){
					swap(xx,yy);p--;if(!p)break;
				}
				u+=xx;v+=yy;
				if(u>n||v>m)break;
			}
			printf("%d %d\n",u,v);
		}
	}
}
int main(){
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	t=read();
	if(t==0||1){
		Sub0::work();return 0;
	}

	return 0;
}
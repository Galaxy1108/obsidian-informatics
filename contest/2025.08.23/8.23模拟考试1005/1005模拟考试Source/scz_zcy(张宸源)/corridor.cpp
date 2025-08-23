#include<bits/stdc++.h>
using namespace std;
int n,m;
bool a[20010][20010];
int pz,flag=0;
void ce(int x,int y,int fx,int cs){
	if(flag==1)return;
	int x1=x,y1=y;
	while(a[x1][y1]==0){
		if(fx==1){
			y1++;
			if(y1>m){
				flag=1;
				printf("%d %d\n",x1,m+1);
				return;
			}
		}
		if(fx==2){
			x1++;
			if(x1>n){
				flag=1;
				printf("%d %d\n",n+1,y1);
				return;
			}
		}
	}
	if(cs+1==pz){
		flag=1;
		printf("%d %d\n",x1,y1);
		return;
	}
	if(fx==1)ce(x1+1,y1,2,cs+1);
	else ce(x1,y1+1,1,cs+1);
}
int main(){
	freopen("corridor.in","r",stdin);
	freopen("corridor.out","w",stdout);
	int ty,k;
	scanf("%d%d%d%d",&ty,&n,&m,&k);
	for(int i=1;i<=k;i=i+1){
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		a[t1][t2]=1;
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i=i+1){
		int w;
		scanf("%d",&w);
		if(w==1){
			int t1,t2;
			scanf("%d%d",&t1,&t2);
			a[t1][t2]=1;
		}
		else{
			int sx,sy;
			scanf("%d%d%d",&sx,&sy,&pz);
			flag=0;
			if(sx==0)ce(sx,sy,2,0);
			else ce(sx,sy,1,0);
		}
	}
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
int h,w,a[1000010],b[1000010],d=0;
long long minn=0x3f3f3f3f3f3f;
void dfs(int x,int y,long long cnt){
	if(x==h&&y==w){
		minn=min(minn,cnt);
		return;
	}
	if(cnt>=minn&&cnt>=d) return;
	if(y<w) dfs(x,y+1,cnt+a[x]);
	if(x<h) dfs(x+1,y,cnt+b[y]);
	return;
}
int main(){
	freopen("kyoto.in","r",stdin);
	freopen("kyoto.out","w",stdout);
	scanf("%d%d",&h,&w);
	for(int i=1;i<=h;i++){
		scanf("%d",&a[i]);
		d+=a[i];
	}
	for(int i=1;i<=w;i++){
		scanf("%d",&b[i]);;
		d+=a[i];
	}
	dfs(1,1,0);
	printf("%lld",minn);
	return 0;
}

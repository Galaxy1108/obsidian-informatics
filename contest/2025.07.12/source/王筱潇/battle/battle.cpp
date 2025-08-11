#include <bits/stdc++.h> 
using namespace std;
struct node{
	int x,y,z;
}h[150010];
struct nodee{
	int x,y,z;
}hl[150010];
struct nodeee{
	int x,y,z;
}hll[150010];
bool cmp(node x,node y){
	return x.x>y.x;
}
bool cmp2(nodee x,nodee y){
	return x.y>y.y;
}
bool cmp3(nodeee x,nodeee y){
	return x.z>y.z;
}
int n,mx=1,my=1,mz=1,tot;
int main(){
	freopen("battle.in","r",stdin);
	freopen("battle.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&h[i].x,&h[i].y,&h[i].z);
		hl[i].x=h[i].x;
		hl[i].y=h[i].y;
		hl[i].z=h[i].z;
		hll[i].x=h[i].x;
		hll[i].y=h[i].y;
		hll[i].z=h[i].z;
	}
	sort(h+1,h+n+1,cmp);
	sort(hl+1,hl+n+1,cmp2);
	sort(hll+1,hll+n+1,cmp3);
	tot=n;
	int hf=1,hlf=1,hllf=1;
	while(h[hf].y>=hl[hlf].y||h[hf].z>=hll[hllf].z){
		hf++;
		tot--;
	}
	while(hl[hlf].x>=h[hf].x||hl[hlf].z>=hll[hllf].z){
		hlf++;
		tot--;
	}
	while(hll[hllf].x>=h[hf].x||hll[hllf].y>=hl[hlf].y){
		hllf++;
		tot--;
	}
	if(tot<=2){
		printf("-1");
		return 0;
	}
	printf("%d",h[hf].x+hl[hlf].y+hll[hllf].z);
	return 0;
}

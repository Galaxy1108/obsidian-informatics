#include<bits/stdc++.h>
#define int long long
#define N 200000
#define lowbit(x) (x&-x)
using namespace std;
int n,m,val[N+5],tree[N*4+5]={},opt,ux,uy,ans[N+5],flag=1,tree2[N+5]={};
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
inline void pushup(int p){tree[p]=abs(tree[p*2]-tree[p*2+1]);return;}
void build(int l,int r,int p){
	if(l==r){
		tree[p]=val[l];
		return;
	}
	int mid=(l+r)>>1ll;
	build(l,mid,p*2),build(mid+1,r,p*2+1);
	pushup(p);
	return;
}
void upd(int l,int r,int x,int v,int p){
	if(l==r){
		tree[p]=v;
		return;
	}
	int mid=(l+r)>>1ll;
	if(x<=mid)upd(l,mid,x,v,p*2);
	if(x>mid)upd(mid+1,r,x,v,p*2+1);
	pushup(p);
	return;
}
void bitupd(int x,int y){
	while(x<=n){
		tree2[x]^=y;
		x+=lowbit(x);
	}
	return;
}
int bitsum(int x){
	int sum=0;
	while(x){
		sum^=tree2[x];
		x-=lowbit(x);
	}
	return sum;
}
main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		val[i]=read(),bitupd(i,val[i]);
		if(val[i]!=0&&val[i]!=1)flag=0;
	}
	build(1,n,1);
	for(int i=1;i<=m;i++){
		opt=read(),ux=read(),uy=read();
		if(opt==1){
			bitupd(ux,val[ux]),bitupd(ux,uy);
			val[ux]=uy,upd(1,n,ux,uy,1);
			if(uy!=0&&uy!=1)flag=0;
		}
		else{
			if(flag)print(bitsum(ux+(1ll<<uy)-1)^bitsum(ux-1)),putchar('\n');
			else if(n==(1ll<<uy))print(tree[1]),putchar('\n');
			else{
				for(int j=ux;j<=ux+(1ll<<uy)-1;j++)ans[j]=val[j];
				for(int j=1;j<=uy;j++){
					for(int k=ux;k<=ux+(1ll<<uy);k+=(1ll<<(j))){
						ans[k]=abs(ans[k]-ans[k+(1ll<<(j-1))]);
					}
				}
				print(ans[ux]),putchar('\n');
			}
		}
	}
	return 0;
}

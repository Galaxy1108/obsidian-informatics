#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define MAXn (int)2e6+1
#define inf 2147483647
using namespace std;
int n,H[MAXn],k;
struct tree{
	int hmax,hmin;
};
LL mmax(LL x,LL y){return x>=y?x:y;}
LL mmin(LL x,LL y){return x<=y?x:y;}
tree T[4*MAXn];
LL build1(int i){
	if(i>=(1<<(k+1))) return 0;
	if(T[i].hmax) return T[i].hmax;
	T[i].hmax=mmax(build1(i*2),build1(i*2+1));
	return T[i].hmax;
}
LL build2(int i){
	if(i>=(1<<(k+1))) return inf;
	if(T[i].hmin!=inf) return T[i].hmin;
	T[i].hmin=mmin(build2(i*2),build2(i*2+1)); 
	return T[i].hmin;
}
LL find_hmax(int l,int r,int i,int j,int u){
	int m=(l+r)/2;
	if(l>i||j>r||u>=(1<<(k+1))) return 0;
	if(i==l&&r==j) return T[u].hmax;
	if(j<=m) return find_hmax(l,m,i,j,u*2);
	else if(i>m) return find_hmax(m+1,r,i,j,u*2+1);
	else return mmax(find_hmax(l,m,i,m,u*2),find_hmax(m+1,r,m+1,j,u*2+1));
}
LL find_hmin(int l,int r,int i,int j,int u){
	int m=(l+r)/2;
	if(l>i||r<j||u>=(1<<(k+1))) return 0;
	if(i==l&&r==j) return T[u].hmin;
	if(j<=m) return find_hmin(l,m,i,j,u*2);
	else if(i>m) return find_hmin(m+1,r,i,j,u*2+1);
	else return mmin(find_hmin(l,m,i,m,u*2),find_hmin(m+1,r,m+1,j,u*2+1));
}
LL sovle_fun(int i,int j){
	int Hmax,Hmin,Fun;
	Hmax=find_hmax(1,1<<k,i,j,1);
	Hmin=find_hmin(1,1<<k,i,j,1);
//	cout<<"["<<i<<','<<j<<"]"<<Hmax<<' '<<Hmin<<' '<<Hmax*Hmin*(j-i+1)<<endl;
	return Hmax*Hmin*(j-i+1);
}
int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&H[i]);
	int n1=n;
	while(n1){n1/=2,k++;} 
	if(n==1<<k) k--;
	for(int i=1; i<(1<<(k+1)); i++){
		T[i].hmin=inf;T[i].hmax=0;
	}
	for(int i=1; i<=n; i++){
		T[i+(1<<k)-1].hmax=T[i+(1<<k)-1].hmin=H[i];
	}
	build1(1);
	build2(1);
	LL FUNmax=0;
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++)
		FUNmax=mmax(FUNmax,sovle_fun(i,j));
	}
	printf("%lld",FUNmax);
	return 0;
}

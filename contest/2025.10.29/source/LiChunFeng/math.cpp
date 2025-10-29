#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)

using namespace std;
typedef long long llg;

llg A,B,a[1010];
int D;

llg gcd(llg x,llg y){
	int r=x%y;
	while(r) x=y,y=r,r=x%y;
	return y;
}

void work(){
	printf("%d\n",D);
	for(int i=1;i<D;i++) printf("%lld ",a[i]);
	printf("%lld",B);
	exit(0);
}

void dfs(int u){
	llg Aa=A,Bb=B,k=gcd(A,B),l,r;
	A/=k; B/=k; if(A==1) work();
	l=B/A; if(A*l<=B) l++;
	r=B*(D-u+1)/A; if(A*r<=B*(D-u+1)) r--;
	for(llg i=l;i<=r;i++){
		a[u]=i;
		A=Aa*i-Bb; B=Bb*i;
		dfs(u+1);
	}
	A=Aa;B=Bb;
}

int main(){
	File("math");
	scanf("%lld %lld",&A,&B);
	for(int i=1;;i++) D=i,dfs(1);
}

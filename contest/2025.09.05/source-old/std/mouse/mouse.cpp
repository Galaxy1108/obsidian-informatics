#include<bits/stdc++.h>
using namespace std;
double k[1005][1005];

double q(int x){
	return x*1.0;
}
double find(int a,int b)
{
	if(a==0) return 0;
	if(b==0) return 1;
	if(k[a][b]!=0) return k[a][b];
	k[a][b]=a/q(a+b);
	if(b>1){
		k[a][b]=k[a][b]+b/q(a+b)*(b-1)/q(a+b-1)*a/q(a+b-2)*find(a-1,b-2);
		if(b>2)k[a][b]=k[a][b]+b/q(a+b)*(b-1)/q(a+b-1)*(b-2)/q(a+b-2)*find(a,b-3);
	}
	return k[a][b];
}
int main(){
	freopen("mouse.in","r",stdin); 
	freopen("mouse.out","w",stdout); 
	int w,d;
	scanf("%d%d",&w,&d);
	printf("%.9lf",find(w,d));
	return 0;
} 

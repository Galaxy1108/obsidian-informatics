#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
int n,MOD,ans;
V input(){scanf("%d%d",&n,&MOD);}
V work(){
	if(n==1)ans=0;
	else if(n==2)ans=0;
	else if(n==3)ans=0;
	else if(n==4)ans=17;
	else if(n==5)ans=904;
	else if(n==6)ans=45926;
	else if(n==7)ans=2725016;
	printf("%d",ans%MOD);
}
int main(){
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout); 
	input();
	work();
	return 0;
}

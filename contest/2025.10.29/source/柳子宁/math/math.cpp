#include<bits/stdc++.h>
using namespace std;
long long A,B;
int a[1010],top,Tag;
void dfs(long long A,long long B,int dep,int lst){
	if(Tag) return;
	if(A<0) return;
	if(A==0){
		Tag=1;
		printf("%d\n",top);
		for(int i=1;i<=top;++i) printf("%d ",a[i]);
		return;
	}
	long long g=__gcd(A,B);
	A/=g,B/=g;
	if(A==1&&B>a[top]){
		a[++top]=B,Tag=1;
		printf("%d\n",top);
		for(int i=1;i<=top;++i) printf("%d ",a[i]);
		--top;
		return;
	}
	if(dep==1) return;
	if(B>1e9) return; 
	for(int i=lst+1;i<=2000;++i){
		a[++top]=i;
		dfs(A*i-B,B*i,dep-1,i);
		--top;
		if(Tag) return;
	}
}
int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	
	scanf("%lld%lld",&A,&B);
	for(int dep=1;;++dep){
		dfs(A,B,dep,0);
		if(Tag) break; 
	}
	return 0;
} 

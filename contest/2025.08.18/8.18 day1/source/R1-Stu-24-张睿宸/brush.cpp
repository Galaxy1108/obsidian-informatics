#include<bits/stdc++.h>
#define ll unsigned long long
#define F(i,a,b) for(int i(a);i<=b;++i)
#define R(i,a,b) for(int i(a);i>=b;--i)
#define _ 0
using namespace std;
int n,m,cost[10001],book[10001];
ll res,best;
inline int input(){
	int x;char ch;
	for(ch=getchar();!isdigit(ch);ch=getchar());
	for(x=0;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
void dfs(int step){
	if(res>=best) return;
	if(step==n+1){
		F(i,m,n) if(book[i]<2) return;
		best=res; 
		return;
	}
	dfs(step+1);
	res+=cost[step];
	F(i,0,m-1) ++book[step+i];
	dfs(step+1);
	F(i,0,m-1) --book[step+i];
	res-=cost[step];
	return;
}
int main(){
	freopen("brush.in","r",stdin);
	freopen("brush.out","w",stdout);
	n=input(),m=input(),best=-1;
	F(i,1,n) cost[i]=input();
	dfs(1);
	cout<<best;
	return ~~(0^_^0);
} 

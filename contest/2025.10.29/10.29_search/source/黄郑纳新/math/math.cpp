#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,ans[1000010],flag=0;
inline void dfs(int x,int y,int op,int lst){
	if(flag)return;
	if(x==0){
		flag=1;
		for(int i=1;i<op;i++)printf("%lld ",ans[i]);
		return;
	}
	for(int i=lst+1;;i++){
		if(x*i>=y){
			x*=i;
			x-=y;
			y*=i;
			x/=__gcd(x,y);
			y/=__gcd(x,y);
			ans[op]=i;
			dfs(x,y,op+1,i);
		}
	}
}
signed main(){
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	dfs(a,b,1,0);
	return 0;
}

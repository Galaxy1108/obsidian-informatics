#include <bits/stdc++.h>
using namespace std;
#define N 405
#define INF 0x3f3f3f3f
int n,c[3];
char s[N];
namespace sub1{
int t[N],ans;
int check(){
	int res=0;
	// for(int i=1;i<=n;i++){
	// 	cerr<<t[i]<<' ';
	// }
	// cerr<<'\n';
#define getval(val) \
	for(int i=1,j=1;i<=n&&j<=n;i++,j++){ \
		while(i<=n&&s[i]!=((val)^48))i++; \
		while(j<=n&&t[j]!=val)j++; \
		if(i<=n&&j<=n)	\
			res+=abs(i-j); \
	}
	getval(0);
	getval(1);
	getval(2);
	return res>>1;
#undef getval
}
void dfs(int x){
	// cerr<<x<<'\n';
	if(x>n){
		// cerr<<"IN\n";
		ans=min(ans,check());
		return ;
	}
#define check(val) \
	if(c[val]>0&&t[x-1]!=val){	   \
		c[val]--;    \
		t[x]=val;    \
		dfs(x+1);    \
		c[val]++;    \
	}
	check(0);
	check(1);
	check(2);
#undef check
}
void solve(){
	ans=INF;
	t[0]=11;
	dfs(1);
	if(ans==INF){
		cout<<"-1";
	}
	else{
		cout<<ans;
	}
}
}
namespace sub2{
void solve(){
	int now=0,ans=0;
	for(int i=1;i<=n;i++){
		if((s[i]^48)==0){
			now++;
		}
		else{
			now=max(0,now-1);
			ans+=now;
		}
	}
	if(now>1){
		cout<<"-1";
	}
	else{
		cout<<ans;
	}
}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>(s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		c[s[i]^48]++;
	}
	if(n<=12){
		sub1::solve();
	}
	else if(c[0]>(n>>1)){
		sub2::solve();
	}
	else{
		sub1::solve();
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
typedef long long ll;
const int N=502;
const ll MOD=998244353;
int n,x,a[N],ans,b[N];
bool isb[N];
inline bool check(){
	int cnt=n;
	for(int i=1;i<=n;++i)isb[i]=0,b[i]=a[i];
	while(cnt>1){
		for(int i=1;i<=n;++i)
			b[i]-=(cnt-1);
		for(int i=1;i<=n;++i)
			if(b[i]<=0&&!isb[i]){
				--cnt;
				isb[i]=1;
			}
	}
	if(cnt==1)return 0;
	return 1;
}
void dfs(int loc){
	if(loc>n){
		if(check()){
			++ans;
		}
		return;
	}
	for(int i=1;i<=x;++i){
		a[loc]=i;
		dfs(loc+1);
		a[loc]=0;
	}
}
ll a3[N],d3[N];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d %d",&n,&x);
	if(n==3){
		a3[1]=1,d3[1]=1;
		for(int i=2;i<=x;++i){
			if(i%2==0)d3[i]=(d3[i-1]+6)%MOD;
			else d3[i]=d3[i-1];
			a3[i]=(a3[i-1]+d3[i]);
			//printf("%lld\n",a3[i]);
		}
		printf("%lld\n",a3[x]);
		return 0;
	}else if(n<=20){
		dfs(1);
		printf("%d\n",ans);	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

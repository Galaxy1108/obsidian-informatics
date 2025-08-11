#include <bits/stdc++.h>
using namespace std;
#define N 605 
#define MOD 1000000007
int n,a[N],val[N<<1];
long long ans=0;
void check(){
	
}
void dfs(int x){
	if(x==n+1){
		check();
		return ;
	}
	for(int i=1;i<=(n<<1);i++){
		for(int j=1;j<=(n<<1);j++){
			if(val[i]!=0&&val[j]!=0&&i==j)continue;
			val[i]=val[j]=x;
			dfs(x+1);
			val[i]=val[j]=0;
		}
	}
}
int main(){
	freopen("ruin.in","r",stdin);
	freopen("ruin.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	ans=0;
//	dfs(1);
	printf("%lld",ans);
	return 0;
}


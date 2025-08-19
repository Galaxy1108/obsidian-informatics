#include<bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define REP(a,b,c) for(int a = b;a <= c;++a)
#define DOW(a,b,c) for(int a = b;a >= c;--a)

int ans = -1e9,m,n,a[55][55];
bool bro[55][55];
void Dfs(int i,int j,int w,int k){
	if(bro[i][j]) return;
	if(k == m) ans = max(ans,w);
	bro[i][j] = true;
	Dfs(i+1,j,w+a[i+1][j],k+1);
	Dfs(i+1,j+1,w+a[i+1][j+1],k+1);
	bro[i][j] = false;
	Dfs(i+1,j,w,k);
	Dfs(i+1,j+1,w,k);
}

int main(){

	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	sc("%d%d",&n,&m);
	DOW(i,1,n) REP(j,1,n) sc("%d",&a[i][j]);
	Dfs(n,1,0,0);
	pr("%d",ans);

	return 0;
}


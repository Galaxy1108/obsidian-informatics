#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lw(x) x&(-x)

int dp[101][66000],val[105][105],n,seed;

int dfs(int zt,int man,int s){
//	cerr<<zt<<" "<<man<<endl;
	if(dp[man][zt])return dp[man][zt];
	if(s==2){
		int a=__lg(lw(zt))+1;
		zt-=lw(zt);
		int b=__lg(lw(zt))+1;
//		cerr<<"flow:"<<zt<<" "<<a<<" "<<b<<endl;
		if(val[man][a]>val[man][b])return dp[man][zt]=a;
		else return dp[man][zt]=b;
	}
	int mx=0,dis=0,nxt=man+1;
	for(int i=1,j=1;j<=n+1;i<<=1,j++){
		if(nxt>n)nxt%=n;
		if((zt&i)){
			int nw=dfs(zt-i,nxt,s-1);
			if(val[man][nw]>mx){
				mx=val[man][nw];
				dis=nw;
			}
		}
	}
	return dp[man][zt]=dis;
}

void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n+1;j++){
            val[i][j]=j;
            std::swap(val[i][j],val[i][rng()%j+1]);
        }
    }
}

signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>seed;
	if(seed!=0)gen(n,seed);
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n+1;j++)cin>>val[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		memset(dp,0,sizeof(dp));
		dfs((1<<(n+1))-1,i,n+1);
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=(1<<(n+1))-1;j++){
//				cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//			}
//		}
		cout<<dp[i][(1<<(n+1))-1]<<" ";
	}
	cout<<endl;
}

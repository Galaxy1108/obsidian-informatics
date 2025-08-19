#include<iostream>
#include<cstring>
using namespace std;
int ma[100][100],tick[100][100],dp[586][186],mem[110][110][60],n,m,ans=0;
void dfs(int s,int j,int deep,int sum){
	
//	if(mem[s][j][deep]<sum){
//		mem[s][j][deep]=sum;
//	}
//	else return;
	if(s==m){
		ans=max(ans,sum);
		return;
	}
	for(int k=2;k<=j;k++){
		if(tick[deep][k] && tick[deep][k-1]){
			tick[deep+1][k-1]=1;
			dfs(s+1,k-1,deep+1,sum+ma[deep+1][k-1]);
			tick[deep+1][k-1]=0;
	}
	}
	if(j!=0 && j<n-deep+1 && tick[deep-1][j+2] && tick[deep-1][j+1]){
		tick[deep][j+1]=1;
		tick[deep][j]=1;
		dfs(s+1,j+1,deep,sum+ma[deep][j+1]);
		tick[deep][j+1]=1;
		tick[deep][j]=0;
		dfs(s,j+1,deep,sum+ma[deep][j+1]-ma[deep][j]);
		tick[deep][j+1]=0;
	}
}
int main(){
	ios::sync_with_stdio(0);
	freopen("brike.in","r",stdin);
	freopen("brike.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			cin >> ma[i][j];
		}
	}
	for(int i=0;i<=n+1;i++)tick[0][i]=1;
	dfs(1,1,1,ma[1][1]);
	cout << ans;
	return 0;
} 
/*
5 12      
2 2 3 4 7
 8 2 7 6
  2 3 1
   4 9
    8
*/

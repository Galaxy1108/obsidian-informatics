#include <bits/stdc++.h>
using namespace std;
int n,cnt[3][114],dp[114][22][22][22],ans;
char c;
int main(){
	freopen("worker.in","r",stdin);
	freopen("worker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>c;
		cnt[0][i]=cnt[0][i-1];
		cnt[1][i]=cnt[1][i-1];
		cnt[2][i]=cnt[2][i-1];
		cnt[c-'A'][i]++;
	}
	if(n<=10){
		cout<<(cnt[0][n]?1:0)+(cnt[1][n]?1:0)+(cnt[2][n]?1:0);
		return 0;
	}
	memset(dp,0x3f,sizeof(dp));
	ans=0x3f3f3f3f;
	dp[10][cnt[0][10]][cnt[1][10]][cnt[2][10]]=0;
	for(int i=10;i<=n;++i){
		for(int j=0;j<=10;++j){
			for(int k=0;k<=10-j;++k){
				for(int l=0;l<=10-j-k;++l){
					int top0=min(n,i+j),top1=min(n,i+k),top2=min(n,i+l);
					if(j) dp[top0][cnt[0][top0]-cnt[0][i]][cnt[1][top0]-cnt[1][i]+k][cnt[2][top0]-cnt[2][i]+l]=min(dp[top0][cnt[0][top0]-cnt[0][i]][cnt[1][top0]-cnt[1][i]+k][cnt[2][top0]-cnt[2][i]+l],dp[i][j][k][l]+1);
					if(k) dp[top1][cnt[0][top1]-cnt[0][i]+j][cnt[1][top1]-cnt[1][i]][cnt[2][top1]-cnt[2][i]+l]=min(dp[top1][cnt[0][top1]-cnt[0][i]+j][cnt[1][top1]-cnt[1][i]][cnt[2][top1]-cnt[2][i]+l],dp[i][j][k][l]+1);
					if(l) dp[top2][cnt[0][top2]-cnt[0][i]+j][cnt[1][top2]-cnt[1][i]+k][cnt[2][top2]-cnt[2][i]]=min(dp[top2][cnt[0][top2]-cnt[0][i]+j][cnt[1][top2]-cnt[1][i]+k][cnt[2][top2]-cnt[2][i]],dp[i][j][k][l]+1);
				}
			}
		}
	}
	for(int i=0;i<=10;++i){
		for(int j=0;j<=10-i;++j){
			for(int k=0;k<=10-i-j;++k){
				ans=min(ans,dp[n][i][j][k]+(i?1:0)+(j?1:0)+(k?1:0));
			}
		}
	}
	cout<<ans;
	return 0;
}

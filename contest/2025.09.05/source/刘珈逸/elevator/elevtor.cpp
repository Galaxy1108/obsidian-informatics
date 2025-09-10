#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5,inf=0x3f3f3f3f;
int n,a[N],b[N];
typedef vector<int> arr;
map<arr,int>mp;
arr u[720];
int dp[N][720][9][2];
arr get(int a,int b,int c,int d){
	arr res;
	if(a^9)res.push_back(a);
	if(b^9)res.push_back(b);
	if(c^9)res.push_back(c);
	if(d^9)res.push_back(d);
	return res;
}
void chk(int&x,int y){
	if(x>y)x=y;
}
int main(){
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	int cnt=0;
	for(int i=0;i<=9;i++)for(int j=i;j<=9;j++)for(int k=j;k<=9;k++)for(int l=k;l<=9;l++){
		auto tmp=get(i,j,k,l);
		mp[tmp]=++cnt;
		u[cnt]=tmp;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",a+i,b+i),a[i]--,b[i]--;a[n+1]=inf; 
	memset(dp,0x3f,sizeof(dp));
	dp[0][cnt][0][0]=dp[0][cnt][0][1]=0;
	//0 上 1 下 
	for(int i=0;i<=n;i++)for(int S=1;S<=cnt;S++){
		for(int pos=0;pos<9;pos++)if(dp[i][S][pos][0]!=inf){
			arr tmp=u[S],now;
			for(int j:tmp)if(j!=pos)now.push_back(j);
			int cur=i+1;
			bool flag=(now.size()!=tmp.size());
			while(now.size()<=4){
				int id=mp[now];
				if(flag){
					chk(dp[cur-1][id][pos][0],dp[i][S][pos][0]);
					chk(dp[cur-1][id][pos][1],dp[i][S][pos][0]);
				}else if(pos!=8){
					chk(dp[i][id][pos+1][0],dp[i][id][pos][0]+1);
				}
				if(a[cur]!=pos)break;
				now.push_back(b[cur]);sort(now.begin(),now.end());
				cur++;flag=1;
			}
		}
		for(int pos=8;pos>=0;pos--)if(dp[i][S][pos][1]!=inf){
			arr tmp=u[S],now;
			for(int j:tmp)if(j!=pos)now.push_back(j);
			int cur=i+1;
			bool flag=(now.size()!=tmp.size());
			while(now.size()<=4){
				int id=mp[now];
				if(flag){
					chk(dp[cur-1][id][pos][0],dp[i][S][pos][1]);
					chk(dp[cur-1][id][pos][1],dp[i][S][pos][1]);
				}else if(pos){
					chk(dp[i][id][pos-1][1],dp[i][id][pos][1]+1);
				}
				if(a[cur]!=pos)break;
				now.push_back(b[cur]);sort(now.begin(),now.end());
				cur++;flag=1;
			}
		}
	}
	int ans=inf;
	for(int i=0;i<9;i++)chk(ans,dp[n][cnt][i][0]);
	printf("%d\n",ans+n*2);
	return 0;
}
/*
记dp[i][S][pos][u]表示目前已经接了i个人,要去的楼层状态为S,目前在第pos层,目前电梯里有u个人的方案数 
考虑转移顺序
再记上一次是上楼还是下楼 
*/

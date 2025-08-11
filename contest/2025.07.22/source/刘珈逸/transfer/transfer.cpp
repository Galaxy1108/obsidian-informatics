#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int n,k;
char s[N];
typedef pair<int,int>pii;
#define fi first
#define se second
queue<pii>q;
bool vis[1<<20];
int tmp1[N],tmp0[N],cur1,cur0;
bool check(int S){
	cur1=cur0=0;
	for(int i=0;i<n*2;i++)
		if(S>>i&1)tmp1[++cur1]=i;
		else tmp0[++cur0]=i;
	for(int i=1;i<=n;i++)if(tmp0[i]>tmp1[i])return 0;
	int cnt=0;
	for(int l=1,r;l<=n&&cnt<=k;l=r+1,cnt++){
		r=l;while(tmp1[l]>tmp0[r])r++;r--;
	}return cnt<=k;
}
int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1;i<=n*2;i++)s[i]-='A';
	int S=0;
	for(int i=0;i<n*2;i++)S|=s[i+1]<<i;
	q.push(pii{S,0});
	int ans=-1;
	while(q.size()){
		int T=q.front().fi,dis=q.front().se;q.pop();
		if(vis[T])continue;vis[T]=1;
		if(check(T)){
			ans=dis;
			break;
		}
		for(int i=0;i<n*2-1;i++){
			int a=T>>i&1,b=T>>(i+1)&1;
			if(a==b)continue;
			q.push(pii{T^(3<<i),dis+1});
		}
	}
	printf("%d\n",ans);
	return 0;
}
/*
dp[i][j]表示选了前i对(a,b),用了j次的最小值
一定是前i对互相匹配 只计算a移动的代价 用前缀和处理 
*/

#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
const int N=1e6+5,mod=1e9+7;
int n,k,b[20];
map<int,int>dp[20][2][2];
map<int,int>res;
int ans;
struct Node{
	int val,from,pos;
};
bool operator<(Node x,Node y){
	return x.val<y.val;
}
priority_queue<Node>q;
void dfs(int x,bool fl1,bool fl2){
	if(x==0){
		if(fl1&&fl2)for(auto it:dp[x][fl1][fl2])res[it.fi]+=it.se;
		return;
	}
	int L=fl1,R=b[x];
	if(fl2)R=9;
	for(int i=L;i<=R;i++){
		bool f1=fl1||i!=L,f2=fl2||i!=R;
		for(auto it:dp[x][fl1][fl2])
			dp[x-1][f1][f2][it.fi*max(i,1ll)]+=it.se;
	}
}
int num[N],cnt;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("find.in","r",stdin);
	freopen("find.out","w",stdout);
	scanf("%lld%lld",&n,&k);n++;
	int cur=0;
	while(n)b[++cur]=n%10,n/=10;
	dp[cur][0][0][1]++;
	for(int i=cur;i>=0;i--)for(int j=0;j<=1;j++)for(int k=0;k<=1;k++)dfs(i,j,k);
	for(auto it:res)num[++cnt]=it.se;
	sort(num+1,num+1+cnt,cmp);
	for(int i=1;i<=cnt;i++)q.push({num[1]*num[i],i,1});
	while(k--&&q.size()){
		Node t=q.top();q.pop();ans+=t.val;ans%=mod;
		if(t.pos==cnt)continue;
		t.pos++;
		t.val=num[t.from]*num[t.pos];
		q.push(t);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
dp[x][0/1][0/1][sum]:
当前是第x位 是否有前导0 是否达到上界 数位乘积是sum 个数 
*/

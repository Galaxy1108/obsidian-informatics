#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
int n,k;
map<int,int>dp[15][2][2];
struct Node{
	int w,p1,p2,val;
};
int v[15];
queue<Node>q;
vector<int>tmp;
struct UT{
	int cur,id,val;
};
bool operator<(UT x,UT y){
	return x.val<y.val;
}
priority_queue<UT>Q;
int ans;
signed main(){
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	scanf("%lld%lld",&n,&k);int N=n;n++;
	for(int i=1;i<=13;i++)v[i]=n%10,n/=10;
	q.push({13,0,0,1});dp[13][0][0][1]++;
	while(q.size()){
		Node x=q.front();q.pop();
		if(!x.w){
			if(x.p1&&x.p2)tmp.push_back(dp[x.w][x.p1][x.p2][x.val]);
			continue;
		}
		int L=1,R=9,v=dp[x.w][x.p1][x.p2][x.val];
		if(!x.p1)L=0;if(!x.p2)R=::v[x.w]; 
		for(int i=L;i<=R;i++){
			int p1=i||x.p1,p2=x.p2||i!=::v[x.w],val=x.val*max(1ll,i);
			if(!dp[x.w-1][p1][p2][val])q.push({x.w-1,p1,p2,val});
			dp[x.w-1][p1][p2][val]+=v;
		}
	}sort(tmp.begin(),tmp.end(),greater<int>());
	for(int i=0;i<tmp.size();i++)Q.push({0,i,tmp[0]*tmp[i]});
	while(k--&&Q.size()){
		UT x=Q.top();Q.pop();ans=(ans+x.val)%mod;
		x.cur++;if(x.cur==tmp.size())continue;
		Q.push({x.cur,x.id,tmp[x.cur]*tmp[x.id]});
	}printf("%lld\n",ans);
	return 0;
}
/*
数位dp
dp[x][y][0/1][0/1] :位数,乘积,前导0,上界 
245779898294
*/

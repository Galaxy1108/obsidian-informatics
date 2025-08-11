#include<cstdio>
#include<algorithm>
#include<unordered_map>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll n;
int k;
int a[15],len;
int idx;
unordered_map<ll,int> op;//把大的变成小的 
ll b[1000005];//小的对应的大的 
bool vis[15][9000];
void solve(int x,ll sum,bool limit){
	if(x==0){
		if(!op.count(sum)){
			op[sum]=++idx;
			b[idx]=sum;
		}
		return;			
	}
	if(vis[x][op[sum]]) return;
	vis[x][op[sum]]=1;
	int mx=9;
	if(limit) mx=a[x];
	for(int i=1;i<=mx;i++){
		solve(x-1,1ll*sum*i,limit&(i==mx));
	}
}
ll c[1000005];
ll f[15][100005];
ll dfs(int x,int v,bool limit){
	if(x==0){
		if(b[v]==1) return 1;
		else return 0;
	}
	if(!limit&&f[x][v]!=-1) return f[x][v];
	ll sum=0;
	int mx=9;
	if(limit) mx=a[x];
	for(int i=1;i<=mx;i++){
		if(b[v]%i==0) sum+=dfs(x-1,op[b[v]/i],limit&&(i==mx));
	}
	if(!limit) f[x][v]=sum;
	return sum;
}
int main(){
	freopen("gold.in","r",stdin);
	freopen("gold.out","w",stdout);
	scanf("%lld%d",&n,&k);
	ll t=n;
	while(t){
		a[++len]=t%10;
		t/=10;
	}
	for(int i=0;i<=len;i++){
		solve(i,1,(i==len));//直接去掉前导零 
	}
	memset(f,-1,sizeof f);
	for(int i=1;i<=idx;i++){
		for(int j=1;j<=len;j++){
			c[i]+=dfs(j,i,(j==len));
		}
	}
	sort(c+1,c+idx+1);
	reverse(c+1,c+idx+1);
	ll sum=0;
	priority_queue<pair<ll,pair<int,int> > > q;
	for(int i=1;i<=idx;i++){
		q.push({1ll*c[i]*c[1],{i,1}});
	}
	while(k--){
		sum=(sum+q.top().first%mod)%mod;
		pair<int,int> u=q.top().second;
		q.pop();
		if(u.second<idx){
			u.second++;
			q.push({1ll*c[u.first]*c[u.second],u});
		}
	} 
	printf("%lld",sum);
	return 0;
}

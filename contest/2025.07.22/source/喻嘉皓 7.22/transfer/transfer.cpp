#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1000010;
int n,K;
char S[2*N];
int L[N],R[N],cnt;
int ans,ans2=INT_MAX;
vector<int> t1,t2;
void init(){
	int x=0,y=0;
	int sum=0;
	R[0]=1;
	for(int i=1;i<=2*n;i++){
		if(S[i]=='A'){
			x++;	
			if(x==y){
				if(L[cnt]) R[cnt]=i;
			}
		}
		else{
			y++;
			if(y>x){
				sum+=y-x; 
				if(R[cnt]) L[++cnt]=i;
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		int op=1;
		for(int j=L[i];j<=R[i];j++){
			if(op) S[j]='A';
			else S[j]='B';
			op=1-op; 
		}
	}
	ans+=sum;
	for(int i=1;i<=2*n;i++){
		if(S[i]=='A') t1.pb(i);
	}
}
bool vis[2*N]; 
int count(char temp[]){
	for(int i=1;i<=2*n;i++) vis[i]=0;
	int sit=1;//标志着现在向右走 
	int it=0;//用指针指着下一个的起始位置
	int cnt=0;//记录歌的数量 
	int res=0;//记录目前这首歌有几个高音 
	for(int i=1;i<=2*n;i++){
		if(vis[i]) continue;
		//遇到A可以跳过，遇到B必须停止向右
		 if(sit){//目前在向右走 
		 	if(temp[i]=='A'){
		 		res++; vis[i]=1;
			}
			else{
				sit=0; i--;
			}
		 }
		 else{
		 	if(temp[i]=='A'){
		 		if(!it) it=i;
			}
			else{
				res--; vis[i]=1;
				if(!res) i=(it?it-1:i),cnt++,it=0,sit=1;
			}
		 } 
	}
	return cnt;
}
int dist(char temp[]){
	t2.clear();
	for(int i=1;i<=2*n;i++){
		if(temp[i]=='A') t2.pb(i);
	}
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=abs(t1[i]-t2[i]);
	}
	return sum;
}
char tmp[N];
void dfs(int now,int x,int y){
	if(x<y||x>n||y>n) return;
	if(now>2*n){
		if(x!=n||y!=n) return;
		if(count(tmp)<=K) ans2=min(ans2,dist(tmp));
		return;
	}
	tmp[now]='A';//代表向右
	dfs(now+1,x+1,y);
	tmp[now]='B';
	dfs(now+1,x,y+1); 
}
int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>K;
	cin>>S+1;
	init();
	if(count(S)<=K){
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans+ans2;
	return 0;
}


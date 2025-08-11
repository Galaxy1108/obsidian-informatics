#include<bits/stdc++.h>
using namespace std;
const int N=10;
int n,ans;
int op[(1<<N)+10],c[(1<<N)+10];
int F[(1<<N)+10][(1<<N)+10];
int sum[2][(1<<N)+10];
int L[(1<<N)+10];
int _2[N+1];
void init(){
	_2[0]=1;
	for(int i=1;i<=n;i++) _2[i]=_2[i-1]*2;
	for(int i=1;i<=(1<<n);i++){
		int z=0;
		int tmp=i;
		while(tmp%2==0){
			tmp/=2;
			z++;
		}
		L[i]=i-_2[i]+1;
	}
}
int getsum(){
	for(int i=1;i<=(1<<n);i++){
		for(int j=i+1;j<=(1<<n);j++){
			int k=0;
			int na=0,nb=0;
			for(int k=j;k<=n;k++){
				if(L[k]<=i){
					na=sum[0][k]-sum[0][L[k]]-1;
					nb=sum[1][k]-sum[1][L[k]]-1;
					break;
				}
			}
			if(op[i]==0&&op[j]==0) k=2;
			else if(op[i]==0&&op[j]==1) k=1;
			else if(op[i]==1&&op[j]==0) k=1;
			else k=0;
			if(na>=nb) k=2-k;
			ans+=k*F[i][j];
		}
	}
}
void dfs(int now,int Sum){
	if(now>(1<<n)){
		ans=min(ans,getsum()+Sum);
		return;
	}
	sum[op[now]][now]=sum[op[now]][now-1];
	sum[!op[now]][now]=sum[!op[now]][now-1];
	sum[op[now]][now]++;
	dfs(now+1,Sum);
	sum[op[now]][now]--;
	Sum+=c[now]; op[now]=1-op[now];
	sum[op[now]][now]++;
	dfs(now+1,Sum);
	sum[op[now]][now]--;
}
int main(){
	freopen("cost.in","r",stdin);
	freopen("cost.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=(1<<n);i++) cin>>op[i];
	for(int i=1;i<=(1<<n);i++) cin>>c[i];
	for(int i=1;i<=(1<<n);i++){
		for(int j=1;j+i<=(1<<n);j++){
			cin>>F[i][i+j];
		}
	}
	dfs(1,0);
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
string st[50];
int pos[100];
int sign[100];
int N;
int flag=0;
void dfs(int cnt){
	if(cnt>N){
		flag=1;
		for(int i=1;i<=2*N;i++){
			cout<<st[pos[i]]<<'\n';
		}
	}
	else{
		for(int i=1;i<=N;i++){
		if(sign[i]) continue;
		if(flag) break;
		sign[i]=1;
		for(int j=1;j<=2*N;j++){
			if(pos[j]) continue;
			if(j+i+1>2*N) continue;
			if(pos[j+i+1]) continue;
			pos[j]=i;
			pos[j+i+1]=i;
			dfs(cnt+1);
			pos[j]=0;
			pos[j+i+1]=0;
		}
		sign[i]=0;
		return ;
	}
	}
	
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>st[i];
	}
	dfs(1);
	return 0;
} 

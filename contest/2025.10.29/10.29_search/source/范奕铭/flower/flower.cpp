#include<bits/stdc++.h>
using namespace std;
int N,w[105],v[45];
string s[45];
void dfs(int hao,int pos){
	if(pos>2*N) return;
	if(hao==N){
		for(int i=1;i<=2*N;i++) cout<<s[w[i]]<<endl;
		exit(0);
	}
	if(w[pos]){
		dfs(hao,pos+1);
		return;
	}
	for(int i=1;i<=N;i++){
		if(v[i]) continue;
		if(w[pos+i+1]) continue;
		if(pos+i+1>2*N) break;
		v[i]=1; w[pos]=i; w[pos+i+1]=i;
		dfs(hao+1,pos+1);
		v[i]=0; w[pos]=0; w[pos+i+1]=0;
	}
	return;
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++) cin>>s[i];
	dfs(0,1);
	return 0;
}

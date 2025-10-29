#include<bits/stdc++.h>
using namespace std;
int fa[305];
vector <int> son[305];
int siz[305];
int dep[305];
void dfs(int x){
	/*if(son[x].size()==0){
		siz[x]=1;
		return ;
	}
	else{*/
	siz[x]=1;
		for(int i=0;i<son[x].size();i++){
		int u=son[x][i];
		dep[u]=dep[x]+1;
		dfs(u);
		siz[x]+=siz[u];
	    }
	
	
}
long long ans;
queue <int> q;
void bfs(){
	
	while(q.size()){
		int x=q.front();
		int maxn=0;
	    int pos=0;
	    for(int i=0;i<son[x].size();i++){
		int u=son[x][i];
		if(siz[u]>maxn){
			maxn=siz[u];
			pos=u;
		}
	    }
	    ans-=maxn;
	    for(int i=0;i<son[x].size();i++){
	    	int u=son[x][i];
	    	if(u!=pos){
	    		q.push(u);
			}
		}
		q.pop();
	}
	
}
int main(){
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	int N,P;
	cin>>N>>P;
	for(int i=1;i<=P;i++){
		int a,b;
		cin>>a>>b;
		fa[b]=a;
		son[a].push_back(b);
	}
	dep[1]=0;
	memset(siz,1,sizeof(siz));
	dfs(1);
	q.push(1);
	ans=N;
	bfs();
	cout<<ans;
	return 0;
}


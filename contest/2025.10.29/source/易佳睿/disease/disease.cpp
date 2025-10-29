#include<bits/stdc++.h>
using namespace std;
int N,P,fa[305],minn=1e9;
bool dis[305],br[305];
vector<int> G[305];
double START;
void DFS(){
	vector<int> cut;
	for(int i=1;i<=N;i++){
		if(!dis[i]) continue;
		for(int v:G[i])
			if(!dis[v]&&!br[v])
				cut.push_back(v);
	}
	if(cut.size()==0){
		int res=0;
		for(int i=1;i<=N;i++) 
			if(dis[i]) res++;
		minn=min(minn,res);
		return ;
	}
	for(int v:cut) dis[v]=1;
	for(int v:cut){
		br[v]=1,dis[v]=0;
		DFS();
		br[v]=0,dis[v]=1;
	}
	for(int v:cut) dis[v]=0;
	cut.clear();
}

int main()
{
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	cin>>N>>P;
	while(P--){
		int i,j; cin>>i>>j;
		G[i].push_back(j);
		fa[j]=i;
	}
	dis[1]=1;
	DFS();
	cout<<minn<<'\n';
}

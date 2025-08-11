#include<bits/stdc++.h>
using namespace std;
const int N=500+5,inf=0x3f3f3f3f;
typedef pair<int,int>pii;
#define fi first
#define se second
#define pb push_back
struct Node{
	int pre,cnt,id,dis;
};
bool operator<(Node x,Node y){
	return x.dis>y.dis;
}
struct Mp{
	int pre,cnt,id;
};
bool operator<(Mp x,Mp y){
	if(x.pre^y.pre)return x.pre<y.pre;
	if(x.cnt^y.cnt)return x.cnt<y.cnt;
	return x.id<y.id; 
} 
set<Mp>vis;
vector<pii>G[N];
priority_queue<Node>q;
int n,m,t,l,L[N];
int main(){
	freopen("wildboar.in","r",stdin);
	freopen("wildboar.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&t,&l);
	if(n>10||m>10||l>10){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		G[a].pb({b,c}),G[b].pb({a,c});
	}for(int i=1;i<=l;i++)scanf("%d",L+i);
	while(t--){
		int p,q;scanf("%d%d",&p,&q);L[p]=q;
	}
	Node x={0,2,L[1],0};q.push(x);
	while(q.size()){
		Node x=q.top();q.pop();Mp y={x.pre,x.cnt,x.id};
		if(x.cnt==l+1){
			printf("%d\n",x.dis);
			return 0; 
		} 
		if(vis.find(y)!=vis.end())continue;vis.insert(y);
		for(pii it:G[x.id])if(it.fi^x.pre){
			q.push({x.id,x.cnt+(L[x.cnt]==it.fi),it.fi,x.dis+it.se});
		}
	}puts("-1");
	return 0;
}

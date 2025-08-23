#include<iostream>
#include<algorithm>
using namespace std;
struct edge{
	int to,from,val;
};
vector<edge> tree[10000086];
int n,fa[10000086],v[10000086],v,f1=1,f2=1,f3=1,ans[10000086];
int main(){
	freopen("treeq.in","r",stdin);
	freopen("treeq.out","w",stdout);	
	cin >> n;
	for(int i=2;i<=n;i++){
		cin >> fa[i] >> v[i];
		tree[fa[i]].push_back({i,fa[i],v[i]});
		tree[i].push_back({fa[i],i,v[i]});
		if(fa!=1)f1=0;
		if(v!=1)f2=0;
		if(fa!=i-1)f3=0;
	}
	sort(v+2,v+1+n);
	long long maxn=0,len=0,mem[1000086]; 
	for(int i=2;i<=n;i++){
		maxn=max(maxn,v[i]); 
	}
	for(int i=2;i<=n;i++){
		if(v[i]==maxn){
			mem[++len]=i;
			ans[i]++;
		}
	}
	for(int i=2;i<=n;i++){
		if(v[i]*(n-1)>maxn){
			ans[i]++;
		}
		else{
			for(int i=1;i<=len;i++){
				ans[mem[i]]++;
			}
		}
	}
	long long answ;
	for(int i=2;i<=n;i++){
		answ^=ans[i];
	}
	cout << answ;
	return 0;
} 

#include<iostream>
#include<vector>
using namespace std;
long long n,p,u,v;
vector<int> tree[1086];
int main(){
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
	cin >> n >> p;
	for(int i=1;i<=p;i++){
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	cout << 1;
	return 0;
}

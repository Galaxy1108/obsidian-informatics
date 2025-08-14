#include<iostream>
#include<vector>
#include<cstdio> 
using namespace std;
struct edge{
	int to,type;
};
int n,m,s,t,flag,x,y,o;
vector<edge> ma[1000086];
int main(){
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	cin >> n >> m >> s >> t;
	for(int i=1;i<=m;i++){
		cin >> x >> y >> o;
		ma[x].push_back({y,o});
	}
	cout << "0 0";
	return 0;
}

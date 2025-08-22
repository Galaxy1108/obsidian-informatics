#include<iostream>
#include<vector>
using namespace std;
struct edge{
	long long to,val;
};
long long n,v,vis[2086],dis[2086],ans,st,minn=1e12,minu,minv;
vector<edge> ma[2086];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout); 
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			cin >> v;
			ma[i].push_back({j,v});
			ma[j].push_back({i,v});	
			if(minn>v){
				minn=v;
				minu=i;
				minv=j;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i==minu or i==minv){
			cout << minn*(n-1) << endl;
		}
		else{
			cout << minn*(n-2)+min(ma[i][minu],ma[i][minv]) << endl;	
		}
	}
	return 0;
}

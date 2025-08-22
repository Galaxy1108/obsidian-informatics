#include <random>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int n,seed,a[N][N],b[N][N];
bool vis[N][N];
int nw[N];
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
signed main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>seed;
	if(seed){
		gen(n,seed);
	}else{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n+1;j++){
				cin>>a[i][j];
			}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
			b[i][a[i][j]]=j;
	for(int i=1;i<=n;i++)
		nw[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int k=(j-i)%n+n;
			if(k>n){
				k-=n;
			}
			while(vis[j][b[k][nw[k]]]){
				nw[k]++;
			}
			vis[j][b[k][nw[k]]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++)
			if(!vis[i][j])cout<<j<<" ";
	}
	cout<<"\n";
	return 0;
}


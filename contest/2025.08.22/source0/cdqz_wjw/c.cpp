#include<bits/stdc++.h>
using namespace std;
const int MAXN=5010;
int a[MAXN][MAXN];
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
int n,seed;
int fi[MAXN][MAXN];
bool vis[MAXN];
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>seed;
	if(seed==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n+1;j++){
				cin>>a[i][j];
			}
		}
	}
	else gen(n,seed);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++){
			fi[i][a[i][j]]=j;
		}
//		for(int j=1;j<=n+1;j++)cout<<fi[i][j]<<" ";
//		cout<<"\n";
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++)vis[j]=0;
		int now=i;
		for(int j=1;j<=n;j++,now=now%n+1){
			for(int k=1;k<=n+1;k++){
				if(!vis[fi[now][k]]){
					vis[fi[now][k]]=1;break;
				}
			}
		}
		for(int j=1;j<=n+1;j++){
			if(!vis[j]){
				cout<<j<<" ";break;
			}
		}
	}
	return 0;
}

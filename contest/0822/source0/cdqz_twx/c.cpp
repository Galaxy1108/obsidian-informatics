#include<bits/stdc++.h>
using namespace std;
const int MAXN=5010;
int a[MAXN][MAXN];
int reva[MAXN][MAXN];
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
int n, seed;
int main(){
	freopen("c.in", "r",stdin);
	freopen("c.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>seed;
	if(seed==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n+1;j++){
				cin>>a[i][j];
			}
		}
	}else{
		gen(n, seed);
	}
	//保证所有 ai 是一个长度为 n + 1 的排列。
	//?....................................!
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++){
			reva[i][a[i][j]] = j;
		}
	}
	int vis[MAXN];
	for(int i=1;i<=n;i++){
		memset(vis, 0, sizeof vis);
		for(int j=i, cnt=1;cnt<=n;j=j%n+1, cnt++){
			int minwant;
			for(minwant=1;minwant<=n;minwant++){
				if(vis[reva[j][minwant]]==0){
					break;
						
				} 
				
			}
			
			vis[reva[j][minwant]] = 1;
			
		}
		for(int k=1;k<=n+1;k++){
			if(vis[k]==0) cout<<k<<" ";
		}
	}
	return 0;
}

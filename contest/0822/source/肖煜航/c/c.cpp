#include<cstdio>
#include<algorithm>
#include<random>
#include<cstring>
using namespace std;
const int N=5010;
int a[N][N];
void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
int n,sed;
int f[1<<17];
int dfs(int x,int st){
	if(x==n+1) x=1;
	if(f[st]!=-1) return f[st];
	int res=0;
	int cnt=0;
	for(int i=1;i<=n+1;i++) if(st&(1<<(i-1))) cnt++;
	if(cnt==2){
		int mx=0;
		for(int i=1;i<=n+1;i++){
			if(st&(1<<(i-1))){
				if(mx<a[x][i]){
					mx=a[x][i];
					res=i;
				} 
			}
		}
	}
	else{
		int mx=0;
		for(int i=1;i<=n+1;i++){
			if(st&(1<<(i-1))){
				int o=dfs(x+1,st-(1<<(i-1)));
				if(a[x][o]>mx){
					mx=a[x][o];
					res=o;
				}
			}
		}
	}
	return f[st]=res;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d%d",&n,&sed);
	if(sed==0){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n+1;j++) scanf("%d",&a[i][j]);
		}
	}
	else{
		gen(n,sed);
	}
	for(int i=1;i<=n;i++){
		memset(f,-1,sizeof f);
		printf("%d ",dfs(i,(1<<(n+1))-1));
	}
	return 0;
} 

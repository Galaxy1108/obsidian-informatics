#include<cstdio>
#include<algorithm>
#include<vector>
#include<ctime>
#include<cmath>
using namespace std;
const int N=15;
bool vis[15];
int a[15];
int n; 
int cnt;
vector<int> ans[113401];
int st;
bool stop;
inline void write(int x){
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void dfs(int x){
	if(x==n){
		for(int i=1;i<=cnt;i++){
			bool ok=0;
			for(int j=0;j<ans[i].size();j++){
				if(abs(a[j]-ans[i][j])>1){
					ok=1;
					break;
				}	
			}
			if(!ok){
				return;
 			}
		}
		cnt++;
		for(int i=0;i<n;i++) ans[cnt].push_back(a[i]);
		int nw=clock();
		if((nw-st)>=950){
			stop=1;
			write(cnt);
			putchar('\n');
			for(int i=1;i<=cnt;i++){
				for(int j=0;j<ans[i].size();j++){
					write(ans[i][j]);
					putchar(' ');
				}
				putchar('\n');
			}
			exit(0);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[x]=i;
		dfs(x+1);
		if(stop) return;
		vis[i]=0;
	}
}
int main(){
	freopen("constr.in","r",stdin);
	freopen("constr.out","w",stdout);
	st=clock();
	scanf("%d",&n);
	dfs(0);
	return 0;
} 

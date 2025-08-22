#include<bits/stdc++.h>
#include <random>
using namespace std;
const int MAXN=5010;
int a[MAXN][MAXN],n,seed,book[MAXN];
void gen(int n,int seed){
    mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            swap(a[i][j],a[i][rng()%j+1]);
        }
    }
}
int dfs(int x){
	if(x==n){
		int a=0,b=0;
		for(int i=1;i<=n+1;i++){
			if(!book[i]){
				if(!a)
					a=i;
				else{
					b=i;
					break;
				}
			}
		}
		return(::a[a]>::a[b])?a:b;
	}
	int id,maxx=0;
	for(int i=1;i<=n+1;i++)
		if(!book[i]){
			book[i]=1;
			int t=dfs(x+1);
			if(a[x][t]>maxx){
				maxx=a[x][t];
				id=t;
			}
			book[i]=0;
		}
	return id;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>seed;
	gen(n,seed);
	for(int i=1;i<=n;i++){
		memset(book,0,sizeof book);
		cout<<dfs(i)<<" ";
	}
	return 0;
}


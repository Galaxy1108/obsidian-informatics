#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
#define ll long long
int maxnum[N][N],minnum[N][N];
int a[N];
int main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		int maxn = -1,minn = INT_MAX; 
		for(int j = i;j<=n;j++){
			maxn = max(maxn,a[j]);
			minn = min(minn,a[j]);
			maxnum[i][j] = maxn;
			minnum[i][j] = minn;
		} 
	}
	ll maxn = -1;
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			maxn = max(maxn,1ll*maxnum[i][j]*minnum[i][j]*(j-i+1));
		}
	}
	cout<<maxn;
	return 0;
} 

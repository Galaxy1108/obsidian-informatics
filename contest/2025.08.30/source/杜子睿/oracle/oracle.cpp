#include<bits/stdc++.h>
using namespace std;
int n,m,book[15][15],a[10],ans;
bool check(){
	int fl=0,s=0;
	for(int i=1;i<=n;i++){
		s+=a[i];
		if(a[i]>=2)
			fl=0;
		else if(fl)
			return false;
		else
			fl=1;
	}
	return true;
}
void dfs(int x){
	if(x==m+1){
		ans+=check();
		return;
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
			if(book[i][j])
				continue;
			a[i]++;
			a[j+1]--;
			book[i][j]=1;
			dfs(x+1);
			a[i]--;
			a[j+1]++;
			book[i][j]=0;
		}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("oracle.in","r",stdin);
	freopen("oracle.out","w",stdout);
	cin>>n>>m;
	dfs(1);
	cout<<ans;
	return 0;
}

